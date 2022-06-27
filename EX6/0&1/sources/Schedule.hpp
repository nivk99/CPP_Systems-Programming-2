#pragma once
#include <queue>
#include <tuple>
#include "Team.hpp"
namespace basketball
{
class Schedule
{
private:
	std::queue<std::tuple<Team*,Team*>> _all_teams;
public:
	Schedule(std::vector<Team*>& teams);
	Schedule()=default;
	std::tuple<Team*,Team*> next_team();
	~Schedule()=default;
};
}

