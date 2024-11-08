#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <list>

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class Queue { /*did not define member functions in a.cpp file since
	that does not work for template classes/has requirements not
	available to use in visual studio*/

	//used singly linked list
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Queue() : head(nullptr), tail(nullptr), size(0) {}

	void push(T thedata) {
		Node<T>* newNode = new Node<T>;
		newNode->data = thedata;
		newNode->next = nullptr;
		if (head == nullptr)
			head = newNode;
		else
			tail->next = newNode;
		tail = newNode;
		size += 1;
	}

	void pop() {
		if (head == nullptr) {
			cout << "COULD NOT POP: QUEUE IS EMPTY" << endl;
		}
		else {
			Node<T>* delNode = head;
			head = head->next;
			delete delNode;
			size -= 1;
			if (head == nullptr) //reset tail if queue is now empty
				tail = nullptr;
		}
	}

	T front() {
		return head->data;
	}
	
	int getSize() {
		return size;
	}

	bool empty() {
		return head == nullptr;
	}

	void display() { //DISPLAYING ALL ELEMENTS: PART b of QUESTION 1
		cout << "CURRENT QUEUE:" << endl << endl;
		for (int i = 0; i < getSize(); i++) {
			cout << front() << endl;
			cout << endl;
			push(front());
			pop();
		}
		cout << endl;
	}

	void move_to_rear() { //MOVE FRONT ELEMENT TO REAR: PART c of QUESTION 1
		push(front());
		pop();
		cout << "MOVED FRONT ELEMENT TO REAR" << endl << endl << endl;
	}

	Node<T>* getHead(){
		return head;
	}

	void setHead(Node<T>* newHead) {
		head = newHead;
	}
};

template <typename T1>
int linear_search(vector<T1>& items, T1& target, size_t pos_last) {

	if (target == items.at(pos_last))
		return pos_last;

	if (pos_last == 0) //could not find target
		return -1;

	else
		return linear_search(items, target, pos_last - 1);
};

void insertion_sort(list<int>& thelist); //definion found in insertion-sort_list.cpp

void printList(const list<int>& thelist); //definion found in insertion-sort_list.cpp


//try 5 of insertion sort: works perfectly but not on large lists :(
/*
void insertion_sort(list<int>& thelist) {
	if (thelist.size() <= 1) {
		return; // No need to sort if the list has 0 or 1 element
	}

	// Start from the second element
	list<int>::iterator j_itr = thelist.begin();
	++j_itr; // Move to the second element

	for (int j = 1; j < thelist.size(); ++j) {
		int key = *j_itr; // Store the value of the current element
		bool insertionNeeded = false;

		// Set up i_itr to be one position before j_itr
		list<int>::iterator i_itr = j_itr;
		--i_itr; // Move i_itr to the element before j_itr

		// Inner loop to shift elements greater than key to the right
		list<int>::iterator next_itr = j_itr; // Initialize next_itr to j_itr
		for (int i = j - 1; i >= 0; --i) {
			cout << i << endl;
			if (*i_itr > key) {
				*next_itr = *i_itr; // Shift the value to the right
				insertionNeeded = true;

				if (i_itr == thelist.begin()) {

					break; // Stop if we've reached the beginning
				}

				next_itr = i_itr;  // Move next_itr one step left
				--i_itr;           // Move i_itr one step left
			}
			else {
				break; // Key is in the right spot
			}
		}

		//CODE from Professor
		changed condition from "if (i_itr == thelist.begin() && *i_itr > key)"
		to if (i_itr == thelist.begin() && insertionNeeded), since insertionNeeded
		is already a flag for *i_itr > key
		if (i_itr == thelist.begin() && insertionNeeded) {
			*next_itr = *i_itr; // Shift the first element
			*i_itr = key;       // Insert `key` at the beginning
		}
		else {
			*next_itr = key; // Place `key` in its correct position
		}

		// Place key in its correct position after shifting
		//if (insertionNeeded) {
			//*next_itr = key;    // Insert `key` after the last shifted element
		//}
		//else if (*i_itr > key) {
			//*i_itr = key;       // Handle insertion at the beginning
		//}

		++j_itr; // Move to the next element in the list
	}
}
*/

/*
//try 4
void insertion_sort(list<int>& thelist) {
	int i, j, key;
	bool insertionNeeded = false;

	list<int>::iterator j_itr = thelist.begin();
	++j_itr;
	//cout << *j_itr << endl;
	list<int>::iterator i_itr = prev(j_itr);
	//cout << *i_itr;

	//list<int>::iterator i_itr = thelist.begin();

	for (j = 1; j < thelist.size(); j++) {
		cout << j << endl;
		//cout << endl;
		key = *j_itr;
		//cout << *j_itr << endl;
		//cout << key << " " << endl;
		//cout << *j_itr << endl;
		insertionNeeded = false;

		use a temp variable "next_itr" to store the next values of i without actually changing i.
			this prevents incrimenting i when it's not needed
		for (i = j - 1; i >= 0; i--) {
			cout << i << endl;
			cout << endl;
			if (key < *i_itr) {
				*next(i_itr) = *i_itr;
				insertionNeeded = true;
			}
			else
				break;
			--i;
			//--i_itr; //only incremented under certain condition
			//cout << *i_itr << endl;
		}
		if (insertionNeeded) {
			//list<int>::iterator next_itr = i_itr;
			*next(i_itr) = key;
		}
		++j_itr; //advance the j iterator to the next list element
	}

}

*/

/*
//try 3
void insertion_sort(list<int>& thelist) {
	int i, j, key;
	bool insertionNeeded = false;

	list<int>::iterator j_itr = thelist.begin();
	++j_itr;

	//list<int>::iterator i_itr = thelist.begin();

	for (j = 1; j < thelist.size(); j++) {
		key = *j_itr;
		insertionNeeded = false;

		//use a temp variable "next_itr" to store the next values of i without actually changing i.
		//this prevents incrimenting i when it's not needed
		list<int>::iterator i_itr = --j_itr;
		for (i = j - 1; i >= 0; i--) {
			if (key < *i_itr) {
				list<int>::iterator next_itr = i_itr; 
				++next_itr;
				*next_itr = *i_itr;
				insertionNeeded = true;
				if (i_itr == thelist.begin())
					break; //stop when reached the end
				--i_itr;
			}
			else
				break;
			//++i_itr; only incremented under certain condition
		}
		if (insertionNeeded) {
			list<int>::iterator next_itr = i_itr;
			*++next_itr = key;
		}
		++j_itr; //advance the j iterator to the next list element
	}

}

//try 2
template <typename T>
void insertion_sort(Queue<T>& myqueue) { //passing my defined queue class
	int i, j;
	Node<T>* key;
	bool insertionNeeded = false;

	Node<T>* current = myqueue.getHead();
	while (current != nullptr) { //traversing the list
		//cout << current->data << endl;
		key = current;
		insertionNeeded = false;
		//current = current->next; //PUT AT END

		Node<T>* beginning = myqueue.getHead();
		while (beginning != nullptr) {
			if (beginning->next == current)
				break;
			beginning = beginning->next; //beginning = where to start the next inner loop ("j - 1" equivilent)
		}

		while (beginning != nullptr) {
			if (key->data < beginning->data && beginning->next != nullptr) {
				beginning->next = beginning;
				insertionNeeded = true;
			}
			else
				break;

			beginning = beginning->next;
		}
		
		if (insertionNeeded && beginning->next != nullptr)
			beginning->next = key;


		current = current->next;
	}
} 



//try 1
template <typename T>
void insertion_sort(Queue<T>& myqueue) { //FIXME: BUG
	if (myqueue.getHead() == nullptr)
		return; // Check if the queue is empty

	Node<T>* sorted = nullptr; // Start with an empty sorted list

	Node<T>* current = myqueue.getHead();
	while (current != nullptr) {
		Node<T>* next = current->next; // Store next node
		if (sorted == nullptr || sorted->data >= current->data) {
			// Insert at the beginning of the sorted list
			current->next = sorted;
			sorted = current;
		}
		else {
			// Locate the node before the point of insertion
			Node<T>* temp = sorted;
			while (temp->next != nullptr && temp->next->data < current->data) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}
	myqueue.setHead(sorted); // Update the head of the queue
}*/
