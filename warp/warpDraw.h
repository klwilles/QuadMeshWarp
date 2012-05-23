#ifndef _WARP_DRAW
#define _WARP_DRAW
/*
 *  warpDraw.h
 *  myTexture
 *
 *  Created by Ben Norskov on 6/4/10.
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
class warpDraw {
	public :
	warpDraw();
	void draw();
	void beginDrawFBO();
	void endDrawFBO();
	void renderMesh();

	void updateMesh();
	void updateTexture();
	void warpCurrentPoint(int _x, int _y);
	void setPoint(int _x, int _y, int _z, GLfloat _val);
	void setTextPoint(int _x, int _y, int _z, GLfloat _val);
	void printLocation();

	bool hasMeshChanged;

	int	x_image, y_image, w_image, h_image;

};
#endif

