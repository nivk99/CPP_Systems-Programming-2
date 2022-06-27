#include "Duke.hpp"
using namespace coup;

Duke::Duke(Game& game,std::string name):Player(game,std::move(name))
{

}
std::string Duke::role() const 
{
	return "Duke";
}
void Duke::tax()
{
	this->next_player();
	this->More_than_ten_coins();
	this->_coins+=3;

}
void Duke::block(Player& player)
{
	player.get_coins()-=2;
	player.get_block_foreign_aid()=true;
	
}