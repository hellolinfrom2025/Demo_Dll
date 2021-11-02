// StaticCallDll.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <assert.h>

int TestDllOfC();
int TestDllOfCpp();
int TestDllExportClassByFunc();
int TestDllExportClassByCPP();
int TestDllExportClassByCPPInterface();

int main()
{
	int ret = 0;
	ret += TestDllOfC();
	ret += TestDllOfCpp();
	ret += TestDllExportClassByFunc();
	ret += TestDllExportClassByCPP();
	ret += TestDllExportClassByCPPInterface();

	system("pause");
	return ret;
}

#include "../DllOfC/Geometry2D.h"
int TestDllOfC()
{
	Point2d p1{ 1,2 };
	Point2d p2{ 1.1,2.2 };
	Point2d p3;
	uint32_t  status = PointAddPoint(p1, p2, &p3);
	printf("p3.x=%f,p3.y=%f\n", p3.x, p3.y);

	return 0;
}

#include "../DllOfCpp/Geometry3D.h"
int TestDllOfCpp()
{
	using namespace GEOMETRY3D;
	Point3d p1{ 1,2 };
	Point3d p2{ 1.1,2.2 };
	Point3d p3;
	eStatus  status = PointAddPoint(p1, p2, p3);
	printf("p3.x=%f,p3.y=%f,p3.z=%f\n", p3.x, p3.y, p3.z);


	auto ptr = GetObj();
	printf("p =%d\n", *ptr);
	return 0;
}

#include "../DllExportClassByFunc/Point3D.h"
int TestDllExportClassByFunc()
{
	using namespace Point3D;
	CPoint3D* pDetecter = GetObj();
	double result = DllDetect(pDetecter, 1.1, 2.2, 3.3);
	printf("result=%f\n", result);
	ReleaseObj(pDetecter);

	return 0;
}

#include "../DllExportClassByCPP//CPoint2D.h"
int TestDllExportClassByCPP()
{
	using namespace Point2D;
	CPoint2D Pt2d;
	double result = Pt2d.Detect(111, 2.2);
	printf("result=%f\n", result);
	return 0;
}


#include "../DllExportClassByCPPInterface/Camera.h"
int TestDllExportClassByCPPInterface()
{
	using namespace Device;
	auto ptrHikvisionCam = CreateCamera(eCameraManufacturer::kHikvision);
	ptrHikvisionCam->Init(5);
	ptrHikvisionCam->Open();
	ptrHikvisionCam->Close();

	auto ptrBaslerCam = CreateCamera(eCameraManufacturer::kBasler);
	ptrBaslerCam->Init(2);
	ptrBaslerCam->Open();
	ptrBaslerCam->Close();
	return 0;
}


