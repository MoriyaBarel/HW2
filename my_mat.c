#include <stdio.h>
#include "my_mat.h"
#define len 10
#define MAX 99999999
int arr[len][len];

void build_mat(){
    int i,j,weight;
    for (i = 0; i < len; i++){
        for (j = 0; j < len; j++){
            if(i==j){
                arr[i][j]=0;
            }
            else{
                // printf("enter weight for: %d,%d ",i,j);
                scanf("%d", &weight);
                arr[i][j] = weight;
                // arr[j][i] = weight;
            } 
        }  
    }  
}

void path(int i, int j){
    if(shortest_path(i,j) == -1){
        printf("False\n");
    } else {
        printf("True\n");
    } 
}

int shortest_path(int i,int j){
    int temp[len][len];
    for (int x=0 ; x < len; x++){
        for (int y=0 ; y < len; y++){
            temp[x][y] = arr[x][y];
         }
    }
    // converting zeros to max int
    for (int m = 0; m < len; m++){
        for (int n = 0; n < len; n++){ 
            if (temp[m][n] == 0 && m != n){
             temp[m][n] = MAX;
            }
            else if (n == m)
                temp[m][n] = 0;
        } 
    }
    for (int k = 0; k < len; k++) {
        for (int n = 0; n < len; n++) {
            for (int m = 0; m < len; m++) {
                if (temp[n][k] + temp[k][m] < temp[n][m]){
                    temp[n][m] = temp[n][k] + temp[k][m];
                    }   
                }
            }
        }
    if (temp[i][j] != MAX && temp[i][j] != 0) {
        int ans = temp[i][j];
        return ans;
    } else {
        return -1;
    } 
}
