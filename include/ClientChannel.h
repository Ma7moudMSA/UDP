#ifndef CLIENTCHANNEL_H
#define CLIENTCHANNEL_H

#include "Channel.h"
#include <iostream>

class ClientChannel : public Channel {
public:
  ClientChannel(Socket *socket) : Channel(socket) {}

  void start() override {
    std::cout << "Client started." << std::endl;
    channelSocket->connect();
  }

  void stop() override {
    channelSocket->shutdown();
    std::cout << "Client stopped." << std::endl;
  }

  void send(const std::string &message) override {
    channelSocket->send(message);
  }

  void receive() override { channelSocket->receive(); }
};

#endif // CLIENTCHANNEL_H
