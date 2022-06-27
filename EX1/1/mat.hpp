
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
//#define DEBUG
using namespace std;
namespace ariel
{
   std::string mat(const  int column, const  int row, const char firstCh, const char secondCh);
}

//A recursive function that fills the vector (like a two-dimensional array) by 2 characters.
namespace rug
{
void fill(std::vector<std::vector<char>> &vec,  int colDown, int rowRight, int colUp, int rowLeft,char firstCh,char secondCh,bool printDebug);
//Function Copies a vector to a string
std::string shift(const std::vector<std::vector<char>> &vec,const unsigned int column,const unsigned int row);

void printVector(const std::vector<std::vector<char>> &vec);
}