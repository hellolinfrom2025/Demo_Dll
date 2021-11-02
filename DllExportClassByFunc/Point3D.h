#pragma once
#ifndef Point3D_h__
#define Point3D_h__

//ʹ��C���ĺ�����
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
	//ǰ������
	class CPoint3D;

	//������ȡ����ĺ���
	DLL_API CPoint3D* LAPI
		GetObj();

	//������Ҫ�����ĺ���
	DLL_API double LAPI
		DllDetect(IN  CPoint3D*const pPoint3D, IN const double x, IN const double y, IN const double z);

	//�ͷŶ�����
	DLL_API bool LAPI
		ReleaseObj(IN CPoint3D* pPoint3D);
}
#endif // Point3D_h__
