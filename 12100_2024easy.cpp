#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
#include<queue>
#include<memory.h>
#include<stack>
#include<string>
#include<deque>
#include<math.h>
#define MAX 10000

using namespace std;
typedef long long ll;
ll ans;
int n;
int cnt = 0;

int result;
int map[21][21];

//�ѹ� ���������� �ٽ� ������ �� ����
ll resulting(vector<vector<ll>>mapping)
{
	ll res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res = max(res, mapping[i][j]);
		}
	}
	return res;
}
//vector�� ��ȯ���ִ� �Լ��� ����� -> 2���� vector�� ������ش�
vector<vector<ll>>right(vector<vector<ll>> mapping)
{
	// 2���� bool�� check�� ������ֱ�
	vector<vector<bool>>check(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if (mapping[i][j] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (mapping[i][k] == mapping[i][k - 1] && !check[i][k])
				{
					mapping[i][k] *= 2;
					mapping[i][k - 1] = 0;
					check[i][k] = true;
					break;
				}
				else if (mapping[i][k] == 0)
				{
					//������ �ʿ� �����ϱ� ���������� ��ĭ�� ����ְ� ��ĭ ������ֱ�
					mapping[i][k] = mapping[i][k - 1];
					mapping[i][k - 1] = 0;
				}
				else
					break;
			}
		}
	}
	return mapping;
}

vector<vector<ll>>left(vector<vector<ll>>mapping)
{
	vector<vector<bool>>check(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n ; j++)
		{
			if (mapping[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (mapping[i][k] == mapping[i][k + 1] && !check[i][k])
				{
					mapping[i][k] *= 2;
					mapping[i][k + 1] = 0;
					check[i][k] = true;
					break;
				}
				else if (mapping[i][k] == 0)
				{
					mapping[i][k] = mapping[i][k + 1];
					mapping[i][k + 1] = 0;
				}
				else
					break;
			}
		}
	}
	return mapping;
}

vector<vector<ll>>up(vector<vector<ll>> mapping)
{
	// 2���� bool�� check�� ������ֱ�
	vector<vector<bool>>check(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (mapping[j][i] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (mapping[k][i] == mapping[k + 1][i] && !check[k][i])
				{
					mapping[k][i] *= 2;
					mapping[k + 1][i] = 0;
					check[k][i] = true;
					break;
				}
				else if (mapping[k][i] == 0)
				{
					//������ �ʿ� �����ϱ� ���������� ��ĭ�� ����ְ� ��ĭ ������ֱ�
					mapping[k][i] = mapping[k + 1][i];
					mapping[k + 1][i] = 0;
				}
				else
					break;
			}
		}
	}
	return mapping;
}

vector<vector<ll>>down(vector<vector<ll>>mapping)
{
	vector<vector<bool>>check(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = n-2; j >=0; j--)
		{
			if (mapping[j][i] == 0)
				continue;
			for (int k = j + 1; k <n; k++)
			{
				if (mapping[k][i] == mapping[k - 1][i] && !check[k][i])
				{
					mapping[k][i] *= 2;
					mapping[k - 1][i] = 0;
					check[k][i] = true;
					break;
				}
				else if (mapping[k][i] == 0)
				{
					mapping[k][i] = mapping[k + 1][i];
					mapping[k - 1][i] = 0;
				}
				else
					break;
			}
		}
	}
	return mapping;
}


void DFS(int len, vector<vector<ll>>mapping)
{
	ans = max(ans, resulting(mapping));
	if (len == 5)
	{
		return;
	}
	DFS(len + 1, right(mapping));
	DFS(len + 1, left(mapping));
	DFS(len + 1, up(mapping));
	DFS(len + 1, down(mapping));
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<ll>>board(n, vector<ll>(n));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	DFS(0, board);
	cout << ans;
	return 0;
}