#include<iostream>
#include<cstdlib>
using namespace std;

class ArrayList{
	int *arr;
	int size;
	int capacity;
public:
	ArrayList(){
		size = 0;
		capacity = 5;
		arr = (int*)malloc(5*sizeof(int));
	}
	
	void add(int num){
		if(size > capacity-1){
			cout << "Resizing..." << endl;
			capacity*=1.5;
			arr = (int*)realloc(arr,capacity*sizeof(int));
		} 
		arr[size] = num;
		size++;
		return;
	}
	
	void addAt(int num,int pos){
		if(pos < 0 || pos > size){
			cout << "Invalid position" << endl;
			return;
		}
		if(size > capacity-1){
			cout << "Resizing..." << endl;
			capacity*=1.5;
			arr = (int*)realloc(arr,capacity*sizeof(int));
		} 
		for(int i = size-1;i >=pos;i--){
			arr[i+1] = arr[i];
		}
		arr[pos] = num;
		size++;
		return;
	}
	
	void removeLast(){
		if(size == 0){
			cout << "List is empty." << endl;
			return;
		}
		arr[size-1] = 0;
		size--;
		if(size <= capacity * (2/3.0)){
			if(capacity > 5){
				cout << "Resizing..." << endl;
			}
			capacity*=0.75;
			if(capacity < 5){
				capacity = 5;
			}
			arr = (int*)realloc(arr,capacity*sizeof(int));
		}
		return;
	}
	
	void removeAt(int pos){
		if(pos < 0 || pos > size){
			cout << "Invalid position" << endl;
			return;
		}
		for(int i = pos; i < size; i++){
			arr[i] = arr[i+1];
		}
		size--;
		if(size <= capacity * (2/3.0)){
			if(capacity > 5){
				cout << "Resizing..." << endl;
			}
			capacity*=0.75;
			if(capacity < 5){
				capacity = 5;
			}
			arr = (int*)realloc(arr,capacity*sizeof(int));
		}
		return;
	}
	
	int removeAll(int num){
		int instances = 0;
		if(size == 0){
			cout << "Nothing to remove" << endl;
			return -1;
		}
		for(int i = size-1;i>=0;i--){
			if(arr[i] == num){
				instances++;
				for(int j = i;j<size;j++){
					arr[j] = arr[j+1];
				}
				size--;
			}
		}
		if(size <= capacity * (2/3.0)){
			if(capacity > 5){
				cout << "Resizing..." << endl;
			}
			capacity*=0.75;
			if(capacity < 5){
				capacity = 5;
			}
			arr = (int*)realloc(arr,capacity*sizeof(int));
		}
		return instances;
	}
	
	void print(){
		cout << "Capacity: " << capacity << " Size: " << size << endl;
		for(int i=0;i<size;i++){
			cout << *(arr+i) << " ";
		}
		cout << endl;
		return;
	}
};

int main(void){
	ArrayList *list = new ArrayList();
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
			case 'r':
				list->removeLast();
				break;
			case '@':
				cin >> num;
				cin >> pos;
				list->addAt(num,pos);
				break;
			case 'R':
				cin >> pos;
				list->removeAt(pos);
				break;
			case 'A':
				cin >> num;
				cout << list->removeAll(num) << " instances of " << num << " removed" << endl;
				break;
			case 'p':
				list->print();
				break;
		}
	}while(op!= 'x');
	
	return 0;
}