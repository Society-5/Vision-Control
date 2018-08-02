build: 
	g++ -I. -I/usr/include/opencv -I/usr/include/opencv2 -L/usr/lib/ -g -o main main.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lzbar
