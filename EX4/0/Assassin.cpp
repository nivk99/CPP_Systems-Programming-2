#include "Assassin.hpp"
using namespace coup;

Assassin::Assassin(Game& game,std::string name):Player(game,std::move(name)),_role_block(false)
{
}

std::string Assassin::role() const 
{
	return "Assassin";
}

void Assassin::coup(Player& player)
{
    this->next_player();
	this->_block_foreign_aid=false;
	const int  num = 7;
	std::string name=player.get_name();
	if(this->_coins<num)
	{
		if(this->_role_block)
		{
			if(!this->_coup_players.empty())
			{
				this->add(this->_coup_players.at(0));
				this->_coup_players.erase(this->_coup_players.begin()+0);

			}
			else
			{
				this->set_role_block(false);
				return;
			}
			

		}
		else
		{
			if(this->_coins>2)
			{
				this->_coins-=3;
				this->_coup_players.push_back(&player);
			}
			else
			{
				throw std::runtime_error("Invalid input the coinst <7");
			}

		}

	}
	else
	{
		this->_coins-=num;
	}
	this->_game.delete_player(name);
	this->set_role_block(false);

}






void Assassin::set_role_block(bool role)
{
	this->_role_block=role;
}
bool Assassin::get_role_block()const
{
	return this->_role_block;

}
