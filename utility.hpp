#pragma once
#include "Server.hpp"

class Utility
{
public:
	static bool comparePrice(Product*, Product*);
	static bool compareName(Product*, Product*);
	std::string functie(std::vector<std::string>);
	static bool compareUserID(User*, User*);
	static bool compareUserIDIdentic(User*, User*);
};