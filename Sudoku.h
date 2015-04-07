#include<iostream>
class Sudoku{
public:
  Sudoku();
  void GiveQuestion();
  void ReadIn();
  void Solve();
  static const int sudokuSize=144;
private:
  int mapQue[sudokuSize];
  int mapIn[sudokuSize];
  int x[10];
  int a,b,c,d,e,f,g,h,i,j;
};
