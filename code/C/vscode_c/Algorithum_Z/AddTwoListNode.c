#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 生成一个指定长度的随机链表
struct ListNode* randomListNode(int length) {
    struct ListNode *head = NULL, *cur = NULL;
    for (int i = 0; i < length; ++i) {
        int val = rand() % 10; // 生成一个 0 到 9 的随机数
        struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            cur = newNode;
        } else {
            cur->next = newNode;
            cur = cur->next;
        }
    }
    return head;
}

// 定义函数 addTwoNumbers
struct ListNode* addTwoNumbers(struct ListNode* h1, struct ListNode* h2) {
    struct ListNode *ans = NULL, *cur = NULL;
    int carry = 0;
    int sum, val;

    for (; h1 != NULL || h2 != NULL; h1 = (h1 != NULL) ? h1->next : NULL, h2 = (h2 != NULL) ? h2->next : NULL) {
        sum = (h1 == NULL ? 0 : h1->val)
                + (h2 == NULL ? 0 : h2->val)
                + carry;

        val = sum % 10;
        carry = sum / 10;
        if (ans == NULL) {
            ans = (struct ListNode*)malloc(sizeof(struct ListNode));
            ans->val = val;
            ans->next = NULL;
            cur = ans;
        } else {
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur->next->val = val;
            cur->next->next = NULL;
            cur = cur->next;
        }
    }

    while (carry == 1) {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next->val = 1;
        cur->next->next = NULL;
        carry = 0;
    }

    return ans;
}

// 示例测试函数
int main() {
    // 创建示例链表
    struct ListNode *h1 = randomListNode(3); // 生成长度为 3 的随机链表
    struct ListNode *h2 = randomListNode(3); // 生成长度为 3 的随机链表

    // 调用函数计算结果
    struct ListNode *result = addTwoNumbers(h1, h2);

    // 输出结果
    struct ListNode *temp = result;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    // 释放内存
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }
    while (h1 != NULL) {
        temp = h1;
        h1 = h1->next;
        free(temp);
    }
    while (h2 != NULL) {
        temp = h2;
        h2 = h2->next;
        free(temp);
    }

    return 0;
}
