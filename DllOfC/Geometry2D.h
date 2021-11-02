#pragma once
#include <stdint.h>

#ifdef DLLOFC_EXPORTS
#  define DLL_API __declspec(dllexport)
#else
#  ifdef __cplusplus
#    define DLL_API extern "C" __declspec(dllimport)
#  else
#    define DLL_API __declspec(dllimport)
#  endif
#endif
#define LAPI __stdcall
#define IN
#define OUT

#define STATUS	uint32_t
#define STATUS_OK									0x0000
#define STATUS_INVALID_PARAM						0x0001	

typedef struct sPoint2d
{
	double x;
	double y;
}Point2d;

DLL_API STATUS LAPI
PointAddPoint(IN const Point2d p1,IN const Point2d p2,OUT Point2d *p3);
