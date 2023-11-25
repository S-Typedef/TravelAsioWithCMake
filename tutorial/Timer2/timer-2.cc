#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

#include "timer-2.h"

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "Hello, world!" << std::endl;
}

int run_timer2()
{
	using namespace boost;

	std::cout<< "Hello!" << std::endl;

	asio::io_context io;
	asio::steady_timer t{io, asio::chrono::seconds{5}};
	t.async_wait(&print);
	std::cout<< "World!" << std::endl;
	io.run();
	
	return 0;
}