#pragma once
#ifndef Geometry3D_h__
#define Geometry3D_h__
#include <stdint.h>
#include <memory>

#ifdef DLLOFCPP_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#define LAPI __stdcall
#define IN
#define OUT

namespace GEOMETRY3D
{
	enum class eStatus
	{
		kStatusOk = 0x0000,
		kStatusInvalidParam = 0x0001
	};

	typedef struct sPoint3d
	{
		double x{ 0.0 };
		double y{ 0.0 };
		double z{ 0.0 };
	}Point3d;

	DLL_API eStatus LAPI
		PointAddPoint(IN const Point3d& p1, IN const Point3d& p2, OUT Point3d &p3);

	DLL_API std::shared_ptr<int> LAPI
		GetObj();
}
#endif // Geometry3D_h__
