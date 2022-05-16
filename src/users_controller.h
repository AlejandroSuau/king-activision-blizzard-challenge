#pragma once

#include "user.h"

#include <unordered_set>

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

    // # Unordered set
    // - Complexity: O(1).
    // - Order: All elements are sorted.
    // - How internally works: is implemented using a hash table where keys are hashed
    //   into indices of a hash table so that the insertion is always randomized.

    // # Set
    // - Complexity: O(LogN).
    // - Order: All elements are sorted.
    // - How internally works: are implemented using Binary Search Trees.
    std::unordered_set<User, UserHashFunction> users_;
};