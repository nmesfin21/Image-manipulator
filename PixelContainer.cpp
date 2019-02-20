/******************************************************************************
* pixelContainer.cpp
* CSS 342
* Assigment 4
* Author Natnael Tezera
* Professor: Clark f. Olson
*
* This is an implmentation class for pixeContainer.h
* This is an implimentation file for for ImageContainer.h .
* It is written with the assumption of using Professor Clark's
* imageLib c++ class.
*  
*******************************************************************************
*/

#include <iostream>
#include "ImageContainer.h"
#include "ImageLib.h"
#include "PixelContainer.h"

using namespace std;

/**
* Default constructor
* Precondtion: None
* Postcondition: creates a linked list of pixel
* with size 0, head and tail pointers point to nullptr
*/
PixelContainer::PixelContainer() {
	head = nullptr;
	tail = nullptr;
	size = 0;
	
		
}

/**
* Copy constructor:
* Precondtion: None
* Postcondtion: a copy of input linked list of pixels is created
*/
PixelContainer::PixelContainer(const PixelContainer &input) {
	
	head = input.head;
	nodePtr temp = input.head;


	while (temp != input.tail) {
		addPixel(temp ->pixel);
		temp = temp->next;
	}
	tail = input.tail;
	

}

/**
* overload operator=
* Precondtion: the lhs and rhs are not the same
* Postconditon: if the lhs and the rhs are not identical, the rhs
* will be assigned to the lhs, else the lhs will be the same
*/
const PixelContainer& PixelContainer::operator=(const PixelContainer &rhs) {
	if (this != &rhs)	//check for self assignent
	{	
		// dealocate memory
		nodePtr curr = head;
		while (curr != tail) {
			curr = curr->next;
			head = head->next;
			delete head;
		}
		tail = nullptr;

		// copy to the left side
		PixelContainer(rhs);
	}
	return *this;
}

/*
* Destructor:
* Precondtion: None
* Postcondition: if the head and tail pointers are not pointing to
* nullptr, deletes head and tail and set the head and tail pointers
* to nullptr, otherwise delete the value in head and tail. set the
* size to 0
*/
PixelContainer::~PixelContainer() {
	
	removeAll();
	/**
	while (head != tail) {
		nodePtr junk = head;
		head = head->next;
		delete junk;
		junk->next = nullptr;	
	}
	head = nullptr;
	tail = nullptr;
	size = 0;
	*/
}

/**
* addPixel:
* Adds pixel in the linked list
* Precondition: p is a pixel value defined by convension in imageLib.h
* Postconditon: if the linked list is empty, p will be added to the
* front of the linked list, otherwise it will be added to the end
*/
void PixelContainer::addPixel(pixel &p) {

	int newSize = getSize() + 1;
	nodePtr n = new Node;	// declare a temporary n
	n->next = tail;		 
	n->pixel = p;
	
	
	size = newSize;
	if (head != tail) {
		
		nodePtr curr = head;
		while (curr->next != tail) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
};

/**
* merge:
* Merges linked list of pixels together
* Precondition: None
* Postcondition: the rhs is merged to the lhs and creates
*/
PixelContainer &PixelContainer::merge(PixelContainer &rhs) {
	
		
		//head = rhs.head;
		tail = rhs.head;
		nodePtr temp = rhs.head;
		
		while (temp->next != rhs.tail) {
			temp->pixel = rhs.head->pixel;
			temp = temp->next;
		}
		
		tail = temp->next;
		size = size + rhs.getSize();
			
	return *this;
}

/**
* size:
* Returns the size of the linkedlist
* Precondition: None
* Postcondition: if the linked list is empty returns 0, otherwise return
* the number of elements in the linked list
*/
int PixelContainer::getSize() {
	return size;
}

/**
* contains
* checks if a pixel is in a linked list
* Precondition: pixelHolder is a linked list of pixels defined by the
* the convension in PixelContainer, and p is defined by the convervension
* in ImageLib
* Postcondition:if the p is in PixelHolder it returns true, otherwise
* return false
*/
bool PixelContainer::containes(pixel &p) {
	nodePtr curr = head;

	if (size == 0 || head == nullptr) {
		return false;
	}
	else {
		while (curr ->next!= nullptr) {
			
			if (curr->pixel.blue == p.blue && curr->pixel.green == p.green
				&& curr->pixel.red == p.red) {
				return true;
			}
			curr = curr->next;

		}

	}
	return true;

}


/**
* averageColor:
* Computes the average color of pixels in the linked list
* Precondition: None
* Postcondition: the average color of pixels in the linked list is
* computed, and assingn to the return parameters red, blue and green
*/
void PixelContainer::averageColor(byte &red, byte &blue, byte &green) {
	nodePtr curr = head;
	int addRed = 0;
	int addGreen = 0;
	int addBlue = 0;

	while (curr != nullptr) {
		addRed = addRed + curr->pixel.red;
		addGreen = addGreen + curr->pixel.green;
		addBlue = addBlue + curr->pixel.blue;
		curr = curr->next;
	}
	
	red = addRed/size;
	blue = addBlue/size;
	green = addGreen/size; 
}

/*
* removeAll:
* removes All elements in the linked list
* Precondition: None
* Postcondition: all elements in the linked list are removed
* head and tail set to nullptr and the size set to 0
*/
void PixelContainer::removeAll() {
	if(size == 0){
		head = nullptr;
		tail = nullptr;
		}	
	else
	{
	nodePtr curr = head;
	while (head != nullptr) {
			head = head ->next;
			delete curr;
			curr = head;
			size--;
		}
		head = nullptr;
		curr = nullptr;
	
	}
}



