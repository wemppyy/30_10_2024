#include <iostream>

using namespace std;

// doubly linked list
struct Node {
	int data;
	Node* next;
	Node* prev;

public:
	Node(int data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}

	Node(int data, Node* next, Node* prev) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}

	void push_front(Node* head, int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void push_back(Node* head, int data) {
		Node* newNode = new Node(data);
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}

	void print(Node* head) {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int len(Node* head) {
		Node* temp = head;
		int count = 0;
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}
		return count;
	}

	void print_reverse(Node* head) {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << endl;
	}

	~Node() {
		delete next;
		delete prev;
	}
};

int print_menu() {
	int choice;
	cout << "Menu" << endl;
	cout << "1. Push front" << endl;
	cout << "2. Push back" << endl;
	cout << "3. Print" << endl;
	cout << "4. Print reverse" << endl;
	cout << "5. Length" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int call_function(Node* head, int choice) {
	int data;
	switch (choice) {
	case 1:
		cout << "Enter data: ";
		cin >> data;
		head->push_front(head, data);
		break;
	case 2:
		cout << "Enter data: ";
		cin >> data;
		head->push_back(head, data);
		break;
	case 3:
		head->print(head);
		break;
	case 4:
		head->print_reverse(head);
		break;
	case 5:
		cout << "Length: " << head->len(head) << endl;
		break;
	case 6:
		return 0;
	default:
		cout << "Invalid choice" << endl;
	}
	return 1;
}

int main() {
	Node* head = new Node(10);
	while (true) {
		int choice = print_menu();
		system("cls");
		if (call_function(head, choice) == 0) {
			break;
		}
	}

	return 0;
}