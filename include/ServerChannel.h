#ifndef SERVERCHANNEL_H
#define SERVERCHANNEL_H

#include "Channel.h"
#include <iostream>

class ServerChannel : public Channel {
public:
  ServerChannel(Socket *socket) : Channel(socket) {}

  void start() override {
    std::cout << "Server started." << std::endl;
    channelSocket->connect();
  }

  void stop() override {
    channelSocket->shutdown();
    std::cout << "Server stopped." << std::endl;
  }

  void send(const std::string &message) override {
    channelSocket->send(message);
  }

  void receive() override { channelSocket->receive(); }
};

#endif // SERVERCHANNEL_H
