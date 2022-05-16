#pragma once

#include "users_controller.h"


class IOperation {
public:
    virtual ~IOperation() {}
    virtual void Perform(UsersController& users_controller) = 0;
};


class AddUserOperation : public IOperation {
public:
    ~AddUserOperation() {}
    void Perform(UsersController& users_controller) override;
};


class SendMessageToUserOperation : public IOperation {
public:
    ~SendMessageToUserOperation() {}
    void Perform(UsersController& users_controller) override;
};


class PrintAndRemoveUserReceivedMessagesOperation : public IOperation {
public:
    ~PrintAndRemoveUserReceivedMessagesOperation() {}
    void Perform(UsersController& users_controller) override;
};


class SortAndPrintAllSenderMessagesOperation : public IOperation {
public:
    ~SortAndPrintAllSenderMessagesOperation() {}
    void Perform(UsersController& users_controller) override;  
};
