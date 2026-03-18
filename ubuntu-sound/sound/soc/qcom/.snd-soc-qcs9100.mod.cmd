savedcmd_sound/soc/qcom/snd-soc-qcs9100.mod := printf '%s\n'   qcs9100.o | awk '!x[$$0]++ { print("sound/soc/qcom/"$$0) }' > sound/soc/qcom/snd-soc-qcs9100.mod
