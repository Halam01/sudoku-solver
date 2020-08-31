//
//  solver.hpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/14/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#ifndef solver_hpp
#define solver_hpp

#include <stdio.h>
#include <ctime>
#include "gameboard.hpp"

class Solver {
private:
    Gameboard gameboard;
    bool mrv_enabled;
    bool lcv_enabled;
    clock_t startTime;
    double duration;
    int total_backtracks;
    std::vector<Cell*> mrv_queue;
    
    void sort_mrv();
    int countConstraints(int index, int value);
    
    
public:
    Solver(Gameboard gameboard);
    ~Solver();
    void solve();
};

#endif /* solver_hpp */
