#include <iostream>
#include <string>

int desk[8][8]; //матрица доски
std::string current_move; //строка хода
const int blank=0; //пустая клетка

//код фигур белых
const int W_pawn=1;
const int W_knight=2;
const int W_bishop=3;
const int W_rook=4;
const int W_queen=5;
const int W_king=6;

//код фигур черных
const int B_pawn=11;
const int B_knight=12;
const int B_bishop=13;
const int B_rook=14;
const int B_queen=15;
const int B_king=16;

void start(){
    ///инициализация поля
    //белых
    desk[0][0]=W_rook;
    desk[1][0]=W_knight;
    desk[2][0]=W_bishop;
    desk[3][0]=W_queen;
    desk[4][0]=W_king;
    desk[5][0]=W_bishop;
    desk[6][0]=W_knight;
    desk[7][0]=W_rook;

    //чёрных
    desk[0][7]=B_rook;
    desk[1][7]=B_knight;
    desk[2][7]=B_bishop;
    desk[3][7]=B_queen;
    desk[4][7]=B_king;
    desk[5][7]=B_bishop;
    desk[6][7]=B_knight;
    desk[7][7]=B_rook;

    //пешек
    for(int i=0; i < 8; i++){
        desk[i][1]=W_pawn;
        desk[i][6]=B_pawn;
    }

    //пустые
    for(int i=2; i < 6; i++){
        for(int j=0; j < 8; j++){
            desk[j][i]=blank;
        }
    }
}

//визуализация доски
/**
в массиве desk[x][y]
где x — столбец,
а y — строка.
**/
const void show_desk(){
    for(int i=7; i >= 0; i--){
        std::cout << i+1 << "  ";
        for(int j=0; j < 8; j++){
            ///чтение фигур
            switch(desk[j][i]){

            //белые
            case W_pawn:
                std::cout << "P ";
                break;
            case W_knight:
                std::cout << "N ";
                break;
            case W_bishop:
                std::cout << "B ";
                break;
            case W_rook:
                std::cout << "R ";
                break;
            case W_queen:
                std::cout << "Q ";
                break;
            case W_king:
                std::cout << "K ";
                break;

            //чёрные
            case B_pawn:
                std::cout << "p ";
                break;
            case B_knight:
                std::cout << "n ";
                break;
            case B_bishop:
                std::cout << "b ";
                break;
            case B_rook:
                std::cout << "r ";
                break;
            case B_queen:
                std::cout << "q ";
                break;
            case B_king:
                std::cout << "k ";
                break;

            default:
                std::cout <<"# ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "#  a b c d e f g h" << std::endl;
}

int x_in(){
    return current_move[0]-'a';
}
int y_in(){
    return current_move[1]-'1';
}

int x_to(){
    return current_move[3]-'a';
}
int y_to(){
    return current_move[4]-'1';
}

void game_cycle(int &move_num){
    system("cls");

    //вывод номера кода и ввод хода
    std::cout << "move: " << move_num << std::endl;
    show_desk();
    in_move:
    std::getline(std::cin, current_move);;
    if(current_move.size() != 5 ||
        current_move[0] < 'a' || current_move[0] > 'h' ||
        current_move[1] < '1' || current_move[1] > '8' ||
        current_move[3] < 'a' || current_move[3] > 'h' ||
        current_move[4] < '1' || current_move[4] > '8'){
    std::cout << "wrong move" << std::endl;
    goto in_move;
    }
    std::cout << std::endl << desk[x_in()][y_in()] << " " << desk[x_to()][y_to()];
}

int main(){
    int move_num=0;
    start();

    while(true){
        game_cycle(move_num);
        move_num++;
    }

    return 0;
}
