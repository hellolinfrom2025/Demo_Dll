#include "pch.h"
#include "Camera.h"
#include <iostream>

namespace Device
{
	class HikvisionCamera :public ICamera
	{
	public:
		virtual ~HikvisionCamera()override
		{
			std::cout << "~HikvisionCamera()" << std::endl;
		}

		virtual bool Init(const int id) override
		{
			std::cout <<"HikvisionCamera id:" <<id << std::endl;
			return true;
		}

		virtual bool Open() override
		{
			std::cout << "HikvisionCamera::Open()" << std::endl;
			return true;
		}

		virtual bool Close() override
		{
			std::cout << "HikvisionCamera::Close()" << std::endl;
			return true;
		}
	};

	class BaslerCamera :public ICamera
	{
	public:
		virtual ~BaslerCamera()override
		{
			std::cout << "~BaslerCamera()" << std::endl;
		}

		virtual bool Init(const int id) override
		{
			std::cout << "BaslerCamera id:" << id << std::endl;
			return true;
		}

		virtual bool Open() override
		{
			std::cout << "BaslerCamera::Open()" << std::endl;
			return true;
		}

		virtual bool Close() override
		{
			std::cout << "BaslerCamera::Close()" << std::endl;
			return true;
		}
	};

DLL_API std::shared_ptr<ICamera>LAPI 
CreateCamera(const eCameraManufacturer & manufacturer)
{
	switch (manufacturer) {
	case eCameraManufacturer::kHikvision:
	{
		return std::make_shared<HikvisionCamera>();
		break;
	}
	case eCameraManufacturer::kBasler:
	{
		return std::make_shared<BaslerCamera>();
		break;
	}
	default:
		return nullptr;
		break;
	}
}
}
