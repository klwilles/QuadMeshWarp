#ifndef _IMAGE_SPLITTER
#define _IMAGE_SPLITTER
/*
 *  imageSplitter.h
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

#include "ofMain.h"
#include "ofxFBOTexture.h"
#include "warpDraw.h"
#include "gridGui.h"

class imageSplitter {
public:

	imageSplitter();
	~imageSplitter();

	void setup(int _num_screens, int _w, int _h);

	void initializePoints();
	void movePoints(float _x_inc, float _y_inc);

	void keyEventHandler(int key);

	void guiOnOff();

	void beginDraw();
	void endDraw();
	void draw();

	void setupTexture();
	void cleanUpTexture();

	void setCurrentScreen(int _s);
	void nextPoint();
	void previousPoint();
	void saveCurrentScreen();

	//ofPoint ** points;//screens, texture and quad points, point value
	vector<ofPoint> points;
	vector< vector<ofPoint> > point_collection;
	int current_screen;

	//gridGui gui1;
//	gridGui gui2;
//	gridGui gui3;
//	gridGui gui4;

	vector<gridGui *> guis;


	ofxFBOTexture texture;


private:


	int total_width, total_height;
	int num_screens;
	bool screensDisabled;
};

#endif

