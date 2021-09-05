
#include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
    int data;
    Node *next, *prev;
};

class Hashing {

private:
	int n = 10; 
	vector<Node*> ht; 
	vector<Node*> top; 
public:
	Hashing() {
		ht.resize(n, NULL);
		top.resize(n, NULL);
	}
	int hash_key(int d) {
		return d % n;
	}

	void insert() {
		int d;
		cout << "Enter a value: ";
		cin >> d;

		int i = hash_key(d);
		
		Node* t = new Node();
		t->data = d;
		if(ht[i] == NULL) {
			ht[i] = t;
			top[i] = t;

			cout << top[i]->data << endl;
		} else {
			t -> prev = top[i];
			top[i] -> next = t;
			top[i] = t;
		}
	}

	void search() {
		int d;
		cout << "Enter a value: ";
		cin >> d;

		int i = hash_key(d);

		if(ht[i] != NULL) {
			Node *cur = ht[i];
			while(cur != NULL) {
				if(cur->data == d) {
					cout << "\n" << d << " is present in hash table" << "\n" << endl;
					return;
				}
				cur = cur -> next;
			}
		}

		cout << "\n" << d << " is not present in hash table" << "\n" << endl;
	}

	void del() {
		int d;
		cout << "Enter a value: ";
		cin >> d;

		int i = hash_key(d);

		if(ht[i] != NULL) {
			Node *cur = ht[i];
			while(cur != NULL && cur -> next != NULL) {
				if(cur-> next ->data == d) {
					cur -> next = cur -> next -> next;
					cout << "\n" << d << " is deleted from hash table" << "\n" << endl;
					return;
				}

				cur = cur -> next;
			}
		}

		cout << "\n" << d << " is not present in hash table" << "\n" << endl;
	}


	void print() {
		cout << "\n      ***** Hash table *****\n";
		Node* pr;
		for(int i = 0; i < n; i++) {
			cout << i << " : ";
			pr = ht[i];

			while(pr != NULL) {
				cout << pr -> data << " -> ";
				pr = pr -> next;
			}

			cout << "null" << endl;
		}

		cout << "\n\n";
	}
	
};

int main() {

	cout << "********** Implementation of Hashing **********\n";

	int ch;
	Hashing h;

	while(true) {
		cout << "1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> ch;

		switch(ch) {
			case 1: h.insert(); break;
			case 2: h.del(); break;
			case 3: h.print(); break;
			case 4: h.search(); break;
			default: return 0;
		}
	} 
}
