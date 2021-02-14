#include <iostream>

#include <boost/asio/io_service.hpp>

#include "server.h"


int main()
{
    try {
        boost::asio::io_service ioService;

        Server server(ioService, std::stoi("9898"), "../new_files");

        ioService.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
