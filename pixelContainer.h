#pragma once
/******************************************************************************
* pixelContainer.h
* CSS 342 
* Assigment 4 Design
* Author Natnael Tezera
* Professor: Clark f. Olson
*
* This file describe the interface for pixelContainer.cpp
* The file describes the prototypes that will be implemented in the 
* pixelContainer.cpp
*******************************************************************************
*/

#include <iostream>
#include "ImageContainer.h"
#include "ImageLib.h"

using namespace std;

class PixelContainer {
	
private:
	// A Node struct that carries pixel data
	// and a pointer to the next data 
	typedef struct Node {
		pixel pixel;
		Node *next;
		}* nodePtr;

	int size;			// the number of elements in list
	nodePtr head;		// The head pointer of the pixelContainer
	nodePtr tail;		// curr pointer in pixelContainer
		
public:
	
	/**
	* Default constructor
	* Precondtion: None
	* Postcondition: creates a linked list of pixel 
	* with size 0, head and tail pointers point to nullptr
	*/
	PixelContainer();

	/**
	* Copy constructor:
	* Precondtion: None
	* Postcondtion: a copy of input linked list of pixels is created 
	*/
	PixelContainer(const PixelContainer& input);

	/**
	* overload operator=
	* Precondtion: the lhs and rhs are not the same
	* Postconditon: if the lhs and the rhs are not identical, the rhs
	* will be assigned to the lhs, else the lhs will be the same
	*/
	const PixelContainer& operator=( const PixelContainer& rhs);

	/*
	* Destructor:
	* Precondtion: None
	* Postcondition: if the head and curr pointers are not pointing to
	* nullptr, deletes head and curr and set the head and curr pointers
	* to nullptr, otherwise delete the value in head and curr.
	*/
	~PixelContainer();

	/**
	* addPixel:
	* Adds pixel in the linked list
	* Precondition: p is a pixel value defined by convension in imageLib.h 
	* Postconditon: if the linked list is empty, p will be added to the 
	* front of the linked list, otherwise it will be added to the end 
	*/
	void addPixel(pixel &p);

	/**
	* merge:
	* Merges linked list of pixels together
	* Precondition: None
	* Postcondition: the rhs is merged to the lhs and creates
	*/
	PixelContainer& merge(PixelContainer &rhs);

	/**
	* size:
	* Returns the size of the linkedlist
	* Precondition: None
	* Postcondition: if the linked list is empty returns 0, otherwise return
	* the number of elements in the linked list 
	*/
	int getSize();
		

	/**
	* contains
	* checks if a pixel is in a linked list
	* Precondition: pixelHolder is a linked list of pixels defined by the
	* the convension in PixelContainer, and p is defined by the convervension
	* in ImageLib
	* Postcondition:if the p is in PixelHolder it returns true, otherwise
	* return false
	*/
	bool containes(pixel &p);

	/**
	* averageColor:
	* Computes the average color of pixels in the linked list
	* Precondition: None
	* Postcondition: the average color of pixels in the linked list is 
	* computed, and assingn to the return parameters red, blue and green 
	*/
	void averageColor(byte &red, byte &blue, byte &green);

	/*
	* removeAll:
	* removes All elements in the linked list
	* Precondition: None
	* Postcondition: all elements in the linked list are removed
	* head and tail set to nullptr and the size set to 0			
	*/
	void removeAll();


};