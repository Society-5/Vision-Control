#pragma once

#include <opencv2/opencv.hpp>
#include <zbar.h>

using namespace cv;
using namespace std;
using namespace zbar;

#include <decode_object.hpp>
#include <vector>

// Display barcode and QR code location  
void display(Mat &im, vector<decodedObject>&decodedObjects)
{
	// Loop over all decoded objects
	for(int i = 0; i < decodedObjects.size(); i++)
	{
		vector<Point> points = decodedObjects[i].location;
		vector<Point> hull;

		// If the points do not form a quad, find convex hull
		if(points.size() > 4)
			convexHull(points, hull);
		else
			hull = points;

		// Number of points in the convex hull
		int n = hull.size();

		for(int j = 0; j < n; j++)
		{
			line(im, hull[j], hull[ (j+1) % n], Scalar(255,0,0), 3);
		}

	}

	// Display results 
	imshow("Results", im);
	waitKey(1);
	//while(true) {}

}
