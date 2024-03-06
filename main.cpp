#include <iostream>

class node {
public:
    int data;
    node* next;
};

class linkMe {
public:
    long front;

    void init() {
        front = NULL;
    }

    node makeNode(int n) {
        node *t;
        t = new node;
        t->next = NULL;
        t->data = n;
        return *t;

    }

    node findTail() {
        node current = front;
        while (current.next != NULL) {

        }

    }
};

int main()
{

    return 0;
}
