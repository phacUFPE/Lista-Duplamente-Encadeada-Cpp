#include <iostream>
#include "dclist.cpp"

using namespace std;

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
