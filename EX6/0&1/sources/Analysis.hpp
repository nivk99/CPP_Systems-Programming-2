
#pragma once
#include "Team.hpp"
#include <vector>
namespace basketball
{
class Analysis
{
private:
	std::vector<Team*> _teams;
public:
	Analysis(std::vector<Team*>teams);
	~Analysis()=default;

	void victory_loss();
	void difference();
	void leading_group(int num);//הקבוצה המובילה
	void Sequence_victories();//רצף של ניצחונות
	void Sequence_losses();//רצף הפסדים
	void Scored_more_than_absorbed();//קלע יותר מאשר ספג


};

}