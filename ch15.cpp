#include "stdafx.h"
#include "ch15.h"

double one(double) { return 1; }

double slope(double x) { return x / 2; }

double square(double x) { return x*x; }

int fun6() {

	const int xmax = 600;
	const int ymax = 400;

	const int x_orig = xmax / 2;
	const int y_orig = ymax / 2;
	const Point orig(x_orig, y_orig);

	const int r_min = -10; // range [-10,11)
	const int r_max = 11;

	const int n_points = 400; // number of points used in range

	const int x_scale = 30; // scaling factors
	const int y_scale = 30;

	Simple_window win(Point(100, 100), xmax, ymax, "Function graphing");

	Function s(one, r_min, r_max, orig, n_points, x_scale,y_scale);
	Function s2(slope, r_min, r_max, orig, n_points, x_scale, y_scale);
	Function s3(square, r_min, r_max, orig, n_points, x_scale, y_scale);

	win.attach(s);
	win.attach(s2);
	win.attach(s3);

	Text ts(Point(100, y_orig - 40), "one");
	Text ts2(Point(100, y_orig + y_orig / 2 - 20), "x/2");
	Text ts3(Point(x_orig - 100, 20), "x*x");
	win.attach(ts);
	win.attach(ts2);
	win.attach(ts3);

	const int xlength = xmax - 40; // make the axis a bit smaller than the window
	const int ylength = ymax - 40;

	Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale, "one notch == 1");
	Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale, "one notch == 1");
	win.attach(x);
	win.attach(y);

	win.wait_for_button();

	return 0;
}