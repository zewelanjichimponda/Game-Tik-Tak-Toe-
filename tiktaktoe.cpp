//
//  main.cpp
//  tik tak toe
//
//  Created by ZEWELANJI CHIMPONDA on 5/8/20.
//  Copyright © 2020 ZEWELANJI CHIMPONDA. All rights reserved.
//

#include <iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void display(){
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<endl;
     cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<endl;
     cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" | "<<endl;
}

int getWin()
{
    //horizontal
    if(board[0][0]==board[0][1] && board[0][1]==board[0][2])
        return 1;
    else if(board[2][0]==board[2][1] && board[2][1]==board[2][2])
        return 1;
    else if(board[1][0]==board[1][1] && board[1][1]==board[1][2])
        return 1;
    
    //vertical
    else if(board[0][0]==board[1][0] && board[1][0]==board[2][0])
        return 1;
    else if(board[0][1]==board[1][1] && board[1][1]==board[2][1])
        return 1;
    else if(board[0][2]==board[1][2] && board[1][2]==board[2][2])
        return 1;
    
    //cross
    else if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return 1;
    else if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;
    
    else if(board[0][0]!='1' && board[0][1] !='2' && board[0][2]!='3' && board[1][0]!= '4' && board[1][1]!= '5' && board[1][2] != '6' && board[2][0]!= '7' && board[2][1]!= '8' && board[2][2]!='9')
        return 0;
    else return -1;
}


int main(int argc, const char * argv[]) {
    int player =1, status, choose;
    char mark;
    do{
        display();
        if(player%2!=0)
            player=1;
        else player=2;
        cout<<"player "<< player<<" Enter number from board: "<<endl;
        cin>>choose;
        
        if(player==1)
            mark='X';
        else
            mark='O';
        
        if(board[0][0]== '1' && choose==1)
            board[0][0]=mark;
        else if(board[0][1]== '2' && choose==2)
            board[0][1]=mark;
        else if(board[0][2]== '3' && choose==3)
            board[0][2]=mark;
        else if(board[1][0]== '4' && choose==4)
            board[1][0]=mark;
        else if(board[1][1]== '5' && choose==5)
            board[1][1]=mark;
        else if(board[1][2]== '6' && choose==6)
            board[1][2]=mark;
        else if(board[2][0]== '7' && choose==7)
            board[2][0]=mark;
        else if(board[2][1]== '8' && choose==8)
            board[2][1]=mark;
        else if(board[2][2]== '9' && choose==9)
            board[2][2]=mark;
        
        else {
            cout<<"Invalid Entry"<<endl;
            player--;
            cin.ignore();
            cin.get();
        }
        
        status= getWin();
        player++;
    } while (status==-1);
    
    display();
    
    if(status==1)
        cout<<"player "<<--player<<" Wins";
    else
        cout<<"game over, no winner"<<endl;
    
    cin.ignore();
    cin.get();
    return 0;
}
