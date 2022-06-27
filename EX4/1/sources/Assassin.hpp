#pragma once
#include "Game.hpp"
#include "Player.hpp"
namespace coup{
	class Assassin: public Player
	{
	
	private:
		bool _role_block;
		std::vector<Player*> _coup_players;

	public:
		Assassin(Game& game,std::string name);
		~Assassin()= default;
		std::string role() const override;
		void coup(Player& player) override;
		void next_player() override;

		void set_role_block(bool role);
		bool get_role_block() const; 
		void for_life();

	
	
	
};
}