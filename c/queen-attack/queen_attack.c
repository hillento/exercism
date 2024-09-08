#include "queen_attack.h"

int offBoard(uint8_t x){
    return (x >= 8) ? 1 : 0;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    //If the queens are too far vertically or horizontally 
    if(offBoard(queen_1.row) || offBoard(queen_2.row) || offBoard(queen_1.column) || offBoard(queen_2.column)) 
    { 
        return INVALID_POSITION; 
    }

    //If the queens are on the same row, attack is valid
    if(queen_1.row == queen_2.row && queen_1.column != queen_2.column)
    {
        return CAN_ATTACK;
    }

    //If queens are on the same column, attack is valid
    if(queen_1.row != queen_2.row && queen_1.column == queen_2.column)
    {
        return CAN_ATTACK;
    }

    //If queens are on the same column, attack is valid
    if(queen_1.row == queen_2.row && queen_1.column == queen_2.column)
    {
        return INVALID_POSITION;
    }

    //if queens the same horizontal and vertical distance away,
    if(abs(queen_1.column - queen_2.column) == abs(queen_1.row - queen_2.row))
    {
        return CAN_ATTACK;
    }

    //If it doesn't meet attack requirements, then it cannot attack
    return CAN_NOT_ATTACK;
}   
