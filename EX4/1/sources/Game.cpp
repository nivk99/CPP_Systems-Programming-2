# include "Game.hpp"
using namespace coup;

std::string Game::turn ()
{
	return this->_players_names.at(uint(this->next_turn()));

}
std::vector<std::string> Game::players()
{
	std::vector<std::string> players_names;

	for (uint i = 0; i < this->_players.size(); i++)
	{
		if(this->_players[this->_players_names.at(i)])
		{
			players_names.push_back(this->_players_names.at(i));
		}
			
	}
	return players_names;

}
std::string Game::winner()
{
	if(!this->start)
	{
		throw std::runtime_error("Game:: Invalid input not  start game");
	}
	int i=0;
	for (const auto& row: this->_players) 
	{
		if(row.second)
		{
			i++;
		}
		if(i>1)
		{
			throw std::runtime_error("Game::Invalid input Game not over");
		}
	}

	
    for (const auto& row: this->_players) 
    {
		if(row.second)
		{
			return row.first;
		}
	}
	
	return "";
}
void Game::add_player(std::string& name)
{
	int j=0;
	const int num =6;

	std::vector<std::string> players = this->players();
	for(std::string name : players){
		j++;
	}

	if(j>=num)
	{
		throw std::runtime_error("Game::Invalid input this->_players_names.size()>6");
	}

	int num_name=0;
	for(uint i=0;i<this->_players_names.size();i++)
	{
		if(this->_players_names.at(i)==(name))
		{
			num_name++;
		}
		if(num_name>1)
		{
			throw std::runtime_error("Game::Invalid input num_name>1");
		}
	}

	 if (this->_players.find(name) == this->_players.end())
	 {
		if(this->start)
		{
			throw std::runtime_error("Invalid input start game");
		}
		this->_players_names.push_back(name);
		this->_players[name]=true;

	 }
	 else
	 {
		this->_players[name]=true;
	 }

}
void Game::delete_player(std::string& name)
{
	if(!this->_players[name])
	{
		throw std::runtime_error("Game::Invalid input delete_playe");

	}
	this->_players[name]=false;
}

int Game::next_turn()
{
	if(this->_next==-1)
	{
		return 0;
	}

	if(this->_players.size()>this->_next)
	{
		for (uint i = uint(this->_next); i < this->_players.size(); i++)
		{
			if(this->_players[this->_players_names.at(i)])
			{
				return this->_next;
			}
			this->_next++;
			
		}
		
	}


	this->_next=0;
	for (uint i = 0; i < this->_players.size(); i++)
	{
		if(this->_players[this->_players_names.at(i)])
		{
			return this->_next;
		}
		this->_next++;
	}

	return this->_next;

}


void Game::add_next()
{
	const int num1 =2;
	const int num2 =6;
	if(this->_players.size()<num1||this->_players.size()>num2)
	{
		throw std::runtime_error("Game::Invalid input this->_players.size()<2||this->_players.size()>6");
	}
	_next++;

}


void Game::subtract_next()
{
	_next--;

}


Game::Game():_next(-1),start(false)
{

}
