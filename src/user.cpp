#include "user.h"


// When trying to move a constant string, it performs a copy, instead
// of a move. So, we should not move a constant string.
User::User(std::string user_id) : user_id_(user_id) {}

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