#pragma once

#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

class MulticastServer {
public:
  MulticastServer(const std::string &multicastAddress, int port);
  ~MulticastServer();
  void startSending(const std::string &message, int intervalSeconds);
  void sendMulticastMessage(const std::string &message);

private:
  std::string multicastAddress;
  int port;
  int sockfd;
  struct sockaddr_in multicastAddr;

  void setupSocket();
};
