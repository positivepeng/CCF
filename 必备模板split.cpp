#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

template<typename Out>
void split(const  string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

int main()
{
	string s = "/articles/<int>/<int>/<str>/";
	vector<string> results = split(s,'/');
	for(int i = 0;i < results.size(); i++)
		cout << results[i] << " " << results[i].size() << endl;
	
}
