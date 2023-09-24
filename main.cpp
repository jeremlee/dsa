//i love intelli j thank you codechum
#include <iostream>
#include<cstdlib>
using namespace std;
//singly linked list practice
struct Node{
	int data;
	Node* next;
};


class LinkedList{
	Node *head;
	Node *list;
public:
	LinkedList(){
		head = NULL;
		list = NULL;
	}
	void add(int data){
		if(head == NULL){
			Node *node = (Node*)malloc(sizeof(Node));
			node->data = data;
			node->next = NULL;
			head = node;
		} else if(list == NULL){
			Node *node = (Node*)malloc(sizeof(Node));
			node->data = data;
			node->next = NULL;
			head->next = node;
			list = node;
		} else{
			Node *node = (Node*)malloc(sizeof(Node));
			node->data = data;
			node->next = NULL;
			list->next = node;
			list = node;
		}
		return;
	}
	
	void removeAt(int position){
		if(head == NULL || position<=0){
			cout << "No" << endl;
			return;
		}
		if(position == 1){
			Node *temp = head;
			head = head->next;
			free(temp);
			return;
		}
		Node *current = head;
		int count = 1;
		while(current != NULL && count < position - 1){
			current = current->next;
			count++;
		}
		Node *temp = current->next;
		current->next = temp->next;
		if(temp->next == NULL){
			current->next = NULL;
			list = current;
		}
		free(temp);
		return;
	}
	
	void addAt(int data, int position){
		if(head == NULL || position<=0){
			cout << "No" << endl;
			return;
		}
		if(position == 1){
			Node *node = (Node*)malloc(sizeof(Node));
			node->data = data;
			node->next = head;
			head = node;
			return;
		}
		Node *current = head;
		int count = 1;
		while(current != NULL && count < position-1){
			current = current->next;
			count++;
		}
		Node *node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->next = current->next;
		if(current->next == NULL){
			node->next = NULL;
			list = node;
		}
		current->next = node;
		return;
	}
	
	void display(){
		Node *p = head;
		while(p != NULL){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		free(p);
		return;
	}
	
	int getSum(){
		int sum = 0;
		Node* p = head;
		while(p != NULL){
			sum+=p->data;
			p = p->next;
		}
		return sum;
	}

};

int main(void){
    LinkedList *list = new LinkedList();
    char op;
    int num,position;
    do{
        cout << "Enter operation (a - add, @ - addAt, r - removeAt, d - display, s - sum, x - exit): ";
        cin >> op;
        switch(op){
            case 'a':
                cin >> num;
                list->add(num);
                break;
            case '@':
                cin >> num;
                cin >> position;
                list->addAt(num,position);
                break;
            case 'r':
                cin >> position;
                list->removeAt(position);
                break;
            case 'd':
                list->display();
                break;
            case 's':
            	cout << "Sum is: " << list->getSum() << endl;
            	break;
        }
    }while(op != 'x');
    return 0;
}
