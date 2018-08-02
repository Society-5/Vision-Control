#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

struct decodedObject
{
	string type;
	string data;
	vector <Point> location;
};

