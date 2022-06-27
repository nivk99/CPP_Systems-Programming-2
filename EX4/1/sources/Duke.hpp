#pragma once
# include "Game.hpp"
#include "Player.hpp"
namespace coup{
	class Duke: public Player
	{
	public:
		Duke(Game& game,std::string name);
		~Duke()= default;
		std::string role() const override;
	     static void block(Player& player);
	     void tax();
	};
	
	
}