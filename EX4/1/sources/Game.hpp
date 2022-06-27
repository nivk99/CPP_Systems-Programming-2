#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
namespace coup{
	class Game
	{
	private:
		int _next;
		std::unordered_map<std::string,bool> _players;
		std::vector<std::string> _players_names;
	public:
		bool start;
		~Game()= default;
		Game();
		std::string turn ();
		std::vector<std::string> players();
		std::string winner();
		void add_player(std::string& name);
		void delete_player(std::string& name);
		int next_turn();
		void add_next();
		void subtract_next();

		 
	};

	
}