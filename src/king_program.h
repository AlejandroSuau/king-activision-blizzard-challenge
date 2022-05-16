#pragma once

#include "message_store.h"
#include "users_controller.h"
#include "operations_chooser.h"
#include "operations_performer.h"


class KingProgram {
public:
    KingProgram();

    void Execute();

private:
    MessageStore message_store_;
    UsersController users_controller_;
    OperationsChooser operations_chooser_;
    OperationsPerformer operations_performer_;
};