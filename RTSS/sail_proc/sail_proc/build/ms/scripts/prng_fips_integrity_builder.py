import subprocess
import hashlib
import os, sys
import shlex

READ_SYMBOL_ADDR_COLUMN = 1
OFFSET_COLUMN_INDEX = 1
ADDR_COLUMN_INDEX = 2
SIZE_COLUMN_INDEX = 4
SECTION_SIZE = 3



#----------------------------------------------------------------------------
# run_readelf
#----------------------------------------------------------------------------


def run_readelf(options, file_path):
    if os.name == 'nt':
        readelf_path = 'llvm-readelf'
    else:
        if os.path.isfile('/pkg/qct/software/llvm/release/arm/14.0.0/bin/llvm-readelf') == True:
            readelf_path = '/pkg/qct/software/llvm/release/arm/14.0.0/bin/llvm-readelf'
        elif "LLVM_READELF" in os.environ:
            readelf_path = os.getenv("LLVM_READELF")
        else:
            raise RuntimeError("LLVM_READELF environment variable is not set. (ex: llvm/release/arm/*.*.*/bin/llvm-readelf)")
    
    command = '{0} {1} {2}'.format(readelf_path, options, file_path)

    if os.name != 'nt':
        ret = subprocess.check_output(shlex.split(command, posix=False), shell=False)
    else:
        ret = subprocess.check_output(shlex.split(command, posix=False), shell=True)

    return ret

#----------------------------------------------------------------------------
# find_symbol_addr
#----------------------------------------------------------------------------
def find_symbol_addr(symbol, elfread):
    for line in elfread.split('\n'):
        if symbol in line:
            return int(line.split()[READ_SYMBOL_ADDR_COLUMN], 16)
    return -1

#----------------------------------------------------------------------------
# find_symbol_section_start_addr_offset
#----------------------------------------------------------------------------
def find_symbol_section_start_addr_offset(symbol, elf_readelf):
    symbol_addr = find_symbol_addr(symbol, elf_readelf)
    if symbol_addr == -1:
        return -1, -1
    for line in elf_readelf.split('n'):
        if 'LOAD' in line:
            for i in range(0, len(line.split())-1):
                if line.split()[i] == 'LOAD':
                    min = int(line.split()[i + ADDR_COLUMN_INDEX],16)
                    max = int(line.split()[i + ADDR_COLUMN_INDEX], 16) + int(line.split()[i + SIZE_COLUMN_INDEX], 16)
                    if hex(min) <= hex(symbol_addr) and  hex(max) >= hex(symbol_addr):
                        return int(line.split()[i + ADDR_COLUMN_INDEX], 16), int(line.split()[i + OFFSET_COLUMN_INDEX], 16)

    return -1, -1

#----------------------------------------------------------------------------
# find_symbol_offset
#----------------------------------------------------------------------------
def find_symbol_offset(symbol, output, offset_addr, offset):
    for line in output.split('\n'):
        if symbol in line:
            return int(line.split()[READ_SYMBOL_ADDR_COLUMN], 16) - offset_addr + offset
    return -1

    
def is_symbol_missing(text_start,
                      text_end,
                      hash_text_start,
                      hash_text_end,
                      rodata_start,
                      rodata_end,
                      hash_rodata_start,
                      hash_rodata_end):
    if -1 not in [text_start,
                  text_end,
                  hash_text_start,
                  hash_text_end,
                  rodata_start,
                  rodata_end,
                  hash_rodata_start,
                  hash_rodata_end]:
        return False

    print("WARNING: Could not generate FIPS Integrity HASH. Missing symbol.")
    if text_start == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_TEXT_MARKER$$Base")
    if text_end == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_TEXT_MARKER$$Limit")
    if hash_text_start == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_TEXT_HASH$$Base")
    if hash_text_end == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_TEXT_HASH$$Limit")
    if rodata_start == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_RODATA_MARKER$$Base")
    if rodata_end == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_RODATA_MARKER$$Limit")
    if hash_rodata_start == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_RODATA_HASH$$Base")
    if hash_rodata_end == -1:
        print("Missing Symbol: Image$$PRNG_INTEGRITY_RODATA_HASH$$Limit")		
    return True

#----------------------------------------------------------------------------
# prng_fips_add_integrity_hash
#----------------------------------------------------------------------------
def prng_fips_add_integrity_hash(elf_file_path, rslt_file_path):
    elf_readelf = run_readelf('-a', elf_file_path).decode("utf-8")

    # Find the section address and offset where PRNG FIPS Hybrid Module's .text is located
    text_sectStartAddr, text_sectStartOffset = find_symbol_section_start_addr_offset('Image$$PRNG_INTEGRITY_TEXT_MARKER$$Base', elf_readelf)
    if text_sectStartAddr == -1 or text_sectStartOffset == -1:
        print("WARNING: Could not generate FIPS Integrity HASH. Could not find loadable text section in elf")
        return

    # Find the section address and offset where PRNG FIPS Hybrid Module's .rodata is located
    rodata_sectStartAddr, rodata_sectStartOffset = find_symbol_section_start_addr_offset('Image$$PRNG_INTEGRITY_RODATA_MARKER$$Base', elf_readelf)
    if rodata_sectStartAddr == -1 or rodata_sectStartOffset == -1:
        print("WARNING: Could not generate FIPS Integrity HASH. Could not find loadable rodata section in mbn")
        return

    text_start = find_symbol_offset('Image$$PRNG_INTEGRITY_TEXT_MARKER$$Base', elf_readelf, text_sectStartAddr, text_sectStartOffset)
    text_end = find_symbol_offset('Image$$PRNG_INTEGRITY_TEXT_MARKER$$Limit', elf_readelf, text_sectStartAddr, text_sectStartOffset)
    rodata_start = find_symbol_offset('Image$$PRNG_INTEGRITY_RODATA_MARKER$$Base', elf_readelf, rodata_sectStartAddr, rodata_sectStartOffset)
    rodata_end = find_symbol_offset('Image$$PRNG_INTEGRITY_RODATA_MARKER$$Limit', elf_readelf, rodata_sectStartAddr, rodata_sectStartOffset)
    hash_text_start = find_symbol_offset('Image$$PRNG_INTEGRITY_TEXT_HASH$$Base', elf_readelf, rodata_sectStartAddr, rodata_sectStartOffset)
    hash_text_end = find_symbol_offset('Image$$PRNG_INTEGRITY_TEXT_HASH$$Limit', elf_readelf, rodata_sectStartAddr, rodata_sectStartOffset)
    hash_rodata_start = find_symbol_offset('Image$$PRNG_INTEGRITY_RODATA_HASH$$Base', elf_readelf, rodata_sectStartAddr, rodata_sectStartOffset)
    hash_rodata_end = find_symbol_offset('Image$$PRNG_INTEGRITY_RODATA_HASH$$Limit', elf_readelf, rodata_sectStartAddr, rodata_sectStartOffset)
    

    # Could not find a needed symbol in the readelf output
    if is_symbol_missing(text_start,
                         text_end,
                         hash_text_start,
                         hash_text_end,
                         rodata_start,
                         rodata_end,
                         hash_rodata_start,
                         hash_rodata_end):
        return

    text_hash = hashlib.sha256()
    rodata_hash = hashlib.sha256()
    data = None

    with open(elf_file_path, 'rb') as mbn:
        data = bytearray(mbn.read())
        text_to_hash = data[text_start:text_end]
        text_hash.update(text_to_hash)
        rodata_to_hash = data[rodata_start:rodata_end]
        rodata_hash.update(rodata_to_hash)

    script_dir = os.path.dirname(os.path.abspath(__file__))
    hash_file_location = os.path.join(script_dir, 'prng_fips_wa_module_hash.txt')
    write_option = 'a' if os.path.isfile(hash_file_location) else 'w+'

    with open(hash_file_location, write_option) as hash_file:
        target_text_file_name = "prng_fips_wa_text_hash_64"
        target_rodata_file_name = "prng_fips_wa_rodata_hash_64"
        hash_file.write("{0}: {1}\n".format(target_text_file_name, text_hash.hexdigest()))
        hash_file.write("{0}: {1}\n".format(target_rodata_file_name, rodata_hash.hexdigest()))
	
    with open(rslt_file_path, 'wb+') as result:
        result_bin = data
        result_bin[hash_text_start:hash_text_end] = text_hash.digest()
        result_bin[hash_rodata_start:hash_rodata_end] = rodata_hash.digest()
        result.write(result_bin)

def add_prng_fips_integrity_hash(target, source):
    file_elf = source #source[0].get_abspath()
    file_rslt = target #target[0].get_abspath()

    prng_fips_add_integrity_hash(file_elf, file_rslt)

    return None
    
if __name__ == "__main__":
    a = sys.argv[1]
    b = sys.argv[2]
    add_prng_fips_integrity_hash(a, b)
