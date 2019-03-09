/* CCF201703-3 Markdown */
#include <bits/stdc++.h>
using namespace std;
string line, text;
 
// 段落处理
void solve()
{
    // 处理下划线：标签<em></em>
    size_t leftp = text.find("_");
    while(leftp != string::npos) {
        text.replace(leftp, 1, "<em>");
        size_t rightp = text.find("_", leftp);
        text.replace(rightp, 1, "</em>");
        leftp = text.find("_", rightp);
    }
 
    // 处理方括号
    leftp = text.find("[");
    while(leftp != string::npos) {
        size_t rightp = text.find("]", leftp);
        size_t leftp2 = text.find("(", rightp);
        size_t rightp2 = text.find(")", leftp2);
        string tmp = text.substr(leftp + 1, rightp - leftp - 1);
        string tmp2 = text.substr(leftp2 + 1, rightp2 - leftp2 - 1);
        text.replace(text.begin() + leftp, text.begin()+rightp2 + 1, "<a href=\"" + tmp2 + "\">" + tmp + "</a>");
        leftp = text.find("[", rightp2);
    }
 
    if(text[0] == '#') {
        // 处理#：标签<h></h>
        int i = 0;
        while(text[i] == '#') i++;
        text = "<h" + string(1, '0' + i) + ">" + text.substr(i + 1);
        text.insert(text.size() - 1, "</h" + string(1, '0' + i) + ">");
    } else if(text[0] == '*') {
        // 处理*：标签<ul><li></li>......</ul>
        text.insert(0, "<ul>\n");
        text.insert(text.size(), "</ul>\n");
        size_t leftp = text.find("*");
        while(leftp != string::npos) {
            size_t rightp = text.find("\n", leftp);
            text.insert(rightp, "</li>");
            text.replace(leftp, 2, "<li>");
            leftp = text.find("*", rightp);
        }
    } else {
            // 处理段落：<p></p>
            text = "<p>" + text.substr(0, text.size() - 1) + "</p>\n";
    }
 
    cout << text;
    text = "";
}
 
int main()
{
    bool flag = false;
 
    getline(cin, line);
    for(;;) {
        if(line.size() > 0)
            text += line + "\n";
        else if(line.size() == 0 && text.size() > 0)
            solve();
 
        if(flag) break;
        if(!getline(cin, line)) {
            flag = true;
            line = "";
        }
    }
 
    return 0;
}
 
/*
# Heading
## Sub-heading
Paragraphs are separated
by a blank line.
text attributes _italic_.
Bullet list:
* apples
* oranges
* pears
A [link](http://example.com).
*/
