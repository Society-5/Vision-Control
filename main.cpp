#include <decode_object.hpp>

#include <decode.hpp>

#include <cover_to_display.hpp>

int main (int argc, char* argv[])
{
	VideoCapture cap;

	if (!cap.open ("http://172.16.0.165:8080/video"))
        return 0;

	for (;;) {

		Mat im;

		// Read image
		cap >> im;

		if (im.empty ()) break; // end of video stream

		// Variable for decoded objects 
		vector <decodedObject> decodedObjects;

		// Find and decode barcodes and QR codes
		decode (im, decodedObjects, [](const decodedObject& obj)
				{
					// Print type and data
					cout << "Type : " << obj.type << endl;
					cout << "Data : " << obj.data << endl << endl;
				});

		// Display location 
		display (im, decodedObjects);
	}

	return EXIT_SUCCESS;
}

