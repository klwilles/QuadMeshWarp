#ifndef _MESH_HOLDER
#define _MESH_HOLDER
/*
 *  meshHolder.h
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
#include "warpDraw.h"
#include "XmlManagerWarper.h"

class meshHolder {

	public :

	meshHolder(string _xml);

	vector<GLfloat> * edit_point;

	vector<GLfloat> current_point; //3 values
	vector<GLfloat>::iterator it1;

	vector< vector<GLfloat> > current_column; //4 values of 3 values
	vector< vector<GLfloat> >::iterator it2;

	vector< vector< vector<GLfloat> > > entire_mesh; //4 of 4 of 3 values
	vector< vector< vector<GLfloat> > >::iterator it3;

	int current_point_number;
	void updateCurrentPoint(int _x, int _y);
	void moveMesh(float _x, float _y);

	//void meshHolder::updateImageDraw(int _s, int _t) {

	void printPoints();
	void setCurrentPoint(int _point);
	void synchronizeMesh();

	void setMeshPoints();
	void saveMeshPoints();

	warpDraw viewer;

	XmlManagerWarper xml;

private:
	string xml_file_name;

};

#endif

