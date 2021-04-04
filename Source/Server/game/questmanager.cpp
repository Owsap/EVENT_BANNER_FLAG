/// 1.
// Search
		else if (name == "new_xmas_event")

// Add above
#if defined(__EVENT_BANNER_FLAG__)
		else if (name == "banner")
		{
			CHARACTER_MANAGER::instance().InitializeBanners();
		}
#endif
