#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
const int maxn=2<<20*100;
int main(){
	printf("Please key in lenth of time(s)\n");
	double t;scanf("%lf",&t);t*=1000;
	t+=clock();int i=1;
	while(clock()<=t){
		int *a=(int*)malloc(maxn);
		memset(a,0,maxn);
		printf("%d\n",i);
		i++;
	}
	return 0;
}
