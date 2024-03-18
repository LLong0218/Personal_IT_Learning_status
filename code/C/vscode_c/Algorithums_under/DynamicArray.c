#include<stdio.h>
#include<stdlib.h>
typedef struct DynamicArray
{
    /* data */
    int* data;//指向数组的指针
    size_t size;//数组大小
    size_t capacity;//数组容量（扩容，缩容）
}DynamicArray;

//初始化数组
void initializeArray(DynamicArray * arr,size_t initializeCapacity){
    arr->data=(int*)malloc(initializeCapacity*sizeof(int));//分配内存空间
    arr->size=0;//数组初始大小
    arr->capacity=initializeCapacity;//数组初始容量
}

//增加元素
void append(DynamicArray*arr,int element){
    //如果目前大小已经等于容量，增加导致超限，则扩容
    if(arr->size == arr->capacity){
        arr->capacity *= 2;//扩两倍
        arr->data = (int*)realloc(arr->data,arr->capacity*sizeof(int));//重新分配内存
    }
    //在末尾添加新元素
    arr->data[arr->size++]= element;
}

//释放动态数组
void freeArray(DynamicArray* arr){
    //释放数组内存
    free(arr->data);
    //归零大小和容量
    arr->size=0;
    arr->capacity=0;
    //数组指针指向null（置空）
    arr->data = NULL;
}

int main(){
    //声明动态数组
    DynamicArray arr;
    initializeArray(&arr,10);//初始化数组及其大小
    //添加元素
    for(int i=0;i<10;i++){
        append(&arr,i);
    }
    printf("Array element: ");
    for(size_t i=0;i<arr.size;i++){
        printf("%d ",arr.data[i]);
    }
    printf("\n");
    freeArray(&arr);
}
