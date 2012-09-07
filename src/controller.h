/*
        LightCrawl 1.0
        Simple crawler to casually fetch web pages for text processing
        Author: Utkarsh Desai

        controller.h
*/

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include "urlqueue.h"

/*
	Controller Class

	Spawns the crawl threads and controls the overall operation
*/
class Controller
{
	private:
		int numThreads;
		int fetchLimit;
		int fetchDelay;
		bool queueReuse;
		std::vector<std::string>& ignoredTypes;
		std::vector<std::string>& ignoredDomains;
		URLQueue globalQueue; 

	public:
		Controller(int numT, int fLimit, int fDelay, bool reuse, std::vector<std::string>& seeds, std::vector<std::string>& iTypes, std::vector<std::string>& iDomains);
		void startThreads();
		void doCrawl(int id);
};

#endif
