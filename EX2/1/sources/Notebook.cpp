
#include "Notebook.hpp"
#include <stdexcept>
#include <exception>
using namespace std;
using namespace ariel;


void Notebook::write(int page, int row, int column, Direction direction, const string &toWrite)
{
     const int minInvalidValue=32;
     const int maxInvalidValue=126;

     if ( row  < 0 || column < 0 ||  page < 0)
    {
         throw runtime_error("Invalid input.\n Do not enter a negative number.");
    }
    if(column >= __maximum_line_length)
    {
         throw runtime_error("Invalid input.\n Do not enter more than 100 characters");
    }

    if (direction==Direction::Horizontal&&((int)toWrite.length() > __maximum_line_length||column + (int)toWrite.length() > __maximum_line_length))
    {
          throw runtime_error("Invalid input.\n Do not enter more than 100 characters");
    }     


    for(const char ch:toWrite)
    {
       if (ch=='~'||ch=='\n'||ch=='\0'||ch=='\r'||ch<minInvalidValue||ch>maxInvalidValue){
      throw runtime_error("Invalid input.\n Do not enter an invalid character.");
    }

    }
    this->startLine(page,row,direction,(int)toWrite.length());
    if(row !=0)
    {
           this->startLine(page,row-1,direction,(int)toWrite.length());

    }
    this->startLine(page,row+1,direction,(int)toWrite.length());
    if(!this->checkWrite(page,row,column,direction,(int)toWrite.length()))
    {
      throw runtime_error("Invalid input.\n Unable to write because it is written or deleted.");

    }

    int i=0;
    for(char ch:toWrite)
    {
         if(direction==Direction::Horizontal)
         {
              this->_note[page][row][column+i++]=ch;
         }
         else
         {
              this->_note[page][row+i++][column]=ch;

         }

    }


}

string Notebook::read(int page, int row, int column, Direction direction, int lenChar)
{

    if (page < 0 || row < 0 || column < 0 || lenChar < 0)
    {
         throw runtime_error("Invalid input.\n Do not enter a negative number.");
    }
    if(column >= __maximum_line_length)
    {
         throw runtime_error("Invalid input.\n Do not enter more than 100 characters");
    }

    if ( direction==Direction::Horizontal&&(column + lenChar  > __maximum_line_length))
    {
         throw runtime_error("Invalid input.\n Do not enter more than 100 characters");
    }

    this->startLine(page,row,direction,lenChar);
    if(row !=0)
    {
           this->startLine(page,row-1,direction,lenChar);

    }
     this->startLine(page,row+1,direction,lenChar);


    string readNote;
    for(int i=0;i<lenChar;i++)
    {
         if( direction==Direction::Horizontal)
         {
              readNote+=this->_note[page][row][column+i];
         }
         else
         {
              readNote+=this->_note[page][row+i][column];

         }
    }


    return readNote;
}

void Notebook::erase( int page, int row, int column, Direction direction, int lenChar)
{

     if (page < 0 || row < 0 || column < 0 || lenChar < 0)
    {
         throw runtime_error("Invalid input.\n Do not enter a negative number.");
    }

    if(column >= __maximum_line_length)
    {
         throw runtime_error("Invalid input.\n Do not enter more than 100 characters");
    }

    if ( direction==Direction::Horizontal&&(column + lenChar  > __maximum_line_length))
    {
         throw runtime_error("Invalid input.\n Do not enter more than 100 characters");
    }

     this->startLine(page,row,direction,lenChar);
     if (row!=0)
     {
         this->startLine(page,row-1,direction,lenChar);
     }
     this->startLine(page,row+1,direction,lenChar);
     for(int i=0;i<lenChar;i++)
    {
         if( direction==Direction::Horizontal)
         {
             this->_note[page][row][column+i]='~';
         }
         else
         {
              this->_note[page][row+i][column]='~';

         }
    }




}

void Notebook::show(int page)
{
       if (page < 0)
    {
         throw runtime_error("Invalid input.\n Do not enter a negative number.");
    }
    cout<<"Page number "<<page<<":"<<endl<<"------------"<<endl<<endl;

    	for (const auto& row: this->_note[page]) 
         {
              cout<<row.first<<"- ";
              for(const auto& pair:row.second)
              {
                   cout<<pair;

              }
              cout<<endl;

         }

}

void Notebook::startLine(int page,int row,Direction direction,int len)
{
     if (direction==Direction::Horizontal&&this->_note[page].find(row)==this->_note[page].end())
     {
          for(int i=0;i<__maximum_line_length;i++)
          {
               this->_note[page][row][i]='_';
          }

     }
     if(direction==Direction::Vertical)
     {
          for(int i=0;i<len;i++)
          {
               if(this->_note[page].find(row+i)==this->_note[page].end())
               {

                    for(int j=0;j<__maximum_line_length;j++)
                    {
                         this->_note[page][row+i][j]='_';
                    }
     

               }
          }



     }
}


bool Notebook::checkWrite(int page, int row, int column, Direction direction, int len)
{

  for(int i=0;i<len;i++)
    {
         if(direction==Direction::Horizontal)
         {
              if(this->_note[page][row][column+i]!='_')
              {
                   return false;
              }

         }
         else
         {
              if(this->_note[page][row+i][column]!='_')
              {
                   return false;
              }

         }
    }

       return true;



}


