
#pragma once
namespace basketball
{
class Team;
 class Game
{
public:
	Game()=default;
	~Game()=default;
	static void game(Team* &home,Team* &outside);
};
}

