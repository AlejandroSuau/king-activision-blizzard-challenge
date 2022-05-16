#include "operations_performer.h"

#include "operation.h"


OperationsPerformer::OperationsPerformer(UsersController& users_controller)
    : users_controller_(users_controller), did_finish_(false) {}

// QUESTION: How to do this with lambdas? Instead of inheritance operations.
void OperationsPerformer::PerformOperation(std::size_t operation_id) {
    std::unique_ptr<IOperation> operation;
    switch(operation_id) {
        case 1:
            operation = std::make_unique<AddUserOperation>();
            break;
        case 2:
            operation = std::make_unique<SendMessageToUserOperation>();
            break;
        case 3:
            operation = std::make_unique<PrintAndRemoveUserReceivedMessagesOperation>();
            break;
        case 4:
            operation = std::make_unique<SortAndPrintAllSenderMessagesOperation>();
            break;
        default:
        case 5:
            did_finish_ = true;
            break;
    }
    
    // QUESTION: How the program knows which perform should do? In terms of memory. (VTABLE)
    if (!did_finish_) operation->Perform(users_controller_);
}

bool OperationsPerformer::DidFinish() const {
    return did_finish_;
}