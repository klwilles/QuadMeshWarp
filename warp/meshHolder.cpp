/*
 *  meshHolder.cpp
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

#include "meshHolder.h"

meshHolder::meshHolder(string _xml) {


	current_point_number = 0;
	xml_file_name = _xml;

//	for (it3=entire_mesh.begin(); it3!=entire_mesh.end(); ++it3) {
//		for (it2=it3->begin(); it2!=it3->end(); ++it2) {
//			for (it1=it2->begin(); it1!=it2->end(); ++it1) {
//				//entire_mesh[i][j][k] = 0;
//				*it1 = 0;
//			}
//		}
//	}

	setMeshPoints();
	synchronizeMesh();
}

//------------------------------------------------------------
void meshHolder::setCurrentPoint(int _point) {
	current_point_number = _point;
	/*
	0 = 0.0
	1 = 0.1

	4 = 1.0
	5 = 1.1
	 ...
	*/

	float fpoint = (float) _point;
	int x = (int)(fpoint*.25);

	int y = (int) ((int)fpoint % 4);

	printf("meshHolder::setCurrentPoint x %i, y %i, point %i", x, y, _point);
	if (current_point_number < 100){
		edit_point = &entire_mesh[x][y];

	}
	//cout << _point / 4 << _point % 4 << endl;
}

//------------------------------------------------------------
void meshHolder::updateCurrentPoint(int _x, int _y) {
	if (current_point_number < 100) {
		edit_point->at(0) += (GLfloat)_x;
		edit_point->at(1) += (GLfloat)_y;
		synchronizeMesh();
	}
}

//------------------------------------------------------------
void meshHolder::moveMesh(float _x, float _y) {
	vector<GLfloat> * _point;
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			_point = &entire_mesh[i][j];
			_point->at(0) += (GLfloat)_x;
			_point->at(1) += (GLfloat)_y;
		}
	}
	synchronizeMesh();
}

/*//------------------------------------------------------------
void meshHolder::updateImageDraw(int _s, int _t) {
	///
	if (current_point_number == 100) {
		//edit width / height;
		w_image += _s * -1;
		h_image += _t * -1;//it comes in backwards for scaling. up or right should be taller
	} else if (current_point_number == 101) {
		//edit x/y
		viewer.x_image += _s;
		viewer.y_image += _t;
	}
}*/

//------------------------------------------------------------
void meshHolder::synchronizeMesh(){
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			for (int k=0; k<3; k++) {
				viewer.setPoint(i, j, k, (GLfloat)entire_mesh[i][j][k]);
			}
		}
	}
	viewer.updateMesh();
}

void meshHolder::setMeshPoints() {
	//	ofSetDataPathRoot("/Users/bennorskov/Desktop/WALL/of_preRelease_v0061_osxSL_FAT/apps/MINE/myTexture/bin/data/");

	/*GLfloat ctrlpoints[4][4][3] = {
	 {	{0, 0, 0},			{341, 0, 0},	{683, 0, 0},	{1024, 0, 0}	},
	 {	{0, 284, 0},		{341, 284, 0},	{683, 284, 0},	{1024, 284, 0}	},
	 {	{0, 484, 0},		{341, 484, 0},	{683, 484, 0},	{1024, 484, 0}	},
	 {	{0, 768, 0},		{341, 768, 0},	{683, 768, 0},	{1024, 768, 0}	}
	 };*/

	// 1 set of columns

	xml.load(xml_file_name, "meshPos");
	// a {0, 0, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("a_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("a_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("a_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// b {341, 0, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("b_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("b_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("b_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// c {683, 0, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("c_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("c_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("c_z"));

	current_column.push_back(current_point);
	current_point.clear();

	//d {1024, 0, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("d_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("d_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("d_z"));

	current_column.push_back(current_point);
	current_point.clear();

	entire_mesh.push_back(current_column);
	current_column.clear();

	// 2nd set of columns----------------------------------------------------

	// e {0, 284, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("e_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("e_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("e_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// f {341, 284, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("f_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("f_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("f_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// g {683, 284, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("g_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("g_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("g_z"));

	current_column.push_back(current_point);
	current_point.clear();

	//h {1024, 284, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("h_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("h_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("h_z"));

	current_column.push_back(current_point);
	current_point.clear();

	entire_mesh.push_back(current_column);
	current_column.clear();

	// 3rd set of columns----------------------------------------------------

	// i {0, 484, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("i_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("i_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("i_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// j {341, 484, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("j_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("j_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("j_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// k {683, 484, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("k_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("k_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("k_z"));

	current_column.push_back(current_point);
	current_point.clear();

	//l {1024, 484, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("l_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("l_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("l_z"));

	current_column.push_back(current_point);
	current_point.clear();

	entire_mesh.push_back(current_column);
	current_column.clear();

	// 4th set of columns----------------------------------------------------

	// m {0, 768, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("m_x"));
	cout << xml.getFloatPropertyFromXMLTag("m_x") << endl;
	current_point.push_back(xml.getFloatPropertyFromXMLTag("m_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("m_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// n {341, 768, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("n_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("n_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("n_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// o {683, 768, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("o_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("o_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("o_z"));

	current_column.push_back(current_point);
	current_point.clear();

	// p {1024, 768, 0}
	current_point.push_back(xml.getFloatPropertyFromXMLTag("p_x"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("p_y"));
	current_point.push_back(xml.getFloatPropertyFromXMLTag("p_z"));

	current_column.push_back(current_point);
	current_point.clear();

	entire_mesh.push_back(current_column);
	current_column.clear();
}

void meshHolder::saveMeshPoints() {

	/*for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			for (int k=0; k<3; k++) {
				cout << "and mesh " << i << " " << j << " " << k << " " << entire_mesh[i][j][k] << endl;
			}
		}
	}*/
	ofSetDataPathRoot("data/");
	// -----------------------------------------------------------------------------------------ROW ONE-----------
	string tagName = "a_x";
	float val = (float)entire_mesh[0][0][0];xml.setXMLTagFromProperty(tagName, val);
	val = (float)entire_mesh[0][0][1];		xml.setXMLTagFromProperty("a_y", val);
    val = (float)entire_mesh[0][0][2];		xml.setXMLTagFromProperty("a_z", val);

    val = (float)entire_mesh[0][1][0];		xml.setXMLTagFromProperty("b_x", val);
    val = (float)entire_mesh[0][1][1];		xml.setXMLTagFromProperty("b_y", val);
    val = (float)entire_mesh[0][1][2];		xml.setXMLTagFromProperty("b_z", val);

	val = (float)entire_mesh[0][2][0];		xml.setXMLTagFromProperty("c_x", val);
    val = (float)entire_mesh[0][2][1];		xml.setXMLTagFromProperty("c_y", val);
    val = (float)entire_mesh[0][2][2];		xml.setXMLTagFromProperty("c_z", val);

	val = (float)entire_mesh[0][3][0];		xml.setXMLTagFromProperty("d_x", val);
    val = (float)entire_mesh[0][3][1];		xml.setXMLTagFromProperty("d_y", val);
    val = (float)entire_mesh[0][3][2];		xml.setXMLTagFromProperty("d_z", val);

	// -----------------------------------------------------------------------------------------ROW TWO-----------

	val = (float)entire_mesh[1][0][0];		xml.setXMLTagFromProperty("e_x", val);
    val = (float)entire_mesh[1][0][1];		xml.setXMLTagFromProperty("e_y", val);
    val = (float)entire_mesh[1][0][2];		xml.setXMLTagFromProperty("e_z", val);

	val = (float)entire_mesh[1][1][0];		xml.setXMLTagFromProperty("f_x", val);
    val = (float)entire_mesh[1][1][1];		xml.setXMLTagFromProperty("f_y", val);
    val = (float)entire_mesh[1][1][2];		xml.setXMLTagFromProperty("f_z", val);

	val = (float)entire_mesh[1][2][0];		xml.setXMLTagFromProperty("g_x", val);
    val = (float)entire_mesh[1][2][1];		xml.setXMLTagFromProperty("g_y", val);
    val = (float)entire_mesh[1][2][2];		xml.setXMLTagFromProperty("g_z", val);

	val = (float)entire_mesh[1][3][0];		xml.setXMLTagFromProperty("h_x", val);
    val = (float)entire_mesh[1][3][1];		xml.setXMLTagFromProperty("h_y", val);
    val = (float)entire_mesh[1][3][2];		xml.setXMLTagFromProperty("h_z", val);

	// -----------------------------------------------------------------------------------------ROW THREE-----------

	val = (float)entire_mesh[2][0][0];		xml.setXMLTagFromProperty("i_x", val);
    val = (float)entire_mesh[2][0][1];		xml.setXMLTagFromProperty("i_y", val);
    val = (float)entire_mesh[2][0][2];		xml.setXMLTagFromProperty("i_z", val);

	val = (float)entire_mesh[2][1][0];		xml.setXMLTagFromProperty("j_x", val);
    val = (float)entire_mesh[2][1][1];		xml.setXMLTagFromProperty("j_y", val);
    val = (float)entire_mesh[2][1][2];		xml.setXMLTagFromProperty("j_z", val);

	val = (float)entire_mesh[2][2][0];		xml.setXMLTagFromProperty("k_x", val);
    val = (float)entire_mesh[2][2][1];		xml.setXMLTagFromProperty("k_y", val);
    val = (float)entire_mesh[2][2][2];		xml.setXMLTagFromProperty("k_z", val);

	val = (float)entire_mesh[2][3][0];		xml.setXMLTagFromProperty("l_x", val);
    val = (float)entire_mesh[2][3][1];		xml.setXMLTagFromProperty("l_y", val);
    val = (float)entire_mesh[2][3][2];		xml.setXMLTagFromProperty("l_z", val);


	// -----------------------------------------------------------------------------------------ROW FOUR-----------

	val = (float)entire_mesh[3][0][0];		xml.setXMLTagFromProperty("m_x", val);
    val = (float)entire_mesh[3][0][1];		xml.setXMLTagFromProperty("m_y", val);
    val = (float)entire_mesh[3][0][2];		xml.setXMLTagFromProperty("m_z", val);

	val = (float)entire_mesh[3][1][0];		xml.setXMLTagFromProperty("n_x", val);
    val = (float)entire_mesh[3][1][1];		xml.setXMLTagFromProperty("n_y", val);
    val = (float)entire_mesh[3][1][2];		xml.setXMLTagFromProperty("n_z", val);

	val = (float)entire_mesh[3][2][0];		xml.setXMLTagFromProperty("o_x", val);
    val = (float)entire_mesh[3][2][1];		xml.setXMLTagFromProperty("o_y", val);
    val = (float)entire_mesh[3][2][2];		xml.setXMLTagFromProperty("o_z", val);

	val = (float)entire_mesh[3][3][0];		xml.setXMLTagFromProperty("p_x", val);
    val = (float)entire_mesh[3][3][1];		xml.setXMLTagFromProperty("p_y", val);
    val = (float)entire_mesh[3][3][2];		xml.setXMLTagFromProperty("p_z", val);

	xml.save();
}

