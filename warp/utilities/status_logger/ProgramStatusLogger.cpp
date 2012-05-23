/*
 *  ProgramStatusLogger.cpp
 *  wallofSpirituality
 *
 *  Created by Kenneth Willes on 5/10/10.
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

#include "ProgramStatusLogger.h"

// public

void ProgramStatusLogger::record(string message){
	record(message, OF_LOG_NOTICE);
}

void ProgramStatusLogger::record(string message, ofLogLevel log_level){
	record(message, log_level, true, true);
}

// private

void ProgramStatusLogger::record(string message, ofLogLevel log_level, bool show_console_output, bool write_to_file){

	// to filter out what messages get output to the console
	// and written to log.txt, then set the enum prop here.

	// possible enum values are
	// OF_LOG_VERBOSE, -- For describing what is happening in program flow
	// OF_LOG_NOTICE, -- Something important happened
	// OF_LOG_WARNING, -- This means that this shouldn't be doing this but it can still hop along
	// OF_LOG_ERROR, -- This did something bad
	// OF_LOG_FATAL_ERROR, -- This is crashing, freezing, blue screen of death
	// OF_LOG_SILENT -- This is for the filter to prevent recording

	// OF_LOG_SILENT doesn't show anything, OF_LOG_VERBOSE shows everything.

	ofLogLevel filter = OF_LOG_NOTICE;

	//////////////////////////////////

	string log("\n");

	log += "------------------------------------\n";
	// Get YEAR/MONTH/DAY
	log += ofToString(ofGetYear(), 0)+"/"+ofToString(ofGetMonth(), 0)+"/"+ofToString(ofGetDay(), 0)+" ";
	log += ofToString(ofGetHours(), 0)+":"+ofToString(ofGetMinutes(), 0)+":"+ofToString(ofGetSeconds(), 0)+" ";

	if(log_level >= filter){

		if(log_level == OF_LOG_VERBOSE){

			log += "- OF_VERBOSE\n";
			log += message + "\n";

			if(show_console_output==true){
				outputToConsole(log);
			}
			if(write_to_file==true){
				writeToFile(log);
			}

		}

		else if(log_level == OF_LOG_NOTICE){

			log += "- OF_NOTICE\n";
			log += message + "\n";

			if(show_console_output==true){
				outputToConsole(log);
			}
			if(write_to_file==true){
				writeToFile(log);
			}

		}
		else if(log_level == OF_LOG_WARNING){

			log += "- OF_WARNING\n";
			log += message + "\n";

			if(show_console_output==true){
				outputToConsole(log);
			}
			if(write_to_file==true){
				writeToFile(log);
			}

		}
		else if(log_level == OF_LOG_ERROR){
			log += "- OF_ERROR\n";
			log += message + "\n";

			if(show_console_output==true){
				outputToConsole(log);
			}
			if(write_to_file==true){
				writeToFile(log);
			}

		}
		else if(log_level == OF_LOG_FATAL_ERROR){

			log += "- OF_FATAL_ERROR\n";
			log += message + "\n";

			if(show_console_output==true){
				outputToConsole(log);
			}
			if(write_to_file==true){
				writeToFile(log);
			}

		}
	}


}

void ProgramStatusLogger::outputToConsole(string str){
	cout << str << endl;
}

void ProgramStatusLogger::writeToFile(string str){

	/*	Would like to write to database instead so that this doesn't lock up
		from to many things accessing it at once. Also would be nice to check
		a website as to the status of things.
	 */

	ofSetDataPathRoot("./data/");
	string filepath = ofToDataPath("log.txt");

	std::ofstream fout(filepath.c_str(), ios::out | ios::app);

	if (fout.is_open()) {
		fout << str << endl;
		fout.close();
	} else {
		outputToConsole("WARNING: could not open log file\n");
	}

}
