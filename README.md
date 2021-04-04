# Event Banner Flag

Introduced in the 10th anniversary of Metin2, your city will look more appealing with banner flags describing the on-going event your server is currently running.  

## How to add more banners?

@ `data/banner/list.txt`
VNUM | NAME
------ | ------
20142 | halloween
20143 | easter
20135 | xmas

You can simply add more banner flags following the example above.  

**`VNUM`** is the **VNUM** / **ID** of the NPC.  
**`NAME`** is the name of the **command** and **file** of the banner.  

**Note:** If you want to add for example the **Ramadan Banner** which **VNUM** is *20138*, this is how you should do it step by step.
1. Edit @ `data/banner/list.txt` and extended the file with:  

VNUM | NAME
------ | ------
20138 | ramadan

2. Make duplicates of the existing banners.  
    2.1. Copy `data/banner/a/xmas.txt` and rename the duplicated file to `data/banner/a/ramadan.txt`  
	Edit `data/banner/a/ramadan.txt` and replace the **VNUM** / **ID** with the **Ramadan Banner** *20138*.  

	2.2. Copy `data/banner/b/xmas.txt` and rename the duplicated file to `data/banner/b/ramadan.txt`  
	Edit `data/banner/a/ramadan.txt` and replace the **VNUM** / **ID** with the **Ramadan Banner** *20138*.  

	2.3. Copy `data/banner/a/xmas.txt` and rename the duplicated file to `data/banner/c/ramadan.txt`  
	Edit `data/banner/a/ramadan.txt` and replace the **VNUM** / **ID** with the **Ramadan Banner** *20138*.  

3. @ `Src/Client/UserInterface/InstanceBase.cpp`  
	Search

       #if defined(ENABLE_EVENT_BANNER_FLAG)
       BOOL CInstanceBase::IsBannerFlag()
       {
           if (GetRace() >= 20127 && GetRace() <= 20143)
               return TRUE;
           return FALSE;
       }
       #endif

	Replace with (*If you want it to be more managble*)

       #if defined(ENABLE_EVENT_BANNER_FLAG)
       BOOL CInstanceBase::IsBannerFlag()
       {
           switch(GetRace())
           {
           case 20127: // Anniversary Banner 1
           case 20128: // Anniversary Banner 2
           case 20129: // Anniversary Banner 3
           case 20130: // Anniversary Banner 4
           case 20131: // Anniversary Banner 5
           case 20132: // Anniversary Banner 6
           case 20133: // Anniversary Banner 7
           case 20134: // Solar Banner
           case 20135: // Christmas Banner
           case 20138: // Ramadan Banner
           case 20142: // Halloween Banner
           case 20143: // Easter Banner
               return TRUE;
           }
           return FALSE;
       }
       #endif


Don't forget each folder (**a** / **b** / **c**) have different positions so be careful when copying files.


## How to activiate?

In-game, you can use the command:  
`/banner < x > < banner_name >` where < **x** > is the status ( **1** : **ON** / **0** : **OFF** ) and < **banner_name** > is the name of the banner @ `data/banner/list.txt`  
