#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    /*std::string image_path = "C:/Users/alexa/Desktop/netVisualizations/HandWritenMLP.png";
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        std::cin.get();
        return 1;
    }
    // imshow("Display window", img);
    // waitKey(0); // Wait for a keystroke in the window*/


// ############################# YUV #############################
    Mat img(3, 3, CV_8UC3, cv::Scalar(255, 0, 0));
    // imshow("Display window", img);
    // waitKey(0); // Wait for a keystroke in the window
    cout << "### BGR ###" << endl;
    cout << img << endl;
    cout << "### YUV ###" << endl;
    Mat yuv;
    cvtColor(img, yuv, cv::COLOR_BGR2YUV);
    cout << yuv << endl;


    std::cin.get();
    return 0;
}