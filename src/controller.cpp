/*
        LightCrawl 1.0
        Simple crawler to casually fetch web pages for text processing
        Author: Utkarsh Desai

        controller.cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "controller.h"
#include "urlqueue.h"

/*
	Constructor

	Arguments:
	numT- number of threads
	fLimit- fetch limit
	fDelay- fetch delay
	reuse- save queue for reuse
	seeds- set of seed urls
	iTypes- set of file types to ignore
	iDomains- set of domains to ignore
*/
Controller::Controller(int numT, int fLimit, int fDelay, bool reuse, std::vector<std::string>& seeds, std::vector<std::string>& iTypes, std::vector<std::string>& iDomains) : ignoredTypes(iTypes), ignoredDomains(iDomains)
{
	numThreads = numT;
	fetchLimit = fLimit;
	fetchDelay = fDelay;
	queueReuse = reuse;
	
	//For each seed url, add to queue
	for(int i = 0; i < seeds.size(); i++)
		globalQueue.addURL(seeds[i]);
}

void Controller::startThreads()
{
	std::cout<<"Spawning threads ... "<<std::endl;
	
	std::thread crawlThreads[numThreads];
	
	for(int i = 0; i < numThreads; i++)
	{
		crawlThreads[i] = std::thread(&Controller::doCrawl, this, i);
		//TODO: Error check in case of spawn failure
		//Something like if object is null, throw error
	}

	for(int i = 0; i < numThreads; i++)
	{
		crawlThreads[i].join();
	}
	std::cout<<"Crawl Started."<<std::endl;


	std::cout<<"Crawl Ended."<<std::endl;
}

void Controller::doCrawl(int id)
{
	//create output file for this thread (require thread id)

	//get next url from queue
	// if valid url then fetch it	
	// if null, sleep
	// if limit reached, exit

	//write crawled page to outfile
	
	//sleep according to fetchdelay

}
