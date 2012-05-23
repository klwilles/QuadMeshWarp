#ifndef SLIDERINT_H_INCLUDED
#define SLIDERINT_H_INCLUDED

/*
 *  SliderInt.h
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

class SliderInt {
    public:
        SliderInt(){
            min = 1;
            val = 2;
            max = 3;
        }
        SliderInt(int _min, int _val, int _max){
            min = _min;
            val = _val;
            max = _max;
        }
        virtual ~SliderInt(){}
        int min;
        int val;
        int max;
};

#endif // SLIDERINT_H_INCLUDED