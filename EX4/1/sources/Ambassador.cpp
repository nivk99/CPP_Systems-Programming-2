#include "Ambassador.hpp"
using namespace coup;
Ambassador::Ambassador(Game& game,std::string name):Player(game,std::move(name))
{

}
std::string Ambassador::role() const 
{
	return "Ambassador";
}

 void Ambassador::transfer(Player& player1,Player& player2)
{
	this->next_player();
	More_than_ten_coins();
	if(player1.coins()>0)
	{
		player1.get_coins()-=1;
		player2.get_coins()+=1;
		this->action="transfer";

	}
	else
	{
		this->_game.subtract_next();
		throw std::runtime_error("Ambassador:: Invalid input\n player1.coins()<0");

	}


}
void Ambassador::block(Player& player)
{
	if(player.role()=="Captain")
	{
		Captain *pl=dynamic_cast<Captain*>(&player);
		pl->set_prevent_theft(true);
	}
	else
	{
		throw std::runtime_error("Invalid input\n Ambassador::block");
	}

}

