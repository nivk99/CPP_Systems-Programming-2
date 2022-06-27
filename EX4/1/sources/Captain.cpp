#include "Captain.hpp"
using namespace coup;

Captain::Captain(Game& game,std::string name):Player(game,std::move(name)),_prevent_theft(false),pL(nullptr),num_steal(0)
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
		pL=&(player);
		num_steal=0;

		if(player.coins()>1)
		{
			this->_coins+=2;
			player.get_coins()-=2;
			num_steal=2;

		}
		if(player.coins()==1)
		{
			this->_coins+=1;
			player.get_coins()-=1;
			num_steal=1;

		}

	}
		this->action="steal";

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
	if(bo)
	{
		if(pL!=nullptr)
		{
			pL->get_coins()+=this->num_steal;
			this->_coins-=num_steal;
			pL=nullptr;
		}
	}

}
