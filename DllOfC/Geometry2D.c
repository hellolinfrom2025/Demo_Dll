#include "Geometry2D.h"

DLL_API STATUS LAPI
PointAddPoint(IN const Point2d p1, IN const Point2d p2, OUT Point2d *p3)
{
	if (p3==NULL) {
		return STATUS_INVALID_PARAM;
	}

	p3->x = p1.x + p2.x;
	p3->y = p1.y + p2.y;
	return  STATUS_OK;
}
