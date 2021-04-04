/// 1.
// Search
struct command_info cmd_info[] =

// Add above
#if defined(__EVENT_BANNER_FLAG__)
ACMD(do_banner);
#endif

/// 2.
// Search
	{ "\n", NULL, 0, POS_DEAD, GM_IMPLEMENTOR } /* 반드시 이 것이 마지막이어야 한다. */

// Add above
#if defined(__EVENT_BANNER_FLAG__)
	{ "banner", do_banner, 0, POS_DEAD, GM_IMPLEMENTOR },
#endif
