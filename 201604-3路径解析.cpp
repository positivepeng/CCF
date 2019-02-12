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
	string ans = "";
	
	if(line.size() == 0)
		ans = ans + curr;
	
	vector<string> splits = split(line,"/");
	
	for(int i = 0;i < splits.size(); i++)
		cout << splits[i] << " " << splits[i].size() << " ";
	cout << endl;
	
	vector<int> valid(splits.size());
	for(int i = 0;i < valid.size(); i++)
		valid[i] = 1;
	
	if(splits.size() == 0)
		cout << "/" << endl;
	
	//���·��
	if(line[0] == '.') 
	{
		
	}
	
	
	
	return "";
	
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





















