#ifndef _GRID_GUI
#define _GRID_GUI
/*
 *  squareGui.h
 *  myTexture
 *
 *  Created by Ben Norskov on 5/26/10.
 *  Copyright 2010 Southern Adventist University. All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

 *
 */

#include "ofMain.h"
#include "meshHolder.h"

class gridGui {

public:
	gridGui(string _xml);

	void draw();
	void selectPoint(int _point);
	void printPoints();

	void movePoint(int _x, int _y);
	void moveMesh(float _x, float _y);

	void drawCtrlPoints();

	void nextPoint();
	void previousPoint();
	void save();

	meshHolder mesh;

	bool drawGui;
	int current_point;

private:
	int circle_diameter;
};
#endif
