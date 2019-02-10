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

void deal_inline(vector<string>& lines)
{
	for(int i = 0;i < lines.size(); i++)
	{
		//deal _text_
		int pos = -1,cnt = 0;
		while(1)
		{
			pos = lines[i].find("_",pos+1);
			if(pos == -1)
				break;
				
			if(cnt % 2 == 0)
			{
				lines[i].replace(pos,1,"<em>");
				cnt++; 
			}
			else
			{
				lines[i].replace(pos,1,"</em>");
				cnt++;
			}
	
		}
		
		//deal []()
		if(lines[i].find("[") != -1)
		{
			int pos = -1;
			while(1)
			{
				int text_left = lines[i].find("[",pos+1);
				int text_right = lines[i].find("]",pos+1);
				int link_left = lines[i].find("(",pos+1);
				int link_right = lines[i].find(")",pos+1);
				
				pos = link_right;
				
				if(pos == -1)
					break;
				
				string text = lines[i].substr(text_left+1,text_right-text_left-1);
				string link = lines[i].substr(link_left+1,link_right-link_left-1);
				
				lines[i].replace(text_left,link_right - text_left + 1,"<a href=\"" + link + "\">" + text + "</a>");
			}
		}
	}
}

vector<int> get_block_type(vector<string>& lines)
{
	// p.first  : the type of the block
	// p.second : the level of the title
	vector<int> block_type;     
	
	
	for(int i = 0;i < lines.size(); i++)
	{
		string s = lines[i];
		if(s.size() == 0)
			block_type.push_back(LINE);
		else if(s.find("#") != -1)
			block_type.push_back(TITLE);
		else if(s.find("*") != -1)
			block_type.push_back(UNORDERLIST);
		else
			block_type.push_back(PARAGRAPH);
	}
	
	return block_type;
}

void solve_title(string &s)
{
	int level = 0;
	while(s[level] == '#')
		level++;
	
	int start = level;
	while(s[start] == ' ') 
		start++;
	
	string heading = "h0";
	heading[1] = level + '0';
	
	string title = s.substr(start,s.size() - start);
	
	s = "<" + heading + ">" + title + "</" + heading + ">";
	
}

void solve_list(int begin,vector<string> &lines,vector<int> types)
{
	lines[begin-1] = "<ul>";
	int i = begin;
	for(;i < lines.size(); i++)
	{
		if(types[i] == UNORDERLIST)
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
	lines[i] = "</ul>";
}

void solve_para(int begin,vector<string> &lines,vector<int> types)
{
	int i = begin;
	lines[i] = "<p>" + lines[i];
	while(types[i] == PARAGRAPH)
		i++;
	lines[i-1] = lines[i-1] + "</p>";
}

void deal_block(vector<string>& lines)
{
	vector<int> types = get_block_type(lines);
	
	for(int i = 0;i < lines.size(); i++)
	{
		if(lines[i].size() == 0)
			continue;
		if(types[i] == TITLE)
			solve_title(lines[i]);
		if(types[i] == UNORDERLIST)       //this code can't deal it appears at the beginning
		{
			solve_list(i,lines,types);
			while(types[i] == UNORDERLIST)
				i++;
		}
		if(types[i] == PARAGRAPH)
		{
			solve_para(i,lines,types);
			while(types[i] == PARAGRAPH)
				i++;
		}
	}
	
}



int main(int argc, char const *argv[])
{
	string line;
	vector<string> lines;
	vector<string> ans;
	
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

