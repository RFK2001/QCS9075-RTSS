savedcmd_sound/soc/qcom/snd-soc-qcm6490.mod := printf '%s\n'   qcm6490.o | awk '!x[$$0]++ { print("sound/soc/qcom/"$$0) }' > sound/soc/qcom/snd-soc-qcm6490.mod
