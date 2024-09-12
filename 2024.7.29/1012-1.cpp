#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 3E5 + 7;
int n,m,tot,T,rt[4][N],p[N],val[N]; ll a[N],MX,ans,tmp;
struct SGT{ int ls,rs; ll mx; } t[N * 100];

inline ll max(ll x,ll y) { return x > y ? x : y; }

inline int min(int x,int y) { return x < y ? x : y ; }

inline int max(int x,int y) { return x > y ? x : y ; }

inline void read(int &x)
{
	char c = getchar(); x = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

ll query(int o,int l,int r,int x,int y)
{
	if(!o) return 0ll;
	if(l >= x && r <= y) return t[o].mx;
	
	int mid = l + r >> 1;
    if (y <= mid || !t[o].rs) return query(t[o].ls, l, mid, x, y);
    else if (x > mid || !t[o].ls) return query(t[o].rs, mid + 1, r, x, y);
	else return max(query(t[o].ls,l,mid,x,y),query(t[o].rs,mid + 1,r,x,y));
}

void insert(int &o,int last,int l,int r,int x,ll y)
{
	t[o = ++tot] = t[last], t[o].mx = max(t[o].mx,y);
	if(l == r) return;
	
	int mid = l + r >> 1;
	if(x <= mid) insert(t[o].ls,t[last].ls,l,mid,x,y);
	else insert(t[o].rs,t[last].rs,mid + 1,r,x,y);
}

inline ll solve(int x,int y)
{ return (y < 1 ? 0 : query(rt[0][x],1,n,1,min(y,n))) + (y > n ? 0 : query(rt[1][x],1,n,max(y,1),n)); }

/*inline void output(ll x)
{
	int u[33];
	
	for(u[0] = 0;x;x /= 10) u[++u[0]] = x % 10;
	if(!u[0]) u[++u[0]] = 0;
	
	while(u[0]) putchar(u[u[0]--] + '0'); 
}*/

int main()
{
	for(read(T);T--;)
	{
		read(n), read(m), t[tot = 0] = (SGT){ 0,0,0 };
		
		rt[0][0] = 0;
		for(int i = 1;i <= n; ++ i)
			read(p[i]), read(val[i]),
			a[i] = val[i] + query(rt[0][i - 1],1,n,1,p[i]),
			insert(rt[0][i],rt[0][i - 1],1,n,p[i],a[i]);
		rt[0][n + 1] = rt[0][n];
		
		rt[1][n + 1] = 0;
		for(int i = n;i >= 1; -- i)
			tmp = query(rt[1][i + 1],1,n,p[i],n), a[i] += tmp,
			insert(rt[1][i],rt[1][i + 1],1,n,p[i],tmp + val[i]);
		rt[1][0] = rt[1][1];
		
		rt[2][0] = 0;
		for(int i = 1;i <= n; ++ i)
			insert(rt[2][i],rt[2][i - 1],1,n,p[i],a[i]);
		rt[2][n + 1] = rt[2][n];
		
		rt[3][n + 1] = 0;
		for(int i = n;i >= 1; -- i)
			insert(rt[3][i],rt[3][i + 1],1,n,p[i],a[i]);
		rt[3][0] = rt[3][1];
		
		MX = query(rt[0][n],1,n,1,n), p[0] = p[n + 1] = -100;
		for(int xl,xr,yl,yr;m--;)
		{
			read(xl), read(yl), read(xr), read(yr),
			ans = max(query(rt[2][xl - 1],1,n,yr + 1,n),query(rt[3][xr + 1],1,n,1,yl - 1));
			
			if(ans == MX) { printf("%lld\n",ans); continue; }
			
			p[xl - 1] != yr + 1 && (ans = max(ans,solve(xl - 1,yr + 1)), 1),
			p[xr + 1] != yl - 1 && (ans = max(ans,solve(xr + 1,yl - 1)), 1);
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}