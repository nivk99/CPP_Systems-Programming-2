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
	int i=0;
   this->_game.add_next();
	if(this->_name!=this->_game.turn())
	{
		this->_game.subtract_next();

		throw std::runtime_error("Assassin::Invalid input this->_name!=this->_game.turn())");
	}
	if(this->coins()<2)
	{
		this->_game.subtract_next();
		throw std::runtime_error("Assassin::Invalid input coins()<2)");
	}
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
				this->action="coup";
				return;
			}
			

		}
		else
		{
			if(this->_coins>2)
			{
				i=3;
				this->_coins-=3;
				this->_coup_players.push_back(&player);
			}
			else
			{
				this->_game.subtract_next();
				throw std::runtime_error("Assassin::Invalid input the coinst <7");
			}

		}

	}
	else
	{
		i=num;
		this->_coins-=num;
	}

	try
	{
		this->_game.delete_player(name);
		this->action="coup";
	}
	catch(const std::exception& e)
	{
		this->_game.subtract_next();
			this->_coins+=i;
		throw std::runtime_error("Assassin::Invalid input delete_playe");
	}
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

void Assassin::next_player()
{
	Player::next_player();
	this->set_role_block(false);

}


void Assassin::for_life()
{
	if(this->_coup_players.empty())
	{
		throw std::runtime_error("Assassin::Invalid input the empty()");
	}
	this->add(this->_coup_players.at(0));
	this->_coup_players.erase(this->_coup_players.begin()+0);

}