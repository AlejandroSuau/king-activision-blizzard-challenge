#pragma once

#include "user.h"

#include <set>

#include "message_store.h"

// QUESTION: Should be separated implementation from UI (like printing.)

class UsersController {
public:
    UsersController(MessageStore& message_store);

    void AddNewUser(const std::string user_id);
    void SendMessageToUser(const std::string user_id_from,
                           const std::string user_id_to,
                           const std::string message_content);
    void PrintAndRemoveUserReceivedMessages(const std::string& user_id);

    const User* GetUser(const std::string user_id) const;
    MessageStore& GetMessageStore();

private:
    // QUESTION: Why put messages store reference inside UsersController ...?
    MessageStore& message_store_;
    // QUESTION: Why using a set (it is sorted ...). It should be unordered_set.
    // Whats the complexity of set? How STL set internally works?
    // How unordered_set works, what is the complexity?
    std::set<User> users_; 
};