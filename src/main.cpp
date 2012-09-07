/*
	LightCrawl 1.0
	Simple crawler to casually fetch web pages for text processing
	Author: Utkarsh Desai

	main.cpp
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "utils.h"
#include "controller.h"

#define DEBUG 1


/*
	main function
	Arguments Required:
	1. File containing seed URLs

	Optional Arguments:
	1. Number of threads (-t <num>) : Default 2
	2. Number of pages to fetch (-n <num>) : Default 100
	3. Set of Domains to ignore (-i) <file> : Default domains.set
	4. Delay between fetch requests (-d <num>) : Default 1000ms
	5. Save Queue for reuse? (-s) : Default no
	6. File types to ignore (-x <file>) : Default skiptype.set
*/

int main(int argc, char** argv)
{
	const char* USAGE_STRING = "Usage: lightcrawl <seedfile> <options>\nCheck README.txt for more details on options\n";
	
	if(argc < 2){
		std::cout << "Insufficient arguments. " << USAGE_STRING << std::endl;
		return 1;
	}
	
	//Get the seeds file	
	std::string seedsFile(argv[1]);

	std::cout << "Using seed file: " << seedsFile << std::endl;

	//Set default values for optional arguments
	int numThreads = 2;
	int fetchLimit = 100;
	int fetchDelay = 1000;
	bool queueReuse = false;
	std::string ignoredDomainsFile = "../resources/domains.set";
	std::string ignoredTypesFile = "../resources/skiptype.set";

	//Load optional arguments if specified
	if(argc > 2)
	{
		for(int option = 2; option < argc; option++)
		{
			if(argv[option][0] == '-')
			{
				//Decide what to do based on option specified
				switch(argv[option][1])
				{
					case 't':
						numThreads = atoi(argv[++option]);	//TODO: validate option
						break;
					case 'n':
						fetchLimit = atoi(argv[++option]);
						break;
					case 'i':
						ignoredDomainsFile = argv[++option];
						break;
					case 'd':
						fetchDelay = atoi(argv[++option]);
						break;
					case 's':
						queueReuse = true;
						break;
					case 'x':
						ignoredTypesFile = argv[++option];
						break;
					default:
						std::cout << "Invalid option specified." << USAGE_STRING << std::endl;
						return 1;
				}	
			}
		}
	}

	/* Debugging code */
	if(DEBUG)
	{
		std::cout<<numThreads<<" "<<fetchLimit<<" "<<ignoredDomainsFile<<" "<<fetchDelay<<" "<<queueReuse<<" "<<ignoredTypesFile<<" "<<seedsFile<<std::endl;
	}

	std::ofstream log_fs("log.txt"); 	//TODO: declare filename in header or something
	

	/* Read from specified files */

	//Read seeds
	std::ifstream seed_fs(seedsFile.c_str());
	if(!seed_fs)
	{
		printToLog(log_fs, "Unable to open seeds file.\n");
	}
	std::vector<std::string> seedURLs;
	getLinesFromFile(seed_fs, seedURLs);
	
	//Read ignored types
	std::ifstream ignrtypes_fs(ignoredTypesFile.c_str());
	if(!ignrtypes_fs)
	{
		printToLog(log_fs, "Unable to open ignored types file.\n");
	}
	std::vector<std::string> ignoredTypes;
	getLinesFromFile(ignrtypes_fs, ignoredTypes);

	//Read ignored domains if specified
	std::ifstream ignrdomains_fs(ignoredDomainsFile.c_str());
	if(!ignrdomains_fs)
	{
		printToLog(log_fs, "Unable to open ignored domains file.\n");
	}
	std::vector<std::string> ignoredDomains;
	getLinesFromFile(ignrdomains_fs, ignoredDomains);

	if(DEBUG)
	{
		std::cout<<seedURLs.size()<<" "<<ignoredTypes.size()<<" "<<ignoredDomains.size()<<std::endl;
	}
	
	//Pass arguments to controller
	Controller crawlControl(numThreads, fetchLimit, fetchDelay, queueReuse, seedURLs, ignoredTypes, ignoredDomains);

	//Begin the crawl
	crawlControl.startThreads();

	return 0;
}


