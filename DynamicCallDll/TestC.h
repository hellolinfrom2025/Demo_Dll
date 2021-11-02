#pragma once
#include <stdint.h>

#ifdef __cplusplus
#  ifdef DLLOFC_EXPORTS
#    define GEOMETRY2D_API extern "C" 
#  else
#    define GEOMETRY2D_API extern "C" 
#  endif
#  define IKAPC_CC
#else
#  ifdef DLLOFC_EXPORTS
#    define GEOMETRY2D_API 
#  else
#    define GEOMETRY2D_API
#  endif
#  define IKAPC_CC __cdecl
# endif

#define STATUS	uint32_t
#define STATUS_OK									0x0000
#define STATUS_INVALID_PARAM						0x0001	

typedef struct sPoint2d
{
	double x;
	double y;
}Point2d;

GEOMETRY2D_API STATUS IKAPC_CC
PointAddPoint(const Point2d p1, const Point2d p2, Point2d *p3);
