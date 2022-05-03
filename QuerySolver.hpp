#pragma once
#include "Server.hpp"
#include "LRUCache.hpp"
#include "utility.hpp"

class QuerySolver
{
private:
	Server* server;
	LRUCache* lru;
public:
	QuerySolver();
	~QuerySolver();
	std::list<Product*> Query_3a();
	std::list<User*> Query_3b();
	std::list<Product*> Query_3c();
	std::list<Product*> Query_3d();
	std::list<User*> Query_3e();
	std::list<User*> Query_3f();
};