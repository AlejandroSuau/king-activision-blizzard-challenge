#pragma once

#include "users_controller.h"


class OperationsPerformer {
public:
    OperationsPerformer(UsersController& users_controller);

    void PerformOperation(std::size_t operation_id);
    
    bool DidFinish() const;

private:
    UsersController& users_controller_;
    bool did_finish_;
};