#include <stdio.h>
#include <stdlib.h> // 包含动态内存分配所需的函数原型

// 定义动态数组结构体
typedef struct {
    int* data;  // 指向数组的指针
    size_t size; // 数组的当前大小
    size_t capacity; // 数组的当前容量
} DynamicArray;

// 初始化动态数组
void initializeArray(DynamicArray* arr, size_t initialCapacity) {
    arr->data = (int*)malloc(initialCapacity * sizeof(int)); // 分配初始容量的内存空间
    arr->size = 0; // 初始化数组大小为0
    arr->capacity = initialCapacity; // 初始化数组容量
}

// 在动态数组末尾添加元素
void append(DynamicArray* arr, int element) {
    // 如果数组已满，则扩展数组容量
    if (arr->size == arr->capacity) {
        arr->capacity *= 2; // 扩展容量为原来的两倍
        arr->data = (int*)realloc(arr->data, arr->capacity * sizeof(int)); // 重新分配内存空间
    }
    arr->data[arr->size++] = element; // 在末尾添加元素，并更新数组大小
}

// 释放动态数组的内存空间
void freeArray(DynamicArray* arr) {
    free(arr->data); // 释放内存空间
    arr->size = 0; // 将数组大小设为0
    arr->capacity = 0; // 将数组容量设为0
    arr->data = NULL; // 将数组指针置空
}

int main (){ 
    DynamicArray arr;
    initializeArray(&arr, 5); // 初始化数组，初始容量为5

    // 添加元素到数组中
    for (int i = 0; i < 10; i++) {
        append(&arr, i);
    }

    // 打印数组中的元素
    printf("Array elements: ");
    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    freeArray(&arr); // 释放数组的内存空间

    return 0;
}
