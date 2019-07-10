#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        std::cerr << "usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }

    cv::Mat image;
    image = cv::imread( argv[1], cv::IMREAD_COLOR );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    cv::Mat kernel {0.8,0.0,-0.8,
                0.8,0.0,-0.8,
                0.8,0.0,-0.8};


    cv::filter2D(image, image, -1, kernel, cv::Point(-1,-1), 0, cv::BORDER_DEFAULT);

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    cv::imshow("Display Image", image);

    cv::waitKey(0);

    return 0;
}
