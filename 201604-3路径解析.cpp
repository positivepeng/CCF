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
	// 一个路径经过正规化操作后，其指定的文件不变，
	// 但是会变成一个不包含 . 和 .. 的绝对路径，
	// 且不包含连续多个 / 符号。如果一个路径以 / 结尾
	// 那么它代表的一定是一个目录，正规化操作要去掉结尾的 /。
	// 若这个路径代表根目录，则正规化操作的结果是 /。
	// 若路径为空字符串，则正规化操作的结果是当前目录。           <-----
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
	
	//相对路径
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





















