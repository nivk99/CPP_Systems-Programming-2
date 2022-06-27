
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Leauge.hpp"
using namespace basketball;

int main(int argc, char const *argv[])
{
  std::vector<Team*> teams;
  char ch='A';
		std::string str=std::to_string(ch);
		double level=0;
		for(uint i=0;i<20;i++)
		{

			teams.push_back(new Team{str,level});
			ch++;
			str=std::to_string(ch);
			level+=0.1;
			if(level>1)
			{
				level=0;
			}
		}
    
	Leauge l(teams);
   l.start_game();
  for(Team* & a:l.get_teams())
  {
    cout<<"name:  "<<a->get_name()<<endl;
    cout<<"level:  "<<a->get_level()<<endl;
    cout<<"victory:  "<<a->get_victory()<<endl;
    cout<<"loss:  "<<a->get_loss()<<endl;
    cout<<"shots:  "<<a->get_amount_of_shots()<<endl;
     cout<<"revenue:  "<<a->get_amount_of_revenue()<<endl;
    cout<<endl;
    
  }
	return 0;
}