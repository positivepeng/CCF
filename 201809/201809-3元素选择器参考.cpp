#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <stack>
#include <ctype.h>
#include <map>
#include <sstream>
 
using namespace std;
 
struct Node{
	int no;
	string label;
	string id;
};
 
//变成小写
string tolow(string s)
{
	for(int i = 0;i<s.length();i++)
		s[i] = tolower(s[i]);
	return s;
} 
 
//分割字符串,并且放在容器内
void split(string s,vector<string>&v) 
{
	stringstream ss;
	string temp;
	ss.str(s);
	while(!ss.eof())
	{
		ss >> temp;
		v.push_back(temp);
	}
}
 
 
vector<string>demands;       //命令 
map<string,int>an;           //祖先的label和id,   以及命令中要求的段数 
 
int main() {
	int n,m,i;
	char c;
	
	//放置数组
	vector<Node>nodes; 
	
	//读入行数 
	cin >> n >> m;
	cin.ignore();
	
	for(i = 0;i < n; i++)
	{
		int flag = 0;
		int tno = 0;
		string tlabel = "";
		string tid = "";
		Node temp;
		while((c=getchar())!='\n')
		{
			if(c=='.')//no
			{
				tno++;
			}
			else if(c=='#') //id
			{
				cin >> tid;
				getchar();
				temp.id = c + tid;
				break;
			}
			else       //label
			{
				tlabel+=c;
				while((c=getchar())!=' ')
				{
					if(c=='\n')
					{
						flag = 1;
						break;
					}
					tlabel+=c;
				}
				temp.label = tolow(tlabel);
			}
			if(flag) break;
		}
		temp.no = tno/2;
		nodes.push_back(temp);
		//cout<<temp.no<<" "<<temp.label<<" "<<temp.id<<endl;
	}
	//开始操作
	while(m--)
	{
		char d[100]; 
		vector<int>ans;//保存行数 
		gets(d);
		split(d,demands);
		//全部id变小写
		for(int i = 0;i<demands.size();i++)
		{
			if(demands[i][0]!='#') demands[i] = tolow(demands[i]);
		} 
		if(demands.size()==1)//如果只有一个的话直接可以匹配 
		{
			//匹配有没有相等的情况 
			for(int i =0;i<n;i++)
			{
				if(nodes[i].label == demands[0] ||nodes[i].id== demands[0])
				{
					ans.push_back(i);
				}
			}
		}
		//是后继选择器
		else
		{			
			for(int i = 0;i<n;i++)
			{
				int len = demands.size()-1;
				//找到第一个了 
				if(nodes[i].label == demands[len]||nodes[i].id== demands[len])
				{
					len--;
					for(int j = i-1;j>=0&&nodes[j].no<=nodes[i].no;j--)
					{
						if(nodes[j].no<nodes[i].no)
						{
							if(nodes[j].label == demands[len]||nodes[j].id == demands[len])
							{
								len--;
								if(len==-1) break;
							}
						}
					}
				}
				if(len==-1)
					ans.push_back(i);		
			}
		} 		
		cout<<ans.size()<<" ";
			for(int i = 0;i<ans.size();i++)
				cout<<ans[i]+1<<" ";
			cout<<endl;
	} 
	return 0;
}
 
/*
11 5
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #one
......div
........p #two
div div p
p
h1 #subtitle
html
div p
*/
 

