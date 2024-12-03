
#include "MulticastServer.h"
#include <chrono>
#include <string.h>
#include <thread>

MulticastServer::MulticastServer(const std::string &multicastAddress, int port)
    : multicastAddress(multicastAddress), port(port) {
  setupSocket();
}

MulticastServer::~MulticastServer() { close(sockfd); }

void MulticastServer::setupSocket() {
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    std::cerr << "Failed to create socket." << std::endl;
    exit(1);
  }

  memset(&multicastAddr, 0, sizeof(multicastAddr));
  multicastAddr.sin_family = AF_INET;
  multicastAddr.sin_addr.s_addr = inet_addr(multicastAddress.c_str());
  multicastAddr.sin_port = htons(port);
}

void MulticastServer::sendMulticastMessage(const std::string &message) {
  if (sendto(sockfd, message.c_str(), message.size(), 0,
             (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) < 0) {
    std::cerr << "Failed to send multicast message." << std::endl;
  } else {
    std::cout << "Sending multicast message: " << message << std::endl;
  }
}

void MulticastServer::startSending(const std::string &message,
                                   int intervalSeconds) {
  while (true) {
    sendMulticastMessage(message);
    std::this_thread::sleep_for(std::chrono::seconds(intervalSeconds));
  }
}
