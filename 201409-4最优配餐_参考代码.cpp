
/* CCF201409-4 ������� */

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1000;
const int TRUE = 1;

const int DIRECTSIZE = 4;
struct direct
{
	int drow, dcol;
} direct[DIRECTSIZE] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int buyer[N+1][N+1];
int visited[N+1][N+1];

struct node
{
	int row, col, step;
	node() {}
	node(int r, int c, int s)
	{
		row=r, col=c, step=s;
	}
};

queue<node> q;
int buyercount = 0;
long long ans = 0;

void bfs(int n)
{
	node front, v;

	while(!q.empty())
		{
			front = q.front();
			q.pop();

			for(int i=0; i<DIRECTSIZE; i++)
				{
					// �ƶ�һ��
					v.row = front.row + direct[i].drow;
					v.col = front.col + direct[i].dcol;
					v.step = front.step + 1;

					// ����Խ��������
					if(v.row < 1 || v.row > n || v.col < 1 || v.col > n)
						continue;

					// �Ѿ����ʹ��ĵ㲻�ٷ���
					if(visited[v.row][v.col])
						continue;

					// ����Ƕ��͵㣬�����ɱ������ۼ�
					if(buyer[v.row][v.col] > 0)
						{
							visited[v.row][v.col] = 1;
							ans += buyer[v.row][v.col] * v.step;
							if(--buyercount == 0)
								return;
						}

					// ��ǰ���������v��Ϊ�Ѿ����ʹ���v����������
					visited[v.row][v.col] = 1;
					q.push(v);
				}
		}
}

int main()
{
	int n, m, k, d, x, y, c;

	// ������ʼ��
	memset(buyer, 0, sizeof(buyer));
	memset(visited, 0, sizeof(visited));

	// ��������
	cin >> n >> m >> k >> d;
	for(int i=1; i<=m; i++)
		{
			cin >> x >> y;
			q.push(node(x, y, 0));
			visited[x][y] = TRUE;      // �����ֵ�����ʱ����Ҫ����
		}
	for(int i=1; i<=k; i++)
		{
			cin >> x >> y;
			cin >> c;
			if(buyer[x][y] == 0)    // ͳ�ƿͻ����ڵص�����������ͻ�������ͬһ�ص�
				buyercount++;
			buyer[x][y] += c;       // ͳ��ĳ���ص�Ķ�������
		}
	for(int i=1; i<=d; i++)
		{
			cin >> x >> y;
			visited[x][y] = TRUE;
		}

	// BFS
	bfs(n);

	// ������
	cout << ans << endl;

	return 0;
}

