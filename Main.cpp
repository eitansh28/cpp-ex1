#include<iostream>
#include <string>
#include <stdexcept>
#include "mat.hpp"

using namespace std;

int main(){
    cout<<"Thank you for buying from 'Eitan - designing mats as you wish'!"<<endl;
    cout<<endl;
    int col;
    int row;
    char symbol1;
    char symbol2;
    string design;
    int exit=0;
    while (exit==0){
        cout<<"choose width size for your mat(odd number)"<<endl;
        cin>>col;
        cout<<"choose length size for your mat(odd number)"<<endl;
        cin>>row;
        cout<<"choose the first symbol to design your mat"<<endl;
        cin>>symbol1;
        cout<<"choose the second symbol to design your mat"<<endl;
        cin>>symbol2;
        try {
            design=ariel::mat(col,row,symbol1,symbol2);
            cout<<"Your designed mat is ready!!"<<endl;
            cout<<design<<endl;
        } 
        catch (const exception& e) { 
            cout<<"please insert odd number and legal chars"<<endl; 
        };
        cout<<"If you want to continue to choose mats - click 0. if you want to get out - click 1"<<endl;
        cin>>exit;
        }
    cout<<"Thank you for buying from 'Eitan - designing mats as you wish'!"<<endl;
}