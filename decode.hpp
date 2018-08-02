#pragma once

#include <opencv2/opencv.hpp>
#include <zbar.h>

#include <decode_object.hpp>
#include <vector>

using namespace cv;
using namespace std;
using namespace zbar;

// Find and decode barcodes and QR codes
void decode (Mat &im, vector<decodedObject>&decodedObjects, void (*callback)(const decodedObject&))
{

	// Create zbar scanner
	ImageScanner scanner;

	// Configure scanner
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	// Convert image to grayscale
	Mat imGray;
	cvtColor(im, imGray,COLOR_BGR2GRAY);

	// Wrap image data in a zbar image
	Image image(im.cols, im.rows, "Y800", (uchar *)imGray.data, im.cols * im.rows);

	// Scan the image for barcodes and QRCodes
	int n = scanner.scan(image);

	// Print results
	for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
	{
		decodedObject obj;

		obj.type = symbol->get_type_name();
		obj.data = symbol->get_data();
		
		(*callback) (obj);

		// Obtain location
		for(int i = 0; i< symbol->get_location_size(); i++)
		{
			obj.location.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
		}

		decodedObjects.push_back(obj);
	}
}
