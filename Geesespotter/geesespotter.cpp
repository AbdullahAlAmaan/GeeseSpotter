#include "geesespotter_lib.h"
#include <iostream>
//1   
char *create_board(std::size_t x_dim, std::size_t y_dim){
char* board= new char[(x_dim*y_dim)]{};
for (std::size_t i = 0; i < x_dim*y_dim; ++i) {
        board[i] = 0;
}
return board;}
//2
void clean_board(char *board){
delete[] board;
board=nullptr;
return;}
//3
void print_board(char *board, std::size_t x_dim, std::size_t y_dim) {
    for (std::size_t y = 0; y < y_dim; ++y) {
        for (std::size_t x = 0; x < x_dim; ++x) {
            std::size_t index = y * x_dim + x;

            if ((board[index] & marked_mask()) == marked_mask()) {
                std::cout << "M";
            } else if ((board[index] & hidden_mask()) == hidden_mask()) {
                std::cout << "*";
            } else {
                std::cout << (board[index] & value_mask());
            }
        }
        
        std::cout << std::endl;
    }
}

//4
void hide_board(char * board, std::size_t x_dim, std::size_t y_dim){
    for(std::size_t i = 0; i< x_dim*y_dim; ++i){
        board[i] |= hidden_mask();}
return;}
//5
int mark(char * board, std::size_t x_dim, std::size_t y_dim, std::size_t x_loc, std::size_t y_loc){
    std::size_t a = y_loc * x_dim + x_loc;
    if((board[a] & hidden_mask()) != 0){
    if ((board[a] & marked_mask()) == marked_mask()) {
        board[a] &= ~marked_mask();
    } else {
        board[a] |= marked_mask();}
return 0;}
return 1;}
//6
void compute_neighbours(char *board, std::size_t x_dim, std::size_t y_dim) {
    for (std::size_t y = 0; y < y_dim; ++y) {
        for (std::size_t x = 0; x < x_dim; ++x) {
            std::size_t index = y * x_dim + x;
            if ((board[index] & value_mask()) != 9) {  
                int geese_count = 0;
                for (int a = 0; a < 3; ++a) {
                    for (int b = 0; b < 3; ++b) {
                        int x1 = a - 1;
                        int y1 = b - 1;
                        int x2 = x + x1;
                        int y2 = y + y1;
                        if (x2 >= 0 && x2 < x_dim && y2 >= 0 && y2 < y_dim && !(x1 == 0 && y1 == 0)) {
                            std::size_t index1 = y2 * x_dim + x2;
                            if ((board[index1] & value_mask()) == 9) {
                                geese_count++;
                            }
                        }
                    }
                }
                board[index] = (board[index] & ~value_mask()) | (geese_count & value_mask());
            }
        }
    }
    
}

//7
bool is_game_won(char *board, std::size_t x_dim, std::size_t y_dim) {
    for (std::size_t y = 0; y < y_dim; ++y) {
        for (std::size_t x = 0; x < x_dim; ++x) {
            std::size_t index = y * x_dim + x;
            char cell = board[index];
            if ((cell & value_mask()) == 9) {
                if (!(cell & (marked_mask() | hidden_mask()))) {
                    return false; 
                }
            } else {
                if (cell & hidden_mask()) {
                    return false; 
                }
            }
        }
    }
    return true; 
}

//8
int reveal(char *board, std::size_t x_dim, std::size_t y_dim, std::size_t x_loc, std::size_t y_loc) {
    std::size_t index = y_loc * x_dim + x_loc;

    if (board[index] & marked_mask()) {
        return 1;
    }
    else if (!(board[index] & hidden_mask())) {
        return 2;
    }
    else if ((board[index] & value_mask()) == 9) {
        for (std::size_t i = 0; i < x_dim * y_dim; ++i) {
            board[i] &= ~hidden_mask();
        }
        return 9; 
    }
    board[index] &= ~hidden_mask();
    if ((board[index] & value_mask()) == 0) {
        for (int y1 = 0; y1 < 3; ++y1) {
            for (int x1 = 0; x1 < 3; ++x1) {
                int x2 = x_loc + x1 - 1;
                int y2 = y_loc + y1 - 1;
                if ((x2 >= 0) && (x2 <x_dim) && (y2 >= 0) && (y2 < y_dim) && !(x1 == 1 && y1 == 1)) {
                    std::size_t index1 = y2 * x_dim + x2;
                    if ((board[index1] & hidden_mask()) && !(board[index1] & marked_mask())) {
                        board[index1] &= ~hidden_mask();
                    }
                }
            }
        }
    }

    return 0;
}








