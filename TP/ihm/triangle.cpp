#include "triangle.h"
//----------------------------------------------------------------------
int Triangle::ComputeZCoordinate(point P1, point P2, int x, int y) 
{
    return P1.x * (P2.y - y) + P2.x * (y - P1.y) + x * (P1.y - P2.y);
}
//----------------------------------------------------------------------
bool Triangle::IsPointInTriangle(int x, int y)
{
    int z1 = ComputeZCoordinate(p1, p2, x, y);
    int z2 = ComputeZCoordinate(p2, p3, x, y);
    int z3 = ComputeZCoordinate(p3, p1, x, y);

    return (z1 > 0 && z2 > 0 && z3 > 0) || (z1 < 0 && z2 < 0 && z3 < 0);
}
//----------------------------------------------------------------------
