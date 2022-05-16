#include "operations_chooser.h"

#include <stdio.h>
#include <string>


OperationsChooser::OperationsChooser() {}

std::size_t OperationsChooser::ChooseOperation() const {
    std::size_t operation;
    bool is_correct_operation;
    do {
        std::string raw_input;
        std::getline(std::cin, raw_input);
        sscanf(raw_input.c_str(), "%zu", &operation);
        
        is_correct_operation = IsCorrectOperation(operation);
        if (!is_correct_operation) {
            std::cout << "Invalid Option Selected." << std::endl;
            std::cout << "Please select a correct one:";
        }
    } while(!is_correct_operation);
    
    return operation;
}

bool OperationsChooser::IsCorrectOperation(const std::size_t operation) const {
    return (operation >= MIN_OPERATION && operation <= MAX_OPERATION);
}

void OperationsChooser::ShowOperations() const {
    ClearScreen();
    std::cout << std::endl << "========== MENU ==========" << std::endl;
	std::cout << "1. Create User" << std::endl;
	std::cout << "2. Send Message" << std::endl;
	std::cout << "3. Receive All Messages For User" << std::endl;
    std::cout << "4. Report All Messages Of All Senders" << std::endl;
	std::cout << "5. Quit" << std::endl;
    std::cout << "==========================" << std::endl << std::endl;
    std::cout << "Please select an option:";
}

void OperationsChooser::ClearScreen() const {
    std::cout << "\033[2J\033[1;1H";
}
