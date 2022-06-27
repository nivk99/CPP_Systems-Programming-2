#pragma once
# include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>
namespace coup
{
	class Player
	{
	 protected:
        Game& _game;
		std::string _name;
		int _coins;
		//bool _block_foreign_aid;
	
	public:
		std::string action;
		Player(Game& game,std::string name);
		~Player()= default;
		void income();
		void foreign_aid();
		virtual void coup(Player& player);
		virtual std::string role()  const;
		int coins() const;

		std::string get_name() const;
		int& get_coins();
		virtual void next_player();
		void More_than_ten_coins() const;

		void add(Player *player);

		
	};
	
}