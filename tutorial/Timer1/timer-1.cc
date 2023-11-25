#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

#include "timer-1.h"

int run_timer1()
{
	using namespace boost;

	std::cout<< "Hello!" << std::endl;

	asio::io_context io;
	asio::steady_timer t{io, asio::chrono::seconds{5}};
	t.wait();

	std::cout<< "World!" << std::endl;


	return 0;
}