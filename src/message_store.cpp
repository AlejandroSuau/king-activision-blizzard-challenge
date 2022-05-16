#include "message_store.h"
#include "user.h"

#include <algorithm>
#include <iostream>
#include <sstream>


MessageStore::MessageStore() {}

void MessageStore::AddMessage(const std::shared_ptr<const Message> message) {
    messages_.push_back(message);
}

void MessageStore::SortMessages() {
    auto comparator = [](const std::shared_ptr<const Message> left, 
                         const std::shared_ptr<const Message> right) {
        const User& user_from_left = left->GetUserFrom();
        const User& user_from_right = right->GetUserFrom();
        if (user_from_left != user_from_right)
            return (user_from_left < user_from_right);

        const User& user_to_left = left->GetUserTo();
        const User& user_to_right = right->GetUserTo();
        if (user_to_left != user_to_right)
            return (user_to_left < user_to_right);

        return (left->GetTimestamp() < right->GetTimestamp());
    };
    std::sort(messages_.begin(), messages_.end(), comparator);
}

void MessageStore::PrintAllSenderMessages() const {
    if (messages_.empty()) return;

    std::stringstream ss;
    auto print_messages = [&ss](const User& user, const std::size_t messages_count) {
        std::cout << user.GetUserId() << " (" << messages_count << "):\n" << ss.str();
    };

    std::size_t i = 0, user_messages_count = 0;
    for (const auto message : messages_) {
        if (i > 0 && message->GetUserFrom() != messages_[i - 1]->GetUserFrom()) {
            const User& previous_user = messages_[i - 1]->GetUserFrom();
            print_messages(previous_user, user_messages_count);
            ss.str("");
            user_messages_count = 0;
        }
        ss << "\t" << message->GetTimestamp() << ", ";
        ss << message->GetUserTo().GetUserId() << std::endl;
        ++i; ++user_messages_count;
    }

    if (ss.str() != "") {
        auto last_message = messages_[messages_.size() - 1];
        print_messages(last_message->GetUserFrom(), user_messages_count);
    }
}

std::vector<std::shared_ptr<const Message>>& MessageStore::GetMessages() {
    return messages_;
}