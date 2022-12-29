#include "vier.h"

void FourInARow::SetBoard(int Height, int Width){
    std::vector<int> Temp;
    Temp.resize(Width, 0);
    Board.resize(Height, Temp);        
}

bool FourInARow::isFull(){
    for(auto h : Board)
        for(auto w : h)
            if(w != 0) return false;
    return true;
}

bool FourInARow::Place(int Column){
    if(Board[0][Column] != 0) return false;
    for(int i = Board.size() - 1; i >= 0; i--)
        if(Board[i][Column] == 0){ 
            Board[i][Column] = currentPlayer;
            if(checkWinner()) std::cout << currentPlayer << " Won!" << std::endl;
            currentPlayer == 1 ? currentPlayer = 2 : currentPlayer = 1;
            return true;    
        }
    return false;
}

bool FourInARow::checkWinner(){
    if(isFull()){
        std::cout << "Draw" << std::endl;
        return true;
    }
    // for(int y = int(Board.size()) - 1; y >= 0; y--)
    for(int y = 0; y < int(Board.size()); y++)
        for(int x = 0; x < int(Board[0].size()); x++)
            if( checkDirection(x, y, 0, 1) ||
                checkDirection(x, y, 1, 0) ||
                checkDirection(x, y, 1, 1) ||
                checkDirection(x, y, 1, -1))
                return true; 
    return false;
}

bool FourInARow::checkDirection(int x, int y, int dx, int dy){
    if(x + 3*dx < 0 || x + 3*dx >= int(Board[0].size()) || y + 3*dy < 0 || y + 3*dy >= int(Board.size())) return false;
    if(Board[y][x] != currentPlayer) return false;
    if(Board[y+dy][x+dx] != currentPlayer) return false;
    if(Board[y+2*dy][x+2*dx] != currentPlayer) return false;
    if(Board[y+3*dy][x+3*dx] != currentPlayer) return false;
    return true;
}

void FourInARow::Print(){
    for(auto a : Board){
        for(auto b : a)
            std::cout << b << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}