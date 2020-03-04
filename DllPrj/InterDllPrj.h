#pragma once
#ifndef LIN__INTERDLLPRJ__H
#define LIN__INTERDLLPRJ__H
#ifdef DLLPRJ_EXPORTS
#define DETECT_API extern "C" __declspec(dllexport)
#else
#define DETECT_API extern "C" __declspec(dllimport)
#endif
#include <opencv2/opencv.hpp>
//---------------暴露在外的引用第三方库-----------------------
#ifdef _DEBUG
#pragma  comment(lib, "opencv_core341d.lib")
#pragma  comment(lib, "opencv_imgcodecs341d.lib")
#pragma  comment(lib, "opencv_highgui341d.lib")
#pragma  comment(lib, "opencv_imgproc341d.lib")
#pragma  comment(lib, "opencv_calib3d341d.lib")
#else
#pragma  comment(lib, "opencv_core341.lib")
#pragma  comment(lib, "opencv_imgcodecs341.lib")
#pragma  comment(lib, "opencv_highgui341.lib")
#pragma  comment(lib, "opencv_imgproc341.lib")
#pragma  comment(lib, "opencv_calib3d341.lib")
#endif
namespace lin {
	//---------------------输出结构体-----------------------------
	struct img_detected_output {
		//0-OK,1-NG
		int status;
		cv::Mat imgOriginal;
		cv::Mat imgDisplayRect;
	};
	//-----------------导出接口函数-------方式1：提供类对象的创建和管理----------
	DETECT_API bool createInstance(void **handel);
	DETECT_API bool releaseInstance(void *handel);
	DETECT_API bool showRect(void *handel, const cv::Mat& img, lin::img_detected_output& cellImgDetected);
	DETECT_API bool calcPerimeter(void *handel,int width,int height,int& result);
}
#endif

