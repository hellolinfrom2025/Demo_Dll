#include "LMath.h"

using namespace cv;

LMath::LMath()
{
}


LMath::~LMath()
{
}

void LMath::showRect(const cv::Mat &matInput)
{
	int image_h = matInput.rows;
	int image_w = matInput.cols;
	rectangle(matInput, Point(0, 0), Point(image_w - 1, image_h - 1), Scalar(0, 0, 255), 3, 8, 0);
}

void LMath::calcPerimeter(int w, int h, int& r)
{
	r = 2 * (w + h);
}
