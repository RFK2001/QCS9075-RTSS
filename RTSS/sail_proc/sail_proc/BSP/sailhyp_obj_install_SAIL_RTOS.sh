#!/bin/bash
SRCROOT=${1:BUG}
DSTROOT=${2:BUG}
args=("$@")

echo 'sailhyp OBJ installer root dir = ' ${args[0]}
cp $SRCROOT/security/aarch32/DEBUG/sailhyp/*.o $DSTROOT/sailhyp/.
rm $DSTROOT/sailhyp/TestSAILAccessControlcfgmain.o
rm $DSTROOT/sailhyp/TestSAILAccessControlmain.o
rm $DSTROOT/sailhyp/TestsSAILAccessControlAPImain.o
echo "sailhyp OBJ install completed.."
