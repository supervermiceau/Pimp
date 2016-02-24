#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

typedef struct 
{
	float x;	
	float y;	
} point;


// Define a new triangle class
class Triangle
{
public:
	point p1;
	point p2;
	point p3;

	const wxColour *colour;

	float thickness;
};

#endif // #ifndef __TRIANGLE_H__


