#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#define N 10
#define HOME 0
#define DIRECTORY 1
#define FILE 2
using namespace std;

typedef struct DIR
{
	string par;
	set<string> childs;
	int type;
}dir;

map<string,dir> dirs;

void init()
{
	dir home;
	home.type = HOME:
	home.par = "NONE";
	home.childs.insert("d1");
	home.childs.insert("d2");
	dirs["/"] = home;
	
	dir d1;
	d1.type = DIRECTORY;
	d1.par = "/"
	d1.childs.insert("f1");
	d1.childs.insert("f2");
	dirs["d1"] = d1;
	
	dir f1;
	f1.type = FILE:
	f1.par = "d1";
	dirs["f1"] = f1;
	
	dir f2;
	f2.type = FILE:
	f2.par = "d1";
	dirs["f2"] = f2;
	
	dir d2;
	d2.type = DIRECTORY;
	d2.par = "/";
	d2.childs.insert("d3");
	d2.childs.insert("d4");
	d2.childs.insert("f4");
	dirs["d2"] = d2;
	
	dir d3;
	d3.type = DIRECTORY;
	d3.par = "d2";
	d3.childs.insert("f3");
	dirs["d3"] = d3;
	
	dir d4;
	d4.type = DIRECTORY;
	d4.par = "d2";
	d4.childs.insert("f1");
	dirs["d4"] = d4;
	
	
	
	
	
	
	
	

}
int main(int argc, char const *argv[])
{
	return 0;
}

