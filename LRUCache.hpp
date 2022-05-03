#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class LRUCache
{
private:
	unsigned int capacity;
	unsigned int size;
	std::vector<int> lru;
public:
	LRUCache(int);
	std::vector<int> processRequests(std::vector<int> requestsNo);
	int getCapacity();
	int getSize();
	std::vector<int> getLRU();
	int getLRUCapacity();
	void setCapacity(int capacity);
	void setLRU(std::vector<int> aux);
};