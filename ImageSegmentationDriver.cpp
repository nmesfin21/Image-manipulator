/******************************************************************************
* ImageSegmentationDriver.cpp
* CSS 342
* Assigment 4 Design
* Author Natnael Tezera
* Professor: Clark f. Olson
*
* This file is the driver class to create image segmentation
* The class uses ImageContainer and PixelContainer classes in non-trival way 
* to create the segmentations. 
* 
* It is written with the assumption of using Professor Clark's
* imageLib c++ class.
* 
*******************************************************************************
*/

#include <iostream>
#include <cmath>
#include "ImageContainer.h"
#include "ImageLib.h"
#include "pixelContainer.h"

/**
* closePixel:
* checks if seed and neighbor has close enough color intensity
* Preconditiion: seed and neighbor represent a pixel defined under
*					the convension of imageLib
* Postcondition: Returns true if the summation of the absolute value
* of the difference beetween pixel seed's red, green and blue components and 
* corresponding component of neighbor pixel. otherwise false.
*/
bool closePixel(pixel seed, pixel neighbor) {

	return  (abs(seed.red - neighbor.red) + abs(seed.blue - neighbor.blue)
		+ abs(seed.green - neighbor.green) < 100);

}


/**
* assignToGroup:
* recurssively examine neighbors of seed pixels or neighbors of close enough 
* pixels and add close enough pixels to the pixelHolder. 
* Precondition: the dimension of inputImage and outputImage is equal
*				0 <= row <= inputImage.getHeight() 
*               0 <= col <= inputImage.getWidth() 
*				seed has to be a pixel on inputImage
* Postcondition: if a pixel is neighbor to seed and close enough to seed
* or neighbor of a pixel and close enough to seed. it will be added to 
* pixelHolder and the outputimage painted with the average color. 
*/
void assignToGroup(pixel seed, pixel neighbor, PixelContainer &pixelHolder, 
			ImageContainer &inputImage,	ImageContainer &outputImage, 
													int row, int col) {

			byte red;
			byte green;
			byte blue;
		
		
			if (outputImage.getPixel(row, col).red == 0) {
				pixelHolder.addPixel(seed);
				outputImage.setPixel(row, col, 255, 0, 0);

				//check right neighbors
				if (col + 1 < inputImage.getWidth()) {
					pixel rightNeighbor = inputImage.getPixel(row, col + 1);

					if (closePixel(seed, rightNeighbor) &&
						outputImage.getPixel(row, col + 1).red != 255) {
						assignToGroup(seed, rightNeighbor, pixelHolder,
							inputImage, outputImage, row, col + 1);
					}
				}
				
				// check left neighbor				
				if (col - 1 > 0) {
					pixel leftNeighbor = inputImage.getPixel(row, col - 1);
					if (closePixel(seed, leftNeighbor) &&
						outputImage.getPixel(row, col - 1).red != 255) {

						assignToGroup(seed, leftNeighbor, pixelHolder,
							inputImage, outputImage, row, col - 1);
					}
				}
				
								
				// check above neighbor
				if (row - 1 > 0) {
					pixel upNeighbor = inputImage.getPixel(row - 1, col);
					if (closePixel(seed, upNeighbor) &&
						outputImage.getPixel(row - 1, col).red != 255) {
						assignToGroup(seed, upNeighbor, pixelHolder,
							inputImage, outputImage, row - 1, col);
					}
				}
				
				// check bottom neighbor
				if (row + 1 < inputImage.getHeight()) {
					pixel bottomNeighbor = inputImage.getPixel(row + 1, col);
					if (closePixel(seed, bottomNeighbor) && 
							outputImage.getPixel(row + 1, col).red != 255) {
						assignToGroup(seed, bottomNeighbor, pixelHolder,
							inputImage, outputImage, row + 1, col);
					}
						
				}
				// Compute the average color in pixel holder,
				// and paint the outputImage with the average color
				pixelHolder.averageColor(red, blue, green);		
				outputImage.setPixel(row, col, red, blue, green);
						
				
		}	
}
			

/**
* This is the entry function
* Precondition: the name of input image is valid
*				the name of output image is valid				
* Postcondition:an Image created by segmentation based on the closeness of
* neighboring pixels and stored on output.gif
*/
int main() {


	// Creates two pixel container objects
	PixelContainer pixelStorage;
	PixelContainer pixelHolder;

	ImageContainer inputImage("try.gif");	// reads test image
	//inputImage.invertPixel();
	// out put image
	ImageContainer outputImage(inputImage.getHeight(), inputImage.getWidth());
	
	byte red;
	byte green;
	byte blue;

	int segmentCounter = 0;	// segment counter
	pixel seed;
	pixel neighbor = inputImage.getPixel(0, 0);
	
	
	for (int row = 0; row < outputImage.getHeight(); row++) {
		for (int col = 0; col < outputImage.getWidth(); col++) {
			//check the red compontent of pixel 
			if (outputImage.getPixel(row, col).red == 0) {
				seed = inputImage.getPixel(row, col);	//Assign seed
				assignToGroup(seed, neighbor, pixelHolder, inputImage, 
				outputImage, row, col);					// Call recursive function
				segmentCounter++;						// increment number of
														// segment
				pixelStorage.merge(pixelHolder);		// merge the pixel
				pixelHolder.averageColor(red, blue, green);
			}
			
			pixelHolder.removeAll();
		}
	}
	
	//print out number of pixels in merged container
	// and number of segments and the average color
	cout<< "number of in pixel in mergedstorage: " << pixelStorage.getSize()
	<<endl;
	cout<< "number of segments: " << segmentCounter << endl;
	cout<<"the average color (red, blue, green): ( " << red << ", " << blue <<
		", " << green << ")" << endl; 

	//Paint the output image
	outputImage.writeGifImage("output.gif");

	

}


