#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        std::cerr << "usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }

    cv::Mat image, output;
    image = cv::imread( argv[1], cv::IMREAD_COLOR );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display Image", image);
    cv::waitKey(0);

    cv::boxFilter(image, output, -1 /*depth*/, cv::Size(7,7) /*kernel size*/, cv::Point(-1,-1), true /*normalized or not*/, cv::BORDER_DEFAULT);
    cv::imshow("Display Image", output);
    cv::waitKey(0);

    cv::GaussianBlur(image, output, cv::Size(9,9) /*kernel size*/, 1.5/*x std dev*/, 1.5/*y std dev*/, cv::BORDER_DEFAULT);
    cv::imshow("Display Image", output);
    cv::waitKey(0);

    return 0;
}
