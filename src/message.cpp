#include "message.h"

#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "user.h"


Message::Message(const User& user_from,
                 const User& user_to,
                 const std::string content)
    : user_from_(user_from),
      user_to_(user_to),
      content_(content), 
      timestamp_(time(0)) {}

const std::string Message::GetTimestamp(const char* format) const {
    std::stringstream ss;
    ss << std::put_time(std::localtime(&timestamp_), format);
		return ss.str();
}

const User& Message::GetUserFrom() const {
  return user_from_;
}

const User& Message::GetUserTo() const {
  return user_to_;
}

const std::string& Message::GetContent() const {
  return content_;
}