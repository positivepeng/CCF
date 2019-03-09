#include<bits\stdc++.h>
using namespace std;

const int N = 1005;

typedef vector<int> vec;
typedef vector<vec> mat;

//矩阵相乘函数
mat mul(mat &x, mat &y) 
{
    mat res(x.size(), vec(y[0].size()));
    for (int i = 0; i < x.size(); i++) 
	{
        for (int k = 0; k < y.size(); k++) 
		{
            if (x[i][k])
            {
                for (int j = 0; j < y[0].size(); j++) 
                    res[i][j] ^= x[i][k] & y[k][j];
            }
        }
    }
    return res;
}
//矩阵快速幂
mat pow(mat M, int n) {
    mat res(M.size(), vec(M.size()));
    for (int i = 0; i < M.size(); i++)  res[i][i] = 1; //初始化单位矩阵
    while (n > 0) {
        if (n & 1)
            res = mul(res, M);
        M = mul(M, M);
        n >>= 1;
    }
    return res;
}

int main() {
    int n, q, k;
    cin >> n;

    mat A(n, vec(n));

    char *s = new char[n + 1];
    //输入A矩阵
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < n; j++) {
            A[i][j] = s[j] - '0';
        }
    }
    //输入b矩阵
    mat b(n, vec(1));
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        b[i][0] = s[i] - '0';
    }

    cin >> q;
    while (q--) {
        cin >> k;
        mat t = pow(A, k);
        mat ans = mul(t, b);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i][0];
        cout << endl;
    }
    return 0;
}
