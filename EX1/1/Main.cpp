/**
 * 
 * It is a main file which prints the construction of the carpet according to the input of the user.
 * 
 * AUTHORS: Niv Kotek
 * 
 *  Date: 2022-03-15
 */


#include "Main.hpp"

int main(int argc, char const *argv[])
{
    int num=0;
    while (true)
    {
        cout<<"Select the function you want."<<endl;
        cout<<"Select 1 for Recursive Printing."<<endl;
        cout<<"Select 2 for Random Output."<<endl;
        cout<<"Select 3 for Input Output."<<endl;
        cout<<"Select 4 for exceptions."<<endl;
        cout<<"Select 5 for exit."<<endl;
        cin>>num;

        //Select the appropriate function

        if(num==1)
        {
        //Input Output from the user
          recursivePrinting();
          continue;

        }

        if (num==2)
        {
            //Random output
            randomOutput();
            continue;
        }

        if (num==3)
        {
            //Recursive printing
            inputOutput();
            continue;
        }

        if(num==4)
        {
            //Printing of exceptions
            exceptions();
            continue;
        }

        if(num!=1||num!=2||num!=3||num!=4)
        {
            return 0;

        }

      
    }
    
}

/**
 * The function prints the carpet construction at each stage of the recursion
 * @return Void function - returns nothing
 */
void recursivePrinting()
{
    int col=0,row=0;
    char firstCh=0, secondCh=0;

        //Select inputs by user

        cout<<"Type the number of columns"<<endl;
        cin >> col;

        cout<<"Type the number of rows"<<endl;
        cin >> row;

        cout<<"Type the first character"<<endl;
        cin >> firstCh;

        cout<<"Type the second character"<<endl;
        cin >> secondCh;


         std::vector<std::vector<char>> vec(row,vector<char>(col));
         //Initialize values
         for(int i=0;i<row;i++)
         {
             for(int j=0;j<col;j++)
             {
                 vec[i][j]='0';
             }

         }

        try {
            //Send to function
            fill(vec,col,row,0,0,firstCh, secondCh,true); // Exception - not a valid code
        } catch (exception& ex) {
            cout << "   caught exception: " << ex.what() << endl;  
        }


}


/**
 * The function prints the carpet randomly
 *  @return Void function - returns nothing
 */
void randomOutput()
{
    int col=0,row=0;
    char firstCh=0, secondCh=0;
    srand((int)time(0));
    for(int i=0;i<10;i++)
    {
        cout<<" "<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Result number: "<<i+1<<endl;

        col=rand()%100+1;// random - [1-99]
        col=col%2==0?col+1:col;//odd number

        row=rand()%100+1;// random - [1-99]
        row=row%2==0?row+1:row;//odd number

        firstCh=rand()%10+34;
        secondCh=((rand()%10+34));

        cout<<"The first character: "<<firstCh<<", "<<"The second character: "<<secondCh<<endl;
        cout<<"Number of columns: "<<col<<", "<<"Number of Rows: "<<row<<endl;
        cout<<" "<<endl;
        //Send to function
         printMat(col,row, firstCh,  secondCh);
    }


}

/**
 * The function prints the carpet according to user input
 *  @return Void function - returns nothing
 */
void inputOutput()
{

    int col=0,row=0;
    char firstCh=0, secondCh=0;
    string ans;
    while (true)
    {
       //Select inputs by user

        cout<<"Type the number of columns"<<endl;
        cin >> col;

        cout<<"Type the number of rows"<<endl;
        cin >> row;

        cout<<"Type the first character"<<endl;
        cin >> firstCh;

        cout<<"Type the second character"<<endl;
        cin >> secondCh;

        printMat(col,row,firstCh, secondCh);

        cout<<"Do you want to do it again? Write yes or no"<<endl;
         cin >> ans;

         if(ans!="yes")
         {
            return;

         }


    }

}


/**
 *The function prints exceptions  bad receivers
 *  @return Void function - returns nothing
 */
void exceptions()
{
    cout<<"even column:"<<endl;
        printMat(8,5,'&','*');

    cout<<"even row"<<endl;
       printMat(5,8,'&','*');

    cout<<"negative number:"<<endl;
      printMat(-5,5,'%','*');

    cout<<"invalid character:"<<endl;
      printMat(5,5,' ','*');

}


/**
 * Function helps print 
 * 
 * @param col -  Number of columns
 * @param row -  Number of Rows
 * @param firstCh -  First character
 * @param ch2 - Second character
 * 
 *  @return Void function - returns nothing
 */
void  printMat(const  int col,const int row,const char firstCh,const char secondCh)
{
try {
    //Send to function and print
    cout <<mat(col,row,firstCh, secondCh) << endl; // Exception - not a valid code
    }
     catch (exception& ex)
    {
        cout << "   caught exception: " << ex.what() << endl;  
    }

    cout<<" "<<endl;
    
}
