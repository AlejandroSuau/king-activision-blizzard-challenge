#include "user.h"


// QUESTION: Moving a const string, seriously?
User::User(const std::string user_id) : user_id_(std::move(user_id)) {}

const std::string& User::GetUserId() const {
    return user_id_;
}

bool operator<(const User& left, const User& right) {
    return (left.user_id_.compare(right.user_id_) < 0);
}

bool operator==(const User& left, const User& right) {
    return (left.user_id_ == right.user_id_);
}

bool operator!=(const User& left, const User& right) {
    return (left.user_id_ != right.user_id_);
}