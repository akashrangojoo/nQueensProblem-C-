/********************************************
 *   NAME        :  PROG8.CC " THE N QUEENS PROBLEM"
 *   AUTHOR      :  AKASH Z1717009
 *   SUBMISSION  :  10/29/2015
 *******************************************/

#include "prog8.h"

/*************************************************
 * FUNCTION  :  solveNQueens
 * INPUTS    :  const unsigned& n
 * USAGE     :  Declare a two dimensional vector and
                start the initialization process.
                If there exists a solution, print the
                board else print a message.
 ***********************************************/

void solveNQueens ( const unsigned& n ){
   vector<vector<bool> > board;  // Declare a two dimentional vector
   initBoard(board,n);
   bool out=solveNqueensUtil(board,0);
   if(out) {printBoard(board); cout<<endl;} // If solution exists print the board.
   else cout<<"No solution Exists for board size "<<n<<endl<<endl; // else print a message

}
/*************************************************
 * FUNCTION  :  initBoard
 * INPUTS    :  vector<vector<bool> > & board,const unsigned & n
 * USAGE     :  Initialize the two dimensional vector and
                set srand.
 ***********************************************/

void initBoard(vector<vector<bool> > & board,const unsigned & n) {
   srand(time(0));
   for(unsigned i=0;i<n;i++){ // initializing th evector board.
      vector<bool> dummy;
      for(unsigned j=0;j<n;j++)
         dummy.push_back(false);
      board.push_back(dummy);
   }
}

/************************************************
 * FUNCTION  :  solveNqueensUtil
 * INPUTS    :  vector<vector<bool> >& board, const unsigned& row
 * USAGE     :  This function is called recursively to place
                the queen at a certain column that is randomly
                generated. isSafe() is called to check if the
                position is safe to place the queen at that row
                and column.
 ***********************************************/

bool solveNqueensUtil (vector<vector<bool> >& board, const unsigned& row)
{
   unsigned column;
   if (row>=board.size()) return true;
   for (unsigned i=0;i<=board.size()+8; i++)  
   {
      column = randCol(0,board.size()-1);       // generating random column
      bool safe = isSafe(board,row,column);  // checking if the position is safe
      if (safe)          
      {
         board[row][column]=true; // If safe set the pos to true
         if (solveNqueensUtil(board,row+1) == true) return true; // call this function recursively for next row.
         else board[row][column]=false; //If the next row returns false set present pos as false and go to next position
      }
   }
   return false;
}

/*************************************************
 * FUNCTION  :  isSafe
 * INPUTS    :  vector<vector<bool> >& board, const unsigned& row,const unsigned& column
 * USAGE     :  This function is called before placing
                the queen at that row and column to check
                if the position is safe.
 ***********************************************/

bool isSafe(const vector<vector<bool> >& board, const int& row, const int column){
   for(int i=0;i<row;i++) {
      for(int j=0;j<=board.size()-1;j++){
         if(board[i][j]) {
            if(column==j)  return false; // checks if the columns are same
            else if(abs(row-i)==abs(column-j)) return false; // checks if they're in same diagonal
         }
      }
   }
   return true;
}

/*************************************************
 * FUNCTION  :  randCol
 * INPUTS    :  unsigned low, unsigned high
 * USAGE     :  This function generates a random number
                between high and low.
 ***********************************************/

unsigned randCol(unsigned low, unsigned high) {
   high++;
   unsigned randNumber = rand()%(high-low)+low;
   return randNumber;
}
/*************************************************
 * FUNCTION  :  printBoard
 * INPUTS    :  vector<vector<bool> >& board
 * USAGE     :  This function is called whenever a solution
                exists. This prints the board.
 ***********************************************/
void printBoard(vector< vector<bool> > &board)
{
   for(unsigned i=0;i<board.size();i++){
      for(unsigned k=0;k<board.size();k++) cout<<" ---"; // printing outer surface
      cout<<endl;

      for(unsigned j=0; j<board.size();j++){
         if(board[i][j]==true){
            cout<<"| Q ";     //  printing queen position
         }
         if(board[i][j]==false){
            cout<<"|   ";
         }
      }
      cout<<"|"<<endl;
   }
   for(unsigned k=0;k<board.size();k++)
      cout<<" ---";
   cout<<endl<<endl;
}

int main()
{
   unsigned N=1;
   while(N<=8){ //calling for each value of N
      cout<<"Size of the Board = "<<N<<endl<<endl;
      solveNQueens(N);
      N++;
      cout<<"******************************************"<<endl<<endl;
   }
   return 0;
}

