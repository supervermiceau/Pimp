#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
//----------------------------------------------------------------------
#include <wx/colour.h>
//----------------------------------------------------------------------
typedef struct 
{
	float x;	
	float y;	
} point;
//----------------------------------------------------------------------

// Define a new triangle class
class Triangle
{
public:
	point p1;
	point p2;
	point p3;

	const wxColour *colour;

	float thickness;
	int ComputeZCoordinate(point P1, point P2, int x, int y);
	bool IsPointInTriangle(int x, int y);
};
//----------------------------------------------------------------------
#endif // #ifndef __TRIANGLE_H__


