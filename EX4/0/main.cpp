#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
	std::vector<std::string> players;
	players.push_back("niv1");
	players.push_back("niv2");
	players.push_back("niv3");

	players.erase(players.begin()+1);
		for(std::string name : players){
		std::cout << name << std::endl;
	}

	
	return 0;
}
