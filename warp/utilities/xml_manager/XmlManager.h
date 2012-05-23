#ifndef XMLMANAGER_H_INCLUDED
#define XMLMANAGER_H_INCLUDED

/*
 *  XmlManager.h
 *  wallofSpirituality
 *
 *  Created by Kenneth Willes on 5/21/10.
 *  Copyright 2010 Southern Adventist University. All rights reserved.

    This class assumes some things about how your xml is structured

    boolean                     int                     float
    <root>                      <root>                      <root>
        <tag>                       <tag>                       <tag>
            <val>                       <val>                       <val>

    string
    <root>
        <tag>
            <val>

    SliderInt                    SliderFloat            ofRectangle
    <root>                       <root>                       <root>
        <tag>                        <tag>                      <tag>
            <min>                       <min>                       <x>
            <val>                       <val>                       <y>
            <max>                       <max>                       <width>
                                                                    <height>

    --------------------------------------------------------------------------
    That's it, don't do anything more complicated ;)

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
#include "ofxXmlSettings.h"
#include "ProgramStatusLogger.h"
#include "SliderFloat.h"
#include "SliderInt.h"

class XmlManager {

    public:

        XmlManager();
        bool load(string _filename, string _root);
        void save(); // nothing gets saved to xml until this is called

//      void setPointerFromXMLTag(int * pointer, const string & tag);
//      void setPointerFromXMLTag(float * pointer, const string & tag);
        void setPropertyFromXMLTag(bool & property, const string & tag);
        void setPropertyFromXMLTag(int & property, const string & tag);
        void setPropertyFromXMLTag(float & property, const string & tag);
        void setPropertyFromXMLTag(string & property, const string & tag);
        void setPropertyFromXMLTag(ofRectangle & property, const string & tag);
        void setPropertyFromXMLTag(SliderInt & property, const string & tag);
        void setPropertyFromXMLTag(SliderFloat & property, const string & tag);

//      void setXMLTagFromPointer(const string & tag, int * pointer);
//      void setXMLTagFromPointer(const string & tag, float * pointer);
        void setXMLTagFromProperty(const string & tag, bool & property);
        void setXMLTagFromProperty(const string & tag, int & property);
        void setXMLTagFromProperty(const string & tag, float & property);
        void setXMLTagFromProperty(const string & tag, string & property);
        void setXMLTagFromProperty(const string & tag, ofRectangle & property);
        void setXMLTagFromProperty(const string & tag, SliderInt & property);
        void setXMLTagFromProperty(const string & tag, SliderFloat & property);

    private:

        ofxXmlSettings xml;
        bool setRootLevel(string _root);

        bool loaded;
        string filename;
        string root;

        void pushXMLError(const string & tag);
        void loadXMLError(const string & tag);

};

#endif // XMLMANAGER_H_INCLUDED
