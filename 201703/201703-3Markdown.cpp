#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>

#define PARAGRAPH 0
#define TITLE 1
#define UNORDERLIST 2
#define LINE 3

using namespace std;

/*
	!!!!!!!!!!!!!!! <50分代码 ，100分代码见参考代码 > !!!!!!!!!!!!!!1 
*/

void deal_inline(vector<string>& lines)
{
	for(int i = 0;i < lines.size(); i++)
	{
		//deal _text_
//		int pos = -1,cnt = 0;
//		while(1)
//		{
//			pos = lines[i].find("_",pos+1);
//			if(pos == -1)
//				break;
//			if(cnt % 2 == 0)
//			{
//				lines[i].replace(pos,1,"<em>");
//				cnt++; 
//			}
//			else
//			{
//				lines[i].replace(pos,1,"</em>");
//				cnt++;
//			}
//		}
		// 处理下划线：标签<em></em>
	    size_t leftp = lines[i].find("_");
	    while(leftp != string::npos) 
		{
	        lines[i].replace(leftp, 1, "<em>");
	        size_t rightp = lines[i].find("_", leftp);
	        lines[i].replace(rightp, 1, "</em>");
	        leftp = lines[i].find("_", rightp);
	    }
		
		//deal []()
//		if(lines[i].find("[") != -1)
//		{
//			int pos = -1;
//			while(1)
//			{
//				int text_left = lines[i].find("[",pos+1);
//				int text_right = lines[i].find("]",pos+1);
//				int link_left = lines[i].find("(",pos+1);
//				int link_right = lines[i].find(")",pos+1);
//				
//				pos = link_right;
//				
//				if(pos == -1)
//					break;
//				
//				string text = lines[i].substr(text_left+1,text_right-text_left-1);
//				string link = lines[i].substr(link_left+1,link_right-link_left-1);
//				
//				lines[i].replace(text_left,link_right - text_left + 1,"<a href=\"" + link + "\">" + text + "</a>");
//			}
//		}
		// 处理方括号
	    leftp = lines[i].find("[");
	    while(leftp != string::npos) {
	        size_t rightp = lines[i].find("]", leftp);
	        size_t leftp2 = lines[i].find("(", rightp);
	        size_t rightp2 = lines[i].find(")", leftp2);
	        string tmp = lines[i].substr(leftp + 1, rightp - leftp - 1);
	        string tmp2 = lines[i].substr(leftp2 + 1, rightp2 - leftp2 - 1);
	        lines[i].replace(lines[i].begin() + leftp, lines[i].begin()+rightp2 + 1, "<a href=\"" + tmp2 + "\">" + tmp + "</a>");
	        leftp = lines[i].find("[", rightp2);
	    }		
	}
}

void solve_title(string &text)
{
	int level = 0;
	while(s[level] == '#')
	{
		level++;
		if(level == 6)
			break;
	}
	
	int start = level;
	while(s[start] == ' ') 
		start++;
	
	string heading = "h0";
	heading[1] = level + '0';
	
	string title = s.substr(start,s.size() - start);
	
	s = "<" + heading + ">" + title + "</" + heading + ">";
}

int solve_list(int begin,vector<string> &lines)
{
	lines.insert(lines.begin()+begin,"<ul>");
	
	int i = begin + 1;
	for(;i < lines.size(); i++)
	{
		if(lines[i].size() > 0 && lines[i][0] == '*')
		{
			int start = 1;
			while(lines[i][start] == ' ')
				start++;
			string text = lines[i].substr(start,lines[i].size()-start);
			lines[i] = "<li>" + text + "</li>";
		}
		else
			break;
	}
	
	lines.insert(lines.begin()+i,"</ul>");
	
	return i+1;
}

int solve_para(int begin,vector<string> &lines)
{
	int i = begin;
	lines[i] = "<p>" + lines[i];
	while((lines[i].size() > 0  && lines[i][0] != '<') || i == begin)
		i++;
	
	lines[i-1] = lines[i-1] + "</p>";
	
	return i-1;
}

void deal_block(vector<string>& lines)
{	
	
	for(int i = 0;i < lines.size(); i++)
	{
		if(lines[i].size() == 0 || (lines[i][0] == '<' && lines[i][lines.size()-1] == '>'))
			continue;
		if(lines[i][0] == '#') 
			solve_title(lines[i]);
		else if(lines[i][0] == '*')       //this code can't deal it appears at the beginning
			i = solve_list(i,lines);
		else
			i = solve_para(i,lines);
	}
}



int main(int argc, char const *argv[])
{
	string line;
	vector<string> lines;
	
	while(getline(cin,line) && line.compare("!!") != 0) 
		lines.push_back(line);
	
	deal_inline(lines);
	deal_block(lines);
	
	
	for(int i = 0;i < lines.size(); i++)
	{
		if(lines[i].size() != 0)
			cout << lines[i] << endl;
	}
		
	return 0;
}

