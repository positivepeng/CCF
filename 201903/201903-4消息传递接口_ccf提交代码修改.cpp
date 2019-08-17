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
	// 将读入的一行分割为多个命令，并且过滤掉自己发给自己的命令 
	stringstream ss;
	string temp;
	ss.str(line);
	while(1)
	{
		ss >> temp;
		if(ss.fail())
			return ;
		if(stoi(temp.substr(1, temp.size()-1)) != j)     // 不收发自己的 
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
		int waitR[n];       //  等待R操作，waitR[i]=j表示i在等待j执行R操作 
		int waitS[n];       //  等待S操作，waitS[i]=j表示i在等待j执行S操作 
	
		memset(waitR,-1,sizeof(waitR));
		memset(waitS,-1,sizeof(waitS));    // -1表示没有等待，否则表示等待的id 
		
		for(int j = 0;j < n; j++)
		{
			getline(cin,line);
			split(j,messages[j],line);
		}
		
		while(1)
		{
			// 存放本轮运行的消息 
			vector<P> curr;
			for(int j = 0;j < n; j++)
			{
				if(!messages[j].empty())         // 第j个进程还没有执行完 
				{
					if(waitR[j] == -1 && waitS[j] == -1)              //没有被卡住
					{
						curr.push_back(make_pair(j, messages[j].front()));
						messages[j].pop();
					} 	
				}
			}
			
			if(curr.size() == 0)               // 没有消息执行了就退出 
				break;
			
			for(int i = 0;i < curr.size(); i++)
			{
				P t = curr[i];
				
				// 如果是收消息
				if(t.second[0] == 'R')
				{
					int rever = t.first;
					int sender = stoi(t.second.substr(1, t.second.size()-1));
					// 如果对方正在等待发送，则此时可以发送成功 
					if(waitS[sender] == rever)
					 	waitS[sender] = -1;
					else    // 等待接收 
						waitR[rever] = sender;
				}
				else if(t.second[0] == 'S')       // 发消息 
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
