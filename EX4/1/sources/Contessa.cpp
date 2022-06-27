#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game& game,std::string name):Player(game,std::move(name))
{
	
}

std::string Contessa::role() const 
{
	return "Contessa";
}
void Contessa::block(Player& player)
{
	if(player.role()=="Assassin")
	{
		Assassin *pl=dynamic_cast<Assassin*>(&player);
		pl->set_role_block(true);
		pl->for_life();
	}
	else
	{
		throw std::runtime_error("Invalid input\n player !=Assassin");
	}

}
