# include "Game.hpp"
using namespace coup;

std::string Game::turn ()
{
	return this->_players.at(uint(this->next_turn()));
}
std::vector<std::string> Game::players()
{
	return this->_players;

}
std::string Game::winner()
{
	return this->_players.at(0);
	
}
void Game::add_player(std::string& name)
{
	this->_players.push_back(name);


}
void Game::delete_player(std::string& name)
{
	for (uint i = 0; i < this->_players.size(); i++)
	{
		if((this->_players.at(i).compare(name))!=0)
		{
			this->_players.erase(this->_players.begin()+i);
			return;
		}
	}
}

int Game::next_turn()
{
	if(this->_next==-1)
	{
		return 0;
	}
	if(this->_players.size()>this->_next)
	{
		return this->_next;
	}
	this->_next=0;
	return this->_next;

}
void Game::add_next()
{
	_next++;

}
void Game::subtract_next()
{
	_next--;

}
Game::Game():_next(-1)
{

}
