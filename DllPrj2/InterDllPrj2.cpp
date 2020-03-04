#include "InterDllPrj2.h"
#include "LMath2.h"

using namespace std;
using namespace cv;
namespace lin2 {
	//��̬ȫ�ֶ�����dll�Լ�����
	static LMath2* g_pMath = nullptr;
	//��ʼ������ȫ�ֶ���������Դ������
	bool init(string str="bbb")
	{
		if (g_pMath==nullptr)
		{
			g_pMath = new LMath2();
			//g_pMath->setXXX(str);
		}
		return true;
	}

	//�ı�������ò��� 
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
