#include "users_controller.h"

#include <iostream>


UsersController::UsersController(MessageStore& message_store)
    : message_store_(message_store) {}

void UsersController::AddNewUser(const std::string user_id) {
    const bool is_added = users_.insert(user_id).second;
    if (is_added) {
        std::cout << "User " << user_id << " added!" << std::endl;
    } else {
        std::cout << "User " << user_id << " already exist!" << std::endl;
    }
}

void UsersController::SendMessageToUser(const std::string user_id_from,
                                        const std::string user_id_to,
                                        const std::string message_content) {
    const User* user_from = GetUser(user_id_from);
    const User* user_to = GetUser(user_id_to);
    if (user_from == nullptr || user_to == nullptr) return;

    std::shared_ptr<Message> message = std::make_shared<Message>(
        *user_from, *user_to, message_content);
    message_store_.AddMessage(message);
    
    std::cout << "Message Sent!" << std::endl;
}

void UsersController::PrintAndRemoveUserReceivedMessages(
        const std::string& user_id) {
    const User* user = GetUser(user_id);
    if (user == nullptr) return;

    auto& messages = message_store_.GetMessages();
    std::vector<std::shared_ptr<const Message>>::iterator it = messages.begin();
    std::size_t user_messages_counter = 0;
    while (it != messages.end()) {
        if ((*it)->GetUserTo() == *user) {
            std::cout << "Message " << ++user_messages_counter << std::endl;
            std::cout << "From: " << (*it)->GetUserFrom().GetUserId() << std::endl;
            std::cout << "Content: " << (*it)->GetContent() << std::endl;
            std::cout << std::endl;
            it = messages.erase(it);
        } else {
            ++it;
        }
    }
}

const User* UsersController::GetUser(const std::string user_id) const {
    std::set<User>::iterator it = users_.find(User(user_id));
    if (it == users_.end()) {
        std::cout << "ERROR: User " << user_id << " doesn't exists" << std::endl;
        return nullptr;
    } else {
        return &(*it);
    }
}

MessageStore& UsersController::GetMessageStore() {
    return message_store_;
}