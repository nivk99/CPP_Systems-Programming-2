#pragma once
# include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;
namespace coup{
	class Contessa: public Player
	{	
	public:
		Contessa(Game& game,std::string name);
		~Contessa()= default;
		std::string role() const override;	
		static void block(Player& player);
	
	};
	

	
}