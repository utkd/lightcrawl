/*
	LightCrawl 1.0
        Simple crawler to casually fetch web pages for text processing
        Author: Utkarsh Desai

        utils.h
*/

#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::ifstream& getLinesFromFile(std::ifstream& inputFile, std::vector<std::string>& lines);
std::ofstream& printToLog(std::ofstream& outputFile, std::string message);

#endif
