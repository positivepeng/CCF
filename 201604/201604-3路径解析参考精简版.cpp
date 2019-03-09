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
    cin.get();          // ��getlineʱǧ��Ҫע������������з�
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
//���ߣ���СҰ 
//��Դ��CSDN 
//ԭ�ģ�https://blog.csdn.net/wjh2622075127/article/details/81534470 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
