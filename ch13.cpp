#include "stdafx.h"
#include "ch13.h"

int fun3() {
	Simple_window win(Point(100, 100), 600, 400, "two lines");
	Line horizontal(Point(100, 100), Point(200, 100));
	Line vertical(Point(150, 50), Point(150, 150));

	win.attach(horizontal); // attach the lines to the window
	win.attach(vertical);

	win.wait_for_button();

	return 0;
}

int fun4() {
	Simple_window win(Point(100, 100), 600, 400, "grid");
	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Lines grid;
	for (int x = 0; x < x_size; x += x_grid)
	{
		grid.add(Point(x, 0), Point(x, y_size)); // vertical line
	}

	for (int y = 0; y < y_size; y += y_grid)
	{
		grid.add(Point(0, y), Point(x_size, y)); // horizontal line
	}

	grid.set_style(Line_style::dot);

	win.attach(grid);
	win.wait_for_button();

	return 0;
}

int fun5() {
	Simple_window win(Point(100, 100), 600, 400, "Open_polyline");

	Open_polyline opl;
	opl.add(Point(100, 100));
	opl.add(Point(150, 200));
	opl.add(Point(250, 250));
	opl.add(Point(300, 200));

	win.attach(opl);

	win.wait_for_button();

	return 0;
}