// CPE 522 HW 6 Problem 1
// Matthew J. Touma
// 10/22/2021
//
// This program takes two command line arguments. The first, is the file
// to read text from. The second is the file to write text to.
//
// Sample invocation:
// ./myCopier input_text_file.txt output_text_file.txt
//
// After running the compiled program using the above format, output_text_tile.txt
// will contain the text from input_text_file.txt

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

// change this path to wherever the text file to read is stored.
#define input_filepath "/home/debian/CPE522/homeworks/hw_6/problem_1/"
// the output file will be saved to the same directory
#define output_filepath input_filepath

// main function
int main(int argc, char* argv[]){
	// print a blank line
	cout << endl;
	
	// make sure the user inputs the correct number of 
	// command line arguments.
	if(argc != 3){
		cout << "Incorrect input arguments" << endl;
		cout << "Usage is: ./myCopier fileToRead fileToWrite" << endl;
		return 2; // exit the program
	}
	
	// display the search path
	cout << "Looking for file in " << input_filepath << endl;
	cout << endl;
	
	// store the first command line argument as a variable for the input file
	string in_file_name = argv[1];
	// concatenate the input file name with the file path
	string file_to_open = input_filepath + in_file_name;
	// display the progress
	cout << "Opening " << in_file_name << endl;
	cout << endl;

	// store the second command line argument as a variable for the output file
	string out_file_name = argv[2];
	// concatenate the output file name with the file path
	string file_to_write = output_filepath + out_file_name;
	// display the progress
	cout << "Writing to " << out_file_name << " ..." << endl;
	cout << endl;
	
	// create the input file object
	fstream opened_file;
	// open the file in read mode
	opened_file.open(file_to_open, ios::in);

	// create the output file object
	fstream written_file;
	// open the file in write mode
	written_file.open(file_to_write, ios::out);

	// create a string called line which will store each line
	// from the input file
	string line;

	// get the input text line by line. Store each line into the line variable.
	while(getline(opened_file, line)){
		// write the line variable to the output file
		written_file << line << endl;
	}
	
	// when all the text has been read, close the files.
	written_file.close();
	opened_file.close();
	
	// display the progress
	cout << "done" << endl;
	cout << endl;

	return 0;
}
