//
//  solver.cpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/14/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#include "solver.hpp"
#include <iostream>

void Solver::sort_mrv() {
    
};

int Solver::countConstraints(int index, int value) {
    int constraints = 0;
    
    // remove remaining values from row
    int offset_row = index % this->gameboard.getWidth();
    for(int i = (index - (this->gameboard.getWidth() - offset_row)) + 1 % this->gameboard.getTotalCells(); i <= (index + offset_row) % this->gameboard.getTotalCells(); i++) {
        if(this->gameboard.cells.at(i % this->gameboard.getTotalCells())->containsRemainingValue(value)) {
            constraints++;
        }
    }
    
    // remove remaining values from col
    for(int i = 0; i < this->gameboard.getTotalCells(); i += this->gameboard.getWidth()) {
        if(this->gameboard.cells.at((index + i) % this->gameboard.getTotalCells())->containsRemainingValue(value)) {
            constraints++;
        }
    }
    
    int offset_block = index % this->gameboard.getM();
    // remove remaining values from block
    for(int i = (index - offset_block) % this->gameboard.getTotalCells(); i < (index - offset_block) + (this->gameboard.getWidth() * this->gameboard.getM()); i += this->gameboard.getWidth()) {
        for(int j = 0; j < this->gameboard.getM(); j++) {
            if(this->gameboard.cells.at((i + j) % this->gameboard.getTotalCells())->containsRemainingValue(value)) {
                constraints++;
            }
        }
    }
    
    return constraints;
};
    
Solver::Solver(Gameboard gameboard) {
    this->gameboard = gameboard;
};

Solver::~Solver() {};

void Solver::solve() {

};
