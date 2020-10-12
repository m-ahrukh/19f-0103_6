#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
class LinkedList {
public:
	Node* head, * tail;
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void insert(int x) {
		Node* ptr = new Node;
		ptr->data = x; ptr->next = NULL;
		if (head == NULL) { 
			head = ptr; tail = ptr;
		}
		else {
			tail->next = ptr;
			tail = ptr;
		}
	}
	Node* reverse(Node* node) {
		if (node == NULL) {
			return NULL;
		}
		if (node->next == NULL) {
			head = node;
			return node;
		}
		Node* node1 = reverse(node->next);
		node1->next = node;
		node->next = NULL;
		return node;
	}
	void display() {
		Node* temp;
		temp = head;
		cout << "List is " << endl;
		while (temp != NULL) { 
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	LinkedList *l1 = new LinkedList;
	int num; char ch;
	do {
		cout << "Enter Number "; cin >> num;
		l1->insert(num);
		cout << "Enter Y if you want to insert value "; cin >> ch;
	} while (ch == 'y' || ch == 'y');
	l1->display();
	l1->reverse(l1->head);
	cout << "After Reversing List is " << endl;
	l1->display();
	cout << endl;
	system("pause");
	return 0;
}