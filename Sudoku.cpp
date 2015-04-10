#include<iostream>
#include<cstdlib>
#include<iomanip>
#include "Sudoku.h"
using namespace std;
Sudoku::Sudoku()
{
  for(int i=0;i<sudokuSize;i++){
   
    mapIn[i]=0;
  }
}
void Sudoku::GiveQuestion()
{

  srandom(time(NULL));
  x[0]=0;
  bool ch[10];
  for(j=0;j<=9;j++){
    if(j==0){
      for(jj=1;jj<10;jj++) ch[jj]=0;
      continue;}
    x[j]=random()%9+1;
    
    if(ch[x[j]]==1){ j=-1;
    }else{
      ch[x[j]]=1;}
 }
//  for(j=1;j<=9;j++){ 
  //  cout<<x[j]<<'\n'<<endl;
 // }
  a=x[1];b=x[2];c=x[3];d=x[4];e=x[5];f=x[6];g=x[7];h=x[8];i=x[9];
  int mapAns[sudokuSize]={ i, g, h,-1,-1,-1, c, a, b, f, d, e,
                           c, a, b,-1,-1,-1, f, d, e, i, g, h,
                           f, d, e,-1,-1,-1, i, g, h, c, a, b,
                           g, h, i, a, b, c,-1,-1,-1, d, e, f,
                           a, b, c, d, e, f,-1,-1,-1, g, h, i,
                           d, e, f, g, h, i,-1,-1,-1, a, b, c,
                          -1,-1,-1, h, i, g, b, c, a, e, f, d,
                          -1,-1,-1, b, c, a, e, f, d, h, i, g,
                          -1,-1,-1, e, f, d, h, i, g, b, c, a,
                           e, f, a, i, g, h, d, b, c,-1,-1,-1,
                           h, i, g, c, d, b, a, e, f,-1,-1,-1,
                           b, c, d, f, a, e, g, h, i,-1,-1,-1
                         };
  int mapQue[sudokuSize]={ i, g, h,-1,-1,-1, c, a, b, f, d, e,
                           c, a, 0,-1,-1,-1, f, d, e, i, g, h,
                           f, 0, 0,-1,-1,-1, i, g, h, c, a, b,
                           g, h, i, a, b, c,-1,-1,-1, 0, e, f,
                           a, b, c, d, e, f,-1,-1,-1, 0, h, i,
                           d, e, f, g, h, i,-1,-1,-1, a, b, c,
                          -1,-1,-1, h, i, g, 0, 0, a, e, f, d,
                          -1,-1,-1, b, c, a, e, 0, d, h, i, g,
                          -1,-1,-1, e, f, d, h, i, g, b, c, a,
                           e, f, a, i, g, h, d, b, c,-1,-1,-1,
                           h, i, 0, c, d, b, a, e, f,-1,-1,-1,
                           b, c, d, f, a, e, g, h, i,-1,-1,-1
                         };

  i=0;
  for(j=0;j<sudokuSize;j++){
    cout<<setw(4)<<mapQue[j];
    i++;
    if(i==12){
      cout<<'\n';i=0;}
  }
  cout<<endl;
  return;
}
void Sudoku::setMap(const int map[])
{
  for(int i=0;i<sudokuSize;i++)
    mapIn[i]=map[i];
}
void Sudoku::ReadIn()
{

  for(int i=0;i<sudokuSize;i++){
    cin>>mapIn[i];
  }

  int ii; ii=0;
    for(j=0;j<sudokuSize;j++){
    cout<<setw(4)<<mapIn[j];
    ii++;
    if(ii==12){
      cout<<'\n';ii=0;}
  }
  cout<<endl;

}
void Sudoku::insPossible(int a[], int *b)
{
  int Count[11];
  for(int i=0;i<11;i++){
    Count[i]=0;
  }
  for(int i=0;i<12;i++){
    Count[a[i]+1]=1;
  }
  b=Count;
}
void Sudoku::setElement(int matNum, int value)
{
  mapIn[matNum]=value;
}
int Sudoku::getZero()
{
  for(int i=0;i<sudokuSize;i++)
    if(mapIn[i]==0)
      return i;
    return -1;
}
int Sudoku::checkDark()
{
  int REC[sudokuSize];
  for(int i=0;i<sudokuSize;i++){
    REC[i]=-2;
  }
  int c;c=0;
  for(int i=0;i<sudokuSize;i++){
    if(mapIn[i]==-1){
      REC[c]=i;c++;
    }
  }cout<<c<<endl;
  int ii; ii=0;
    for(j=0;j<sudokuSize;j++){
    cout<<setw(4)<<mapIn[j];
    ii++;
    if(ii==12){
      cout<<'\n';ii=0;}
  }
  cout<<endl;

  if(c>36){return -1;}
  for(int i=0;i<c;i+=9){
    if(REC[i]!=REC[i+1]-1&&REC[i]!=REC[i+2]-2&&REC[i]!=REC[i+3]-12&&REC[i]!=REC[i+4]-13&&REC[i]!=REC[i+5]-14&&REC[i]!=REC[i+6]-24&&REC[i]!=REC[i+7]-25&&REC[i]!=REC[i+8]-26){
      return -1;
    }
  }
  return 1;
}
void Sudoku::Solve()
{
 
  int blankPosition;
  
  if(checkDark()==-1)
    cout<<0<<endl;return;

  blankPosition=getZero();
 // if(blankPosition==-1){
   // if
}
