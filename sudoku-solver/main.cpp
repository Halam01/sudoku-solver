//
//  main.cpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/10/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#include <iostream>
#include "gameboard.hpp"
#include "solver.hpp"

int main(int argc, const char * argv[]) {
    Gameboard gameboard = Gameboard(3, 3, 16);

    gameboard.renderBoard();
    gameboard.initializeStartingValues();
    gameboard.renderBoard();
    
    Solver solver = Solver(gameboard);
    solver.solve();
    
    return 0;
}
