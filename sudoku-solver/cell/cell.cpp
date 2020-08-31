//
//  cell.cpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/10/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#include "cell.hpp"

Cell::Cell(int value, std::vector<int> default_remaining_values) {
    this->value = value;
    this->remaining_values = default_remaining_values;
}

Cell::~Cell() {}

int Cell::getRandomRemainingValue() {
    return remaining_values.at(rand() % remaining_values.size());
}

void Cell::setValue(int value) {
    this->value = value;
}

void Cell::removeRemainingValue(int value) {
    if (!remaining_values.empty()) {
        auto index = std::find(remaining_values.begin(), remaining_values.end(), value);
        if (index != remaining_values.end()) {
            remaining_values.erase(index);
        }
    }
}

bool Cell::containsRemainingValue(int value) {
    if (!remaining_values.empty()) {
        auto index = std::find(remaining_values.begin(), remaining_values.end(), value);
        if (index != remaining_values.end()) {
            return true;
        }
    }
    return false;
}
