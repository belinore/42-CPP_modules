#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

// Determinant formula for calculating the area of a triangle 
// Area = | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) | / 2
Fixed area( Point const &a, Point const &b, Point const &c)
{
	Fixed result = (a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY())) / Fixed(2); 
	if (result < Fixed(0))
		result = result * Fixed(-1);
	return (result);
}

//bsp function to determine if point is inside triangle abc using area method
//Area(ABC) = Area(PBC) + Area(APC) + Area(ABP)
//If point is on edge or vertex (area of any sub-triangle is 0), return false
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "a is " << a << "\nb is " << b << "\nc is " << c << "\npoint is " << point << std::endl;
	Fixed area_abc = area(a, b, c);
	Fixed area_pbc = area(point, b, c);
	Fixed area_apc = area(a, point, c);
	Fixed area_abp = area(a, b, point);
	std::cout << "Area ABC: " << area_abc.toFloat()
	<< "\nArea PBC: " << area_pbc.toFloat()
	<< "\nArea APC: " << area_apc.toFloat()
	<< "\nArea ABP: " << area_abp.toFloat() << std::endl;
	Fixed sum = area_pbc + area_apc + area_abp;
	std::cout << "Sum of areas PBC + APC + ABP: " << sum.toFloat() << std::endl;
	if (area_pbc == 0 || area_apc == 0 || area_abp == 0)
    	return false;
	if (area_abc != area_pbc + area_apc + area_abp)
		return (false);
	return (true);
}