/// 1.
// Search
typedef std::map<DWORD, CHARACTER_SET> pkCharRaceSet;

// Add below
#if defined(__EVENT_BANNER_FLAG__)
typedef std::map<DWORD, std::string> BannerMapType;
#endif

/// 2.
// Search
private:
	int m_iMobItemRate;

// Add above
#if defined(__EVENT_BANNER_FLAG__)
public:
	enum EBannerMapIndex
	{
		EMPIRE_A = 1,
		EMPIRE_B = 21,
		EMPIRE_C = 41,
	};
	bool InitializeBanners();
	bool SpawnBanners(int iEnable, const char* c_szBannerName = NULL);

private:
	BannerMapType BannerMap;
	bool m_bIsLoadedBanners;
#endif
