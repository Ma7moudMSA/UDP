#include "UDPSocket.h"

#include "UDPSocket.h"
#include <string.h>

UDPSocket::UDPSocket(const std::string &multicastAddress, int port) {
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    std::cerr << "Failed to create UDP socket." << std::endl;
    exit(1);
  }
  memset(&multicastAddr, 0, sizeof(multicastAddr));
  multicastAddr.sin_family = AF_INET;
  multicastAddr.sin_addr.s_addr = inet_addr(multicastAddress.c_str());
  multicastAddr.sin_port = htons(port);
}

UDPSocket::~UDPSocket() { close(sockfd); }

void UDPSocket::connect() {
  // UDP is connectionless, so no real connection needed.
  std::cout << "UDP socket ready." << std::endl;
}

void UDPSocket::send(const std::string &message) {
  if (sendto(sockfd, message.c_str(), message.size(), 0,
             (struct sockaddr *)&multicastAddr, sizeof(multicastAddr)) < 0) {
    std::cerr << "UDP send failed." << std::endl;
  }
}

void UDPSocket::receive() {
  char buffer[1024];
  struct sockaddr_in srcAddr;
  socklen_t addrLen = sizeof(srcAddr);
  int bytes = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                       (struct sockaddr *)&srcAddr, &addrLen);
  if (bytes < 0) {
    std::cerr << "UDP receive failed." << std::endl;
  } else {
    std::cout << "UDP received: " << std::string(buffer, bytes) << std::endl;
  }
}

void UDPSocket::shutdown() {
  // Since UDP is connectionless, just close the socket
  close(sockfd);
}
