savedcmd_sound/soc/qcom/snd-soc-x1e80100.mod := printf '%s\n'   x1e80100.o | awk '!x[$$0]++ { print("sound/soc/qcom/"$$0) }' > sound/soc/qcom/snd-soc-x1e80100.mod
