#include <iostream>
using namespace std;


void fillWithZeros(int board[][8], int size){
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = 0;
        }
    }

}

void printBoard(int board[][8], int size){
        
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout<<board[i][j]<< ' ';
        }
        cout<<"\n";
    } 
}

bool checkCapturesVH(int board[][8], int posI, int posJ){
    int count = 0;

    //Revisa las captura verticales
    for(int i=posI; i < 8; i++){
        count += board[i][posJ];
    }
    
    if(count > 1){

        return true;
    }


    count = 0;
     for(int i=posI; i >= 0; i--){
        count += board[i][posJ];
    }

    if(count > 1){

        return true;
    }

    //Revisa las capturas horizontales
    count = 0;
    for(int j=posJ; j < 8; j++){
        count += board[posI][j];
    }

    if(count > 1){

        return true;
    }

    count = 0;
    for(int j=posJ; j >= 0; j--){
        count += board[posI][j];
    }

    
      if(count > 1){

        return true;
    }


    return false;
}

bool checkCapturesD(int board[][8], int posI, int posJ){
    
    int count = 0;
    int i = posI;
    int j = posJ;

    //Revisa las capturas diagonales inferior derecha
    for(; i < 8 && j < 8; i++, j++){
        count += board[i][j];
    }

    if(count > 1 ){

        return true;
    }

    //Revisa las capturas diagonales superior derecha
    count = 0;
    i = posI;
    j = posJ;

    for(; i >= 0 &&  j < 8 ; i--, j++){
        count += board[i][j];
    }

    if(count > 1){

        return true;
    }

    //Revisa las capturas diagonales inferior izquierda
    count = 0;
    i = posI;
    j = posJ;

    for(; i < 8 && j >= 0; i++, j--){
        count += board[i][j];
    }

    if(count > 1){

        return true; 
    }

    //Revisa las capturas diagonales superior izquierda
    count = 0;
    i = posI;
    j = posJ;

    for(; i >= 0 && j >= 0; i--, j--){
        count += board[i][j];
    }

    if(count > 1){

        return true;
    }

    return false;

}

bool firstSQueen(int board[8][8], int posJ){
    if(posJ >=8){

        printBoard(board, 8);
        return true;
    }
    
    for(int i=0; i < 8; i++){
        board[i][posJ] = 1;

        if(!checkCapturesD(board, i, posJ) && !checkCapturesVH(board, i, posJ)){
            if(firstSQueen(board, posJ + 1)){
                return true;
            }
        }

        board[i][posJ] = 0;       

    }

    return false;
}

void allQueens(int board[8][8], int posJ){
    if(posJ >=8){
        printBoard(board, 8);
        cout<<"\n\n";
        return ;
    }
    
    
    for(int i=0; i < 8; i++){
        board[i][posJ] = 1;

        if(!checkCapturesD(board, i, posJ) && !checkCapturesVH(board, i, posJ)){
            allQueens(board, posJ + 1);
        }

        board[i][posJ] = 0;       

    }

}

int main(){

    int board[8][8];
    fillWithZeros(board, 8);


    cout<<"First solution found\n\n";
    firstSQueen(board, 0);

    cout<<"\nAll possible solutions found\n\n";
    allQueens(board, 0);

    return 0;

}
