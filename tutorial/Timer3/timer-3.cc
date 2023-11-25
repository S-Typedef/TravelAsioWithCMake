#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

#include "timer-3.h"

void print(const boost::system::error_code& /*e*/,
	boost::asio::steady_timer* t, int* count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		++(*count);

		t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
		t->async_wait(boost::bind(print,
			boost::asio::placeholders::error, t, count));
	}
}

int run_timer3()
{
	using namespace boost;

	std::cout<< "Hello!" << std::endl;

	int count = 0;
	asio::io_context io;
	asio::steady_timer t{io, asio::chrono::seconds{0}};
	t.async_wait(boost::bind(
		print, boost::asio::placeholders::error, &t, &count
	));
	std::cout<< "World!" << std::endl;
	io.run();
	std::cout<< "Final count is " << count << std::endl;
	
	return 0;
}