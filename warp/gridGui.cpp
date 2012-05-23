/*
 *  gridGui.cpp
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

#include "gridGui.h"

//--------------------------------------------------------------
gridGui::gridGui(string _xml):mesh(_xml) {
	circle_diameter = 3;
	drawGui = false;
}

//--------------------------------------------------------------
void gridGui::draw() {
	mesh.synchronizeMesh();
	mesh.viewer.draw();
}

//--------------------------------------------------------------
void gridGui::drawCtrlPoints(){
	int point_counter = 0;
	ofSetColor(0xff00ff);
	ofFill();
	///MESH HOLDER LOOP GOES HERE FOR EACH POINTS
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if (point_counter == mesh.current_point_number) {
				ofNoFill();
				ofCircle(mesh.entire_mesh[i][j][0], mesh.entire_mesh[i][j][1], circle_diameter + 3);
				ofFill();
			}
			ofCircle(mesh.entire_mesh[i][j][0], mesh.entire_mesh[i][j][1], circle_diameter);
			//we are only using 2 dimensions, so only x and y here
			point_counter++;
		}
	}
	ofSetColor(0xFFFFFF);
}


//--------------------------------------------------------------
void gridGui::movePoint(int _x, int _y){
	mesh.updateCurrentPoint(_x, _y);
}

//--------------------------------------------------------------
void gridGui::moveMesh(float _x, float _y){
	mesh.moveMesh(_x, _y);
}

//--------------------------------------------------------------
void gridGui::selectPoint(int _point){
	current_point = _point;
	mesh.setCurrentPoint(_point);
}

//--------------------------------------------------------------
void gridGui::save(){
	mesh.saveMeshPoints();
}

//--------------------------------------------------------------

void gridGui::printPoints() {
	int point_counter = 0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if (point_counter == mesh.current_point_number);
			cout << "--------------------------------------current" << endl;
			cout << "point number " << point_counter << " x, y: " << mesh.entire_mesh[i][j][0] << ", " << mesh.entire_mesh[i][j][1] << endl;
			point_counter++;
		}
	}
}

//--------------------------------------------------------------

void gridGui::nextPoint() {
	if (mesh.current_point_number >=15) {
		mesh.setCurrentPoint(0);
	}else{

	    printf("gridGui Next Point %i", mesh.current_point_number);
		mesh.setCurrentPoint(mesh.current_point_number + 1);
	}
	current_point = mesh.current_point_number;
}

void gridGui::previousPoint() {
	if ((mesh.current_point_number <= 0) || (mesh.current_point_number > 99)) {
		mesh.setCurrentPoint(15);
	}else{
		mesh.setCurrentPoint(mesh.current_point_number - 1);
	}
	current_point = mesh.current_point_number;
}

