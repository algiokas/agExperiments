#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

//displays an image from an image file (.jpg)
void show_image_file (char * filename) {
      Mat image;
	image = imread(argv[1], 1);

	if (!image.data) {
		std::cout << "No image data" << std::endl;
		return -1;
	}

	namedWindow("Display Image", WINDOW_NORMAL);
	imshow("Display Image", image);

	waitKey(0);
  

}


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
