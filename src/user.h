#pragma once

#include <string>

#include "message.h"


class User {
public:
    User(const std::string user_id);

    const std::string& GetUserId() const;

private:
    // QUESTION: How to do more kind of sort? Asc/Desc ...
    friend bool operator<(const User& left, const User& right);
    friend bool operator==(const User& left, const User& right);
    friend bool operator!=(const User& left, const User& right);

    const std::string user_id_;
};

struct UserHashFunction {
    size_t operator()(const User& u) const {
        return std::hash<std::string>()(u.GetUserId());
    }
};