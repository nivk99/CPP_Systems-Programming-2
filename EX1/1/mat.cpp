/**
 * @file mat.cpp
 * 
 * In this file you can see the implementation of the "design the rugs" solution.
 * In this file you can see about 3 functions.
 * One function: the main function.
 * Second function: A recursive function that solves the problem.
 * Third function: A function that copies a vector (like a two-dimensional array) to a string.
 * 
 * AUTHORS: Niv Kotek
 * 
 * Date: 2022-03-15
 */


#include "mat.hpp"

namespace ariel
{
  /**
   * This is the main function which "paints" the carpet. 
   * The function uses two auxiliary functions. 
   * A recursive function and a function that returns a string.
   * 
   * @param column -  Number of columns
   * @param row - Number of Rows
   * @param firstCh - First character
   * @param secondCh - Second character
   * 
   * @return A string of carpet
   */
  std::string mat(const  int column, const  int row, const char firstCh, const char secondCh)
  {
    const int zero=0;
    const int minInvalidValue=33;
    const int MaxInvalidValue=126;


     // If the column or row is negative
    if(row<=0||column<=0)
    {
      throw runtime_error("Invalid input.\n Do not enter a negative number.");
    }
    
    // If an invalid character
    if (firstCh<minInvalidValue||secondCh<minInvalidValue||firstCh>MaxInvalidValue||secondCh>MaxInvalidValue)
    {
      throw runtime_error("Invalid input.\n Do not enter an invalid character.");
    }
    
     //  If the row or column is even
    if(row%2 == zero || column%2 == zero)
    {
      throw runtime_error("Invalid input.\n Do not enter a column or row with an even number.");
    }


    std::vector<std::vector<char>> vec(row,vector<char>(column));

    // Fill in the characters
    rug::fill(vec,column,row,zero,zero,firstCh, secondCh,false);

    // Copy from array to string
    return rug::shift(vec,column,row);
  }
}

namespace rug
{
/**
 * This is a recursive function which fills the vector.
 * The function each time reduces its size.
 * 
 * @param vec - Vector (like a two-dimensional array)
 * @param colDown - Last column number
 * @param rowRight - Right row number
 * @param colUp - Top column number
 * @param rowLeft - Left row number
 * @param firstCh - First character
 * @param secondCh - Second character
 * @param print - Boolean variable - whether to print the vector (DEBUG)
 * 
 * @return Void function - returns nothing
 * 
 */
void fill(std::vector<std::vector<char>> &vec,  int colDown, int rowRight, int colUp, int rowLeft,char firstCh,char secondCh,bool printDebug)
{

  #if defined(DEBUG)
    //Do print the vector
    if (printDebug)
    {
      printVector(vec);
    }
  #endif


  // Fill the top and bottom frames
  for (int i = colUp; i < colDown; i++)
  {
    vec.at(rowLeft).at(i)=firstCh;
    vec.at(rowRight-1).at(i)=firstCh;
  }

  // Stop conditions
  if(rowRight-1==rowLeft)
  {

    #if defined(DEBUG)
      //Do print the vector
      if (printDebug)
      {
        printVector(vec);
      }
    #endif
    
    return;

  }

  // Fill the frame on the left and on the right
  for(int j=rowLeft;j<rowRight;j++)
  {
    vec.at(j).at(colUp)=firstCh;
    vec.at(j).at(colDown-1)=firstCh;
  }
  
  // Stop conditions
  if (colDown-1==colUp)
  {

    #if defined(DEBUG)
      //Do print the vector
      if (printDebug)
      {
        printVector(vec);
      }
    #endif

    return;
  }


  // Recursive function
  fill(vec,colDown-1,rowRight-1,colUp+1,rowLeft+1,secondCh,firstCh,printDebug);
  
}





/**
 * Function Copies a vector to a string.
 * 
 * @param vec - Vector (like a two-dimensional array)
 * @param column - Number of columns
 * @param row - Number of Rows
 * 
 * @return String
 */
std::string shift(const std::vector<std::vector<char>> &vec,const unsigned int column,const unsigned int row)
{
  string str;
  const char linebreak='\n';
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
      str+=vec.at(i).at(j);
    }
    if(i+1<row)
    {
      str+= linebreak;

    }
  }

  return str;

}



 #if defined(DEBUG)
/**
 * This is a function that prints the vector
 * 
 * @param vec - Vector (like a two-dimensional array)
 * 
 * @return Void function - returns nothing
 */

void printVector(const std::vector<std::vector<char>> &vec)
{
   cout<<endl<<' '<<endl;
  for(int i=0;i<vec.size();i++)
  {
    for(int j=0;j<vec[i].size();j++)
    {
      cout<<vec[i][j]<<' ';

    }
    cout<<endl<<' '<<endl;
  }

}
#endif


}