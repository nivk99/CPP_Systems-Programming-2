#include"Team.hpp"
namespace basketball
{
Team::Team(std::string name,double level):_name(name),_level(level),_victory(0),_loss(0),_amount_of_shots(0),_amount_of_revenue(0)
{
	if(name.empty())
	{
		throw std::runtime_error("Invalid input\n Must enter a valid string");

	}
	const int minInvalidValue=32;
	const int maxInvalidValue=126;
	for(uint i=0;i<name.size();i++)
	{
		if(name.at(i)<minInvalidValue||name.at(i)>maxInvalidValue)
		{
			throw std::runtime_error("Invalid input\n Must enter a valid string");
		}

	}

	if(level<0||level>1)
	{
		throw std::runtime_error("Invalid input\n Please enter the correct level between 0 and 1.");

	}
	this->_name=name;
	this->_level=level;
}




	std::string Team::get_name()
	{
		return this->_name;

	}
	double Team::get_level()
	{
		return this->_level;

	}
	int Team::get_victory()
	{
		return this->_victory;

	}
	int Team::get_loss()
	{
		return this->_loss;

	}
	int Team::get_amount_of_shots()
	{
		return this->_amount_of_shots;

	}
	int Team::get_amount_of_revenue()
	{
		return this->_amount_of_revenue;

	}

	void Team::add_test(int num)
	{
		if(num<0)
		{
			throw std::runtime_error("Invalid input\n A positive number should be entered");
		}
	}

	void Team::add_victory(int num)
	{
		add_test(num);
		this->_victory+=num;

	}
	
	void Team::add_loss(int num)
	{
		add_test(num);
		 this->_loss+=num;

	}

	void Team::add_amount_of_shots(int num)
	{
		add_test(num);
		this->_amount_of_shots+=num;

	}

	void Team::add_amount_of_revenue(int num)
	{
		add_test(num);
		this ->_amount_of_revenue+=num;

	}
}