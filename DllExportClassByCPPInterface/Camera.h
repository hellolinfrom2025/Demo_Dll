#pragma once
#ifndef Camera_h__
#define Camera_h__
#include <memory>

#ifdef DLLEXPORTCLASSBYCPPINTERFACE_EXPORTS
#  define DLL_API __declspec(dllexport)
#else
#  define DLL_API __declspec(dllimport)
#endif
#define LAPI __stdcall

namespace Device
{
	enum class eCameraManufacturer
	{
		kNull = 0,
		kHikvision,
		kBasler
	};

	//定义接口类纯虚函数
	class ICamera
	{
	public:
		virtual~ICamera() = default;
		virtual bool Init(const int id) = 0;
		virtual bool Open() = 0;
		virtual bool Close() = 0;
	};

	//简单工厂函数，用于创建对象
	DLL_API std::shared_ptr<ICamera> LAPI
		CreateCamera(const eCameraManufacturer &manufacturer);
}

#endif // Camera_h__