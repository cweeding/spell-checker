// ADT stack: Array-based implementation
// @file ArrayStack.h
// Used with project4_task2.cpp

#ifndef _ARRAY_STACK
#define _ARRAY_STACK

#include "StackInterface.h"

const int MAX_STACK = 10;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:	
	ItemType items[MAX_STACK]; // Array of stack items
	int top; // Index to top of stack
	
public:
	 ArrayStack(); // Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const;	
}; // end ArrayStack

#include "ArrayStack.cpp"
#endif
