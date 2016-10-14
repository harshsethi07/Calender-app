#include <iostream>
//#include <conio>
#include <cstring>

using namespace std;

int isleap(int year)
{
   if(year%400==0||(year%100!=0&&year%4==0))
      return 1;
   return 0;
}

int fd_year(int year)
{
   int x=1,days=0;
   for(;;)
   {
      if(x==year)      return days%7;
      if(!isleap(x))   days++;
      else             days+=2;
      x++;
   }
}

int max_day(int year,int mnth)
{
   switch(mnth)
   {
      case 1:  return 31;
      case 2:  if(isleap(year)) return 29;
               else             return 28;
      case 3:  return 31;
      case 4:  return 30;
      case 5:  return 31;
      case 6:  return 30;
      case 7:  return 31;
      case 8:  return 31;
      case 9:  return 30;
      case 10: return 31;
      case 11: return 30;
      case 12: return 31;
   }
}

int fd_mnth(int year,int mnth)
{
   int x=fd_year(year);
   while(mnth!=1)
      x+=max_day(year,--mnth);
   return x%7;
}

void decode(char name[],int mnth)
{
   switch(mnth)
   {
      case 1:  strcpy(name,"January");   break;
      case 2:  strcpy(name,"February");  break;
      case 3:  strcpy(name,"March");     break;
      case 4:  strcpy(name,"April");     break;
      case 5:  strcpy(name,"May");       break;
      case 6:  strcpy(name,"June");      break;
      case 7:  strcpy(name,"July");      break;
      case 8:  strcpy(name,"August");    break;
      case 9:  strcpy(name,"September"); break;
      case 10: strcpy(name,"October");   break;
      case 11: strcpy(name,"November");  break;
      case 12: strcpy(name,"December");  break;
   }
}

void print(int year,int mnth)
{
   int i,j,temp=fd_mnth(year,mnth);
   char name[30];
   decode(name,mnth);
   cout<<"\n\nCalender for "<<name<<" month of "<<year<<"\n\n";
   cout<<"\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n\n";
   for(i=1;i<=max_day(year,mnth);)
   {
      cout<<"\t";
      for(j=0;j<7;j++)
      {
         if(i==1) j=temp;
         while(temp!=0){ cout<<"\t";  temp--; }
         cout<<i++<<"\t";
         if(i>max_day(year,mnth)) break;
      }
      cout<<"\n\n";
   }
}

int main()
{
   int year,mnth,choice,i;
   while(1)
   {
      cout<<"\nMain Menu:\n\n1. Print calender for a month\n2. Print calender of a year\n3. Print whether a year is leap or not\n\n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice)
      {
         case 1: cout<<"Enter year: ";           cin>>year;
                 cout<<"Enter month: ";          cin>>mnth;
                 print(year,mnth);
                 //getch();                        
                 break;
         case 2: cout<<"Enter year: ";           cin>>year;
                 for(i=1;i<13;i++)               print(year,i);
                 //getch();                        
                 break;
         case 3: cout<<"Enter year to check: ";  cin>>year;
                 if(isleap(year))                cout<<"Its a leap year\n";
                 else                            cout<<"Its not a leap year\n";
                 //getch();                        
                 break;
      }
   }
}