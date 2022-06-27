#include "Schedule.hpp"
namespace basketball
{
Schedule::Schedule(std::vector<Team*>& teams)
{
	std::queue<std::tuple<Team*,Team*>> que;
	for(uint i=0;i<teams.size();i++)
	{
		for(uint j=i+1;j<teams.size();j++)
		{
			this->_all_teams.push({teams.at(i),teams.at(j)});
			que.push({teams.at(j),teams.at(i)});
		}

	}
	while (!que.empty())
	{
		this->_all_teams.push(que.front());
		que.pop();
	}
	

}
std::tuple<Team*,Team*> Schedule::next_team()
{
	if(!this->_all_teams.empty())
	{
		std::tuple<Team*,Team*>& temp=this->_all_teams.front();
		this->_all_teams.pop();
		return temp;

	}
	else
	{
		return {new Team{"NULL",0},new Team{"NULL",0}};
	}
}
}