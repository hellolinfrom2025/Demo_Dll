#include "LMath2.h"

using namespace cv;

LMath2::LMath2()
{
}


LMath2::~LMath2()
{
}

void LMath2::showRect(const cv::Mat &matInput)
{
	int image_h = matInput.rows;
	int image_w = matInput.cols;
	rectangle(matInput, Point(0, 0), Point(image_w - 1, image_h - 1), Scalar(0, 0, 255), 3, 8, 0);
}

void LMath2::calcPerimeter(int w, int h, int& r)
{
	r = 2 * (w + h);
}
