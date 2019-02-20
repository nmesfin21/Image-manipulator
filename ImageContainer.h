/**
***********************************************************************************
* ImageContainer.h
*
* Author Natnael Tezera
* Class: CSS 342
* Professor: Clark F Olson
* This is a header file for ImageContainer.cpp .
* It is written with an assumtion that we will be using professor Clark's
* ImageLib c++ class.
* This header file delcares private data members and public functions and operators
* It declares operator << as a friend, which we will be using to
*
***********************************************************************************
*/
#pragma once

#include "ImageLib.h"
#include <string>
#include <iostream>

using namespace std;

class ImageContainer {

	/**
	* Operator <<:
	* Outputs an object.
	* Preconditon: none
	* Postcondition: operator << overloaded
	*/
	friend ostream& operator<<(ostream&, const ImageContainer&);

private:						// Declare private data member
	image imageData;

public:							// Declare public data members and functions

	/**
	* Constructor:
	* Precondition: imageName is a valid name that refers to a GIF image
	* Postcondition: an image with the convention of image type defined in
	*			ImageLib.h is constructed
	*/
	ImageContainer(string imageName);

	/**
	* Constructor
	* Precondition: rows and cols are the desired size to make an image
	* Postconditon: a blank image has been created.
	*/
	ImageContainer(int rows, int cols);

	/**
	* Copy constructor:
	* Preconditon: inputImage is the desired image defined by the convention of
	*				image define in imageLib.h
	* Postcondition: Copy of an image is created
	*/
	ImageContainer(const ImageContainer &inputImage);

	/**
	* writeImage:
	* Saves a given GIF image to a valid file name
	* Preconditions:  filename is valid filename to store a GIF image.
	*			inputImage holds an image using the conventions described
	*			for the image type above.
	* Postconditions: inputImage is saved as a GIF image at the location
	*			specified by filename.
	*/
	void writeGifImage(string filename);

	/**
	* overload operator=
	* Precondition: *this needs to be dealocated before the new image assigned
	*			to it
	* Postconditon: assign image to a new location
	*/
	const ImageContainer& operator=(const ImageContainer &input);

	/**
	* increaseRedIntensity:
	* Increases the intensity of the red component of an image
	* Precondition: None
	* Postcondition: the intensity of the red component of the image is increased
	*/
	void increaseRedIntensity(const image &input);

	/**
	* decreaseBlueIntensity:
	* Decreases the intensity of the blue component of an image
	* Precondition: None
	* Postcondition: the intensity of the blue component of the image has been
	*		 decreased
	*/
	void decreaseBlueIntensity(const image &input);

	/**
	* getHeight:
	* Get the length of row for an image
	* Precondition: None
	* postcondition: Returns the length of the image
	*/
	int getHeight() const;

	/**
	* getWidth:
	* Returns the length of column for an image
	* Precondition: None
	* postcondition: Returns the length of the column
	*/
	int getWidth() const;

	/**
	* countDifference:
	* Counts and returns the diffrence between the two images
	* Precondition: the two images have the same dimension
	* Postcondtion: the number of differences is returned.
	*/
	int countDifference(ImageContainer &firstInput, ImageContainer &secondInput) const;

	/**
	* setPixel:
	* Set(alter) the blue, red, and green intensity of a pixel on the image
	* Precondition: the pixel is on the image grid and the range of each color
	*			components are between 0 and 255
	* Postcondtion: the intensity of gree, red and blue component of a pixel
	* set(alter)
	*/
	void setPixel(int row, int col, int red, int blue, int green);

	/**
	* getPixel:
	* returns a pixel
	* Precondtion: row and col are on the image grid
	* Postcondition: a pixel is returned
	*/
	pixel getPixel(int row, int col) const;

	/**
	* overload the == operator
	* Checks if the two ImageContainer objects are identical
	* Precondtion: the two images have the same dimention
	* Postcontion: the similarity of the two ImageContainer object has been
	*		determined
	*/
	bool operator==(const ImageContainer &input) const;

	/**
	* overload the != operator
	* Returns true if the two objects are different, returns false if the are not
	* different
	* Precondtion: None
	* Postcontion: the similarity of the two ImageContainer object has been
	*		determined
	*/
	bool operator!=(const ImageContainer &image) const;

	/**
	* flipImageHorizontal:
	* Flips an image and return a new image
	* precondition: None
	* Postcondition: an image is flipped image
	*/
	const ImageContainer flipImageHorizontal();

	/**
	* flipImageVertical:
	* Flips an image and return a new image
	* precondition: None
	* Postcondition: an image is flipped image
	*/
	const ImageContainer flipImageVertical();

	/**
	* PhotoNegative:
	* Negate the image and return negated image
	* precondition: input is an image defined by the convention of
	*			immage in imageLib.h
	* Postcondition: a negated image returned
	*/
	ImageContainer photoNegative();

	/**
	* invertPixel:
	* Inverts the color of a single pixel
	* Precondition: None
	* PostCondition: Each color band of input pixel p has been inverted
	*			(255 - color)
	*/
	pixel invertPixel(pixel &p);

	/**
	* ~ImageContainer():
	* Destructor
	* Deallocate the memory on the heap
	* Precondition: imageContainer occupies memory on the heap
	* Postcondition: memory occupied by ImageContainer is freed
	*/
	~ImageContainer();

};