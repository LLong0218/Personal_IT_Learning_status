#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    
    //1.初始化
    const uint32_t price =5;//饮料价格
    uint32_t balance =0;//投入钱数
    uint32_t coin;//硬币面值

    //提示语
    printf("欢迎使用本机器,只支持一种饮料,5元一瓶\n");
    printf("请投币(只支持1,2,5元)\n");

    //2.循环开始
        //1.钱不够要一直投
        //2.投多了要找零
        //3.面值过大不可投
    while(balance<price){
        printf("钱不够，请继续投币\n");
        scanf("%d",&coin);
        


        if(coin==1 || coin==2 || coin== 5){
            balance=balance+coin;
            printf("您已经投了%d元,再投%d元\n",balance,price-balance);
        }
        else{
            printf("对不起，不接受此面额的硬币 \n");
        }
        
    }
    if (balance>price ){
            printf("找您%d元\n",balance-price);
        }
    printf("谢谢惠顾，请取走饮料。\n");
    


   
    return 0;
}