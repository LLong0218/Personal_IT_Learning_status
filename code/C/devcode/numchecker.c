#include <stdio.h>
#include <stdlib.h>

// ����һ��������飬������n��������ÿ������1~v֮�����
int* randomArray(int n, int v) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % v + 1;
    }
    return arr;
}

// ��������
int* copyArray(int* arr, int n) {
    int* copy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }
    return copy;
}

// ������������Ƿ���ͬ
int sameArray(int* arr1, int* arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // ����0��ʾ����ͬ
        }
    }
    return 1; // ����1��ʾ��ͬ
}

// ����������i��jλ�õ���
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// ѡ������
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

// ð������
void bubbleSort(int* arr, int n) {
    for (int end = n - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
            }
        }
    }
}

// ��������
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr, j, j + 1);
        }
    }
}

int main() {
    // ���������󳤶�
    int N = 200;
    // �������ÿ��ֵ����1~V֮��ȸ������
    int V = 1000;
    // ���Դ���
    int testTimes = 50000;
    
    printf("���Կ�ʼ\n");
    for (int i = 0; i < testTimes; i++) {
        // ����õ�һ�����ȣ�������[0~N-1]
        int n = rand() % N;
        // �õ��������
        int* arr = randomArray(n, V);
        int* arr1 = copyArray(arr, n);
        int* arr2 = copyArray(arr, n);
        int* arr3 = copyArray(arr, n);
        selectionSort(arr1, n);
        bubbleSort(arr2, n);
        insertionSort(arr3, n);
        if (!sameArray(arr1, arr2, n) || !sameArray(arr1, arr3, n)) {
            printf("������!\n");
            // ���д���
            // ��ӡ��ʲô���ӣ������
            // ��ӡ�������ܣ������������ʲô��
            // ����Ҫ�����Ӵ��룬ÿ��������ȥdebug��
        }
        free(arr);
        free(arr1);
        free(arr2);
        free(arr3);
    }
    printf("���Խ���\n");

    return 0;
}

