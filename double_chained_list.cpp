#include <iostream>
#include <cstddef>

using namespace std;

struct Node{
	Node *prevPointer;
	string item;
	Node *nextPointer;
	
	Node(Node *prev, string strItem, Node *next){
		prevPointer = prev;
		item = strItem;
		nextPointer = next;
	}
	
	bool operator==(const Node& other){
		return prevPointer == other.prevPointer;
	}
	
	string getItem(){
		return item;
	}
};

struct DChainedList{
	Node *last = new Node(NULL, "", NULL);
	Node *first = last;
	int length = 0;
		
	bool empty(){
		return first == last;
	}
	
	void insert(string insItem){
		Node *nextNode = new Node(last, insItem, new Node(NULL, "", NULL));
		(*last).nextPointer = nextNode;
		last = (*last).nextPointer;
		length++;
	}
	
	string remove(string rItem){
		if (empty()){ return NULL;}
		Node *aux = (*first).nextPointer;
		while ((aux != NULL) && (*aux).item != rItem){
			aux = (*aux).nextPointer;
		}
		if (aux == NULL) { return NULL; }
		
		string rtnItem = (*aux).item;
		
		if (aux == last){
			last = (*aux).prevPointer;
		} else {
			(*(*aux).nextPointer).prevPointer = (*aux).prevPointer;
		}
		(*(*aux).prevPointer).nextPointer = (*aux).nextPointer;
		(*aux).nextPointer = NULL;
		(*aux).prevPointer = NULL;
		
		return rtnItem;
	}
	
};

int main(){
	DChainedList dcList = DChainedList();

	dcList.insert("Pedro");
	dcList.insert("Mario");
	dcList.insert("Patricia");
	dcList.insert("Maria");
	
	dcList.remove("Maria");
	
	Node first = *(dcList.first);
	Node second = *(first.nextPointer);
	Node last = *(dcList.last);
	Node penult = *(last.prevPointer);
	
	cout << "(ADDRESS) First..: " << &first << endl;
	cout << "(ITEM) First.....: " << first.item << endl;
	
	cout << endl;
	
	cout << "(ADDRESS) Second.: " << &second << endl;
	cout << "(ITEM) Second....: " << second.item << endl;
	
	cout << endl;
	
	cout << "(ADDRESS) Penult.: " << &penult << endl;
	cout << "(ITEM) Penult....: " << penult.item << endl;
	
	cout << endl;
	
	cout << "(ADDRESS) Last...: " << &last << endl;
	cout << "(ITEM) Last......: " << last.item << endl;
	
	cout << endl;
	
	cout << "Length...........: " << dcList.length << endl;
}
