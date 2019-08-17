#include <bits/stdc++.h>
using namespace std;

vector<string> parseLine(string line){
	stringstream ss;
	ss.str(line);
	vector<string> ans;
	string temp;
	while(1){
		ss >> temp;
		if(ss.fail())
			break;
		ans.push_back(temp);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int T,n;
	string line;
	cin >> T >> n;
	getchar();
	while(T--){
		vector<string> cmds[n];
		vector<int> cmdCnt(n, 0);
		for(int i = 0;i < n; i++){
			getline(cin, line);
			cmds[i] = parseLine(line);
		}
		int send[n], rev[n];
		// 初始为-1，表示所有程序都空闲 
		memset(send, -1, sizeof(send));
		memset(rev, -1, sizeof(rev));
		
		while(1){
			// 是否有空闲程序在执行 
			int has_run = 0, all_finish = 1;
			
			// 开始运行，每个程序一个指令
			for(int i = 0;i < n; i++){									
				// 当前程序空闲可以执行指令 
				if(rev[i] == -1 && send[i] == -1){ 
					has_run = 1; 
					if(cmdCnt[i] < cmds[i].size()){
						// 取出指令 
						string cmd = cmds[i][cmdCnt[i]++];
						int target_id = stoi(cmd.substr(1, cmd.size()-1));
						 
						if(cmd[0] == 'S'){
							if(rev[target_id] == i)
								rev[target_id] = -1;
							else
								send[i] = target_id;
						}
						else if(cmd[0] == 'R'){
							if(send[target_id] == i)
								send[target_id] = -1;
							else
								rev[i] = target_id;
						}
					}
				}
			}
			
			
			for(int j = 0;j < n; j++){
				if(cmdCnt[j] != cmds[j].size())
					all_finish = 0;
			}
			
			if(has_run == 0 || all_finish == 1)
				break;
		}
		
		int is_lock = 0;
		for(int i = 0;i < n; i++){
			if(!(send[i] == -1 && rev[i] == -1))
				is_lock = 1;
		}
		
		cout << is_lock << endl;
		
	}
	return 0;
}


/*
3 2
R1 S1
S0 R0
R1 S1 
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0

2 3
R1 S1 
R2 S0 R0 S2 
S1 R1
R1 
R2 S0 R0
S1 R1
*/


