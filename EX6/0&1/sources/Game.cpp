#include "Game.hpp"
#include <ctime>
#include "Team.hpp"
namespace basketball
{
	
void Game::game(Team* &home,Team* &outside)
{
	srand((uint)time(0));
	int num_home=rand()% 46 + 55;
	int num_outside=rand()% 51 + 50;
	if(home->get_level()>outside->get_level())
	{
		num_home+=10;
	}
	else
	{
		num_outside+=10;

	}
	if(num_home>num_outside)
	{
		home->add_victory(1);
		outside->add_loss(1);


	}
	if(num_home<num_outside)
	{
		outside->add_victory(1);
		home->add_loss(1);

	}

	home->add_amount_of_shots(num_home);
	home->add_amount_of_revenue(num_outside);

	outside->add_amount_of_shots(num_outside);
	outside->add_amount_of_revenue(num_home);


}
}
