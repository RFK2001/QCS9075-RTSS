savedcmd_sound/soc/qcom/qdsp6/audio-pkt.mod := printf '%s\n'   audio-pkt.o | awk '!x[$$0]++ { print("sound/soc/qcom/qdsp6/"$$0) }' > sound/soc/qcom/qdsp6/audio-pkt.mod
