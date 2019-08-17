#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int most(int n)
{
	if(n < 10)	 return 0;
	else if(n == 10)  return 1;
	else if(n == 30)  return 4;
	else if(n == 50)  return 7;
	else if(n >= 50)
		return max(max(1 + most(n-10) ,4 + most(n-30)),most(n-50) + 7);
	else if(n >= 30)
		return max(1 + most(n-10) , 4 + most(n-30));
	else
		return 1 + most(n-10);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << most(n) << endl;
	return 0;
}

