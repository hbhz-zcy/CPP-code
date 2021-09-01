#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
const int list_n=3;
struct xc_node{
	int lastt,waitt;void (*funcpos)();
}xc_list[list_n+1];//duoxiancheng
void xc1(){
	printf("12345\n");
	return;
}
void xc2(){
	Sleep(300);
	return;
}
void xc3(){
	system("cls");
	Sleep(100);
	return;
}



int main(){
	xc_list[1].waitt=10,xc_list[1].funcpos=&xc1;
	xc_list[2].waitt=10,xc_list[2].funcpos=&xc2;
	xc_list[3].waitt=10,xc_list[3].funcpos=&xc3;
	while(1){
		for(int i=1;i<=list_n;i++){
			if(clock()-xc_list[i].lastt>=xc_list[i].waitt){
				(*xc_list[i].funcpos)();
				xc_list[i].lastt=clock();
			}
		}
	}
	return 0;
}
