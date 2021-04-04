/// 1.
// Add to the bottom of the document
#if defined(__EVENT_BANNER_FLAG__)
ACMD(do_banner)
{
	char arg1[256], arg2[256];
	int iEnable = 0;

	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	if (!*arg1 || !*arg2 || !isnhdigit(*arg1))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Usage: /banner <1:0> <banner_name>");
		ch->ChatPacket(CHAT_TYPE_INFO, "Example: /banner 1 easter");
		return;
	}

	str_to_number(iEnable, arg1);

	CHARACTER_MANAGER::instance().SpawnBanners(iEnable, arg2);

	return;
}
#endif
