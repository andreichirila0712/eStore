#include "FinalQuestionsHelper.hpp"

std::vector<Query> getQuery(json& j)
{
	std::vector<Query> rez;
	
	for (json::iterator it = j.begin(); it != j.end(); it++)
	{
		Query q{
			(*it)["productID"].get<int>(),
			(*it)["userID"].get<int>(),
			(*it)["operation"].get<std::string>(),
			(*it)["quantity"].get<int>()
		};
		rez.push_back(q);
	}
	return rez;
}