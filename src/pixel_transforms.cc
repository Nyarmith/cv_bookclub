#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    cv::Mat image, out;
    image = cv::imread( argv[1], cv::IMREAD_COLOR );

    if ( !image.data )
    {
        std::cerr << "No image data \n";
        return -1;
    }

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );

    // original
    cv::imshow("Display Image", out);
    cv::waitKey(0);

    // darken
    out = image - cv::Scalar(128,128,128);
    cv::imshow("Display Image", out);
    cv::waitKey(0);

    // invert
    out = cv::Scalar(255,255,255) - image;
    cv::imshow("Display Image", out);
    cv::waitKey(0);

    // lighten
    out = cv::Scalar(128,128,128) + image;
    cv::imshow("Display Image", out);
    cv::waitKey(0);

    // lower contrast
    out = cv::Scalar(.5,.5,.5) * image;
    cv::imshow("Display Image", out);
    cv::waitKey(0);

    // nonlinear lower contrast
    // ???
    // ???
    // ???

    // raise contrast
    out = cv::Scalar(2,2,2)*image;
    cv::imshow("Display Image", out);
    cv::waitKey(0);

    // nonlinear raise contrast
    // ???
    // ???
    // ???

    return 0;
}
