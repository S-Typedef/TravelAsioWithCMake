#include <iostream>

#include "timer-1.h"
#include "timer-2.h"
#include "timer-3.h"
#include "timer-4.h"
#include "timer-5.h"

#include "daytime-server.h"
#include "daytime-client.h"


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

	if (argc == 1)
		run_daytime_server();
	else
		run_daytime_client(argc, argv);
	return 0;
}