//  ########    #####    #######                             
//  ##     ##  ##   ##  ##     ##                            
//  ##     ## ##     ##        ##                            
//  ########  ##     ##  #######                             
//  ##        ##     ##        ##                            
//  ##         ##   ##  ##     ##                            
//  ##          #####    #######                             
//                                                           
//                                                           
//                                                           
//                                                           
//                                                           
//                                                           
//                                                           
//   #######    ##   ##         #######                      
//  ##     ## ####   ##    ##  ##     ##                     
//         ##   ##   ##    ##         ##                     
//   #######    ##   ##    ##   #######                      
//  ##          ##   #########        ##                     
//  ##          ##         ##  ##     ##                     
//  ######### ######       ##   #######                      
//                                                           
//                                                           
//                                                           
//                                                           
//                                                           
//                                                           
//                                                           
//  ######## ######## ########  ########  ##    ##           
//     ##    ##       ##     ## ##     ##  ##  ##            
//     ##    ##       ##     ## ##     ##   ####             
//     ##    ######   ########  ########     ##              
//     ##    ##       ##   ##   ##   ##      ##              
//     ##    ##       ##    ##  ##    ##     ##              
//     ##    ######## ##     ## ##     ##    ##              
//   ######   ########  #### ######## ######## #### ##    ## 
//  ##    ##  ##     ##  ##  ##       ##        ##  ###   ## 
//  ##        ##     ##  ##  ##       ##        ##  ####  ## 
//  ##   #### ########   ##  ######   ######    ##  ## ## ## 
//  ##    ##  ##   ##    ##  ##       ##        ##  ##  #### 
//  ##    ##  ##    ##   ##  ##       ##        ##  ##   ### 
//   ######   ##     ## #### ##       ##       #### ##    ## 
//      



///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Ryan Ferguson
// Email:            vex1123@gmail.com
// Label:            (program's label from assignment list)
// Title:            (short title from assignment, if any)
// Course:           3013
// Semester:         Spring 2020
//
// Description: This program has a linked list class that implements header and tail nodes. 
// The main program creates two linked lists that have numbers pushed onto the end.
// After printing the tail node a third list is created and the overloaded + is used
// to create a combined third list.
// After outputting the thrid list, the overloaded [] operator is used to cout the 5th nodes int value.
// 
//        
//
// Usage:			Can be used for priority queues as it is set up with both front and back insert.
//       
//
// Files:            Main.cpp file provided by Professor Griffin
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include<string>		   // -----NOTE I added string library here because my compiler said NULL was not defined-----
using namespace std;

int A[100];				  // Array of integers unsure of intened usage never actually is initialised 	

struct Node {			  /*Node struct containing an integer value and a single pointer*/
	int x;
	Node *next;
	Node() {			  // default constructor
		x = -1;
		next = NULL;
	}
	Node(int n) {        // parameterised constructor setting only the value not the pointer
		x = n;
		next = NULL;
	}
};


/**
 * Class List
 *
 * Description:
 *      List is a framework for a singly linked list implementing 
 *	    a head and tail pointer along with a size variable.
 *
 * Public Methods:
 *      - List() : default constructor for a list setting head and tail to NULL and size to 0
 *
 *      - Push(int val) : reads in an int and assigns value to a new node. 
 *		  This function also places the new node onto the end of the list, meaning the last node before the tail
 *		  return - void
 *      
 *		- Insert(int val) : reads in an integer and places the value into a new node.
 *		  This insertion places the node at the front of the list, meaning directly after the header node.
 *		  return - void
 *
 *		- printTail() : couts the tial nodes value
 *		  return - void
 *
 *		- print() : creates a string that stores each integer value of the nodes in the linked list
 *		  that returns the string.
 *		  return - string
 *
 *		- pop() : unimplemented function
 *
 *		- operator+(const List &rhs) : function that creates a new List and stores the local list
 *		  and the new list rhs by pushing them onto the end. The local list from head to tail is first
 *		  then the new pased inlist head to tail.
 *		  return - List
 *
 *		- operator [](int index) : function that overloads the [] operator to allow for a list to be acessed as though
 *		  it is an array and return the integer value of [x] position in the list
 *		  return - list
 *
 *		- friend &operator<<(ostream &os, list L) : friend function declared to use the << cout operator to output
 *		  the list to the screen through the use of the print function in class. Must be friend because it needs acess to
		  the ostream.
 *
 * Private Methods:
 * 
 *
 * Usage:
 *
 *      - Class can bue used for any unsorted linked list
 *      - to us
 *
 */

class List {
private:
	Node *Head;
	Node *Tail;
	int Size;

public:
	List() {
		Head = Tail = NULL;
		Size = 0;
	}

	void Push(int val) {
		// allocate new memory and init node
		Node *Temp = new Node(val);

		if (!Head && !Tail) {
			Head = Tail = Temp;
		}
		else {
			Tail->next = Temp;
			Tail = Temp;
		}
		Size++;
	}

	void Insert(int val) {
		// allocate new memory and init node
		Node *Temp = new Node(val);

		// figure out where it goes in the list

		Temp->next = Head;
		Head = Temp;
		if (!Tail) {
			Tail = Head;
		}
		Size++;
	}

	void PrintTail() {
		cout << Tail->x << endl;
	}

	string Print() {
		Node *Temp = Head;
		string list;

		while (Temp != NULL) {
			list += to_string(Temp->x) + "->";
			Temp = Temp->next;
		}

		return list;
	}

	// not implemented
	int Pop() {
		Size--;
		return 0; //
	}

	List operator+(const List &Rhs) {
		// Create a new list that will contain both when done
		List NewList;

		// Get a reference to beginning of local list
		Node *Temp = Head;

		// Loop through local list and Push values onto new list
		while (Temp != NULL) {
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Get a reference to head of Rhs
		Temp = Rhs.Head;

		// Same as above, loop and push
		while (Temp != NULL) {
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Return new concatenated version of lists
		return NewList;
	}

	// Implementation of [] operator.  This function returns an
	// int value as if the list were an array.
	int operator[](int index) {
		Node *Temp = Head;

		if (index >= Size) {
			cout << "Index out of bounds, exiting";
			exit(0);
		}
		else {

			for (int i = 0; i < index; i++) {
				Temp = Temp->next;
			}
			return Temp->x;
		}
	}

	friend ostream &operator<<(ostream &os, List L) {
		os << L.Print();
		return os;
	}
};

int main(int argc, char **argv) {
	List L1;
	List L2;

	for (int i = 0; i < 25; i++) {
		L1.Push(i);
	}

	for (int i = 50; i < 100; i++) {
		L2.Push(i);
	}

	//cout << L1 << endl;
	L1.PrintTail();
	L2.PrintTail();

	List L3 = L1 + L2;
	cout << L3 << endl;

	cout << L3[5] << endl;
	return 0;
}
