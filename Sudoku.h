#include<iostream>
class Sudoku{
public:
  Sudoku();
  void GiveQuestion();
  void ReadIn();
  void cloneMap(const int map[]);
  bool checkUnity(int *,int);
  void setElement(int , int);
  int getZero();
  int checkDark();
  bool Correct();
  bool Solve();
  static const int sudokuSize=144;
private:
  int mapIn[sudokuSize];
  int testMulti[sudokuSize];
  int passCount;
  int ansCount;
//  int Count[11];
//static  int mapQue[sudokuSize];
  int mapAns[sudokuSize];
  int mapAnswer[sudokuSize];
  int x[10];
  int a,b,c,d,e,f,g,h,i,j,jj;
};
