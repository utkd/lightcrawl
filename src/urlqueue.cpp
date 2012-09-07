/*
        LightCrawl 1.0
        Simple crawler to casually fetch web pages for text processing
        Author: Utkarsh Desai

        urlqueue.cpp
*/

#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include "urlqueue.h"

URLQueue::URLQueue()
{

}

bool URLQueue::addURL(std::string url)
{
	std::lock_guard<std::mutex> lock(queueMutex);
	std::cout<<"Adding "<<url<<std::endl;
	urls.push(url);
	return true;
} 

std::string URLQueue::getNextURL()
{
	std::lock_guard<std::mutex> lock(queueMutex);
	if(!urls.empty())
	{
		std::string nexturl = urls.front();
		urls.pop();
		return nexturl;
	}
	return " ";
}

int URLQueue::getSize()
{
	return urls.size();
}
