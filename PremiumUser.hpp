#pragma once
#include "User.hpp"

class PremiumUser :public User
{
protected:
	int premiumSubscriptionCost;
	std::map<int, int> discounts;
public:
	PremiumUser();
	PremiumUser(const std::string&, const std::string&, const std::string&, int, const std::string&, int, const std::string&, const std::string&, const std::string&, int, const std::string&, int, int, const std::string&, const std::string&, const std::string&, int, const std::map<int, int>&);
	PremiumUser(const PremiumUser&);
	const PremiumUser& operator=(const PremiumUser&);
	void setDiscounts(std::map<int, int>);
	void setPremiumSubscriptionCost(int);
	float getTransportCost();
	std::map<int, int>& getDiscounts();
	int getPremiumSubscriptionCost();
	std::string getUserType();
	json toJSON();
	void displayUser();
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(PremiumUser, billingData, deliveryData, lastName, firstName, email, UserID, premiumSubscriptionCost, discounts)
};