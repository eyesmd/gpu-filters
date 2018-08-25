#include "camera.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

QAtomicInt frameReady = 0; 
using namespace cv;
using namespace std;
void Camera::run(){

	/* open webcam */
	stream = VideoCapture(0); // video device number 0
	width = stream.get(CV_CAP_PROP_FRAME_WIDTH);
	height = stream.get(CV_CAP_PROP_FRAME_HEIGHT);
	if (!stream.isOpened()) {
	    cerr << "Failed to open stream." << endl;
	    exit(1);
	}
	Mat frames[2];
	int index = 0;
	cout << "cam ready" << endl;
	while(1){
	    stream.read(frames[index]);
	    bool is_new_frame = frameReady.testAndSetAcquire(0, 1);

		if (is_new_frame){
			emit new_frame(&frames[index]);
			index = (index+1) % 2;
		}
	}
}