#include <decode_object.hpp>

#include <decode.hpp>

#include <cover_to_display.hpp>

int main (int argc, char* argv[])
{
	VideoCapture cap;
	if (!cap.open (0))
        return 0;

	for (;;) {

		// Read image
		Mat im;

		cap >> im;

		if (frame.empty ()) break; // end of video stream

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

