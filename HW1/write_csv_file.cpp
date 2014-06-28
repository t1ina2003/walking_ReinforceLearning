/*************************************************************
Author: walking
Date: 2013_11_5
Description: Write array into CSV file
Input: array
Output: CSV file
*************************************************************/

///FAILED!!!!!!!!!!!!!!!!!

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "write_csv_file.h"
using namespace std;

void write_file(char * file_name,int count,double **state_value){
    FILE *fpw;
    fpw = fopen(file_name, "wb");
    if (!fpw) printf("%s file create fail...\n",file_name);
    fprintf(fpw, "Iteration times:%d\n",count);
    for(int i=1;i<6;i++)
            for(int j=1;j<6;j++){
                fprintf(fpw, "%.1f,",state_value[i][j]);
                if(j==5) fputc('\n', fpw);
            }
    fclose(fpw);
}
