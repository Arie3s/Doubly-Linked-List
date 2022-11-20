/*
Author : Aries
*/

#include<iostream>
#include<string>

using namespace std;

/*Create a doubly link list and perform the mentioned tasks.
a. Insert a new node at the end of the list.
b. Insert a new node at the beginning of list.
c. Insert a new node at given position.
d. Delete any node.
e. Print the complete doubly link list. */

struct Node {
	int value;
	Node* prev;
	Node* next;
	Node(int d) {
		value = d;
		prev = nullptr;
		next = nullptr;
	}
};

class DLL {
	Node* head;
	int x = 0;
public:
	DLL() {
		head = nullptr;
	}

	void addLast(int d) {
		Node* newNode = new Node(d);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		x++;
	}

	void addFirst(int d) {
		Node* newNode = new Node(d);
		newNode->next = head;
		head->prev = newNode;
		newNode = head;
		x++;
	}
	Node* getTail() {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		return temp;
	}
	void add(int d, int i) {
		if (i == 1) {
			addFirst(d);
			return;
		}
		else if (i == x) {
			addLast(d);
			return;
		}
		int j = 1;
		Node* temp = head;
		while (j < i - 1) {
			temp = temp->next;
			j++;
		}
		Node* newNode = new Node(d);
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->next->prev = newNode;
		x++;
	}

	void del(int pos) {
		Node* temp = head;
		Node* temp1 = nullptr;
		if (pos > x) {
			cout << "index out of range";
			return;
		}
		else if (pos == 1) {
			head = head->next;
			head->prev = nullptr;
			delete temp;
			return;
		}
		else if (pos == x) {
			temp = getTail()->prev;
			temp->next = nullptr;
			temp = getTail();
			delete[] temp;
			temp = nullptr;
			return;
		}
		while (pos > 1) {
			temp1 = temp;
			temp = temp->next;
			pos--;
		}
		temp1->next = temp->next;
		temp1->next->prev = temp1;
		delete temp;
		x--;
	}
	void view() {
		Node* temp = head;
		cout << "size :" << x << endl;
		while (temp->next != nullptr) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	DLL operator + (DLL obj) {
		Node* temp = head;
		DLL NEW;

		while (temp->next != nullptr) {
			NEW.addLast(temp->value);
			temp = temp->next;
		}

		temp = obj.head;
		while (temp != nullptr) {
			NEW.addLast(temp->value);
			temp = temp->next;
		}
		return NEW;
	}

	void operator = (DLL obj) {
		Node* temp = obj.head;
		while (temp != nullptr) {
			addLast(temp->value);
			temp = temp->next;
		}
	}
	Node* getIndex(int pos) {
		Node* temp = head;
		while (temp->next != nullptr && pos != 0) {
			temp = temp->next;
			pos--;
		}
		return temp;
	}
	void sort() {
		int t;
		int n = x;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (getIndex(i)->value > getIndex(j)->value) {
					t = getIndex(i)->value;
					getIndex(i)->value = getIndex(j)->value;
					getIndex(j)->value = t;
				}
			}
		}
	}
};

int main() {
	DLL L, M;


	for (int i = 1; i <= 12; i++) {
		if (i % 2 == 0) {
			L.addLast(i);
			continue;
		}
		M.addLast(i);
	}

	L.view();
	cout << endl;
	M.view();

	DLL N;
	N = L + M;
	cout << endl << "concatanted list :" << endl;
	N.view();
	N.sort();
	N.view();
	return 0;
}

