#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--){
		string line;
		cin >> line; 
		deque<char> op;
		deque<int> num;
		for(int i = 0;i < line.size(); i++){
			char ch = line[i];
			int num1,num2;
			if(ch == 'x' || ch == '/'){
				num1 = num.back();num.pop_back();
				num2 = line[++i] - '0';
				if(ch == 'x')
					num.push_back(num1 * num2);
				else
					num.push_back(num1 / num2);
			}
			else if(ch == '+' || ch == '-')
				op.push_back(ch);
			else
				num.push_back(ch-'0');
		}
	
		while(!op.empty())
		{
			char op1 = op.front();op.pop_front();
			int num1 = num.front();num.pop_front();
			int num2 = num.front();num.pop_front();
			num.push_front((op1 == '+') ? (num1 + num2) : (num1 - num2));
		}
		
		if(num.front() == 24)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;		
	}
	
	return 0;
}


