savedcmd_sound/soc/qcom/snd-soc-lpass-ipq806x.mod := printf '%s\n'   lpass-ipq806x.o | awk '!x[$$0]++ { print("sound/soc/qcom/"$$0) }' > sound/soc/qcom/snd-soc-lpass-ipq806x.mod
