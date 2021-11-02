#include "pch.h"
#include "CPoint3D.h"
#include <iostream>

namespace Point3D
{
	CPoint3D::CPoint3D()
	{
		std::cout << "CPoint3D()" << std::endl;
	}

	CPoint3D::~CPoint3D()
	{
		std::cout << "~CPoint3D()" << std::endl;
	}

	double CPoint3D::Detect(const double x, const double y, const double z)
	{
		return x + y + z;
	}
}