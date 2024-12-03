#ifndef CHANNEL_H
#define CHANNEL_H

#include "Socket.h"

class Channel {
public:
  virtual ~Channel() = default;

  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void send(const std::string &message) = 0;
  virtual void receive() = 0;

protected:
  Socket *channelSocket;

  Channel(Socket *socket) : channelSocket(socket) {}
};

#endif // CHANNEL_H
