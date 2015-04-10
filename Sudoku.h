#include<iostream>
class Sudoku{
public:
  Sudoku();
  void GiveQuestion();
  void ReadIn();
  void Solve();
  static const int sudokuSize=144;
private:
  int mapIn[sudokuSize];
//static  int mapQue[sudokuSize];

  int x[10];
  int a,b,c,d,e,f,g,h,i,j,jj;
};
