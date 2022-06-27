#include "Leauge.hpp"
#include <tuple>
#include "Game.hpp"
namespace basketball
{
	Leauge::Leauge()
	{
		char ch='A';
		std::string str=std::to_string(ch);
		double level=0;
		for(uint i=0;i<20;i++)
		{
			this->_teams.push_back(new Team{str,level});
			ch++;
			str=std::to_string(ch);
			level+=0.1;
			if(level>1)
			{
				level=0;
			}
		}
		this->_schedule=Schedule{this->_teams};
		//this->_game=Game{};

	}
	Leauge::Leauge(std::vector<Team*>& teams)
	{
		if(teams.size()>20)
		{
			throw std::runtime_error("Invalid input\n It is not possible to insert a group larger than 20");

		}
		if(teams.size()==20)
		{
			this->_teams=teams;
			this->_schedule=Schedule{this->_teams};
			return;
		}

		char ch='A';
		std::string str=std::to_string(ch);
		double level=0;
		for(int i=0;i<20-teams.size();i++)
		{
			this->_teams.push_back(new Team {str,level} );
			ch++;
			str=std::to_string(ch);
			level+=0.1;

		}
		this->_schedule=Schedule{this->_teams};
		//this->_game=Game{};


	}
	Leauge::~Leauge()
	{
		for (uint i = 0; i < this->_teams.size(); i++)
		{
			delete this->_teams.at(i);
		}
		
	}

	void Leauge::start_game()
	{
		while (true)
		{
			std::tuple<Team*,Team*>tems {this->_schedule.next_team()};
			if(std::get<0>(tems)->get_name()=="NULL")
			{
				break;
			}

			Game::game(std::get<0>(tems),std::get<1>(tems));
			
			//this->_game.game(std::get<0>(tems),std::get<1>(tems));
			
		}
		
	}

	std::vector<Team*>& Leauge::get_teams()
	{
		return this->_teams;
	}
}