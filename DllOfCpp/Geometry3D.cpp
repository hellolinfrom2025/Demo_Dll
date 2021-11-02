#include "pch.h"
#include "Geometry3D.h"

namespace GEOMETRY3D
{
	DLL_API eStatus LAPI
		PointAddPoint(IN const Point3d& p1, IN const Point3d& p2, OUT Point3d &p3)
	{
		p3.x = p1.x + p2.x;
		p3.y = p1.y + p2.y;
		p3.z = p1.z + p2.z;
		return  eStatus::kStatusOk;
	}

	DLL_API std::shared_ptr<int> LAPI 
		GetObj()
	{
		return std::make_shared<int>(5);
	}
}