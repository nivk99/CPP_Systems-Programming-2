
#pragma once
#include <vector>
#include "Schedule.hpp"
namespace basketball
{
class Leauge
{
private:
	std::vector<Team*> _teams;
	Schedule _schedule;

public:
	Leauge();
	Leauge(std::vector<Team*>& teams);
	~Leauge();

	void start_game();
	std::vector<Team*>& get_teams();
	
};
}

