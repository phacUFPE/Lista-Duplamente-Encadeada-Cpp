#include <iostream>
#include <cstddef>

using namespace std;

struct Node{
	Node *prevPointer;
	Node *nextPointer;
	string item;
	
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
