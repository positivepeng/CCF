#include<iostream>
#include<string.h>
using namespace std;

int tree[3000];
int num[1004];

int construct(int i,int l,int r,int n)  
{
	//构造线段树 
	if(l == r ) return tree[i] = (l <= n-1? num[l] : 0);
	else 
	{
		int mid = (l + r) / 2;
		tree[2*i+1] = construct(2*i+1,l,mid,n);
		tree[2*i+2] = construct(2*i+2,mid + 1,r,n);
		return tree[i] = min(tree[2 * i + 1],tree[2 * i + 2]);
	}
}

int query(int qlow,int qhigh,int low,int high,int pos)   
{
	//qlow,qhigh: 要查询的边界 
	//low,high:   总边界
	//pos,根的位置
	if(qlow < low || qhigh > high || qlow > qhigh) return -1;
	if(qlow == low && qhigh == high) return tree[pos];
	if(qlow > high && qhigh < low )  return -1;
	
	int mid = (low + high) / 2;
	if(qlow >= mid + 1)	return query(qlow,qhigh,mid+1,high,pos*2+2);
	else if(qhigh <= mid) return query(qlow,qhigh,low,mid,pos*2+1);
	else  return min(query(qlow,mid,low,mid,pos*2+1),query(mid+1,qhigh,mid+1,high,pos*2+2));
}

int main() {

	//用线段树logn查询区间[i,j]的最小值
	//矩形的高  区间[i,j]最小值 
	//矩形的宽  j-i+1 

	memset(tree,0,sizeof(tree));

	int n;
	cin >> n;
	for(int i = 0;i < n; i++)
		cin >> num[i];
	
	construct(0,0,n-1,n);
	
	int maxArea = 0;
	
	for(int i = 0;i < n; i++)
	{
		for(int j = i;j < n; j++)
		{
			int minEdge = query(i,j,0,n-1,0);
			maxArea = max(maxArea,minEdge * (j-i+1));
		}
	}
	cout << maxArea << endl;

}
