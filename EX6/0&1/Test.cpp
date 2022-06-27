
#include <fstream>
#include "doctest.h"
#include "Leauge.hpp"
using namespace std;
using namespace basketball;



TEST_CASE("Test 1: bad input")
{


	for (int i = -100; i<0; i++)
	{
		CHECK_THROWS(Team("test",i));
		CHECK_THROWS(Team("test",i).add_loss(i));
		CHECK_THROWS(Team("test",i).add_victory(i));
		CHECK_THROWS(Team("test",i).add_amount_of_shots(i));
		CHECK_THROWS(Team("test",i).add_amount_of_revenue(i));
	}
	for (int i=2;i<100;i++)
	{
		CHECK_THROWS(Team("test",i));
		CHECK_THROWS(Team("test",i).add_loss(i));
		CHECK_THROWS(Team("test",i).add_victory(i));
		CHECK_THROWS(Team("test",i).add_amount_of_shots(i));
		CHECK_THROWS(Team("test",i).add_amount_of_revenue(i));
	}

	CHECK_THROWS(Team("",0));
	CHECK_THROWS(Team("\t",0));
	CHECK_THROWS(Team("\n",0));
	CHECK_THROWS(Team("\r",0));
	CHECK_THROWS(Team("\0",0));
	CHECK_THROWS(Team(nullptr,0));

	CHECK_THROWS(Team("test",-0.1));
	CHECK_THROWS(Team("test",-0.5));
	CHECK_THROWS(Team("test",-0.8));
	CHECK_THROWS(Team("test",-0.9));
	CHECK_THROWS(Team("test",-0.15));


	CHECK_THROWS(Team("test",0.1).add_victory(-1));




}

TEST_CASE("Test 2: good input")
{

	for (double i=0;i<=1;i+=0.01)
	{
		CHECK_NOTHROW(Team("test",i));
	}


		vector<Team*> teams;
  		char ch='A';
		string str="test"+to_string(ch);
		double level=0;
		for(uint i=0;i<20;i++)
		{

			teams.push_back(new Team{str,level});
			ch++;
			str="test"+to_string(ch);
			level+=0.1;
			if(level>1)
			{
				level=0;
			}
		}
	CHECK_NOTHROW(Leauge());
	Leauge l(teams);
   l.start_game();
   
  for(Team* & a:l.get_teams())
  {
	CHECK_NOTHROW(a->get_name());
	cout<<"name:  "<<a->get_name()<<endl;
	CHECK_NOTHROW(a->get_level());
	cout<<"level:  "<<a->get_level()<<endl;
	CHECK_NOTHROW(a->get_victory());
	 cout<<"victory:  "<<a->get_victory()<<endl;
	CHECK_NOTHROW(a->get_loss());
	cout<<"loss:  "<<a->get_loss()<<endl;
	CHECK_NOTHROW(a->get_amount_of_shots());
	cout<<"shots:  "<<a->get_amount_of_shots()<<endl;
	CHECK_NOTHROW(a->get_amount_of_revenue());
	cout<<"revenue:  "<<a->get_amount_of_revenue()<<endl;
    cout<<endl;
    
  }


	
}