#include "king_program.h"

#include <iostream>


KingProgram::KingProgram() 
    : users_controller_(message_store_),
      operations_performer_(users_controller_) {}

void KingProgram::Execute() {
    while (!operations_performer_.DidFinish()) {
        operations_chooser_.ShowOperations();
        const std::size_t operation = operations_chooser_.ChooseOperation();
        operations_performer_.PerformOperation(operation);

        if (!operations_performer_.DidFinish()) {
            std::cout << "Enter any key and press return to continue ...";
            std::string str;
            std::getline(std::cin, str);
        }
    }
}