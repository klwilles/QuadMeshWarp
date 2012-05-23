/*
 *  warpDraw.cpp
 *  myTexture
 *
 *  Created by Ben Norskov on 6/4/10.
 *  Copyright 2010 Southern Adventist University. All rights reserved.
 *
 *	EDITED on 6/14/10 for image Splitter

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
#include "warpDraw.h"

GLfloat ctrlpoints[4][4][3] = {
{	{0, 0, 0},			{341, 0, 0},	{683, 0, 0},	{1024, 0, 0}	},
{	{0, 284, 0},		{341, 284, 0},	{683, 284, 0},	{1024, 284, 0}	},
{	{0, 484, 0},		{341, 484, 0},	{683, 484, 0},	{1024, 484, 0}	},
{	{0, 768, 0},		{341, 768, 0},	{683, 768, 0},	{1024, 768, 0}	}
};
/* screen coords nOTeS:
 1024 x 768
 X values:
 1024/3 ~= 341
 1024-341 = 683

 Y values:
 768/3 = 284
 768-284 = 484
 */
GLfloat texpts [2][2][2] = {
{ {0, 1}, {.5, 1} },	{ {0, 0}, {.5, 0} }
};


warpDraw::warpDraw() {

	x_image = 120;
	y_image = 18;
	w_image = 836;
	h_image = 976;

	glEnable(GL_DEPTH_TEST);
	updateMesh();
	updateTexture();
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_AUTO_NORMAL);
	glMapGrid2f(20, 0, 1, 20, 0, 1);
	glShadeModel(GL_FLAT);

}

void warpDraw::draw() {
	renderMesh();
}

//-----------------------------------------------------

void warpDraw::renderMesh() {
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
}

//-----------------------------------------------------
void warpDraw::updateMesh() {
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
}
//-----------------------------------------------------
void warpDraw::updateTexture() {
	glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2, 0, 1, 4, 2, &texpts[0][0][0]);
}

//-----------------------------------------------------
void warpDraw::setPoint(int _x, int _y, int _z, GLfloat _val) {
	ctrlpoints[_x][_y][_z] = _val;
}

//-----------------------------------------------------
void warpDraw::setTextPoint(int _x, int _y, int _z, GLfloat _val) {
	texpts[_x][_y][_z] = _val;
}

//-----------------------------------------------------
void warpDraw::printLocation() {
	cout << "image x, y, w, h " << x_image << ", " << y_image << ", " << w_image << ", " << h_image << endl;
}
