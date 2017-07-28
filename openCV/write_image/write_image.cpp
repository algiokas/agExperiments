#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main (int argc, char** argv) {
        if (argc !=2) {
                std::cout << "Usage: write_image <image_path>" << std::endl;
                return -1;
        }

        Mat image;
        image = imread(argv[1], 1);

        if (!image.data) {
                std::cout << "No image data" << std::endl;
                return -1;
        }

        FileStorage file("image_matrix.xml", FileStorage::WRITE);
        file << "Image" << image;

        return 0;
}

