#include "InterDllPrj2.h"
#include "LMath2.h"

using namespace std;
using namespace cv;
namespace lin2 {
	//静态全局对象，由dll自己管理
	static LMath2* g_pMath = nullptr;
	//初始化创建全局对象，这里可以传入参数
	bool init(string str="bbb")
	{
		if (g_pMath==nullptr)
		{
			g_pMath = new LMath2();
			//g_pMath->setXXX(str);
		}
		return true;
	}

	//改变对象配置参数 
	bool setXXX(string str)
	{
		if (g_pMath == nullptr)
			return false;
		//g_pMath->setXXX(str);
	}

	bool showRect(const Mat & img, img_detected_output & cellImgDetected)
	{
		if (g_pMath == nullptr)
			init();
		if (g_pMath == nullptr)
			return false;
		Mat matOriginal = img.clone();
		g_pMath->showRect(img);
		cellImgDetected.status = 1;
		cellImgDetected.imgOriginal = matOriginal;
		cellImgDetected.imgDisplayRect = img;
		return true;
	}

	bool calcPerimeter( int width, int height, int &result)
	{
		if (g_pMath == nullptr)
			init();
		if (g_pMath == nullptr)
			return false;
		g_pMath->calcPerimeter(width, height, result);
		return true;
	}

}
