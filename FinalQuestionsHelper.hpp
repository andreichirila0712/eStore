#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

typedef struct lrubluprint {
	int capacity;
	std::vector<int> allLRUOperations;
}LRU_blueprint;

typedef struct query {
	int productID;
	int userID;
	std::string operation;
	int quantity;
}Query;

LRU_blueprint getLruBlueprint(json&);

json writeLruFinalState(std::vector<int>&);

std::vector<Query> getQuery(json&);

json writeFinalState(std::vector<Query>&, std::vector<int>&);

json queryToJson(Query&);