/// 1.
// Search
BOOL CInstanceBase::IsForceVisible()

// Add above
#if defined(ENABLE_EVENT_BANNER_FLAG)
BOOL CInstanceBase::IsBannerFlag()
{
	if (GetRace() >= 20127 && GetRace() <= 20143)
		return TRUE;

	return FALSE;
}
#endif
