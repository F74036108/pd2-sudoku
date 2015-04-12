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
  //Generate a to i randomly
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
  int mapQue[sudokuSize]={ i, g, h,-1,-1,-1, c, a, 0, f, d, e,
                           c, a, 0,-1,-1,-1, f, 0, 0, i, 0, h,
                           f, 0, 0,-1,-1,-1, i, g, h, c, a, b,
                           0, 0, i, a, b, c,-1,-1,-1, 0, e, f,
                           a, b, 0, d, e, f,-1,-1,-1, 0, h, i,
                           d, e, f, g, 0, i,-1,-1,-1, a, 0, c,
                          -1,-1,-1, 0, i, 0, 0, 0, a, e, f, 0,
                          -1,-1,-1, b, 0, a, e, 0, d, h, 0, 0,
                          -1,-1,-1, 0, 0, d, h, i, 0, b, 0, 0,
                           0, 0, 0, 0, 0, 0, d, b, 0,-1,-1,-1,
                           h, i, 0, 0, 0, 0, a, 0, 0,-1,-1,-1,
                           0, c, d, 0, 0, 0, 0, h, i,-1,-1,-1
                         };
//Print out question
  i=0;
  for(j=0;j<sudokuSize;j++){
    cout<<mapQue[j]<<" ";
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
    testMulti[i]=mapIn[i];
  }
  cout<<endl;

}
//Check if 1 to 9 only show once
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
  return true;  
}
void Sudoku::setElement(int matNum, int value)
{
  mapIn[matNum]=value;
}
//Get the position of 0s, 
//return -1 if there isn't any
int Sudoku::getZero()
{
  for(int i=0;i<sudokuSize;i++)
    if(mapIn[i]==0)
      return i;
    return -1;
}
//Check if it sticks to the sudoku rule
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
//Solve out the zero positions
bool Sudoku::Solve()
{
  
  int blankPosition;
  
  /*if(checkDark()==-1){
    cout<<0<<endl;return false;
  }*/

  blankPosition=getZero();

  if(blankPosition==-1)
  {
    if(Correct())
    {      
      if(passCount==0){
        for(int i=0;i<sudokuSize;i++){
          mapAnswer[i]=mapIn[i];
          mapIn[i]=testMulti[i];
        }
      }
      ++passCount;
      if(passCount<2){
        Solve();
      
        int c;c=0;
        for(int i=0;i<sudokuSize;i++){
          if(mapIn[i]==mapAnswer[i]){
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
          return true;
        }else{
          cout<<2<<endl;
          return true;
        }
      }
    }
    else
    {
      cout<<0<<endl;
      return false;
    }
  }
  else
  { 

    if(passCount>=1){

     for(int num=9;num>=1;num--)
      {
      //Check the possible numbers to input,
      //records in array Count
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
      
      int ib,locate;
      switch(blankPosition)
      {
        case 0:case 1:case 2:case 12:case 13:case 14:case 24:case 25:case 26:
        ib=0; break;
        case 3:case 4:case 5:case 15:case 16:case 17:case 27:case 28:case 29:
        ib=1; break;
        case 6:case 7:case 8:case 18:case 19:case 20:case 30:case 31:case 32:
        ib=2; break;
        case 9:case 10:case 11:case 21:case 22:case 23:case 33:case 34:case 35:
        ib=3; break;
        case 36:case 37:case 38:case 48:case 49:case 50:case 60:case 61:case 62:
        ib=4; break;
        case 39:case 40:case 41:case 51:case 52:case 53:case 63:case 64:case 65:
        ib=5; break;
        case 42:case 43:case 44:case 54:case 55:case 56:case 66:case 67:case 68:
        ib=6; break;
        case 45:case 46:case 47:case 57:case 58:case 59:case 69:case 70:case 71:
        ib=7; break;
        case 72:case 73:case 74:case 84:case 85:case 86:case 96:case 97:case 98:
        ib=8; break;
        case 75:case 76:case 77:case 87:case 88:case 89:case 99:case 100:case 101:
        ib=9; break;
        case 78:case 79:case 80:case 90:case 91:case 92:case 102:case 103:case 104:
        ib=10; break;
        case 81:case 82:case 83:case 93:case 94:case 95:case 105:case 106:case 107:
        ib=11; break;
        case 108:case 109:case 110:case 120:case 121:case 122:case 132:case 133:case 134:
        ib=12; break;
        case 111:case 112:case 113:case 123:case 124:case 125:case 135:case 136:case 137:
        ib=13; break;
        case 114:case 115:case 116:case 126:case 127:case 128:case 138:case 139:case 140:
        ib=14; break;
        case 117:case 118:case 119:case 129:case 130:case 131:case 141:case 142:case 143:
        ib=15; break;

      }      
        for(int j=0;j<9;j++)
        {
          locate= 36*(ib/4)+3*(ib%4)+12*(j/3)+(j%3);
          Count[mapIn[locate]+1]=1;
        }

      if(Count[num+1]!=1)
      {
        //input numbers
        setElement(blankPosition,num);
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
      int ib,locate;
      switch(blankPosition)
      {
        case 0:case 1:case 2:case 12:case 13:case 14:case 24:case 25:case 26:
        ib=0; break;
        case 3:case 4:case 5:case 15:case 16:case 17:case 27:case 28:case 29:
        ib=1; break;
        case 6:case 7:case 8:case 18:case 19:case 20:case 30:case 31:case 32:
        ib=2; break;
        case 9:case 10:case 11:case 21:case 22:case 23:case 33:case 34:case 35:
        ib=3; break;
        case 36:case 37:case 38:case 48:case 49:case 50:case 60:case 61:case 62:
        ib=4; break;
        case 39:case 40:case 41:case 51:case 52:case 53:case 63:case 64:case 65:
        ib=5; break;
        case 42:case 43:case 44:case 54:case 55:case 56:case 66:case 67:case 68:
        ib=6; break;
        case 45:case 46:case 47:case 57:case 58:case 59:case 69:case 70:case 71:
        ib=7; break;
        case 72:case 73:case 74:case 84:case 85:case 86:case 96:case 97:case 98:
        ib=8; break;
        case 75:case 76:case 77:case 87:case 88:case 89:case 99:case 100:case 101:
        ib=9; break;
        case 78:case 79:case 80:case 90:case 91:case 92:case 102:case 103:case 104:
        ib=10; break;
        case 81:case 82:case 83:case 93:case 94:case 95:case 105:case 106:case 107:
        ib=11; break;
        case 108:case 109:case 110:case 120:case 121:case 122:case 132:case 133:case 134:
        ib=12; break;
        case 111:case 112:case 113:case 123:case 124:case 125:case 135:case 136:case 137:
        ib=13; break;
        case 114:case 115:case 116:case 126:case 127:case 128:case 138:case 139:case 140:
        ib=14; break;
        case 117:case 118:case 119:case 129:case 130:case 131:case 141:case 142:case 143:
        ib=15; break;

      }
        for(int j=0;j<9;j++)
        {
          locate= 36*(ib/4)+3*(ib%4)+12*(j/3)+(j%3);
          Count[mapIn[locate]+1]=1;
        }

      if(Count[num+1]!=1)
      {
        setElement(blankPosition,num);
       if(Solve()){
          return true;}
        setElement(blankPosition,0);
         
      }
    }
   }

   return false;
  }
}
