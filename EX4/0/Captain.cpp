#include "Captain.hpp"
using namespace coup;

Captain::Captain(Game& game,std::string name):Player(game,std::move(name)),_prevent_theft(false)
{

}

std::string Captain::role() const 
{
	return "Captain";
}


void Captain::steal(Player& player)
{
	this->next_player();
	More_than_ten_coins();
	if(!_prevent_theft)
	{
		this->_coins+=2;
		player.get_coins()-=2;

	}

}
void Captain::block(Player& player)
{
	if(player.role()=="Captain")
	{
		Captain *pl=dynamic_cast<Captain*>(&player);
		pl->set_prevent_theft(true);
	}
	else
	{
		throw std::runtime_error("Invalid input\n Captain::block");
	}

}

void Captain::set_prevent_theft(bool bo)
{
	this->_prevent_theft=bo;

}
