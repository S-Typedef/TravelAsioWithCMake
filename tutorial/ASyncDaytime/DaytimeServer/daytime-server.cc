﻿#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
	using namespace std; // For time_t, time and ctime;
	time_t now = time(0);
	return ctime(&now);
}

class tcp_connection
	: public boost::enable_shared_from_this<tcp_connection>
{
public:
	typedef boost::shared_ptr<tcp_connection> pointer;

	static pointer create(boost::asio::io_context& io_context)
	{
		return pointer(new tcp_connection(io_context));
	}

	tcp::socket& socket()
	{
		return m_socket;
	}

	void start()
	{
		m_message = make_daytime_string();

		boost::asio::async_write(m_socket, boost::asio::buffer(m_message),
				boost::bind(&tcp_connection::handle_write, shared_from_this(),
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
	}

private:
	tcp_connection(boost::asio::io_context& io_context)
		: m_socket(io_context)
	{
	}

	void handle_write(const boost::system::error_code& /*error*/,
			size_t /*bytes_transferred*/)
	{
	}

	tcp::socket m_socket;
	std::string m_message;
};

class tcp_server
{
public:
	tcp_server(boost::asio::io_context& io_context)
		: m_io_context(io_context),
			m_acceptor(io_context, tcp::endpoint(tcp::v4(), 13))
	{
		start_accept();
	}

private:
	void start_accept()
	{
		tcp_connection::pointer new_connection =
			tcp_connection::create(m_io_context);

		m_acceptor.async_accept(new_connection->socket(),
				boost::bind(&tcp_server::handle_accept, this, new_connection,
					boost::asio::placeholders::error));
	}

	void handle_accept(tcp_connection::pointer new_connection,
			const boost::system::error_code& error)
	{
		if (!error)
		{
			new_connection->start();
		}

		start_accept();
	}

	boost::asio::io_context& m_io_context;
	tcp::acceptor m_acceptor;
};

int run_async_daytime_server()
{
	try
	{
		boost::asio::io_context io_context;
		tcp_server server(io_context);
		io_context.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}