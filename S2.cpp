#include <iostream>

using namespace std;

// 定义单链表结点结构
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// 插入数据元素e到链表的指定位置i之前
ListNode* insertElement(ListNode* head, int e, int i) {
    ListNode* newNode = new ListNode(e);

    if (i == 1 || !head) {
        newNode->next = head;
        return newNode;
    }

    ListNode* prev = nullptr;
    ListNode* current = head;
    int count = 1;

    while (current && count < i) {
        prev = current;
        current = current->next;
        count++;
    }

    if (prev) {
        prev->next = newNode;
        newNode->next = current;
    }

    return head;
}

// 删除链表中指定数据元素e
ListNode* deleteElement(ListNode* head, int e) {
    if (!head) return nullptr;

    if (head->data == e) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current && current->data != e) {
        prev = current;
        current = current->next;
    }

    if (current) {
        prev->next = current->next;
        delete current;
    }

    return head;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        head = insertElement(head, val, i + 1);
    }

    int e, i;
    cin >> e >> i;

    head = deleteElement(head, e);
    head = insertElement(head, e, i);
    printList(head);

    // 释放链表内存
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
