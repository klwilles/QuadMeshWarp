/*
 *  testApp.h
 *  quadMeshWarp
 *
 *  Created on 3/4/11 by Kenneth Willes
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

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){



    ofHideCursor();

	ofSetWindowTitle("Quad Mesh Warp");

	ofSetVerticalSync(true); // lock into vertical refresh rate ~ 60 Hz

	ofSetBackgroundAuto(true);



    //Warping

    splitter.setup(4, ofGetWidth(), ofGetHeight());

    testImage.loadImage("greenhills.jpg");



    ofBackground(0,0,0);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    splitter.beginDraw();
    testImage.draw(0,0, ofGetWidth(), ofGetHeight());

    splitter.endDraw();



    glEnable(GL_BLEND);

	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

	glBlendEquation(GL_FUNC_ADD);

    glEnable(GL_DEPTH_TEST);



    splitter.draw();



    glDisable(GL_DEPTH_TEST);

    glDisable(GL_BLEND);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    splitter.keyEventHandler(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

