#include <iostream>
using namespace std;

/**************************************************************************************************
 * Given the head of two singly linked lists num1 and num2 representing two non-negative integers.
 * The task is to return the head of the linked list representing the sum of these two numbers.
 * For example, num1 represented by the linked list : 1 -> 9 -> 0,
 * similarly num2 represented by the linked list: 2 -> 5.
 * Sum of these two numbers is represented by 2 -> 1 -> 5.
 **************************************************************************************************/

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node* addTwoLists(Node* num1, Node* num2) {
    num1 = reverse(num1);
    num2 = reverse(num2);

    Node* sum = NULL;
    int carry = 0;

    while (num1 != NULL || num2 != NULL || carry != 0) {
        int newVal = carry;

        if (num1) {
            newVal += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            newVal += num2->data;
            num2 = num2->next;
        }

        carry = newVal / 10;
        newVal = newVal % 10;

        Node* newNode = new Node(newVal);
        newNode->next = sum;
        sum = newNode;
    }

    while (sum != NULL && sum->data == 0) {
        Node* temp = sum;
        sum = sum->next;
        delete temp;
    }

    if (sum == NULL) {
        return new Node(0);
    }
    return sum;
}
