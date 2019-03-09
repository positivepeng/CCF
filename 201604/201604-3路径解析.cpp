#include<iostream>
#include<cstring>
#include<string>
#include<vector>
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


string solve(string curr,string line)
{
	// һ��·���������滯��������ָ�����ļ����䣬
	// ���ǻ���һ�������� . �� .. �ľ���·����
	// �Ҳ������������ / ���š����һ��·���� / ��β
	// ��ô�������һ����һ��Ŀ¼�����滯����Ҫȥ����β�� /��
	// �����·�������Ŀ¼�������滯�����Ľ���� /��
	// ��·��Ϊ���ַ����������滯�����Ľ���ǵ�ǰĿ¼��           <-----
	
	if(line.size() == 0)         //���ַ��� 
		return curr;
	
	vector<string> curr_split = split(curr,"/");
	vector<string> line_split = split(line,"/");
	
//	cout << "curr_dir : ";
//	for(int i = 0;i < curr_split.size(); i++)
//		cout << curr_split[i] << " ";
//	cout << endl;
//	cout << "line_dir : ";
//	for(int i = 0;i < line_split.size(); i++)
//		cout << line_split[i] << " ";
//	cout << endl;
	
	if(curr_split.size() == 0)   //��Ŀ¼ 
		return "/";
	
	vector<string> ans;
	
	//���·��
	if(line[0] == '.') 
	{
	 	ans = curr_split;
		for(int i = 0;i < line_split.size(); i++)
		{
			if(line_split[i].compare("..") == 0)
			{
				if(!ans.empty())
					ans.erase(ans.end()-1);
			}
			else if(line_split[i].compare(".") == 0)
				continue;
			else
				ans.push_back(line_split[i]);
		}
	}
	else
	{
		for(int i = 0;i < line_split.size(); i++)
		{
			if(line_split[i].compare("..") == 0)
			{
				if(!ans.empty())
					ans.erase(ans.end()-1);
			}
			else if(line_split[i].compare(".") == 0)
				continue;
			else
				ans.push_back(line_split[i]);
		}
	}
	
	string ans_str = "/";
	for(int i = 0;i < ans.size(); i++)
	{
		if(i == 0)
			ans_str += ans[i];
		else
			ans_str += "/" + ans[i];
	}
	
	return ans_str;
}

int main()
{
	int n;
	string line,curr;
	cin >> n;
	cin >> curr;
	cin.ignore();
	
	for(int i = 0;i < n; i++)
	{
		getline(cin,line);
		cout << solve(curr,line) << endl;
	}
}
