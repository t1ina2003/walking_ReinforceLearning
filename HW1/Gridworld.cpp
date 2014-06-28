/*************************************************************
Author: walking
Date: 2013_11_4
Description: a grid world apply state-value function
Input: nothing
Output: a state-value table
*************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "write_csv_file.h"
using namespace std;

void Bellman_eq(double **state_value,int height, int width);
//void write_file(char * file_name,int count,double **state_value);

int main(){
    int height=7,width=7;                                           //set height,width

    double **state_value=(double**) calloc(height,sizeof(double*)); //initial state value table
    for(int i=0;i<height;i++)
        state_value[i]=(double*) calloc(width,sizeof(double));

    int times,count=0;                                             //accumulated Iteration times

    while(cout<<"input cycle times:",cin>>times){
        system("cls");
        for(int i=0;i<times;i++,++count)Bellman_eq(state_value,height,width);

        cout<<endl<<" Iteration times:"<<count<<endl<<endl;//execute times

        for(int i=1;i<6;i++){ //show state value table
            for(int j=1;j<6;j++)
                cout<<setprecision(1)<<fixed<<setw(6)<<state_value[i][j]<<"  ";
            cout<<endl<<endl;
        }

        cout<<"-------------------"<<endl;
        write_file("state_value_table.csv",count,state_value);
    }
}

/*********************************************************************************
       Name:  Bellman_eq().
   Function:  calculate all state-value with three different V(s') condition.
 Parameters:  none.
*********************************************************************************/
void Bellman_eq(double **state_value,int height, int width){
    double **next_state_value=(double**) calloc(height,sizeof(double*));           //initial next_state_value table
    for(int i=0;i<height;i++)
        next_state_value[i]=(double*) calloc(width,sizeof(double));

    double **reward=(double**) calloc(height,sizeof(double*));           //initial reward table
    for(int i=0;i<height;i++)
        reward[i]=(double*) calloc(width,sizeof(double));

    for(int i=0;i<height;i++)                                           //reward table setting
        for(int j=0;j<width;j++)
            if(i==0||j==0||i==6||j==6)reward[i][j]=-1;
    /*Reward table :
    -1,-1,-1,-1,-1,-1,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1, 0, 0, 0, 0, 0,-1,
    -1,-1,-1,-1,-1,-1,-1 */

    double up,down,left,right;
    double up_reward,down_reward,left_reward,right_reward;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            ///V(s') three condition：normal,hit wall,A.B special case
            up=state_value[i][j+1];                                     //normal condition
            down=state_value[i+2][j+1];
            left=state_value[i+1][j];
            right=state_value[i+1][j+2];

            up_reward = reward[i][j+1];
            down_reward = reward[i+2][j+1];
            left_reward = reward[i+1][j];
            right_reward = reward[i+1][j+2];

            if(reward[i][j+1]==-1)      up=state_value[i+1][j+1];       //hit wall condition
            if(reward[i+2][j+1]==-1)    down=state_value[i+1][j+1];
            if(reward[i+1][j]==-1)      left=state_value[i+1][j+1];
            if(reward[i+1][j+2]==-1)    right=state_value[i+1][j+1];

            if ((i+1)==1 && (j+1)==2){                                  //A[1][2],B[1][4]special case
                    up=state_value[5][2];                               //any move result in [5][2],[3][4],reward 10,5.
                    down=state_value[5][2];
                    left=state_value[5][2];
                    right=state_value[5][2];
                    up_reward = 10;
                    down_reward = 10;
                    left_reward = 10;
                    right_reward = 10;
            }
            if ((i+1)==1 && (j+1)==4){
                    up=state_value[3][4];
                    down=state_value[3][4];
                    left=state_value[3][4];
                    right=state_value[3][4];
                    up_reward = 5;
                    down_reward = 5;
                    left_reward = 5;
                    right_reward = 5;
            }

            next_state_value[i+1][j+1]=                     //write in the new state value array
                (0.25*1*(up_reward+0.9*up))+
                (0.25*1*(down_reward+0.9*down))+
                (0.25*1*(left_reward+0.9*left))+
                (0.25*1*(right_reward+0.9*right));
        }
    }
    for(int i=0;i<5;i++)                                    //update the old state value array
        for(int j=0;j<5;j++)
            state_value[i+1][j+1]=next_state_value[i+1][j+1];
}
/*********************************************************************************
       Name:  write_file().
   Function:  Write array into CSV file.
 Parameters:  file_name.
*********************************************************************************/
//void write_file(char * file_name,int count,double **state_value){
//    FILE *fpw;
//    fpw = fopen(file_name, "wb");
//    if (!fpw) printf("%s file create fail...\n",file_name);
//    fprintf(fpw, "Iteration times:%d\n",count);
//    for(int i=1;i<6;i++)
//            for(int j=1;j<6;j++){
//                fprintf(fpw, "%.1f,",state_value[i][j]);
//                if(j==5) fputc('\n', fpw);
//            }
//    fclose(fpw);
//}
