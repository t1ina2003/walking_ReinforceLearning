#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define row 5
#define col 6

int main(){
char yes_no;
double up,down,right,left,com_a,com_b;//com_a,com_b為比較數字
double A[row][col]=
    {-1,-1,-1,-1,-1,-1,
   -1, 0, 0, 0, 0,-1,
   -1, 0,-1, 0, 0,-1,
   -1, 0, 0, 0, 0,-1,
   -1,-1,-1,-1,-1,-1};
double Temp[row][col]=
    {-1,-1,-1,-1,-1,-1,
   -1, 0, 0, 0, 0,-1,
   -1, 0,-1, 0, 0,-1,
   -1, 0, 0, 0, 0,-1,
   -1,-1,-1,-1,-1,-1};
//初始化

A[1][4]=100;
A[2][4]=(-100);
//印出基本pattern
for(int i=0;i<5;i++){
    for(int j=0;j<6;j++) {
        if(A[i][j]==0 ) cout<<"   "<<A[i][j];
        else if(A[i][j]<=9 && A[i][j]>0) cout<<"   "<<A[i][j];
        else if(A[i][j]>9  && A[i][j]<=99) cout<<"  "<<A[i][j];
        else if(A[i][j]>99) cout<<" "<<A[i][j];
        else if(A[i][j]<0  && A[i][j]>=-9) cout<<"  "<<A[i][j];
        else if(A[i][j]<-9 && A[i][j]>=-99)cout<<" "<<A[i][j];
        else if(A[i][j]<-99) cout<<A[i][j];
    }
    cout<<endl;
}
start:
for(int i=1;i<4;i++){
    for(int j=1;j<5;j++){
        if(i == 2 && j==2) continue;
        up=0;down=0;left=0;right=0;
        if(A[i-1][j]==-1){//Up wall
            up += 0.8*A[i][j];
            left += 0.1*A[i][j];
            right += 0.1*A[i][j];
        }else{
            up += 0.8*A[i-1][j];
            left += 0.1*A[i-1][j];
            right += 0.1*A[i-1][j];
        }
        if(A[i+1][j]==-1){//Down wall8
            down += 0.8*A[i][j];
            left += 0.1*A[i][j];
            right += 0.1*A[i][j];
        }else{
            down += 0.8*A[i+1][j];
            left += 0.1*A[i+1][j];
            right += 0.1*A[i+1][j];
        }
        if(A[i][j-1]==-1){//Left wall
            up += 0.1*A[i][j];
            down += 0.1*A[i][j];
            left += 0.8*A[i][j];
        }else{
            up += 0.1*A[i][j-1];
            down += 0.1*A[i][j-1];
            left += 0.8*A[i][j-1];
        }
        if(A[i][j+1]==-1){//Right wall
            up += 0.1*A[i][j];
            down += 0.1*A[i][j];
            right += 0.8*A[i][j];
        }else{
            up += 0.1*A[i][j+1];
            down += 0.1*A[i][j+1];
            right += 0.8*A[i][j+1];
        }
        if(up>down)com_a=up;
        else com_a=down;
        if(left>right)com_b=left;
        else com_b=right;
        if(com_a>com_b)Temp[i][j]=(int)com_a;
        else Temp[i][j]=(int)com_b;
        Temp[1][4]=100;
        Temp[2][4]=(-100);
        //Temp[2][2]=-1;
    }
}
for(int i=0;i<5;i++)
    for(int j=0;j<6;j++)
        A[i][j]=Temp[i][j];


cout<<endl<<endl;

for(int i=0;i<5;i++){
    for(int j=0;j<6;j++) {
        if(A[i][j]==0 ) cout<<"   "<<A[i][j];
        else if(A[i][j]<=9 && A[i][j]>0) cout<<"   "<<A[i][j];
        else if(A[i][j]>9  && A[i][j]<=99) cout<<"  "<<A[i][j];
        else if(A[i][j]>99) cout<<" "<<A[i][j];
        else if(A[i][j]<0  && A[i][j]>=-9) cout<<"  "<<A[i][j];
        else if(A[i][j]<-9 && A[i][j]>=-99)cout<<" "<<A[i][j];
        else if(A[i][j]<-99) cout<<A[i][j];
    }
    cout<<endl;
}
cout<<"do again?";
cin>>yes_no;
if(yes_no=='y'){
        system("cls");
        goto start;}
}



