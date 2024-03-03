#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
struct ListNode {
    int val;
    struct ListNode *next;
};

// 定义双链表节点结构体
struct DoubleListNode {
    int value;
    struct DoubleListNode *last;
    struct DoubleListNode *next;
};

// 反转单链表函数
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pre = NULL;
    struct ListNode *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}


// 反转双链表函数
struct DoubleListNode* reverseDoubleList(struct DoubleListNode* head) {
    struct DoubleListNode *pre = NULL;
    struct DoubleListNode *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}

int main(){
    struct ListNode* head1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2=(struct ListNode*)malloc(sizeof(struct ListNode));
    head1->val=1;head1->next = node1;
    node1->val=3;node1->next=node2;
    node2->val=5;node2->next=NULL;

    struct ListNode *reversed=reverseList(head1);

    while(reversed!=NULL){
        printf("%d -> ",reversed->val);
        reversed=reversed->next;
    }
    printf("NULL\n");
    while (head1!=NULL)
    {
        struct ListNode* temp =head1;
        head1=head1->next;
        free(temp);

    }

    return 0;
    
    
    
}