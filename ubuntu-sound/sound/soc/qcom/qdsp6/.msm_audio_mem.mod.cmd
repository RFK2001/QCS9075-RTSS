savedcmd_sound/soc/qcom/qdsp6/msm_audio_mem.mod := printf '%s\n'   msm_audio_mem.o | awk '!x[$$0]++ { print("sound/soc/qcom/qdsp6/"$$0) }' > sound/soc/qcom/qdsp6/msm_audio_mem.mod
