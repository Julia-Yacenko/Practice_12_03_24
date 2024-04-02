#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;

int main()
{
    cv::Mat colorImg = cv::imread("D:/Camera/test.jpg");
    if (!colorImg.data)
    {
        printf("Error loading image \n"); return -1; 
    }
    
    cv::imshow("RGB", colorImg);

    cv::Mat img2;
    cv::cvtColor(colorImg, img2, COLOR_BGR2HSV);
    cv::imshow("HSV", img2);

    cv::Mat img3;
    cv::cvtColor(colorImg, img3, COLOR_BGR2YUV);
    cv::imshow("YUV", img3);

    cv::Mat img4;
    cv::cvtColor(colorImg, img4, COLOR_BGR2Lab);
    cv::imshow("Lab", img4);

    cv::Mat img5;
    cv::cvtColor(colorImg, img5, COLOR_BGR2GRAY);
    cv::imshow("GRAY", img5);

    cv::Mat img6;
    cv::cvtColor(colorImg, img6, COLOR_BGR2XYZ);
    cv::imshow("XYZ", img6);

    cv::Mat img7;
    cv::cvtColor(colorImg, img7, COLOR_BGR2YCrCb);
    cv::imshow("YCrCb", img7);

    cv::Mat img8;
    cv::cvtColor(colorImg, img8, COLOR_BGR2HLS);
    cv::imshow("HLS", img8);
    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}

