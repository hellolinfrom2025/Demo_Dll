// DllDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "Library.hpp"
#include "InterDllPrj.h"
#include "InterDllPrj2.h"

int main()
{
#if 0 ��̬����DLL
	//----------��̬����DLL����������ʱ�ڣ���ֻҪ�ҵ�Ŀ��DLL------------
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
	//----------��̬���ã���������ʱ�ڣ���Ҫ����.h��.lib��.dll-------------
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

