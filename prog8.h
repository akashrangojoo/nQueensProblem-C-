/********************************************
 *   NAME        :  PROG8.H " THE N QUEENS PROBLEM"
 *   AUTHOR      :  AKASH Z1717009
 *   SUBMISSION  :  10/29/2015
********************************************/

#include "/home/cs689/common/689.h"

#ifndef prog8_h
#define prog8_h

bool solveNqueensUtil (vector<vector<bool> >& board, const unsigned& row);
void solveNQueens ( const unsigned& n );
void initBoard(vector<vector<bool> > & board, const unsigned& n);
bool isSafe(const vector<vector<bool> >& board, const int& row, const int column);
unsigned randCol(unsigned low, unsigned high);
void printBoard(vector< vector<bool> > &board);


#endif

