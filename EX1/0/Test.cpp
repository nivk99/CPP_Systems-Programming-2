#include "mat.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace ariel;


string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}



TEST_CASE("Good input") 
{

   //Correct input
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces( "@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

    //Correct input
    CHECK(nospaces(mat(9, 5, '@', '-'))  == nospaces( "@@@@@@@@@\n"
													  "@-------@\n"
													  "@-@@@@@-@\n"
													  "@-------@\n"
													  "@@@@@@@@@"));


    //Correct input
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces(     "$$$\n"
													     "$+$\n"
													     "$+$\n"
													     "$+$\n"
													     "$$$"));



    //Correct input
    CHECK(nospaces(mat(5, 7, '-', '@')) == nospaces(     "-----\n"
													     "-@@@-\n"
													     "-@-@-\n"
													     "-@-@-\n"
													     "-@-@-\n"
                                                         "-@@@-\n"
                                                          "-----"));


    //Correct input
    CHECK(nospaces(mat(5, 7, '0', '1')) == nospaces(     "00000\n"
													     "01110\n"
													     "01010\n"
													     "01010\n"
													     "01010\n"
                                                         "01110\n"
                                                         "00000"));

    // Correct input                                           
    CHECK(nospaces(mat(1, 5, '*', '%')) == nospaces( "*\n"
                                                     "*\n"
                                                     "*\n"
                                                     "*\n"
                                                      "*"));


}



TEST_CASE("Bad input") 
{


     //Row or column even number
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(5, 10, '$', '%'));



    // Zero  row or column
    CHECK_THROWS(mat(0, 9, '%', '*')); 

    CHECK_THROWS(mat(7, 0, '%', '*')); 


    // Negative row or column
    CHECK_THROWS(mat(-5, 9, '%', '*')); 

    CHECK_THROWS(mat(7, -1, '%', '*')); 



    //Special characters are forbidden to use
    CHECK_THROWS(mat(9, 7, '\t', '*')); 

    CHECK_THROWS(mat(9, 7, '%', '\t'));

    CHECK_THROWS(mat(7, 9, '\n', '*')); 

    CHECK_THROWS(mat(7, 9, '%', '\n'));  

    CHECK_THROWS(mat(5, 3,'\r', '*')); 

    CHECK_THROWS(mat(3, 5, '%', '\r')); 

    CHECK_THROWS(mat(3, 7, '*', '\0')); 

    CHECK_THROWS(mat(7, 9, '\0',  '*')); 

    
}



TEST_CASE("Loop big input") 
{

    string str="";
    //Proper inspection
    for(int i=0;i<77;i++)
    {
        for(int j=0;j<77;j++)
        {
            str+='&';
        }
        str+='\n';
    }

   CHECK_EQ(str,mat(77,77,'&','&'));

  str="";
  //Proper inspection
    for(int i=0;i<65;i++)
    {
        for(int j=0;j<87;j++)
        {
            str+='&';
        }
        str+='\n';
    }

    CHECK_EQ(str,mat(87,65,'&','&'));
   
}



