savedcmd_sound/soc/qcom/qdsp6/spf-core.mod := printf '%s\n'   spf-core.o | awk '!x[$$0]++ { print("sound/soc/qcom/qdsp6/"$$0) }' > sound/soc/qcom/qdsp6/spf-core.mod
