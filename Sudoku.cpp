#include<iostream>
#include "Sudoku.h"
using namespace std;
Sudoku::Sudoku(){}

void Sudoku::GiveQuestion(){}
void Sudoku::ReadIn()
{
  int a;
  for(int i=0;i<sudokuSize;i++){
   cin>>a;
   if(a!='\n')
     map[i]=a;
  }
}
void Sudoku::Solve(){}
