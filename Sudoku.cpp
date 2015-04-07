#include<iostream>
#include<cstdlib>
#include "Sudoku.h"
using namespace std;
Sudoku::Sudoku()
{
  for(int i=0;i<sudokuSize;i++){
    mapQue[i]=0;
    mapIn[i]=0;
  }
}
void Sudoku::GiveQuestion()
{

  srandom(time(NULL));
  x[0]=0;

  for(j=1;j<=9;j++){
    x[j]=random()%9+1;
    if(x[j]==x[j-1]) j=j-1;
  }
  for(j=1;j<=9;j++){ 
    cout<<x[j]<<'\n'<<endl;);
  }
  a=x[1];b=x[2];c=x[3];d=x[4];e=x[5];f=x[6];g=x[7];h=x[8];i=x[9];
  mapQue[sudokuSize]={i,g,h,c,a,b,f,d,e,
                      c,a,b,f,d,e,i,g,h,
                      f,d,e,i,g,h,c,a,b,
                      g,h,i,a,b,c,d,e,f,
                      a,b,c,d,e,f,g,h,i,
                      d,e,f,g,h,i,a,b,c,
                      h,i,g,b,c,a,e,f,d,
                      b,c,a,e,f,d,h,i,g,
                      e,f,d,h,i,g,b,c,a};
}
void Sudoku::ReadIn()
{
  int a;
  for(int i=0;i<sudokuSize;i++){
   cin>>a;
   if(a!='\n')
     mapIn[i]=a;
  }
}
void Sudoku::Solve(){}
