//
//  gameboard.cpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/10/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#include "gameboard.hpp"
#include <iostream>

Gameboard::Gameboard() {
    this->width = 9 * 9;
    this->n = 9;
    this->m = 9;
    this->difficulty = 16;
    this->total_cells = 9 * 9;
    std::vector<int> default_remaining_values;
    
    for (int i = 0; i < this->width; i++) {
        default_remaining_values.push_back(i + 1);
    }

    for (int i = 0; i < total_cells; i++) {
        this->cells.push_back(new Cell(0, default_remaining_values));
    }
}

Gameboard::Gameboard(int n, int m, int difficulty) {
    this->width = n * m;
    this->n = n;
    this->m = m;
    this->difficulty = difficulty;
    this->total_cells = width * width;
    std::vector<int> default_remaining_values;
    
    for (int i = 0; i < this->width; i++) {
        default_remaining_values.push_back(i + 1);
    }

    for (int i = 0; i < total_cells; i++) {
        this->cells.push_back(new Cell(0, default_remaining_values));
    }
}

Gameboard::~Gameboard() {}

void Gameboard::renderBoard() {
    int count = 0;
    for (std::vector<Cell*>::iterator it = cells.begin(); it != cells.end(); ++it) {
        std::cout << (*it)->getValue();
        count++;
        if (count % width == 0) {
            std::cout << std::endl;
        }
    }
}

void Gameboard::initializeStartingValues() {
    for (int i = 0; i < difficulty; i++) {
        int cell_to_assign = rand() % total_cells;
        while(cells.at(cell_to_assign)->getValue() != 0) {
            cell_to_assign = rand() % total_cells;
        }
        
        std::cout << "assigning cell: " << cell_to_assign << std::endl;
        populateCell(cell_to_assign);
    }
}

void Gameboard::populateCell(int index) {
    int assign_value = cells.at(index)->getRandomRemainingValue();
    cells.at(index)->setValue(assign_value);
    cells.at(index)->removeRemainingValue(assign_value);
    
    std::cout << "assigning value: " << assign_value << std::endl;
    
    // remove remaining values from row
    int offset_row = index % width;
    for(int i = (index - (width - offset_row)) + 1 % total_cells; i <= (index + offset_row) % total_cells; i++) {
        std::cout<< "row - removed " << assign_value << " at: " << i % total_cells << std::endl;
        cells.at(i % total_cells)->removeRemainingValue(assign_value);
    }
    
    // remove remaining values from col
    for(int i = 0; i < total_cells; i += width) {
        std::cout<< "col - removed " << assign_value << " at: " << (index + i) % total_cells << std::endl;
        cells.at((index + i) % total_cells)->removeRemainingValue(assign_value);
    }
    
    int offset_block = index % m;
    // remove remaining values from block
    for(int i = (index - offset_block) % total_cells; i < (index - offset_block) + (width * m); i += width) {
        for(int j = 0; j < m; j++) {
            std::cout<< "block - removed " << assign_value << " at: " << (i + j) % total_cells << std::endl;
            cells.at((i + j) % total_cells)->removeRemainingValue(assign_value);
        }
    }
}
