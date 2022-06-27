#include "Player.hpp"
using namespace coup;

Player::Player(Game& game,std::string name):_game(game),_name(std::move( name)),_coins(0),action("NULL")
{
	this->_game.add_player(this->_name);


}


void Player::income()
{
	this->next_player();
	More_than_ten_coins();


	this->_coins++;
	this->action="income";
}
void Player::foreign_aid()
{
	this->next_player();
	More_than_ten_coins();

	this->_coins+=2;
	this->action="foreign_aid";
}
void Player::coup(Player& player)
{
	this->next_player();
	const int  num = 7;
	if(this->_coins<num)
	{
		this->_game.subtract_next();
		throw std::runtime_error("Invalid input the coinst <7!");
	}
	this->_coins-=num;
	try
	{
			this->_game.delete_player(player._name);
			this->action="coup";
	}
	catch(const std::exception& e)
	{
		this->_coins+=num;
		this->_game.subtract_next();
		throw std::runtime_error("Game::Invalid input delete_playe");
	}
	
}
std::string Player::role()  const
{
	return "Player";
}

int Player::coins() const
{
	return this->_coins;
}

int& Player::get_coins()
{
	return this->_coins;
}
std::string  Player::get_name() const
{
	return this->_name;
}

void Player::next_player()
{
	this->_game.add_next();
	if(this->_name!=this->_game.turn())
	{
		this->_game.subtract_next();
		throw std::runtime_error("Invalid input this->_name!=this->_game.turn()");
	}
	this->_game.start=true;
}

void Player::More_than_ten_coins() const
{
	const int num=9;
	if(this->_coins>num)
	{
		this->_game.subtract_next();
		throw std::runtime_error("Invalid input More_than_ten_coins");

	}

}

void Player::add(Player *player)
{
	this->_game.add_player(player->_name);

}
