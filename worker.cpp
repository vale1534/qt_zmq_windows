#include "worker.h"

#include <zmq.hpp>
#include <iostream>

void Worker::run()
{
    zmq::context_t context(1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while(!closed.load()) {
        zmq::message_t request;
        if (!socket.recv(&request, ZMQ_DONTWAIT)) {
            Sleep(50);
            continue;
        }

        std::cout << "<< received Hello" << std::endl;

        zmq::message_t reply (5);
        memcpy(reply.data(), "World", 5);
        socket.send(reply);
    }

    std::cout << "<< exit" << std::endl;
}

void Worker::close()
{
    closed.store(true);
}
