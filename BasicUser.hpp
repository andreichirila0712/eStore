#pragma once
#include "User.hpp"

class BasicUser :public User
{
protected:
	float costTransport;
public:
	BasicUser();
	BasicUser(const std::string&, const std::string&, const std::string&, int, const std::string&, int, const std::string&, const std::string&, const std::string&, int, const std::string&, int, int, const std::string&, const std::string&, const std::string&, float);
	BasicUser(const BasicUser&);
	BasicUser& operator=(const BasicUser&);
	void setTransportCost(int);
	float getTransportCost();
	std::string getUserType();
	json toJSON();
	void displayUser();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(BasicUser, billingData, deliveryData, lastName, firstName, email, UserID, costTransport)
};