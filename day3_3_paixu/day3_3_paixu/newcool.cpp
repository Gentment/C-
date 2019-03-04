//#include<iostream>
//using namespace std;
//
//int x, f, d, p;
//int solve(int x, int f, int d, int p)
//{
//	int tmp = d / x;
//	if (tmp <= f) return tmp;
//	d -= f * x;
//	return f + d / (x + p);
//}
//int main()
//{
//	cin >> x >> f >> d >> p;
//	cout << solve(x, f, d, p) << endl;
//	return 0;
//}



//#include<iostream>
//using namespace std;
//
//int main() {
//	int t, n, a, b, c;
//	cin >> t;
//	while (t--) {
//		cin >> n >> a >> b >> c;
//		n -= c / 2;
//		c = c % 2;
//		n -= b / 3;
//		b = b % 3;
//		if (a >= 1 && b >= 1 && c == 1) {
//			a--;
//			b--;
//			c--;
//			n--;
//		}
//		if (b == 2 && a >= 2) {
//			b = 0;
//			a -= 2;
//			n--;
//		}
//		if (c == 1 && a >= 3) {
//			c = 0;
//			a -= 3;
//			n--;
//		}
//		if (b == 1 && a >= 4) {
//			c = 0;
//			a -= 4;
//			n--;
//		}
//		n -= a / 6;
//		a = a % 6;
//		if (n > 0)
//			printf("No\n");
//		else
//			printf("Yes\n");
//	}
//	return 0;
//}

//#include <iostream>
//#include<algorithm>
//using namespace std;
//
//int dp[1005];
//int c[1005][2];
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) dp[i] = i;
//	for (int i = 1; i <= n; i++) {
//		cin >> c[i][0] >> c[i][1];
//		for (int j = c[i][0]; j <= m; j++)
//			dp[j] =max(dp[j], dp[j - c[i][0]] + c[i][1]);
//	}
//	printf("%d\n", dp[m] - m);
//	return 0;
//}


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Edge
{
	int dis, to;
	bool friend operator <(Edge x1, Edge x2)
	{
		return x1.dis > x2.dis;
	}
}temp, now;
vector <Edge> vec[10005];
bool life[10005];
int dis[10005], n;
priority_queue <Edge> q;

void init()
{
	for (int i = 1; i <= n; i++)
		dis[i] = 100000000;
	memset(life, 0, sizeof(life));
	while (!q.empty())
		q.pop();
}
int dij(int s, int t)
{
	init();
	temp.to = s;
	temp.dis = 0;
	q.push(temp);
	dis[s] = 0;
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (!life[now.to])
		{
			life[now.to] = 1;
			for (int i = 0; i < vec[now.to].size(); i++)
			{
				if (!life[vec[now.to][i].to] && dis[now.to] + vec[now.to][i].dis < dis[vec[now.to][i].to])
				{
					dis[vec[now.to][i].to] = dis[now.to] + vec[now.to][i].dis;
					temp.to = vec[now.to][i].to;
					temp.dis = dis[vec[now.to][i].to];
					q.push(temp);
				}
			}
		}
	}
	return dis[t];
}

int main()
{
	int m, s, t, u, v, d;
	cin >> n >> m >> s >> t;
	while (m--)
	{
		cin >> u >> v >> d;
		temp.dis = d;
		temp.to = v;
		vec[u].push_back(temp);
	}
	printf("%d\n", dij(s, t) + dij(t, s));
	return 0;
}