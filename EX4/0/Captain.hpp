#pragma once
# include "Game.hpp"
#include "Player.hpp"
#include <iostream>
namespace coup{
	class Captain: public Player
	{
	private:
		bool _prevent_theft;

	public:
		Captain(Game& game,std::string name);
		~Captain()= default;
		std::string role() const override;
		static void block(Player& player);
		 void steal(Player& player);

		 void set_prevent_theft(bool bo);
	};
	

	
}