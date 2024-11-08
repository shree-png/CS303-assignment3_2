#include "main.h"
#include <vector>

using namespace std; 
int main() {
	//QUESTION 1: Queue
	//instantiating the queue with integers and pushing 10 values into it
	Queue<int> myqueue;
	for (int i = 1; i < 11; i++)
		myqueue.push(i);

	// displaying all elements using only previous queue methods
	// display() is a method I created to do this task^^; see main.h
	myqueue.display();

	//move_to_rear method: again, see main.h
	myqueue.move_to_rear();
	myqueue.display();
	myqueue.move_to_rear();
	myqueue.display();


	//QUESTION 2: Linear search function
	vector<int> myvector = { 5, 2, 7, 1, 8, 1, 1, 10 };
	int target1 = 8;
	cout << "LAST POSITION OF " << target1 << ": INDEX "
		<< linear_search(myvector, target1, myvector.size() - 1) << endl;

	int target2 = 10;
	cout << "POSITION OF " << target2 << ": INDEX "
		<< linear_search(myvector, target2, myvector.size() - 1) << endl;

	int target3 = 1;
	cout << "LAST POSITION OF " << target3 << ": INDEX "
		<< linear_search(myvector, target3, myvector.size() - 1) << endl;

	int target4 = 3;
	cout << "LAST POSITION OF " << target4 << ": INDEX "
		<< linear_search(myvector, target4, myvector.size() - 1) << endl;

	int target5 = 5;
	cout << "LAST POSITION OF " << target5 << ": INDEX "
		<< linear_search(myvector, target5, myvector.size() - 1) << endl;


	cout << endl << endl;


	//QUESTION 3: Insertion Sort on Linked List
	list<int> mylist1 = {5, 2, 7, 1, 8, 1};
	cout << "BEFORE SORTING:" << endl;
	printList(mylist1);
	cout << endl << endl;
	insertion_sort(mylist1);
	cout << "AFTER SORTING:" << endl;
	printList(mylist1);

	cout << endl << endl;

	list<int> mylist2 = { 6, 5, 4, 3, 2, 1 };
	cout << "BEFORE SORTING:" << endl;
	printList(mylist2);
	cout << endl << endl;
	insertion_sort(mylist2);
	cout << "AFTER SORTING:" << endl;
	printList(mylist2);
	cout << endl << endl;

	list<int> mylist3 = {34, 7, 23, 32, 5, 62, 32, 45, 21, 88, 19, 41, 73, 13, 25, 37, 42, 18};
	cout << "BEFORE SORTING:" << endl;
	printList(mylist3);
	cout << endl << endl;
	insertion_sort(mylist3);
	cout << "AFTER SORTING:" << endl;
	printList(mylist3);
	cout << endl << endl;

	/* TESTING queue function: all functions work properly
	cout << "Empty?: " << myqueue.empty() << endl;
	myqueue.pop();
	cout << "Empty?: " << myqueue.empty() << endl;
	//myqueue.front();
	myqueue.push(1);
	cout << myqueue.front() << endl;
	cout << "Empty?: " << myqueue.empty() << endl;
	cout << "SIZE:" << myqueue.getSize() << endl;
	//cout << front << endl;
	myqueue.push(2);
	cout << myqueue.front() << endl;
	cout << "Empty?: " << myqueue.empty() << endl;
	cout << "SIZE:" << myqueue.getSize() << endl;
	myqueue.push(3);
	cout << "SIZE:" << myqueue.getSize() << endl;
	cout << myqueue.front() << endl;
	myqueue.pop();
	cout << "SIZE:" << myqueue.getSize() << endl;
	cout << myqueue.front() << endl;
	cout << endl;

	Queue<string> myqueue2;
	myqueue2.push("hello world!");
	myqueue2.push("shree");
	myqueue2.push("data structures");
	cout << myqueue2.front() << endl;

	Queue<int> myqueue;
	for (int i = 1; i < 11; i++)
		myqueue.push(i);

	myqueue.display();

	cout << "FRONT: " << myqueue.front() << endl;
	cout << "SIZE: " << myqueue.getSize() << endl;
	myqueue.pop();
	cout << "FRONT: " << myqueue.front() << endl;
	cout << "SIZE: " << myqueue.getSize() << endl;
	cout << endl << endl << endl;

	myqueue.move_to_rear();
	myqueue.display();
	cout << endl << endl << endl;

	myqueue.move_to_rear();
	myqueue.display();*/

	return 0;
}