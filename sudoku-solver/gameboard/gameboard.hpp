//
//  gameboard.hpp
//  sudoku-solver
//
//  Created by Hanna Alam on 11/10/19.
//  Copyright © 2019 Hanna Alam. All rights reserved.
//

#ifndef gameboard_hpp
#define gameboard_hpp

#include <stdio.h>
#include <vector>
#include "cell.hpp"

class Gameboard {
private:
    int width;
    int n;
    int m;
    int total_cells;
    int difficulty;
    
public:
    std::vector<Cell*> cells;
        
    Gameboard();
    Gameboard(int n, int m, int difficulty);
    ~Gameboard();
    int getWidth() { return width; };
    int getN() { return n; };
    int getM() { return m; };
    int getTotalCells() { return width * width; };
    int getDifficulty() {return difficulty; };
    void renderBoard();
    void initializeStartingValues();
    void populateCell(int index);
    
};

#endif /* gameboard_hpp */
