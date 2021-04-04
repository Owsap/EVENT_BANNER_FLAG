/// 1.
// Search @ void CPythonTextTail::ShowCharacterTextTail
	if (pInstance->IsGuildWall())
		return;

// Add below
#if defined(ENABLE_EVENT_BANNER_FLAG)
	if (pInstance->IsBannerFlag())
		return;
#endif
