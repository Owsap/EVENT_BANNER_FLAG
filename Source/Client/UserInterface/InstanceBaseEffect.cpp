/// 1.
// Search @ void CInstanceBase::__AttachEmpireEffect
	if (IsInvisibility())
		return;

// Add below
#if defined(ENABLE_EVENT_BANNER_FLAG)
	if (IsBannerFlag())
		return;
#endif
