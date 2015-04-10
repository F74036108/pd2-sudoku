#include<iostream>
class Sudoku{
public:
  Sudoku();
  void GiveQuestion();
  void ReadIn();
  void setMap(const int map[]);
  void insPossible(int *,int*);
  void setElement(int , int);
  int getZero();
  int checkDark();
  void Solve();
  static const int sudokuSize=144;
private:
  int mapIn[sudokuSize];
//static  int mapQue[sudokuSize];
  int mapAns[sudokuSize];
  int x[10];
  int a,b,c,d,e,f,g,h,i,j,jj;
};
