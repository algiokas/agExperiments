#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "usage: display_image.out <image_path>" << std::endl;
		return -1;
	}

	Mat image;
	image = imread(argv[1], 1);

	if (!image.data) {
		std::cout << "No image data" << std::endl;
		return -1;
	}

	namedWindow("Display Image", WINDOW_NORMAL);
	imshow("Display Image", image);

	waitKey(0);

	return 0;
}
