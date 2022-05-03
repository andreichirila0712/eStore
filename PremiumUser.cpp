#include "PremiumUser.hpp"

PremiumUser::PremiumUser() :premiumSubscriptionCost(0)
{

}

PremiumUser::PremiumUser(const std::string& county, const std::string& locality, const std::string& street, int number, const std::string& block, int apartment, const std::string& county2, const std::string& locality2, const std::string& street2, int number2, const std::string& block2, int apartment2, int UserID, const std::string& lastName, const std::string& firstName, const std::string& email, int premiumSubscriptionCost, const std::map<int, int>& discounts) : User(county, locality, street, number, block, apartment, county2, locality2, street2, number2, block2, apartment2, UserID, lastName, firstName, email), premiumSubscriptionCost(premiumSubscriptionCost), discounts(discounts)
{

}

PremiumUser::PremiumUser(const PremiumUser& pu) : User(pu), premiumSubscriptionCost(pu.premiumSubscriptionCost), discounts(pu.discounts)
{

}

const PremiumUser& PremiumUser::operator=(const PremiumUser& pu)
{
	if (this != &pu)
	{
		this->premiumSubscriptionCost = pu.premiumSubscriptionCost;
		this->discounts = pu.discounts;
		User::operator=(pu);
	}
	return *this;
}

void PremiumUser::displayUser()
{
	throw("undefined");
}

std::string PremiumUser::getUserType()
{
	return "PremiumUser";
}

float PremiumUser::getTransportCost()
{
	throw("undefined");
}

std::map<int, int>& PremiumUser::getDiscounts()
{
	return this->discounts;
}

void PremiumUser::setDiscounts(std::map<int, int> discounts)
{
	this->discounts = discounts;
}

void PremiumUser::setPremiumSubscriptionCost(int premiumSubscriptionCost)
{
	this->premiumSubscriptionCost = premiumSubscriptionCost;
}

int PremiumUser::getPremiumSubscriptionCost()
{
	return this->premiumSubscriptionCost;
}

json PremiumUser::toJSON()
{
	return json(*this);
}