#include<iostream>
using namespace std;

int mon_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_leap(int year)
{
	if(year % 400 == 0)  return true;
	if(year % 4 == 0 && year % 100 != 0)   return true;
	return false;
}

int main()
{
	int y,d;
	int month = 1,day = 0;

	cin >> y >> d;
	if(is_leap(y))
		mon_days[2] = 29;
	else
		mon_days[2] = 28;
	
	while(1)
	{
		if(d > mon_days[month])  
		{
			d -= mon_days[month];
			month++;
		}
		else 
		{
			day = d;
			break;
		}
	}
	
	cout << month << endl;
	cout << day << endl;
	
	
	
}
