#include <iostream>

#include "timer-1.h"
#include "timer-2.h"
#include "timer-3.h"
#include "timer-4.h"
#include "timer-5.h"

#include "SyncDaytime/DaytimeServer/daytime-server.h"
#include "SyncDaytime/DaytimeClient/daytime-client.h"

#include "ASyncDaytime/DaytimeServer/daytime-server.h"
#include "ASyncDaytime/DaytimeClient/daytime-client.h"

#include "SyncUDPDaytime/DaytimeServer/udp-daytime-server.h"
#include "SyncUDPDaytime/DaytimeClient/udp-daytime-client.h"

int main(int argc, char* argv[])
{
	//Timer-1
	//run_timer1();

	//Timer-2
	// run_timer2();

	//Timer-3
	// run_timer3();

	//Timer-4
	// run_timer4();

	//Timer-5
	//run_timer5();

	//Daytime-1

	// if (argc == 1)
	// 	run_sync_daytime_server();
	// else
	// 	run_sync_daytime_client(argc, argv);

	// if (argc == 1)
	// 	run_async_daytime_server();
	// else
	// 	run_async_daytime_client(argc, argv);
	if (argc == 1)
#ifdef USE_ASYNC
		run_async_daytime_server_udp();
#else
		run_sync_daytime_server_udp();
#endif
	else
		run_sync_daytime_client_udp(argc, argv);
	return 0;
}