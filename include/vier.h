#ifndef VIER
#define VIER

#include <vector>
#include <iostream>

class FourInARow{
public:
    FourInARow() : currentPlayer(1) {};
    void SetBoard(int Height, int Width);

    bool isFull();
    bool isFullColumn(int Column);
    bool Place(int Column);
    bool checkWinner();
    bool checkDirection(int x, int y, int dx, int dy);

    void Print();
private:
    std::vector<std::vector<int>> Board{};
    int currentPlayer;
};

#endif