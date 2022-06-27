#pragma once
# include "Game.hpp"
#include "Captain.hpp"
#include "Player.hpp"
#include <iostream>
namespace coup{
	class Ambassador: public Player
	{
	public:
		Ambassador(Game& game,std::string name);
		~Ambassador()= default;
		std::string role() const override;
		static void block(Player& player);
		void transfer(Player& player1,Player& player2);
	};
	
	
}