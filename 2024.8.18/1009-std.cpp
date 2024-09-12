#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1E6 + 7;
int n,m,ans,num,len,T,nxt[2][N]; char s[N],t[N],p[N];

int min(int x,int y) { return x < y ? x : y; }

void read(int &x)
{
	char c = getchar(); x = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

int check()
{
	int a = 0, b = 0;
	
	for(int i = 1,j = 0,k = 0;i <= len; ++ i)
	{
		while(j && p[i] == s[j + 1]) j = nxt[0][j];
		while(k && p[i] == t[k + 1]) k = nxt[1][k];
		if(j == n) ++ a, j = nxt[0][j];
		if(k == m) ++ b, k = nxt[1][k];
	}
	return a == b ? len : 0x3f3f3f3f;
}

int main()
{
    // freopen("test.in", "r", stdin);

	for(scanf("%d\n", &T);T--;)
	{
		scanf("%s %s\n",s + 1,t + 1),
		n = strlen(s + 1), m = strlen(t + 1);
		
		if(n < m)
		{
			for(int i = 1;i <= n; ++ i) swap(s[i],t[i]);
			for(int i = n + 1;i <= m; ++ i) s[i] = t[i];
			swap(n,m);
		}
		
        nxt[0][0] = nxt[1][0] = 0;
		nxt[0][1] = nxt[1][1] = 0;
		for(int i = 2, j = 0;i <= n; ++ i)
		{
			while(j && s[i] != s[j + 1]) j = nxt[0][j];
			nxt[0][i] = (s[i] == s[j + 1] ? ++ j : j);
		}
		
		for(int i = 2,j = 0;i <= m; ++ i)
		{
			while(j && t[i] != t[j + 1]) j = nxt[1][j];
			nxt[1][i] = t[i] == t[j + 1] ? ++ j : j;
		}
		
		num = 0;
		for(int i = 1,j = 0;i <= n; ++ i)
		{
			while(j == m || (j && s[i] != t[j + 1])) j = nxt[1][j];
			if(s[i] == t[j + 1]) ++ j;
			if(j == m) ++num;
		}
		
		if(num) { printf("%d\n",num == 1 ? n : -1); continue; }
		
		ans = 0x3f3f3f3f; int j = 0;
		for(int i = 1;i <= n; ++ i)
		{
			while(j == m || (j && s[i] != t[j + 1])) j = nxt[1][j];
			if(s[i] == t[j + 1]) ++ j;
		}
		
		len = n;
		for(int i = 1;i <= n; ++ i) p[i] = s[i];
		for(int i = j + 1;i <= m; ++ i) p[++len] = t[i];
		ans = min(ans,check());
		
		for(int i = 1;i <= n; ++ i) p[i] = s[i];
		for(int i = 'a',k;i <= 'z'; ++ i)
		{
			p[len = n + 1] = i, k = j;
			while(k && p[len] != t[k + 1]) k = nxt[1][k];
			if(p[len] == t[k + 1]) ++ k;
			while(k < m) p[++len] = t[++k];
			ans = min(ans,check());
		}
		
		//------------------------------
		
		j = 0;
		for(int i = 1;i <= m; ++ i)
		{
			if(j && t[i] != s[j + 1]) j = nxt[1][j];
			if(t[i] == s[j + 1]) ++ j;
		}
		
		len = m;
		for(int i = 1;i <= m; ++ i) p[i] = s[i];
		for(int i = j + 1;i <= n; ++ i) p[++len] = t[i];
		ans = min(ans,check());
		
		len = n + m;
		for(int i = 1;i <= n; ++ i) p[i] = s[i];
		for(int i = 1;i <= m; ++ i) p[i + n] = t[i];
		ans = min(ans,check());
		
		for(int i = 1;i <= m; ++ i) p[i] = t[i];
		for(int i = 1;i <= n; ++ i) p[i + m] = s[i];
		ans = min(ans,check());
		
		for(int i = 1;i <= m; ++ i) p[i] = t[i];
		for(int i = 'a',k;i <= 'z'; ++ i)
		{
			p[len = m + 1] = i, k = j;
			while(k && p[len] != s[k + 1]) k = nxt[0][k];
			if(p[len] == s[k + 1]) ++ k;
			while(k < n) p[++len] = t[++k];
			ans = min(ans,check());
		}
		
		printf("%d\n",ans == 0x3f3f3f3f ? -1 : ans);
	}
	
	return 0;
}
