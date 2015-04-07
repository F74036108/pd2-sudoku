#include<iostream>
class Sudoku{
public:
  Sudoku();
  void GiveQuestion();
  void ReadIn();
  void Solve();
  static const int sudokuSize=144;
private:
  int map[sudokuSize];
};
