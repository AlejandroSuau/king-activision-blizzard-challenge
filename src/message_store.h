#pragma once

#include <vector>
#include <memory>

#include "message.h"


class MessageStore {
public:
    MessageStore();
    // QUESTION: Why add message do not returns a bool?
    void AddMessage(const std::shared_ptr<const Message> message);
    void PrintAllSenderMessages() const;
    void SortMessages();

    std::vector<std::shared_ptr<const Message>>& GetMessages();

private:
    std::vector<std::shared_ptr<const Message>> messages_;
};