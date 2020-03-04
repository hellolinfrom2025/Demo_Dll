// DllDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "Library.hpp"
#include "InterDllPrj.h"
#include "InterDllPrj2.h"

int main()
{
#if 0 动态调用DLL
	//----------动态调用DLL（代码运行时期），只要找到目标DLL------------
typedef bool (*createInstance)(void **);
typedef bool(*releaseInstance)(void *);
typedef bool(*showRect)(void *, const cv::Mat& , lin::img_detected_output& );
typedef bool(*calcPerimeter)(void *, int , int , int& );

	CLibrary lib(L"DllPrj.dll");
	createInstance fnCreateInstance =static_cast<createInstance>(lib.GetProc("createInstance"));
	releaseInstance fnReleaseInstance = static_cast<releaseInstance>(lib.GetProc("releaseInstance"));
	showRect fnShowRect = static_cast<showRect>(lib.GetProc("showRect"));
	calcPerimeter fnCalcPerimeter = static_cast<calcPerimeter>(lib.GetProc("calcPerimeter"));
	void * pMath;
	fnCreateInstance(&pMath);
	cv::Mat mat(400,300, CV_8UC3,cv::Scalar(0));
	lin::img_detected_output output;
	fnShowRect(pMath, mat, output);
	cv::imshow("", output.imgDisplayRect);
	cv::waitKey(0);
	fnReleaseInstance(pMath);

#else
	//----------静态调用（编译链接时期），要包含.h、.lib和.dll-------------
#pragma comment(lib, "DllPrj2.lib")
	cv::Mat mat(400, 300, CV_8UC3, cv::Scalar(0));
	lin2::img_detected_output output;
	lin2::showRect(mat, output);
	cv::imshow("", output.imgDisplayRect);
	cv::waitKey(-1);
#endif
	system("pause");
	//getchar();
    return 0;
}

