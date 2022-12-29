#include <iostream>

#include "vier.h"

int main(){
    int Input = 0;
    int Move = 0;
    FourInARow F;
    F.SetBoard(5, 5);
    while(Input < 2){
        std::cin >> Input;
        switch(Input){
        case 1:{ 
            std::cin >> Move;
            F.Place(Move);
            break;
        }
        case 0: F.Print();
        }
    }    
    return 0;
}