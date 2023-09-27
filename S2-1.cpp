#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

Node* insert(Node* head, int data, int position) {
    Node* newNode = new Node(data);

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int count = 1;

    while (count < position - 1 && current != nullptr) {
        current = current->next;
        count++;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

Node* remove(Node* head, int data) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    Node* head = nullptr;

    for (int i = n - 1; i >= 0; i--) {
        head = insert(head, elements[i], 1);
    }

    int e, i;
    cin >> e >> i;
    bool elementExists = false;

    Node* current = head;
    while (current != nullptr) {
        if (current->data == e) {
            elementExists = true;
            break;
        }
        current = current->next;
    }

    if (elementExists) {
        head = remove(head, e);
    } else if (i >= 1 && i <= n + 1) {
        head = insert(head, e, i);
    }

    printList(head);

    return 0;
}
