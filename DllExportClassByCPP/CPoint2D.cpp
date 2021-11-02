#include "pch.h"
#include "CPoint2D.h"
#include <iostream>

namespace Point2D
{
	CPoint2D::CPoint2D()
	{
		std::cout << "CPoint2D()" << std::endl;
	}

	CPoint2D::~CPoint2D()
	{
		std::cout << "~CPoint2D()" << std::endl;
	}

	double CPoint2D::Detect(const double x, const double y)
	{
		return x + y ;
	}
}