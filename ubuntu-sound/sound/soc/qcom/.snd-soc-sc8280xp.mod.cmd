savedcmd_sound/soc/qcom/snd-soc-sc8280xp.mod := printf '%s\n'   sc8280xp.o | awk '!x[$$0]++ { print("sound/soc/qcom/"$$0) }' > sound/soc/qcom/snd-soc-sc8280xp.mod
