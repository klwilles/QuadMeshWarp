#ifndef _PROGRAM_STATUS_LOGGER
#define _PROGRAM_STATUS_LOGGER

/*
 *  ProgramStatusLogger.h
 *  wallofSpirituality
 *
 *  Created by Kenneth Willes on 5/10/10.
 *  Copyright 2010 Southern Adventist University. All rights reserved.
 *

	Depends on ofLogLevel enum
	Set logging filter in the implementation.

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

 */

#include "ofMain.h"
#include <fstream>
//using namespace std;

class ProgramStatusLogger {

	public:
		static void record(string message);
		static void record(string message, ofLogLevel log_level);

	private:

		static void record(string message, ofLogLevel log_level, bool show_console_output, bool write_to_file);
		static void outputToConsole(string str);
		static void writeToFile(string str);

};

#endif
