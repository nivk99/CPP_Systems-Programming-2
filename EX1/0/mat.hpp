#include <string>
#include <iostream>

namespace ariel
{
   std::string mat(const  int column, const  int row, const char ch1, const char ch2);
}


void fill(char **arr, unsigned  int column_down, unsigned int row_right, unsigned  int column_up,unsigned int row_left,char ch1,char ch2);
std::string shift(char **arr,const unsigned int column,const unsigned int row);
char** memory(const unsigned int column,const unsigned int row);
 void release(char **arr,const unsigned int row);