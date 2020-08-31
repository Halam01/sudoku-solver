//
//  cell.hpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/10/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>
#include <vector>

class Cell {
private:
    int value;
    std::vector<int> remaining_values;
    
public:
    Cell(int value, std::vector<int> values);
    ~Cell();
    std::vector<int>  getRemainingValues() { return remaining_values; };
    int getValue() { return value; };
    int getRandomRemainingValue();
    void setValue(int value);
    void removeRemainingValue(int value);
    bool containsRemainingValue(int value);
};
#endif /* cell_hpp */
