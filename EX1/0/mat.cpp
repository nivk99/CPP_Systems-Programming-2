
#include <stdexcept>
#include <exception>
#include "mat.hpp"
#define LINEBREAK '\n'
#define INVALID_VALUE 32
#define ZERO 0
using namespace std;

struct ExceptionEven: public exception {
   const char *what () const noexcept override{
      return "Invalid input.\n Do not enter a column or row with an even number.";
   }
};

struct ExceptionChar: public exception {
   const char *what () const noexcept override{
      return "Invalid input.\n Do not enter an invalid character.";
   }
};

struct ExceptionNegative: public exception {
   const char *what () const noexcept override{
      return "Invalid input.\n Do not enter a negative number.";
   }
};


namespace ariel
{
  std::string mat(const  int column, const  int row, const char ch1, const char ch2)
  {
    //  If the row or column is even
    if(row%2 == ZERO || column%2 == ZERO)
    {
      throw( ExceptionEven());
    }
    
    // If an invalid character
    if (ch1<INVALID_VALUE||ch2<INVALID_VALUE)
    {
      throw(ExceptionChar());
    }

    // If the column or row is negative
    if(row<=ZERO||column<=ZERO)
    {
      throw( ExceptionNegative());
    }

    // Allocation of memory
    char** arr=memory(column, row);
    // Fill in the characters
    fill(arr,column,row,ZERO,ZERO,ch1, ch2);
    // Copy from array to string
    string str=shift(arr,column,row);
    // Memory release
    release(arr,row);

    return str;
  }
}


// Fill in the characters - Recursive function
void fill(char **arr, unsigned  int column_down, unsigned int row_right, unsigned  int column_up,unsigned int row_left,char ch1,char ch2)
{
  // Fill the top and bottom frames
  for (int i = column_up; i < column_down; i++)
  {
    arr[row_left][i]=ch1;
    arr[row_right-1][i]=ch1;
  }

  // Stop conditions
  if(row_right-1==row_left)
  {
     return;
  }

  // Fill the frame on the left and on the right
  for(int j=row_left;j<row_right;j++)
  {
    arr[j][column_up]=ch1;
    arr[j][column_down-1]=ch1;
  }
  
  // Stop conditions
  if (column_down-1==column_up)
  {
    return;
  }


  // Recursive function
  fill(arr,column_down-1,row_right-1,column_up+1,row_left+1,ch2,ch1);

  
  
}





// Copy from array to string
std::string shift(char **arr,const unsigned int column,const unsigned int row)
{
  string str="";
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
      str+=arr[i][j];
    }
    str+=LINEBREAK;
  }

  return str;

}

 // Allocation of memory
 char** memory(const unsigned int column,const unsigned int row)
 {
    char** arr=new char* [row];
    for(int i=0;i<row;i++)
    {
      arr[i]=new char[column];

    }

    return arr;

 }

// Memory release
 void release(char **arr,const unsigned int row)
 {
  for (int i=0;i<row;i++)
  {

    delete[] arr[i];

  }
  delete[] arr;

 }