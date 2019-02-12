#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int main()
{
	int n, clen=0;         //clen代表目录的长度
	string s, content;
	cin >> n;
	cin >> content;        //输入当前目录
	string ans = "";       //临时存放变量
	string layer1[1010];   //存储各个层次的路径
	content  +=  '/';      //末尾加上/方便处理
	for (int i = 1; i < (int)content.length(); i++)
	{
		if (content[i] == '/')
		{
			clen++ ,layer1[clen] = ans;
			ans = "";
		}
		else ans += content[i];
	}
	getchar();//吸收换行
	while (n--)
	{
		string layer[1010];
		int len;
		ans = "";
		getline(cin, s);
		if (s.length() == 0) //空行
		{
			content.erase(content.length() - 1, 1);
			cout << content << endl;
			continue;
		}
		s += '/';
		if (s[0] == '/') //如果是绝对路径
		{
			len = 0;
		}
		else           //相对路径
		{
			for (int i = 1; i <= clen; i++) layer[i] = layer1[i];
			len = clen;
		}
		for (int i = 0; i < (int)s.length(); i++)
		{
			if (s[i] == '/')
			{
				if (ans.length()==0) continue ;
				if (ans == ".") ;
				else if (ans == "..")
				{
					if (len > 0) len--;
				}
				else len++,layer[len] = ans;
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

