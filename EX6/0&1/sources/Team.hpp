
#pragma once
#include <string>
#include <iostream>
namespace basketball
{
class Team
{
private:
	std::string _name;
	double _level;
	int _victory;// כמות ניצחונות
	int _loss;//כמות הפסדים
	int _amount_of_shots;//כמות קליעות לסל
	int _amount_of_revenue;//כמות הכנסות (הפסד)
public:
	Team(std::string  name="NULL",double level=0);
	~Team()=default;

	std::string get_name();
	double get_level();
	int get_victory();
	int get_loss();
	int get_amount_of_shots();
	int get_amount_of_revenue();

	void add_victory(int num);
	void add_loss(int num);
	void add_amount_of_shots(int num);
	void add_amount_of_revenue(int num);

	static void add_test(int num);

};
}

