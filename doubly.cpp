#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* previous;
};
class LinkedList{
	Node* head;
	Node* tail;
	short size;
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void add(int num){
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = num;
		node->next = NULL;
		if(!head){
			node->previous = NULL;
			head = node;
			tail = node;
		} else{
			node->previous = tail;
			tail->next = node;
			tail = node;
		}
		size++;
		return;
	}
	void addHead(int num){
		Node* node = (Node*)malloc(sizeof(Node));
		if(!head){
			add(num);
		} else{
			node->data = num;
			node->next = head;
			head->previous = node;
			node->previous = NULL;
			head = node;
		}
		size++;
		return;
	}
	void addAt(int num, int pos){
		if(pos == 1){
			add(num);
			return;
		}
		if(pos <= 0){
			cout << "Invalid position" << endl;
			return;
		}
		if(pos == size+1){
			add(num);	
			return;
		} 
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = num;
		Node* p = head;
		short count = 1;
		while(count < pos){
			p = p->next;
			count++;
		}
		node->previous = p->previous;
		p->previous->next = node;
		p->previous = node;
		node->next = p;
		size++;
		return;
	}
	void remove(){
		if(!head){
			cout << "List is empty" << endl;
			return;
		}
		if(!tail->previous){
			Node* temp = tail;
			tail = NULL;
			head = NULL;
			free(temp);
			size--;
			return;
		}
		Node* temp = tail;
		tail = temp->previous;
		tail->next = NULL;
		free(temp);
		size--;
		return;
	}
	void removeHead(){
		if(!head){
			cout << "List is empty" << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		head->previous = NULL;
		free(temp);
		size--;
		return;
	}
	void removeAt(int pos){
		if(!head){
			cout << "List is empty" << endl;
			return;
		}
		if(pos == 1){
			removeHead();
			return;
		}
		if(pos == size){
			remove();
			return;
		}
		short count = 1;
		Node* p = head;
		while(count < pos){
			p = p->next;
			count++;
		}
		Node* temp = p;
		temp->next->previous = temp->previous;
		temp->previous->next = temp->next;
		free(temp);
		size--;
		return;
	}
	int removeAll(int num){
		int instances = 0;
		Node* p = head;
		while(p){
			if(p->data == num){
				if(p == head){
					removeHead();
					p = head;
					instances++;
				} else if(p == tail){
					remove();
					p = NULL;
					instances++;
					break;
				} else{
					Node* temp = p;
					temp->previous->next = temp->next;
					temp->next->previous = temp->previous;
					p = p->next;
					free(temp);
					size--;
					instances++;
				}
			} else{
				p = p->next;
			}
		}
		return instances;
	}
	void printForward(){
		Node* p = head;
		cout << "Printing forward..." << endl;
		cout << "Size: " << size << endl;
		while(p){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		return;
	}
	
	void printBackward(){
		Node* p = tail;
		cout << "Size: " << size << endl;
		cout << "Printing backward..." << endl;
		while(p){
			cout << p->data << " ";
			p = p->previous;
		}
		cout << endl;
		return;
	}
	
};
int main(void){
	LinkedList *list = new LinkedList();
	int num, pos;
	char op;
	do{
		cout << "Enter operation: ";
		cin >> op;
		switch(op){
			case 'a':
				cin >> num;
				list->add(num);
				break;
			case 'h':
				cin >> num;
				list->addHead(num);
				break;
			case 'y':
				list->printForward();
				break;
			case 'z':
				list->printBackward();
				break;
			case 'r':
				list->remove();
				break;		
			case '@':
				cin >> num;
				cin >> pos;
				list->addAt(num,pos);
				break;
			case 'o':
				list->removeHead();
				break;
			case '#':
				cin >> pos;
				list->removeAt(pos);
				break;
			case 'q':
				cin >> num;
				cout << list->removeAll(num) << " instances of " << num << " removed." << endl;
				break;
		}
	}while(op != 'x');
	return 0;
}
