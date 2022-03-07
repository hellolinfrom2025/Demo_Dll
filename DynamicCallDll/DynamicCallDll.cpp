// DynamicCallDll.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <windows.h>
#include <iostream>
#include <assert.h>
#include <functional>

int TestDllOfC();
int TestDllOfCpp();
int TestDllExportClassByFunc();
int TestDllExportClassByCPPInterface();

int main()
{
	int ret = 0;
	ret += TestDllOfC();
	ret += TestDllOfCpp();
	ret += TestDllExportClassByFunc();
	ret += TestDllExportClassByCPPInterface();

	system("pause");
	return ret;
}

#include "../DllOfC/Geometry2D.h"
int TestDllOfC()
{
	HMODULE hModule = LoadLibrary("DllOfC.dll");
	assert(hModule);
	if (hModule == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_MOD_NOT_FOUND) {
			printf("Could not find library depending\n");
			return 1;
		}
		printf("Could not find library file\n");
		system("pause");
		return 1;
	}
	void* pPointAddPoint = ::GetProcAddress(hModule, "PointAddPoint");
	assert(pPointAddPoint);
	if (pPointAddPoint == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_PROC_NOT_FOUND) {
			printf("Could not find func PointAddPoint\n");
			return 1;
		}
		return 1;
	}
	typedef std::function<uint32_t(__stdcall)( const Point2d, const Point2d, Point2d* )> FnPointAddPoint;
	typedef uint32_t(__stdcall *FnPointAddPoint1)(const Point2d, const Point2d, Point2d*);
	FnPointAddPoint Point2DAddPoint2D =reinterpret_cast< FnPointAddPoint1 >(pPointAddPoint);
	Point2d p1{ 1,2 };
	Point2d p2{ 1.1,2.2 };
	Point2d p3;
	uint32_t  status = Point2DAddPoint2D(p1, p2, &p3);
	printf("p3.x=%f,p3.y=%f\n", p3.x, p3.y);
	printf("Point2DAddPoint2D:%16x,&Point2DAddPoint2D:%16x\n", Point2DAddPoint2D, &Point2DAddPoint2D);


	FreeLibrary(hModule);
	return 0;
}

#include "../DllOfCpp/Geometry3D.h"
int TestDllOfCpp()
{
	using namespace GEOMETRY3D;
	HMODULE hModule = LoadLibrary("DllOfCpp.dll");
	assert(hModule);
	if (hModule == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_MOD_NOT_FOUND) {
			printf("Could not find library depending\n");
			return 1;
		}
		printf("Could not find library file\n");
		system("pause");
		return 1;
	}
	void* pPointAddPoint = ::GetProcAddress(hModule, "PointAddPoint");
	assert(pPointAddPoint);
	if (pPointAddPoint == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_PROC_NOT_FOUND) {
			printf("Could not find func PointAddPoint\n");
			return 1;
		}
	}
	typedef eStatus (__stdcall *FnPointAddPoint)(const Point3d&, const Point3d&, Point3d&);
	FnPointAddPoint Point3DAddPoint3D = static_cast<FnPointAddPoint>(pPointAddPoint);
	Point3d p1{ 1,2 };
	Point3d p2{ 1.1,2.2 };
	Point3d p3;
	eStatus  status = Point3DAddPoint3D(p1, p2, p3);
	printf("p3.x=%f,p3.y=%f,p3.z=%f\n", p3.x, p3.y, p3.z);


	void* pGetObj = ::GetProcAddress(hModule, "GetObj");
	assert(pGetObj);
	typedef std::shared_ptr<int>(__stdcall *FnGetObj)();
	FnGetObj fGetObj = static_cast<FnGetObj>(pGetObj);

	//使智能指针先释放与库卸载
	{
		auto ptr= fGetObj();
		printf("p =%d\n", *ptr);
	}

	FreeLibrary(hModule);
	return 0;
}

#include "../DllExportClassByFunc/Point3D.h"
int TestDllExportClassByFunc()
{
	using namespace Point3D;
	HMODULE hModule = LoadLibrary("DllExportClassByFunc.dll");
	assert(hModule);
	if (hModule == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_MOD_NOT_FOUND) {
			printf("Could not find library depending\n");
			return 1;
		}
		printf("Could not find library file\n");
		system("pause");
		return 1;
	}
	void* pGetObj = ::GetProcAddress(hModule, "GetObj");
	assert(pGetObj);
	void* pDllDect = ::GetProcAddress(hModule, "DllDetect");
	assert(pDllDect);
	void* pReleaseObj = ::GetProcAddress(hModule, "ReleaseObj");
	assert(pReleaseObj);
	if (pGetObj == nullptr || pDllDect == nullptr|| pReleaseObj == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_PROC_NOT_FOUND) {
			printf("Could not find func PointAddPoint\n");
			return 1;
		}
	}
	typedef CPoint3D*(__stdcall *FnGetObj)();
	typedef double(__stdcall *FnDllDetect)(CPoint3D*,const double,const double,const double);
	typedef bool(__stdcall *FnReleaseObj)(CPoint3D*);
	FnGetObj GetObj = static_cast<FnGetObj>(pGetObj);
	FnDllDetect DllDetect = static_cast<FnDllDetect>(pDllDect);
	FnReleaseObj ReleaseObj = static_cast<FnReleaseObj>(pReleaseObj);
	CPoint3D* pDetecter= GetObj();
	double result= DllDetect(pDetecter,1.1,2.2,3.3);
	printf("result=%f\n",result);
	ReleaseObj(pDetecter);


	FreeLibrary(hModule);
	return 0;
}

#include "../DllExportClassByCPPInterface/Camera.h"
int TestDllExportClassByCPPInterface()
{
	using namespace Device;
	HMODULE hModule = LoadLibrary("DllExportClassByCPPInterface.dll");
	assert(hModule);
	if (hModule == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_MOD_NOT_FOUND) {
			printf("Could not find library depending\n");
			return 1;
		}
		printf("Could not find library file\n");
		system("pause");
		return 1;
	}
	void* pCreateCamera = ::GetProcAddress(hModule, "CreateCamera");
	assert(pCreateCamera);
	if (pCreateCamera == nullptr) {
		DWORD errNumber = GetLastError();
		if (errNumber == ERROR_PROC_NOT_FOUND) {
			printf("Could not find func PointAddPoint\n");
			return 1;
		}
	}
	typedef std::shared_ptr<ICamera>(__stdcall *FnCreateCamera)(const eCameraManufacturer &);
	FnCreateCamera CreateCamera = static_cast<FnCreateCamera>(pCreateCamera);

	//使智能指针先释放与库卸载
	{
		auto ptrHikvisionCam = CreateCamera(eCameraManufacturer::kHikvision);
		ptrHikvisionCam->Init(5);
		ptrHikvisionCam->Open();
		ptrHikvisionCam->Close();

		auto ptrBaslerCam = CreateCamera(eCameraManufacturer::kBasler);
		ptrBaslerCam->Init(2);
		ptrBaslerCam->Open();
		ptrBaslerCam->Close();
	}

	FreeLibrary(hModule);
	return 0;
}