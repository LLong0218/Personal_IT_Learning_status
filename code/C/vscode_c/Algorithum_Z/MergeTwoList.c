#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 将两个升序链表合并为一个新的 升序 链表并返回
struct ListNode* mergeTwoLists(struct ListNode* head1, struct ListNode* head2) {
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }
    struct ListNode *head = head1->val <= head2->val ? head1 : head2;
    struct ListNode *cur1 = head->next;
    struct ListNode *cur2 = head == head1 ? head2 : head1;
    struct ListNode *pre = head;
    while (cur1 != NULL && cur2 != NULL) {
        if (cur1->val <= cur2->val) {
            pre->next = cur1;
            cur1 = cur1->next;
        } else {
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }
    pre->next = cur1 != NULL ? cur1 : cur2;
    return head;
}

// 测试函数
int main() {
    // 创建两个升序链表
    struct ListNode *head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node12 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head1->val = 1; head1->next = node11;
    node11->val = 3; node11->next = node12;
    node12->val = 5; node12->next = NULL;

    struct ListNode *head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node21 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *node22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head2->val = 2; head2->next = node21;
    node21->val = 4; node21->next = node22;
    node22->val = 6; node22->next = NULL;

    // 调用合并函数
    struct ListNode *merged = mergeTwoLists(head1, head2);

    // 打印合并后的链表
    while (merged != NULL) {
        printf("%d -> ", merged->val);
        merged = merged->next;
    }
    printf("NULL\n");

    // 释放内存
    while (head1 != NULL) {
        struct ListNode *temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        struct ListNode *temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}
