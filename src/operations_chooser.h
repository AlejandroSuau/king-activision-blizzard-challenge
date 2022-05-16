#pragma once

#include <iostream>


class OperationsChooser {
public:
    OperationsChooser();
    
    void ShowOperations() const;
    std::size_t ChooseOperation() const;

private:
    const std::size_t MIN_OPERATION = 1;
    const std::size_t MAX_OPERATION = 5;

    bool IsCorrectOperation(const std::size_t operation) const;

    void ClearScreen() const;
};