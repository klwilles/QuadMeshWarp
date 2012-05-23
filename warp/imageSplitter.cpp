/*
 *  imageSplitter.cpp
 *  emptyExample
 *
 *  Created by Ben Norskov on 6/14/10.
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

#include "imageSplitter.h"

imageSplitter::imageSplitter(){ }

void imageSplitter::setup(int _num_screens, int _w, int _h) {

	screensDisabled = true;
	current_screen = 0;
	num_screens = _num_screens;
	total_width = _w;
	total_height = _h;
	ofSetDataPathRoot("data/");
	texture.allocate(total_width, total_height, true);

	for (int i=0; i<num_screens; i++) {

		gridGui * gui = new gridGui("meshPos" + ofToString(i) + ".xml");

		guis.push_back(gui);

		//points[i] = new ofPoint[4];

		for (int j=0; j<4; j++) {
			// helps to put texture coords in a certain order
			float text_corner_x = (j % 2 == 1) ? 1.0/num_screens * (float)(i + 1) : (float)i/num_screens;
			float text_corner_y = (j >= 2 ) ? 0 : 1;
			/*
			 0 = 0,h; 0,0
			 1 = 0,0; 0,1
			 2 = w,0; 1,1
			 3 = w,h; 1,0
			 */
			points.push_back(ofPoint(text_corner_x, text_corner_y));
			//points[i][j].set(text_corner_x, text_corner_y);
			//{ { {x1, y1} {x2, y2} }, { {x3, y3}, {x4, y4} } }
			//{ {0, 1}, {1, 1} },	{ {0, 0}, {1, 0} }
			//{ {0, 1}, {.5, 1} },	{ {0, 0}, {.5, 0} }
		}
		point_collection.push_back(points);
		points.clear();
	}
}

imageSplitter::~imageSplitter(){
	vector<gridGui *>::iterator it;
	for(it=guis.begin(); it!=guis.end(); ++it){
		delete *it;
	}
	guis.clear();
}

//-------------------------------------------------------------- GUI
void imageSplitter::guiOnOff() {
	if (guis[current_screen]->drawGui) {
		guis[current_screen]->drawGui =  false;
	} else {
		guis[current_screen]->drawGui =  true;
		screensDisabled = false;
	}
}



void imageSplitter::keyEventHandler(int key){

    switch(key){

        case OF_KEY_RIGHT:
            movePoints(1, 0);
            break;
        case OF_KEY_LEFT:
            movePoints(-1, 0);
            break;
        case OF_KEY_UP:
            movePoints(0, -1);
            break;
        case OF_KEY_DOWN:
            movePoints(0, 1);
            break;
        case '0':
            setCurrentScreen(-1); // this -1 calls another method that turns it off
            break;
        case '1':
            setCurrentScreen(0);
            break;
        case '2':
            setCurrentScreen(1);
            break;
        case '3':
            setCurrentScreen(2);
            break;
        case '4':
            setCurrentScreen(3);
            break;
        case '+':
            nextPoint();
            break;
        case '-':
            previousPoint();
            break;
        case 'S':
            cout << "save pressed" << endl;
            //s == width and height of mesh
            saveCurrentScreen();
            break;
        case 'p':
            //p == x and y position of mesn
            setCurrentScreen(100);
            break;

    }

}

//-------------------------------------------------------------- POINT SELECTION
void imageSplitter::setCurrentScreen(int _s) {
	if (_s > 99) {//100 is reserved for moving the entire mesh
		guis[current_screen]->selectPoint(_s);
	} else if (_s == -1) {
		if (screensDisabled != true) {
			guiOnOff();
			screensDisabled = true;
		}
	}else if(_s<=num_screens) {
		if(guis[current_screen]->drawGui) {
			guiOnOff();
		}
		current_screen = _s;
		guiOnOff();
		guis[current_screen]->nextPoint();
		//throws an error if we don't select a point
	} else {
		printf("setCurrentScreen out of bounds %i", _s);
	}
}

//-------------------------------------------------------------- NEXT POINT
void imageSplitter::nextPoint() {
	if ((!screensDisabled) && (current_screen <= num_screens)){
		guis[current_screen]->nextPoint();
	}
}

//-------------------------------------------------------------- LAST POINT
void imageSplitter::previousPoint() {
	if ((!screensDisabled) && (current_screen <= num_screens)){
		guis[current_screen]->previousPoint();
	}
}


//-------------------------------------------------------------- MOVE POINTS/MESH
void imageSplitter::movePoints(float _x_inc, float _y_inc) {
	// need to revisit
	if (( !screensDisabled ) && (guis[current_screen]->current_point > -1) && (guis[current_screen]->current_point <= 99)) {
		guis[current_screen]->movePoint(_x_inc, _y_inc);
	} else if (guis[current_screen]->current_point == 100) {
		guis[current_screen]->moveMesh(_x_inc, _y_inc);
	}
}

//--------------------------------------------------------------
void imageSplitter::saveCurrentScreen() {
	guis[current_screen]->save();
}

//-------------------------------------------------------------- FBO DRAWS
void imageSplitter::beginDraw() {
	texture.begin();
}

//--------------------------------------------------------------
void imageSplitter::endDraw() {
	texture.end();
}

//--------------------------------------------------------------  DRAW
void imageSplitter::draw() {



	for (int i=0; i < num_screens; i++) {
		for (int j=0; j<4; j++) {
			guis[i]->mesh.viewer.setTextPoint(j/2, j%2, 0, point_collection[i][j].x);
			guis[i]->mesh.viewer.setTextPoint(j/2, j%2, 1, point_collection[i][j].y);
		}
		guis[i]->mesh.viewer.updateTexture();

		if (guis[i]->drawGui) guis[i]->drawCtrlPoints();

		setupTexture();

		guis[i]->draw();

		cleanUpTexture();

	}
	/*
	glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glLoadIdentity();

	texture.bind();

    ofTextureData texData = texture.getTextureData();
    if(texData.textureTarget == GL_TEXTURE_RECTANGLE_ARB) {
        glScalef(texture.getWidth(), texture.getHeight(), 1.0f);
    } else {
        glScalef(texture.getWidth() / texData.tex_w, texture.getHeight() / texData.tex_h, 1.0f);
    }
	glMatrixMode(GL_MODELVIEW);

	*for (int i = 1; i<3; i++) {
	 glBegin(GL_QUADS);

	 glTexCoord2f( 0, 0 );//grid[pt0].x, grid[pt0].y);
	 glVertex2f(20, 520);//coor[pt0].x, coor[pt0].y );

	 glTexCoord2f( 0, 1 );//grid[pt1].x, grid[pt1].y);
	 glVertex2f(20, 20);//coor[pt1].x, coor[pt1].y );

	 glTexCoord2f( .5 * i, 1 );//grid[pt2].x, grid[pt2].y);
	 glVertex2f(410 * i, 20);//coor[pt2].x, coor[pt2].y );

	 glTexCoord2f( .5 * i, 0 );//grid[pt3].x, grid[pt3].y);
	 glVertex2f(410 * i, 520);//coor[pt3].x, coor[pt3].y );

	 glEnd();
	 }*
	for (int i = 0; i< num_screens; i++) {
		glBegin(GL_QUADS);
		for (int j=0; j<4; j++) {
			//map the meshes unique texture points
			glTexCoord2f( points[i][j].x, points[i][j].y);//grid[pt1].x, grid[pt1].y);
			glVertex2f(points[i][1][j].x, points[i][1][j].y);//coor[pt1].x, coor[pt1].y );
			//cout << points[i][j].y << " " << points[i][j].x << " " << i << " " << j << endl;
		}
		meshes[i].draw();
		glEnd();
	}
	texture.unbind();
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
//	texture.draw(200, 200, 1200, 1200);
	 */
}

//-------------------------------------------------------------- TEXTURE DRAW STUFF
void imageSplitter::setupTexture() {

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	texture.bind();

	ofTextureData texData = texture.getTextureData();
	if(texData.textureTarget == GL_TEXTURE_RECTANGLE_ARB) {
		glScalef(texture.getWidth(), texture.getHeight(), 1.0f);
	} else {
		glScalef(texture.getWidth() / texData.tex_w, texture.getHeight() / texData.tex_h, 1.0f);
	}

	glMatrixMode(GL_MODELVIEW);
}

void imageSplitter::cleanUpTexture() {
	texture.unbind();
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();// texture scale pop matrix

	glMatrixMode(GL_MODELVIEW);
}

