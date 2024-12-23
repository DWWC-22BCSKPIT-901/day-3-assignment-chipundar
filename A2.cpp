// Question => Given the head of a singly linked list, reverse the list, and return the reversed list

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;  
    ListNode* curr = head;     
    ListNode* next = nullptr;  

    while (curr != nullptr) {
        next = curr->next;      
        curr->next = prev;      
        prev = curr;           
        curr = next;            
    }
    
    return prev;  
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* createNode(int value) {
    return new ListNode(value);
}

int main() {
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    cout << "Original Linked List: ";
    printList(head);

    ListNode* reversedHead = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(reversedHead);

    return 0;
}
