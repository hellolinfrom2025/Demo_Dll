#pragma once
#ifndef Point3D_h__
#define Point3D_h__

//使用C风格的函数名
#ifdef DLLEXPORTCLASSBYFUNC_EXPORTS
#  define DLL_API extern "C" __declspec(dllexport)
#else
#  define DLL_API extern "C" __declspec(dllimport)
#endif
#define LAPI __stdcall
#define IN
#define OUT

namespace Point3D
{
	//前置声明
	class CPoint3D;

	//导出获取对象的函数
	DLL_API CPoint3D* LAPI
		GetObj();

	//类中需要导出的函数
	DLL_API double LAPI
		DllDetect(IN  CPoint3D*const pPoint3D, IN const double x, IN const double y, IN const double z);

	//释放对象函数
	DLL_API bool LAPI
		ReleaseObj(IN CPoint3D* pPoint3D);
}
#endif // Point3D_h__
