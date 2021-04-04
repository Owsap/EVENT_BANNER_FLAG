/// 1.
// Search @ void CPythonMiniMap::Update
		else if (pkInstEach->IsNPC())

// Replace with
#if defined(ENABLE_EVENT_BANNER_FLAG)
		else if (pkInstEach->IsNPC() && !pkInstEach->IsBannerFlag())
#else
		else if (pkInstEach->IsNPC())
#endif
