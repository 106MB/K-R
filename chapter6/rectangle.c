// Creating points and rectangles using structs
#include <stdio.h>
#include <stdlib.h>

struct point {
	int x;
	int y
};
struct rect {
	struct point pt1;
	struct point pt2;
};

struct point makepoint(int x, int y);

int main(void){

}

// Make a point from x and y input
// Return point struct
struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

