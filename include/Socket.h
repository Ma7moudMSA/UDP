#pragma once

#include <string>

class Socket {
public:
  virtual ~Socket() = default;

  // Pure virtual functions for socket behavior
  virtual void connect() = 0;
  virtual void send(const std::string &message) = 0;
  virtual void receive() = 0;
  virtual void shutdown() = 0;
};
