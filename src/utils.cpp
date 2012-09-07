/*
	LightCrawl 1.0
        Simple crawler to casually fetch web pages for text processing
        Author: Utkarsh Desai

        utils.cpp
*/

#include "utils.h"

/*
	Function: getLinesFromFile
	Reads lines from a file and stores them in a vector

	Arguments:
	inputFile - An ifstream object corresponding to the input file (reference)
	lines - A vector of string type to store the individual lines (reference)

	Returns: The input ifstream object

*/
std::ifstream& getLinesFromFile(std::ifstream& inputFile, std::vector<std::string>& lines)
{
	if(inputFile.is_open())
	{
		lines.clear();
	
		std::string singleLine;
		//Read in lines and insert in vector
		while(!inputFile.eof())
		{
			getline(inputFile, singleLine);
			if(!singleLine.empty())
				lines.push_back(singleLine);
		}
		inputFile.clear();
	}
	
	return inputFile;
}

/*
	Function printToLog
	Prints messages to a log file

	Arguments:
	outputFile- An ofstream object corresponding to the log file (reference)
	message- A string message to be output

	Returns: The input ofstream object
	TODO: implement the function
*/
std::ofstream& printToLog(std::ofstream& outputFile, std::string message)
{
	return outputFile;
}

