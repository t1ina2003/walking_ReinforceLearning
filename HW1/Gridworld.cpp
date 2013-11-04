/*************************************************************
Author: walking
Date: 2013_11_4
Description: a grid world apply state-value function
Input:  nothing
Output: a state-value table
*************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

void Bellman_eq();

double state_value[7][7]={0};           //state value table
double next_state_value[7][7]={0};      //next state value table
double reward [7][7]=                   //Reward table
{
    -1,-1,-1,-1,-1,-1,-1,
    -1, 0,10, 0, 5, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1,-1,-1,-1,-1,-1,-1
};
char yes_no;

int main(){
    start:
    Bellman_eq();

    cout<<endl;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++)
            cout<<setprecision(2)<<setw(6)<<state_value[i][j]<<"  ";
        cout<<endl<<endl;
    }
    cout<<"-------------------"<<endl;

    cout<<"Do it again?";
    cin>>yes_no;
    if(yes_no=='y'){
    system("cls");
    goto start;
    }
}

void Bellman_eq(){

    /*Design pattern:
    calculate all state-value with three different V(s') condition.*/
    double up,down,left,right;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ///V(s')有三種狀況：無事件、撞牆reward[i+1][j+2]、特殊點
            up=state_value[i][j+1];
            if ((i)==1 && (j+1)==2) up=state_value[5][2];               //special condition of [1][2]state
            if ((i)==1 && (j+1)==4) up=state_value[3][4];               //special condition of [1][4]state
            if(reward[i][j+1]==-1)up=state_value[i+1][j+1];         //condition bump into wall

            down=state_value[i+2][j+1];
            if ((i+2)==1 && (j+1)==2) down=state_value[5][2];
            if ((i+2)==1 && (j+1)==4) down=state_value[3][4];
            if(reward[i+2][j+1]==-1)down=state_value[i+1][j+1];     //condition bump into wall


            left=state_value[i+1][j];
            if ((i+1)==1 && (j)==2) left=state_value[5][2];
            if ((i+1)==1 && (j)==4) left=state_value[3][4];
            if(reward[i+1][j]==-1)left=state_value[i+1][j+1];       //condition bump into wall

            right=state_value[i+1][j+2];
            if ((i+1)==1 && (j+2)==2) right=state_value[5][2];
            if ((i+1)==1 && (j+2)==4) right=state_value[3][4];
            if(reward[i+1][j+2]==-1)right=state_value[i+1][j+1];    //condition bump into wall

            if(i+1==1 && j+1==2)cout<<" up:"<<up<<endl<<" down:"<<down<<endl<<" left:"<<left<<endl<<" right:"<<right<<endl;

            next_state_value[i+1][j+1]=
                (0.25*1*(reward[i][j+1]+0.9*up))+
                (0.25*1*(reward[i+2][j+1]+0.9*down))+
                (0.25*1*(reward[i+1][j]+0.9*left))+
                (0.25*1*(reward[i+1][j+2]+0.9*right));

            if(i+1==1 && j+1==2)cout<<" rewardup:"<<reward[i][j+1]<<endl<<" rewarddown:"<<reward[i+2][j+1]<<endl<<" rewardleft:"<<reward[i+1][j]<<endl<<" rewardright:"<<reward[i+1][j+2]<<endl;

        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            state_value[i+1][j+1]=next_state_value[i+1][j+1];
        }
    }

}
