#include<iostream>
#include<string>
#include<sstream>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<set>
#include<map> 
#include<algorithm> 

using namespace std;

typedef long long ll;
typedef pair<int,string> P;

using namespace std;

void split(int j, queue<string>& message,string line)
{
	// �������һ�зָ�Ϊ���������ҹ��˵��Լ������Լ������� 
	stringstream ss;
	string temp;
	ss.str(line);
	while(1)
	{
		ss >> temp;
		if(ss.fail())
			return ;
		if(stoi(temp.substr(1, temp.size()-1)) != j)     // ���շ��Լ��� 
			message.push(temp);
	}
}


int main()
{
	int T,n;
	string line;
	cin >> T >> n;
	cin.ignore();
	while(T--)
	{
		queue<string> messages[n];
		int waitR[n];       //  �ȴ�R������waitR[i]=j��ʾi�ڵȴ�jִ��R���� 
		int waitS[n];       //  �ȴ�S������waitS[i]=j��ʾi�ڵȴ�jִ��S���� 
	
		memset(waitR,-1,sizeof(waitR));
		memset(waitS,-1,sizeof(waitS));    // -1��ʾû�еȴ��������ʾ�ȴ���id 
		
		for(int j = 0;j < n; j++)
		{
			getline(cin,line);
			split(j,messages[j],line);
		}
		
		while(1)
		{
			// ��ű������е���Ϣ 
			vector<P> curr;
			for(int j = 0;j < n; j++)
			{
				if(!messages[j].empty())         // ��j�����̻�û��ִ���� 
				{
					if(waitR[j] == -1 && waitS[j] == -1)              //û�б���ס
					{
						curr.push_back(make_pair(j, messages[j].front()));
						messages[j].pop();
					} 	
				}
			}
			
			if(curr.size() == 0)               // û����Ϣִ���˾��˳� 
				break;
			
			for(int i = 0;i < curr.size(); i++)
			{
				P t = curr[i];
				
				// ���������Ϣ
				if(t.second[0] == 'R')
				{
					int rever = t.first;
					int sender = stoi(t.second.substr(1, t.second.size()-1));
					// ����Է����ڵȴ����ͣ����ʱ���Է��ͳɹ� 
					if(waitS[sender] == rever)
					 	waitS[sender] = -1;
					else    // �ȴ����� 
						waitR[rever] = sender;
				}
				else if(t.second[0] == 'S')       // ����Ϣ 
				{
					int sender = t.first;
					int rever = stoi(t.second.substr(1, t.second.size()-1));
					
					if(waitR[rever] == sender)
						waitR[rever] = -1;
					else
						waitS[sender] = rever;
				}
			}
		 
		}
		
		int is_lock = 0;
		for(int i = 0;i < n; i++)
		{
			if(!(waitS[i] == -1 && waitR[i] == -1))
			{
				is_lock = 1;
				break;
			}
		}
		
		cout << is_lock << endl; 
		 
	}
	return 0;
}
