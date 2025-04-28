#pragma once
#ifndef CPoint2D_h__
#define CPoint2D_h__

#ifdef DLLEXPORTCLASSBYCPP_EXPORTS
#  define DLL_API __declspec(dllexport)
#else
#  define DLL_API __declspec(dllimport)
#endif

namespace  Point2D
{

class DLL_API CPoint2D
{
public:
	CPoint2D();
	~CPoint2D();
	// ģ����
	double Detect(const double x, const double y);
};
}
#endif // CPoint2D_h__

