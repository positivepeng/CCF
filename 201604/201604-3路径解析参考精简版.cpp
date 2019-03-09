#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string path, s, str;
    cin >> path;
    cin.get();          // 用getline时千万要注意吸收这个换行符
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        if (str == "") 
			str = path;
        if (str[0] != '/') 
			str = path + '/' + str;
		
        for (int j = 0; j < str.size(); ++j) 
            if (str[j] == '/') str[j] = ' ';
		 
        vector<string> sta;
        stringstream ss(str);
        while (ss >> s) 
		{
            if (s == ".") continue;
            else if (s == ".." && !sta.empty()) 
				sta.pop_back();
            else if (s != "..") 
				sta.push_back(s);
        }
        cout << '/';
        for (int j = 0; j < sta.size(); ++j) {
            if (j) cout << '/';
            cout << sta[j];
        }
        cout << endl;
    }
}
//--------------------- 
//作者：姬小野 
//来源：CSDN 
//原文：https://blog.csdn.net/wjh2622075127/article/details/81534470 
//版权声明：本文为博主原创文章，转载请附上博文链接！
