#pragma once

#include "Socket.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class UDPSocket : public Socket {
public:
  UDPSocket(const std::string &multicastAddress, int port);
  ~UDPSocket() override;

  void connect() override;
  void send(const std::string &message) override;
  void receive() override;
  void shutdown() override;

private:
  int sockfd;
  struct sockaddr_in multicastAddr;
};