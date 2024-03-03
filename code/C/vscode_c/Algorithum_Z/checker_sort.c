#include <stdio.h>
#include <stdlib.h>

// 生成一个随机数组，长度是n，数组中每个数在1~v之间随机
int* randomArray(int n, int v) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % v + 1;
    }
    return arr;
}

// 复制数组
int* copyArray(int* arr, int n) {
    int* copy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }
    return copy;
}

// 检查两个数组是否相同
int sameArray(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // 返回0表示不相同
        }
    }
    return 1; // 返回1表示相同
}

// 交换数组中i和j位置的数
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 选择排序
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}

// 冒泡排序
void bubbleSort(int* arr, int n) {
    for (int end = n - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }
        }
    }
}


// 插入排序
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr, j, j + 1);
        }
    }
}

int main() {
    // 随机数组最大长度
    int N = 200;
    // 随机数组每个值，在1~V之间等概率随机
    int V = 1000;
    // 测试次数
    int testTimes = 50000;

    printf("测试开始\n");
    for (int i = 0; i < testTimes; i++) {
        // 随机得到一个长度，长度在[0~N-1]
        int n = rand() % N;
        // 得到随机数组
        int* arr = randomArray(n, V);
        int* arr1 = copyArray(arr, n);
        int* arr2 = copyArray(arr, n);
        int* arr3 = copyArray(arr, n);
        selectionSort(arr1, n);
        bubbleSort(arr2, n);
        insertionSort(arr3, n);
        if (!sameArray(arr1, arr2, n) || !sameArray(arr1, arr3, n)) {
            printf("出错了!\n");
            // 当有错了
            // 打印是什么例子，出错的
            // 打印三个功能，各自排序成了什么样
            // 可能要把例子带入，每个方法，去debug！
        }
        free(arr);
        free(arr1);
        free(arr2);
        free(arr3);
    }
    printf("测试结束\n");

    return 0;
}