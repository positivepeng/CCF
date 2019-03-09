#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int matrix[1005][1005], b[1005], n, m;
int E[1005][1005], matr[1005][1005], ans[1005];
int ano[1005][1005];
char ch_matrix[1005];

void multi(int E[1005][1005], int ano[1005][1005], int matr[1005][1005])
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            E[i][j] = (ano[i][1] & matr[1][j]);
            for (int k = 2; k <= n; ++k) {
                E[i][j] ^= (ano[i][k] & matr[k][j]);
            }
        }
    }
}

void mul(int E[1005][1005], int b[1005], int ans[1005])
{
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
        ans[i] = E[i][1] & b[1];
        //cout << ans[i] << ' ';
        for (int j = 2; j <= n; ++j) {
            ans[i] ^= E[i][j] & b[j];
        //  cout << ans[i] << ' ';
        }
        //cout << endl;
        //cout << "ans[" << i << "] = " << ans[i] << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> ch_matrix[j];
            matrix[i][j] = ch_matrix[j] - '0';
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> ch_matrix[i];
        b[i] = ch_matrix[i] - '0';
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int i  = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                matr[i][j] = matrix[i][j]; // Ô­¾ØÕó
            }
        }
        memset(E, 0, sizeof(E));
        for (int j = 1; j <= n; ++j) {
            E[j][j] = 1; // µ¥Î»¾ØÕó
        }
        while (k) {
            if (k & 1) {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        ano[i][j] = E[i][j];
                    }
                }
                multi(E, ano, matr);
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    ano[i][j] = matr[i][j];
                }
            }
            multi(matr, ano, ano);
            k >>= 1;
        }
        mul(E, b, ans);
        /*cout << "---------matrix---------" << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << E[i][j];
            }
            cout << endl;
        }
        cout << "ans:  ";*/
        for (int i = 1; i <= n; ++i) {
            cout << ans[i];
        }
        cout << endl;
    }
}
