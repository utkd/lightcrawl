/*
        LightCrawl 1.0
        Simple crawler to casually fetch web pages for text processing
        Author: Utkarsh Desai

        urlqueue.h
*/

#ifndef _URLQUEUE_H
#define _URLQUEUE_H

#include <iostream>
#include <queue>
#include <string>
#include <mutex>

/*
	URLQueue class

	Represents the queue of URLs waiting to be fetched
*/
class URLQueue
{
	private:
		std::mutex queueMutex;
		std::queue<std::string> urls;
	public:
		URLQueue();
		bool addURL(std::string url);
		std::string getNextURL();
		int getSize();
};

#endif
