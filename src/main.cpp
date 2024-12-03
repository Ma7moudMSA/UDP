

#include "MulticastServer.h"
#include <chrono>
#include <ctime>
#include <thread>

// Helper function to get the current time
std::string getCurrentTime() {
  std::time_t now = std::time(nullptr);
  std::tm *localTime = std::localtime(&now);
  char buffer[80];
  std::strftime(buffer, 80, "%I:%M %p", localTime);
  return std::string(buffer);
}

int main() {
  // Multicast address and port
  std::string multicastAddress = "239.0.0.1";
  int port = 12345;

  MulticastServer server(multicastAddress, port);

  // Periodically send system updates
  while (true) {
    std::string message = "System update at " + getCurrentTime();

    server.sendMulticastMessage(message);

    // Wait for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }

  return 0;
}
