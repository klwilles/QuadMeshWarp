#ifndef SLIDERFLOAT_H_INCLUDED
#define SLIDERFLOAT_H_INCLUDED

/*
 *  SliderFloat.h
 *  wallofSpirituality
 *
 *  Created by Kenneth Willes on 5/22/10.
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

class SliderFloat {
    public:
        SliderFloat(){
            min = 1.0;
            val = 2.0;
            max = 3.0;
        }
        SliderFloat(float _min, float _val, float _max){
            min = _min;
            val = _val;
            max = _max;
        }
        virtual ~SliderFloat(){}
        float min;
        float val;
        float max;
};

#endif // SLIDERFLOAT_H_INCLUDED
