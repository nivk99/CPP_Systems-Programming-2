 #pragma once
#include "Direction.hpp"
#include <string>
#include <iostream>
# include <map>
#define __maximum_line_length 100
using namespace std;
namespace ariel
{

    class Notebook
    {

    private:
        map<int,map<int, map<int,char >>> _note;
         void startLine(int page,int row,Direction direction,int len);
         bool checkWrite(int page, int row, int column, Direction direction, int len);
    public:
        void write(int page,  int row,  int column, Direction direction, const string &toWrite);
        string read(int page, int row, int column, Direction direction, int lenChar);
        void erase( int page,  int row,  int column, Direction direction, int lenChar);
        void show(int page);
        //unsigned
    };

}