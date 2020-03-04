#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
//------------这里可以包含隐藏在dll项目的第三库-----------------
class LMath2
{
public:
	LMath2();
	~LMath2();
	void showRect(const cv::Mat &matInput);
	void calcPerimeter(int w, int h, int& r);
};

