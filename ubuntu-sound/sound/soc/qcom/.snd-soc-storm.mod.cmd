savedcmd_sound/soc/qcom/snd-soc-storm.mod := printf '%s\n'   storm.o | awk '!x[$$0]++ { print("sound/soc/qcom/"$$0) }' > sound/soc/qcom/snd-soc-storm.mod
