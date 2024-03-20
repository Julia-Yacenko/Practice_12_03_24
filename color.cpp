#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;

int main()
{
    cv::Mat colorImg = cv::imread("D:/Camera/line.png");
    if (!colorImg.data)
    {
        printf("Error loading image \n"); return -1;
    }
    namedWindow("1", WINDOW_AUTOSIZE);
    cv::imshow("1", colorImg);

    cv::Mat greyImg;
    cv::cvtColor(colorImg, greyImg, COLOR_BGR2GRAY);
    cv::imshow("2", greyImg);

    cv::Mat image;
    GaussianBlur(greyImg, image, Size(5, 5), 0);
    cv::imshow("3", image);

    cv::Mat edges;
    Canny(greyImg, edges, 50, 200);
    cv::imshow("4", edges);
    std::vector<cv::Vec4i> lines;
    HoughLinesP(edges, lines, 1, CV_PI / 180, 150, 10, 250);
    for (size_t i = 0; i < lines.size(); i++) {
        Vec4i l = lines[i];
        line(colorImg, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255, 0, 0), 1, LINE_AA);
    }

    std::vector<Vec3f>  circles;
    HoughCircles(edges, circles, HOUGH_GRADIENT, 1, 750, 200, 10, 10, 100);
    for (size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(colorImg, center, radius, Scalar(0, 255, 0), 2, 8, 0);
    }
    cv::imshow("5", colorImg);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
