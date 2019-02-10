#include<iostream>
using namespace std;

int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int day185011 = 1;   //��0��ʼ���� 


bool is_leap(int y)
{
	if(y % 400 == 0)  return true;
	if(y % 4 == 0 && y % 100 != 0)  return true;
	return false;
}

int main()
{
	int a,b,c,y1,y2;
	cin >> a >> b >> c >> y1 >> y2; 
	for(int y = y1;y <= y2; y++)
	{
		//����y��ĵ�a���µĵ�b������c�Ǽ��¼���
		
		//�ȼ����y���1��1�������ڼ�
		int y11,yeardays,daysum = 0;
		for(int i = 1850;i < y; i++) 
		{
			yeardays = is_leap(i) ? 366 : 365;
			daysum += yeardays; 
		}
		
		y11 = (day185011 + daysum) % 7;
		
		//�ټ����i�µĵ�1�� 
		int monthdays = 0;
		
		if(is_leap(y))
			month_days[1] = 29;
		else 
			month_days[1] = 28;
		
		for(int i = 0;i < a-1; i++)
		{
			monthdays += month_days[i];
		}
		
		int ya1 = (y11 + monthdays) % 7;
		
		int day = -1;
		int tb = b;
		for(int i = 0;i < month_days[a-1]; i++)
		{
			if((ya1 + i) % 7 == c-1) 
			{
				tb--;
				if(tb == 0)  
				{
					day = i+1;
					break;
				}
			} 
		}
		
		if(day != -1)
			printf("%d/%02d/%02d\n",y,a,day);
		else 
			cout << "none" << endl;
	}
} 
