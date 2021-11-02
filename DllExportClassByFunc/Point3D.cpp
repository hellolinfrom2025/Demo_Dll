#include "pch.h"
#include "Point3D.h"
#include "CPoint3D.h"

namespace Point3D
{

	DLL_API CPoint3D* LAPI
		GetObj()
	{
		return new CPoint3D();
	}
	DLL_API double LAPI
		DllDetect(IN  CPoint3D* const pPoint3D, IN const double x, IN const double y, IN const double z)
	{
		if (pPoint3D == nullptr) {
			return 0.0;
		}
		return pPoint3D->Detect(x, y, z);
	}
	DLL_API bool LAPI
		ReleaseObj(IN  CPoint3D *pPoint3D)
	{
		if (pPoint3D) {
			delete pPoint3D;
			pPoint3D = nullptr;
		}
		return true;
	}
}
