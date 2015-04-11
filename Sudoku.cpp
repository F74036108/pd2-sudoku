#include<iostream>
#include<cstdlib>
#include<iomanip>
#include "Sudoku.h"
using namespace std;
Sudoku::Sudoku()
{
  passCount=0;
  for(int i=0;i<sudokuSize;i++){
   
    mapIn[i]=0;
    testMulti[i]=0;
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
void Sudoku::cloneMap(const int map[])
{
  for(int i=0;i<sudokuSize;i++)
    mapIn[i]=map[i];
}
void Sudoku::ReadIn()
{

  for(int i=0;i<sudokuSize;i++){
    cin>>mapIn[i];
    testMulti[sudokuSize-i-1]=mapIn[i];
  }
  cout<<endl;

}
bool Sudoku::checkUnity(int a[],int b)
{
  int arr[11];//count
  
  for(int i=0;i<11;i++)
    arr[i]=0;
  for(int i=0;i<=b;i++)
    ++arr[a[i]+1];
  if(arr[0]==9){
    return true;}
  if(b==11){
    if(arr[0]!=3)
      return false;
  }
  for(int i=2;i<11;i++){
    if(arr[i]!=1){
      return false;
    }
  }
 // cout<<"What"<<endl;
  return true;  
}
int * Sudoku::insPossible(int blank)//Check Possible Ans for blanks
{
//  int Count[11];
  /*int i;
  i=(blank/12);
  for(int i=0;i<11;i++){
    Count[i]=0;
  }
  for(int j=0;j<12;j++)
    Count[mapIn[i*12+j]+1]=1;
  for(int j=0;j<12;j++)
    Count[mapIn[blank+12*j]+1]=1;

  return Count;*/
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
  cout<<"for dark"<<endl;
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
bool Sudoku::Correct()
{
  bool checkResult;
  int checkArr[12], location;
  for(int i=0;i<sudokuSize;i+=12)//RowCheck
  {
    for(int j=0;j<12;j++)
      checkArr[j]=mapIn[i+j];
    checkResult=checkUnity(checkArr,11);
    if(checkResult==false){
      return false;
    }
  }
  for(int i=0;i<12;i++)//Column check
  {
    for(int j=0;j<12;j++)
      checkArr[j]=mapIn[i+12*j];
    checkResult=checkUnity(checkArr,11);
    if(checkResult==false){
      return false;}
  }
  int checkArr2[9];
  for(int i=0;i<16;i++)//Cell check
  {
    for(int j=0;j<9;j++)
    {
    location= 36*(i/4)+3*(i%4)+12*(j/3)+(j%3);
    checkArr2[j]=mapIn[location];
    }
    checkResult=checkUnity(checkArr2, 8);
    if(checkResult==false)
      return false;
  }
  return true;
}
bool Sudoku::Solve()
{
  
  int blankPosition;
  
  /*if(checkDark()==-1){
    cout<<0<<endl;return false;
  }*/

  blankPosition=getZero();
/*  int Count[11];
  int ia;
  ia=(blankPosition/12);
  for(int ii=0;ii<11;ii++){
    Count[ii]=0;
  }
  for(int jj=0;jj<12;jj++){
    Count[mapIn[ia*12+jj]+1]=1;
  
//    Count[mapIn[blankPosition+12*jj]+1]=1;
  }cout<<"te23"<<endl;
*/
//  for(int i=0;i<11;i++){
//  cout<<Count[i]<<endl;}
  if(blankPosition==-1)
  {
    if(Correct())
    {/*
  i    cout<<1<<endl;
      int ii; ii=0;
      for(j=0;j<sudokuSize;j++){
        cout<<mapIn[j]<<" ";
        ii++;
        if(ii==12){
          cout<<'\n';ii=0;}
      }
      cout<<endl;*/
      if(passCount==0){
      for(int i=0;i<sudokuSize;i++){
        mapAnswer[i]=mapIn[i];
        mapIn[i]=testMulti[i];
      }}
       ++passCount;
      if(passCount<2){
      Solve();cout<<"one"<<endl;
      
      int c;c=0;
      for(int i=0;i<sudokuSize;i++){
        if(mapIn[i]==mapAnswer[sudokuSize-1-i]){
          c++;
        }
      }
      if(c==sudokuSize){
        cout<<1<<endl;
        int ii; ii=0;
        for(j=0;j<sudokuSize;j++){
          cout<<mapAnswer[j]<<" ";
          ii++;
          if(ii==12){
            cout<<'\n';ii=0;}
        }
        cout<<endl;
      }else{
        cout<<2<<endl;
        return true;
      }
      }

    
    // return true; 
    }
    else
    {/*
      int ii; ii=0;

      for(j=0;j<sudokuSize;j++){
        cout<<setw(4)<<mapIn[j];
        ii++;
        if(ii==12){
          cout<<'\n';ii=0;}
      }
      cout<<",,,,"<<endl;*/
    if(passCount==2)
   cout<<0<<"here"<<passCount<<endl;
      return false;
    }
  }
  else
  { 

   if(passCount==1){

    for(int num=9;num>=1;num--)
    {
      int Count[11];
      int ia;
      ia=(blankPosition/12);
      for(int ii=0;ii<11;ii++){
        Count[ii]=0;
      }
      for(int jj=0;jj<12;jj++){
        Count[mapIn[ia*12+jj]+1]=1;
        Count[mapIn[blankPosition%12+12*jj]+1]=1;
      }
  

      if(Count[num+1]!=1)
      {
        setElement(blankPosition,num);
     /* int ii; ii=0;
     
      for(j=0;j<sudokuSize;j++){
        cout<<setw(4)<<mapIn[j];
        ii++;
        if(ii==12){
          cout<<'\n';ii=0;}
      }
      cout<<endl;
*/
        if(Solve()){
          return true;}
        setElement(blankPosition,0);
      }
    }
   }else{
    for(int num=1;num<=9;num++)
    {
      int Count[11];
      int ia;
      ia=(blankPosition/12);
      for(int ii=0;ii<11;ii++){
        Count[ii]=0;
      }
      for(int jj=0;jj<12;jj++){
        Count[mapIn[ia*12+jj]+1]=1;
        Count[mapIn[blankPosition%12+12*jj]+1]=1;
      }
      if(Count[num+1]!=1)
      {
        setElement(blankPosition,num);
     /* int ii; ii=0;

      for(j=0;j<sudokuSize;j++){
        cout<<setw(4)<<mapIn[j];
        ii++;
        if(ii==12){
          cout<<'\n';ii=0;}
      }
      cout<<endl;
*/
        if(Solve()){
          return true;}
        setElement(blankPosition,0);
      }
    }
   }

   return false;
  }
}
