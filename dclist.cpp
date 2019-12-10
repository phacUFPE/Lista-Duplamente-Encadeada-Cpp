#include <iostream>
#include "node.cpp"

using namespace std;

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
