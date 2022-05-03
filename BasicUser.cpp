#include "BasicUser.hpp"

BasicUser::BasicUser() :costTransport(0)
{

}

BasicUser::BasicUser(const std::string& county, const std::string& locality, const std::string& street, int number, const std::string& block, int apartment, const std::string& county2, const std::string& locality2, const std::string& street2, int number2, const std::string& block2, int apartment2, int UserID, const std::string& lastName, const std::string& firstName, const std::string& email, float costTransport) : User(county, locality, street, number, block, apartment, county2, locality2, street2, number2, block2, apartment2, UserID, lastName, firstName, email), costTransport(costTransport)
{

}

BasicUser::BasicUser(const BasicUser& bu) : User(bu), costTransport(bu.costTransport)
{

}

BasicUser& BasicUser::operator=(const BasicUser& bu)
{
	if (this != &bu)
	{
		this->costTransport = bu.costTransport;
		User::operator=(bu);
	}
	return *this;
}

void BasicUser::setTransportCost(int costTransport)
{
	this->costTransport = (float)costTransport;
}

float BasicUser::getTransportCost()
{
	return this->costTransport;
}

void BasicUser::displayUser()
{
	throw("undefined");
}

std::string BasicUser::getUserType()
{
	return "BasicUser";
}

json BasicUser::toJSON()
{
	return json(*this);
}