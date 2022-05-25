#pragma once

#include <time.h>
#include <string>

class User;

class Message {
public:
    Message(const User& user_from, const User& user_to, const std::string content);

    const std::string GetTimestamp(const char* format = "%Y-%m-%d %H:%M:%S") const;
    const User& GetUserFrom() const;
    const User& GetUserTo() const;
    const std::string& GetContent() const;

private:
    // QUESTION: What will happend if the User is delete (those references) where delete?.
    // ANSWER: User& addresses will point to a incorrect memory address, so it will ends
    //         with an unexpected behaviour. One way to solve this is using weak_ptr and 
    //         its ".lock()" function.
    const User& user_from_;
    const User& user_to_;
    const std::string content_;
    const time_t timestamp_;
};