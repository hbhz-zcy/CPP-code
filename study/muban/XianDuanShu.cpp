#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int maxn=1e5+10;
int n,m;LL a[maxn];
struct node{int l,r;LL v,lazy;}f[4*maxn];
void pushup(int t){f[t].v=f[t<<1].v+f[t<<1|1].v;}
void pushdown(int t){
	if(!f[t].lazy)  return;
	if(f[t<<1].l!=f[t<<1].r)  f[t<<1].lazy+=f[t].lazy;
	if(f[t<<1|1].l!=f[t<<1|1].r)  f[t<<1|1].lazy+=f[t].lazy;
	f[t<<1].v+=f[t].lazy*(f[t<<1].r-f[t<<1].l+1);
	f[t<<1|1].v+=f[t].lazy*(f[t<<1|1].r-f[t<<1|1].l+1);
	f[t].lazy=0;return;
}
void build(int t,int l,int r){
	f[t].l=l,f[t].r=r;
	if(l==r){f[t].v=a[l];return;}
	int m=(l+r)/2;
	build(t<<1,l,m),build(t<<1|1,m+1,r);
	pushup(t);return;
}
void add(int t,int ul,int ur,LL x){
	int l=f[t].l,r=f[t].r;
	if(l==r){f[t].v+=x;return;}
	if(ul<=l&&r<=ur){f[t].v+=x*(r-l+1),f[t].lazy+=x;return;}
	pushdown(t);int m=(l+r)/2;
	if(ul<=m)  add(t<<1,ul,ur,x);
	if(ur>m)  add(t<<1|1,ul,ur,x);
	pushup(t);
	return;
}
LL getsum(int t,int ul,int ur){
	int l=f[t].l,r=f[t].r;
	if(ul<=l&&r<=ur)  return f[t].v;
	pushdown(t);LL rt=0;int m=(l+r)/2;
	if(ul<=m)  rt+=getsum(t<<1,ul,ur);
	if(ur>m)  rt+=getsum(t<<1|1,ul,ur);
	return rt;
}
void ts(){
	for(int i=1;i<=2*n;i++)
		printf("%d:%d,%d,%d,%d\n",i,f[i].l,f[i].r,f[i].lazy,f[i].v);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
	build(1,1,n);
	while(m--){
		int t,x,y;LL k;scanf("%d%d%d",&t,&x,&y);
		if(t==1){scanf("%lld",&k);add(1,x,y,k);}
		else printf("%lld\n",getsum(1,x,y));
	}
	return 0;
}
