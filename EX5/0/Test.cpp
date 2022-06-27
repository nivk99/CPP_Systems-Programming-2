
/**
 * @file Test.cpp
 * @brief 
 * @version 1.0
 * @date 2022-05-15
 * 
 * 
 * AUTHORS: Niv Kotek (Nivk99@gmail.com)
 * 
 * @copyright Coyright (C) 2022
 */

#include <iostream>
#include <fstream>
#include "doctest.h"
#include "OrgChart.hpp"
#include <string>
using namespace std;
using namespace ariel;


/**
 *                                        @test Test cases
 *           ________________________________________________________________________________
 */



TEST_CASE("Test 1: level order")
{
	std::vector<std::string> vect{"CEO","CTO","CFO","COO","VP_SW","VP_BI"};
	uint i=0;

	OrgChart organization;
  	organization.add_root("CEO")
      .add_sub("CEO", "CTO")// Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO") // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO") // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO


	for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  	{
		CHECK_EQ((*it),vect.at(i++));//prints: CEO CTO CFO COO VP_SW VP_BI

  	}

	i=0;
	for ( auto element : organization)
 	{ 
		CHECK_EQ(element,vect.at(i++));//prints: CEO CTO CFO COO VP_SW VP_BI
  	} 
}


TEST_CASE("Test 2: reverse level order")
{

	std::vector<std::string> vect{"niv","kotek","omer","dor","mizy","yotam"};
	uint i=0;

	OrgChart organization;
  	organization.add_root("yotam")
      .add_sub("yotam", "omer")
      .add_sub("yotam", "dor") 
      .add_sub("yotam", "mizy") 
      .add_sub("omer", "niv") 
      .add_sub("mizy", "kotek");


	for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  	{
    	CHECK_EQ((*it),vect.at(i++)) ;// prints: "niv","kotek","omer","dor","mizy","yotam"
 	} 



}


TEST_CASE("Test 3: level preorder")
{

	std::vector<std::string> vect{"shlomo","daniel","paula","hanan","lgor","lavie"};
	uint i=0;

	OrgChart organization;
  	organization.add_root("shlomo")
      .add_sub("shlomo", "daniel")
      .add_sub("shlomo", "hanan") 
      .add_sub("shlomo", "lgor") 
      .add_sub("daniel", "paula") 
      .add_sub("lgor", "lavie"); 


  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it)
  {
   	CHECK_EQ((*it),vect.at(i++)) ;// prints: "shlomo","daniel","paula","hanan","lgor","lavie"
  }  


}

TEST_CASE("Test 4: string size")
{

	std::vector<std::string> vect{"Niv_Kotek","Omar_Kotek","Hanan_Tzobari","Yotam_Mesika","Lavie_Sapir","Ortal_Avraham"};
	uint i=0;

	OrgChart organization;
  	organization.add_root("Niv_Kotek")
      .add_sub("Niv_Kotek", "Omar_Kotek")
      .add_sub("Niv_Kotek", "Hanan_Tzobari") 
      .add_sub("Niv_Kotek", "Yotam_Mesika") 
      .add_sub("Omar_Kotek", "Lavie_Sapir") 
      .add_sub("Yotam_Mesika", "Ortal_Avraham"); 

for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
	CHECK_EQ(it->size(),vect.at(i++).size()) ;

  } 
}