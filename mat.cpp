#include<iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

const int high=126;
const int low=33;


namespace ariel {
	string mat(int col, int row, char s1, char s2){
        if(col%2 == 0 || row%2 == 0){
            throw invalid_argument{"Mat size is always odd"};
        }
        if(col<0 || row<0){
            throw invalid_argument{"col and row must be a positive numbers"};
        }
        if(s1<low || s1>high || s2>high || s2<low){
            throw invalid_argument{"bad symbols"};
        }
        
        vector<vector<char>> mymat(row, vector<char>(col));
        char sym=' ';
        int curRow=0;
        int curCol=0;
        while(curRow<=row/2 && curCol<=col/2){   //running on all the 'frames', from the outer to the inner
            if(curRow%2==0){    //change symbol between frames
                sym=s1;
            }else{
                sym=s2;
            }
            for(int i=curRow;i<col-curCol;i++){
                mymat[curRow][i]=sym;   //inserting the symbol in the top row of the frame
                mymat[row-1-curRow][i]=sym;  //inserting the symbol in the bottom row of the frame
            }
            for(int j=curRow;j<row-curRow;j++){
                mymat[j][col-1-curCol]=sym;   //inserting the symbol in the right column of the frame
                mymat[j][curRow]=sym;   ////inserting the symbol in the left column of the frame
            }
            curRow++;
            curCol++;
        }
                
        string design;   //insert the matrix into a string
        for(int i=0;i<row;i++){
             for(int j=0;j<col;j++){
                 design+=mymat[i][j];
             }design+='\n';
        }
        return design;
    }
}

