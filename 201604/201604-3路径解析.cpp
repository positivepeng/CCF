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
	
	if(line.size() == 0)         //空字符串 
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
	
	if(curr_split.size() == 0)   //根目录 
		return "/";
	
	vector<string> ans;
	
	//相对路径
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
