#include "LRUCache.hpp"


LRUCache::LRUCache(int capacity):capacity(capacity)
{
	lru.reserve(this->capacity);
}

std::vector<int> LRUCache::processRequests(std::vector<int> requestsNo)
{
	for (std::vector<int>::iterator it = requestsNo.begin(); it != requestsNo.end(); it++)
	{
		std::vector<int>::iterator it2;
		for (it2 = lru.begin(); it2 != lru.end(); it2++)
			if ((*it) == (*it2))
				lru.erase(it2);

		it2 = lru.insert(lru.begin(), *it);

		if (lru.size() > capacity)
			lru.pop_back();
	}
	return lru;
}

int LRUCache::getCapacity()
{
	return this->capacity;
}

int LRUCache::getSize()
{
	return this->size;
}

std::vector<int> LRUCache::getLRU()
{
	return this->lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void LRUCache::setLRU(std::vector<int> lru)
{
	this->lru = lru;
}