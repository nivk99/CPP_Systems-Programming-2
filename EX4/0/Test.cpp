
#include "doctest.h"
#include <string>

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

TEST_CASE("Test"){
	SUBCASE("Bad input")
	{
		Game game_1{};
		Duke duke{game_1, "Moshe"};
		Assassin assassin{game_1, "Yossi"};
		Ambassador ambassador{game_1, "Meirav"};
		Captain captain{game_1, "Reut"};
		Contessa contessa{game_1, "Gilad"};
		CHECK_THROWS(contessa.income());
		CHECK_THROWS(captain.income());
		CHECK_THROWS(ambassador.income());
		CHECK_THROWS(assassin.income());
		for (size_t i = 0; i < 6; i++)
		{
			if(i==0)
			{
				CHECK_THROWS(duke.coup(assassin));

				CHECK_THROWS(assassin.coup(duke));

				CHECK_THROWS(ambassador.coup(assassin));

				CHECK_THROWS(captain.coup(assassin));

				CHECK_THROWS(contessa.coup(assassin));
			}
			else
			{
				duke.foreign_aid();
				assassin.foreign_aid();
				ambassador.foreign_aid();
				captain.foreign_aid();
				contessa.foreign_aid();

			}
		}
		CHECK_THROWS(duke.foreign_aid());
		CHECK_THROWS(assassin.foreign_aid());
		CHECK_THROWS(ambassador.foreign_aid());
		CHECK_THROWS(contessa.foreign_aid());

		Game game_2{};
		Contessa contessa2{game_2, "Gilad"};
		Duke duke2{game_2, "Moshe"};
		CHECK_THROWS(contessa2.block(duke2));
        
		Game game_3{};
		Ambassador ambassador3{game_3, "Meirav"};
		Duke duke3{game_3, "Moshe"};
		CHECK_THROWS(ambassador3.block(duke3));
	}

	SUBCASE("Good input")
	{
		Game game_1{};
		Duke duke{game_1, "Moshe"};
		Assassin assassin{game_1, "Yossi"};
		Ambassador ambassador{game_1, "Meirav"};
		Captain captain{game_1, "Reut"};
		Contessa contessa{game_1, "Gilad"};


		CHECK_NOTHROW(duke.income());
		CHECK_NOTHROW(assassin.income());
		CHECK_NOTHROW(ambassador.income());
		CHECK_NOTHROW(captain.income());
		CHECK_NOTHROW(contessa.income());

		CHECK_EQ(duke.role(),"Duke");
		CHECK_EQ(assassin.role(),"Assassin");
		CHECK_EQ(ambassador.role(),"Ambassador");
		CHECK_EQ(captain.role(),"Captain");
		CHECK_EQ(contessa.role(),"Contessa");


		CHECK_EQ(duke.get_name(),"Moshe");
		CHECK_EQ(assassin.get_name(),"Yossi");
		CHECK_EQ(ambassador.get_name(),"Meirav");
		CHECK_EQ(captain.get_name(),"Reut");
		CHECK_EQ(contessa.get_name(),"Gilad");

		CHECK_EQ(duke.coins(),1);
		CHECK_EQ(assassin.coins(),1);
		CHECK_EQ(ambassador.coins(),1);
		CHECK_EQ(captain.coins(),1);
		CHECK_EQ(contessa.coins(),1);


		Game game_2{};
		Duke duke2{game_2, "Moshe"};
		Assassin assassin2{game_2, "Yossi"};
		Ambassador ambassador2{game_2, "Meirav"};
		Captain captain2{game_2, "Reut"};
		Contessa contessa2{game_2, "Gilad"};

		CHECK_NOTHROW(duke2.tax());
		CHECK_EQ(duke2.coins(),3);
		assassin2.foreign_aid();
		CHECK_EQ(assassin2.coins(),2);
		duke2.block(assassin2);
		CHECK_EQ(assassin2.coins(),0);

		ambassador2.transfer(duke2,assassin2);
		CHECK_EQ(duke2.coins(),2);
		CHECK_EQ(assassin2.coins(),1);

		captain2.steal(duke2);
		CHECK_EQ(duke2.coins(),0);
		CHECK_EQ(captain2.coins(),2);

	}
}