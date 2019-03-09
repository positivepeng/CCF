#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

int main()
{
	int n, clen=0;         //clen����Ŀ¼�ĳ���
	string s, content;
	cin >> n;
	cin >> content;        //���뵱ǰĿ¼
	string ans = "";       //��ʱ��ű���
	string layer1[1010];   //�洢������ε�·��
	//content  +=  '/';      //ĩβ����/���㴦��
	
	//�ָǰĿ¼ 
//	for (int i = 1; i < (int)content.length(); i++)
//	{
//		if (content[i] == '/')
//		{
//			layer1[++clen] = ans;
//			ans = "";
//		}
//		else 
//			ans += content[i];
//	}
	vector<string> temp = split(content,"/");
	for(int i = 0;i < temp.size(); i++)
		layer1[i+1] = temp[i];
	
	getchar();			//���ջ���
	while (n--)
	{
		string layer[1010];
		int len;
		ans = "";
		getline(cin, s);
		
		if (s.length() == 0)         //����
		{
			content.erase(content.length() - 1, 1);        // ȡ������'/' 
			cout << content << endl;
			continue;
		}
		
		s += '/';
		if (s[0] == '/') //����Ǿ���·��
		{
			len = 0;
		}
		else             //���·��
		{
			for (int i = 1; i <= clen; i++) 
				layer[i] = layer1[i];
			len = clen;
		}
		for (int i = 0; i < (int)s.length(); i++)
		{
			if (s[i] == '/')
			{
				if (ans.length()==0) 
					continue ;
				if (ans == ".") ;
				else if (ans == "..")
				{
					if (len > 0) 
						len--;
				}
				else 
				{
					len++;
					layer[len] = ans;
				}
				ans = "";
			}
			else  ans += s[i];
		}
		cout << "/";
		for (int i = 1; i <=len; i++)
		{
			if (i != 1) cout << "/";
			cout << layer[i];
		}
		cout << endl;
	}
	return 0;
}

