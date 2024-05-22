#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e2 + 5, maxm = 2e3 + 5;
const LL INF = (1ull << 32);
struct Edge {
	int v, nex; LL w;
	Edge(int v = 0, LL w = 0, int nex = 0) : v(v), w(w), nex(nex) {}
} E[maxm << 1];
int hd[maxn], tote;
void addedge(int u, int v, LL w) {
	E[tote++] = Edge(v, w, hd[u]), hd[u] = tote - 1;
	E[tote++] = Edge(u, 0, hd[v]), hd[v] = tote - 1;
}

int S, T, dep[maxn], cur[maxn];
bool bfs() {
	memset(dep, 0, sizeof(int) * (T + 1));
	memcpy(cur, hd, sizeof(int) * (T + 1));
	queue<int> q;
	q.push(S), dep[S] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = hd[u]; ~i; i = E[i].nex) {
			int v = E[i].v;
			if (E[i].w > 0 && !dep[v])
				q.push(v), dep[v] = dep[u] + 1;
		}
	}
	return dep[T] > 0;
}

LL dfs(int u, LL flow) {
	if (u == T) return flow;
	LL res = flow;
	for (int &i = cur[u]; ~i; i = E[i].nex) {
		int v = E[i].v;
		if (E[i].w > 0 && dep[v] == dep[u] + 1) {
			LL tmp = dfs(v, min(res, E[i].w));
			E[i].w -= tmp, E[i ^ 1].w += tmp;
			res -= tmp;
		}
	}
	return flow - res;
}

LL dinic() {
	LL ans = 0;
	while (bfs()) ans += dfs(S, INF);
	return ans;
}

int main() {
	// freopen("test.in", "r", stdin);
	// freopen("test.out", "w", stdout);
	int n, m; LL x;
	memset(hd, -1, sizeof(hd));
	scanf("%d%d%lld", &n, &m, &x);
	S = 1, T = n;
	for (int i = 1; i <= m; i++) {
		int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
		addedge(u, v, w);
	}
	LL mxf = dinic();
	if (mxf == 0) printf("Orz Ni Jinan Saint Cow!\n");
	else printf("%lld %lld\n", mxf, (x + mxf - 1) / mxf);
	return 0;
}
