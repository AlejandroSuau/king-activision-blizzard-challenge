#include "operation.h"

#include <iostream>


void AddUserOperation::Perform(UsersController& users_controller) {
    std::cout << "Please enter name: ";
    std::string user_id;
    std::getline(std::cin, user_id);
    users_controller.AddNewUser(user_id);
}

void SendMessageToUserOperation::Perform(UsersController& users_controller) {
    std::cout << "From: ";
    std::string user_id_from;
    std::getline(std::cin, user_id_from);
    
    std::cout << "To: ";
    std::string user_id_to;
    std::getline(std::cin, user_id_to);  
    
    std::cout << "Message: ";
    std::string message;
    std::getline(std::cin, message);
    users_controller.SendMessageToUser(user_id_from, user_id_to, message);
    
    std::cout << std::endl;
}

void PrintAndRemoveUserReceivedMessagesOperation::Perform(UsersController& users_controller) {
    std::cout << "Enter name of user to receive all messages for: " << std::endl;
    std::string user_id;
    std::getline(std::cin, user_id);
    std::cout << std::endl;
    users_controller.PrintAndRemoveUserReceivedMessages(user_id);
}

void SortAndPrintAllSenderMessagesOperation::Perform(UsersController& users_controller) {
    MessageStore& message_store = users_controller.GetMessageStore();
    message_store.SortMessages();
    message_store.PrintAllSenderMessages();
}
