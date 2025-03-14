#include <iostream>
using namespace std;

// Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node *cloneLinkedList(Node *head) {
    // Write your code here
    
}