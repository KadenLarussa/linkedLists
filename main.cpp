#include <iostream>
class node {
public:
int data;
node* next;
};
class linkedList {
public:
node *front;
void init() {
front = nullptr;
}
node *makeNode(int n) {
node *t = new node;
t->data = n;
t->next = nullptr;
return t;
}
node *findTail() {
if (front ==nullptr) return nullptr;
node *current = front;
while (current->next != nullptr) {
current = current->next;
}
}
void buildSimple (int n) {
node *tail = nullptr;
for (int i = 0; i < n; i++) {
if (i == 0) {
init();
front = makeNode(i);
tail = front;
} else {
tail->next = makeNode(i);
tail = tail->next;
}
}
}
void showList() {
node *current;
current = front;
while(current != nullptr) {
std::cout << current->data << " ";
current = current->next;
}
}
node *findSpot(int n) {
node *curr = front;
node *prev = nullptr;
while (curr != nullptr && curr->data < n) {
prev = curr;
curr = curr->next;
}
return prev;
}
void insertSorted(int n) {
node *newNode = makeNode(n);
if (front == nullptr || n < front->data) { // If its the beginning
newNode->next = front;
front = newNode;
} else {
node *prev = findSpot(n);
newNode->next = prev->next;
prev->next = newNode;
}
}
void insertAfter(int afterValue, int newValue) {
node* spot = front;
while (spot != nullptr && spot->data != afterValue) {
spot = spot->next;
}
if (spot != nullptr) {
node* newNode = makeNode(newValue);
newNode->next = spot->next;
spot->next = newNode;
}
}
void deleteNode(int n) {
if (front == nullptr) return;
if (front->data == n) {
node *temp = front;
front = front->next;
delete temp; // Free the memory because my compiler told me to
return;
}
node *prev = nullptr;
node *curr = front;
while (curr != nullptr && curr->data != n) {
prev = curr;
curr = curr->next;
}
if (curr == nullptr) {
std::cout << "Node not found." << std::endl;
return;
}
prev->next = curr->next;
delete curr; // Free the memory because my compiler told me to
}
};
#include <iostream>
int main() {
linkedList myList;
myList.buildSimple(10);
std::cout << "Current List:" << std::endl;
myList.showList();
int choice = 0;
int value, afterValue;
do {
std::cout << "\nMenu:\n";
std::cout << "1. Show List\n";
std::cout << "2. Insert a Node Sorted\n";
std::cout << "3. Insert a Node After a Given Value\n";
std::cout << "4. Delete a Node\n";
std::cout << "5. Exit\n";
std::cout << "Enter your choice: ";
std::cin >> choice;
switch (choice) {
case 1:
myList.showList();
break;
case 2:
std::cout << "Enter the value of the new node: ";
std::cin >> value;
myList.insertSorted(value);
std::cout << "Node inserted.\n";
myList.showList();
break;
case 3:
std::cout << "Enter the value after which to insert the new node: ";
std::cin >> afterValue;
std::cout << "Enter the value of the new node: ";
std::cin >> value;
myList.insertAfter(afterValue, value);
std::cout << "Node inserted.\n";
myList.showList();
break;
case 4:
std::cout << "Enter the value of the node to delete: ";
std::cin >> value;
myList.deleteNode(value);
std::cout << "Node deleted.\n";
myList.showList();
break;
case 5:
std::cout << "Exiting program.\n";
break;
default:
std::cout << "Invalid choice. Please try again.\n";
break;
}
} while (choice != 5);
return 0;
}