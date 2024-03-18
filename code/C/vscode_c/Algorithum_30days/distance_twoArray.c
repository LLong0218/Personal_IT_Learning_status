//给定两个含有n个整数的数组A，B，请设计一个在时间上尽可能高效的算法
//找出集合（A，B两个数组中任意两个元素的差值绝对值）的最大最小m，M
//要求：给出设计思想，语言：C，C++，给出时间空间复杂度

//方法一：暴力解
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int Solution(int A[], int B[],int n ,int m, int M){
    int temp_m,temp_M;
    temp_m = temp_M = abs(A[0]-B[0]);
    for(int i=0;i<n;i++){
        for(int j=0; j<n ;j++){
            int median = abs(A[i]- B[j]);
            if(median<temp_m){
                temp_m = median;
            }
            if(median>temp_M){
                temp_M = median;
            }
        }
    }
    m=temp_m;
    M=temp_M;
    return M;
    
    
}

int main(){
    int m,M;
    int A[3]={1,2,4};
    int B[3]={5,2,3};
    printf("%d",Solution(A,B,3,m,M));
    return 0;
    
}