#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        std::cerr << "usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }

    cv::Mat image, ycrcb;
    image = cv::imread( argv[1], cv::IMREAD_COLOR );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::imshow("Display Image", image);
    cv::waitKey(0);

    // separate channels and normalize intensity channel
    cv::cvtColor( image, ycrcb, cv::COLOR_BGR2YCrCb );
    std::vector<cv::Mat> channels;
    cv::split(ycrcb, channels);
    cv::equalizeHist(channels[0], channels[0]);

    cv::merge(channels, ycrcb);

    cv::cvtColor(ycrcb, image, cv::COLOR_YCrCb2BGR);

    cv::imshow("Display Image", image);
    cv::waitKey(0);

    return 0;
}
