#include "InterDllPrj.h"
#include "LMath.h"

using namespace std;
using namespace cv;
namespace lin {

	bool createInstance(void **handel)
	{
		LMath* pMath = new LMath();
		*handel = pMath;
		return true;
	}

	bool releaseInstance(void *handel)
	{
		if (handel == nullptr)
			return false;
		delete handel;
		handel = nullptr;
		return true;
	}
	bool showRect(void * handel, const Mat & img, img_detected_output & cellImgDetected)
	{
		if (handel == nullptr)
			return false;
		LMath* pMath =static_cast<LMath*>(handel);
		Mat matOriginal = img.clone();
		pMath->showRect(img);
		cellImgDetected.status = 1;
		cellImgDetected.imgOriginal = matOriginal;
		cellImgDetected.imgDisplayRect = img;
		return true;
	}

	bool calcPerimeter(void *handel, int width, int height, int &result)
	{
		if (handel == nullptr)
			return false;
		LMath* pMath = static_cast<LMath*>(handel);
		pMath->calcPerimeter(width, height, result);
		return true;
	}

}
