/// 1.
// Search @ CHARACTER_MANAGER::CHARACTER_MANAGER
	m_iUserDamageRatePremium = 100;

// Add below
#if defined(__EVENT_BANNER_FLAG__)
	m_bIsLoadedBanners = false;
#endif

/// 2.
// Add to the bottom of the document
#if defined(__EVENT_BANNER_FLAG__)
#include "CsvReader.h"
bool CHARACTER_MANAGER::InitializeBanners()
{
	if (m_bIsLoadedBanners)
		return false;

	const char* c_szFileName = "data/banner/list.txt";

	cCsvTable nameData;
	if (!nameData.Load(c_szFileName, '\t'))
	{
		sys_log(0, "%s couldn't be loaded or its format is incorrect.", c_szFileName);
		return false;
	}
	else
	{
		nameData.Next();
		while (nameData.Next())
		{
			if (nameData.ColCount() < 2)
				continue;

			BannerMap.insert(std::make_pair(atoi(nameData.AsStringByIndex(0)), nameData.AsStringByIndex(1)));
		}
	}
	nameData.Destroy();

	m_bIsLoadedBanners = true;

	DWORD dwFlagVnum = quest::CQuestManager::instance().GetEventFlag("banner");
	if (dwFlagVnum > 0)
		SpawnBanners(dwFlagVnum);

	return true;
}

bool CHARACTER_MANAGER::SpawnBanners(int iEnable, const char* c_szBannerName)
{
	if (!m_bIsLoadedBanners)
		InitializeBanners();

	bool bDestroy = true;
	bool bSpawn = false;

	DWORD dwBannerVnum = 0;
	std::string strBannerName;

	if (!c_szBannerName)
	{
		BannerMapType::const_iterator it = BannerMap.find(iEnable);
		if (it == BannerMap.end())
			return false;

		dwBannerVnum = it->first;
		strBannerName = it->second;
	}
	else
	{
		for (BannerMapType::const_iterator it = BannerMap.begin(); BannerMap.end() != it; ++it)
		{
			if (!strcmp(it->second.c_str(), c_szBannerName))
			{
				dwBannerVnum = it->first;
				strBannerName = it->second;
				break;
			}
		}
	}

	if (dwBannerVnum == 0 || strBannerName.empty())
		return false;

	if (iEnable > 0)
		bSpawn = true;

	if (bDestroy)
	{
		quest::CQuestManager::instance().RequestSetEventFlag("banner", 0);

		CharacterVectorInteractor i;
		CHARACTER_MANAGER::GetCharactersByRaceNum(dwBannerVnum, i);

		for (CharacterVectorInteractor::iterator it = i.begin(); it != i.end(); it++)
		{
			M2_DESTROY_CHARACTER(*it);
		}
	}

	if (bSpawn)
	{
		quest::CQuestManager::instance().RequestSetEventFlag("banner", dwBannerVnum);

		if (map_allow_find(EBannerMapIndex::EMPIRE_A))
		{
			std::string strBannerFile = "data/banner/a/" + strBannerName + ".txt";

			if (LPSECTREE_MAP pkMap = SECTREE_MANAGER::instance().GetMap(EBannerMapIndex::EMPIRE_A))
			{
				regen_do(strBannerFile.c_str(), EBannerMapIndex::EMPIRE_A, pkMap->m_setting.iBaseX, pkMap->m_setting.iBaseY, NULL, false);
			}
		}

		if (map_allow_find(EBannerMapIndex::EMPIRE_B))
		{
			std::string strBannerFile = "data/banner/b/" + strBannerName + ".txt";

			if (LPSECTREE_MAP pkMap = SECTREE_MANAGER::instance().GetMap(EBannerMapIndex::EMPIRE_B))
			{
				regen_do(strBannerFile.c_str(), EBannerMapIndex::EMPIRE_B, pkMap->m_setting.iBaseX, pkMap->m_setting.iBaseY, NULL, false);
			}
		}

		if (map_allow_find(EBannerMapIndex::EMPIRE_C))
		{
			std::string strBannerFile = "data/banner/c/" + strBannerName + ".txt";

			if (LPSECTREE_MAP pkMap = SECTREE_MANAGER::instance().GetMap(EBannerMapIndex::EMPIRE_C))
			{
				regen_do(strBannerFile.c_str(), EBannerMapIndex::EMPIRE_C, pkMap->m_setting.iBaseX, pkMap->m_setting.iBaseY, NULL, false);
			}
		}
	}

	return true;
}
#endif
