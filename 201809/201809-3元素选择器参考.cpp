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
 
//���Сд
string tolow(string s)
{
	for(int i = 0;i<s.length();i++)
		s[i] = tolower(s[i]);
	return s;
} 
 
//�ָ��ַ���,���ҷ���������
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
 
 
vector<string>demands;       //���� 
map<string,int>an;           //���ȵ�label��id,   �Լ�������Ҫ��Ķ��� 
 
int main() {
	int n,m,i;
	char c;
	
	//��������
	vector<Node>nodes; 
	
	//�������� 
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
	//��ʼ����
	while(m--)
	{
		char d[100]; 
		vector<int>ans;//�������� 
		gets(d);
		split(d,demands);
		//ȫ��id��Сд
		for(int i = 0;i<demands.size();i++)
		{
			if(demands[i][0]!='#') demands[i] = tolow(demands[i]);
		} 
		if(demands.size()==1)//���ֻ��һ���Ļ�ֱ�ӿ���ƥ�� 
		{
			//ƥ����û����ȵ���� 
			for(int i =0;i<n;i++)
			{
				if(nodes[i].label == demands[0] ||nodes[i].id== demands[0])
				{
					ans.push_back(i);
				}
			}
		}
		//�Ǻ��ѡ����
		else
		{			
			for(int i = 0;i<n;i++)
			{
				int len = demands.size()-1;
				//�ҵ���һ���� 
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
 

