#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define pos0 "CON"
#define pos1 "data/1to2.txt"
#define pos2 "data/2to1.txt"
#define wpos (ID==1?pos1:pos2)
#define rpos (ID==2?pos1:pos2)
#define clear system("cls")
#define nowtm clock()
int ID,q,t;
void filew(char c,int x){
	fclose(stdout);
	if(c=='w') freopen(wpos,"w",stdout);
	if(c=='r') freopen(rpos,"w",stdout);
	if(c=='1') freopen(pos1,"w",stdout);
	if(c=='2') freopen(pos2,"w",stdout);
	printf("%d %d",x,nowtm);
}
void filew(char c){
	fclose(stdout);
	if(c=='w') freopen(wpos,"w",stdout);
	if(c=='r') freopen(rpos,"w",stdout);
	if(c=='1') freopen(pos1,"w",stdout);
	if(c=='2') freopen(pos2,"w",stdout);
	if(c=='0') freopen(pos0,"w",stdout);
}
void filer(char c,int &x,int &y){
	fclose(stdin);
	if(c=='w') freopen(wpos,"r",stdin);
	if(c=='r') freopen(rpos,"r",stdin);
	if(c=='1') freopen(pos1,"r",stdin);
	if(c=='2') freopen(pos2,"r",stdin);
	scanf("%d%d",t,nowtm);
}
void filer(char c){
	fclose(stdin);
	if(c=='w') freopen(wpos,"r",stdin);
	if(c=='r') freopen(rpos,"r",stdin);
	if(c=='1') freopen(pos1,"r",stdin);
	if(c=='2') freopen(pos2,"r",stdin);
	if(c=='0') freopen(pos0,"r",stdin);
}
void toend(){
	filew('w',0);
	fclose();
	return 0;
}
void upd(){
	int x,y;filer('w',x,y);
	filew('w',x);
}
void wait(){
	int x,y;filer('r',x,y);
	for(int i=1;i<=10;i++){
		Sleep(500);
		filer('r',q,t);
		if(q!=x&&nowtm-t<10000)  return;
	}
	upd();
	while(1){
		clear();
		for(int i=1;i<=10;i++){
			filew('0');
			printf("%d Waiting...\n",i);
			Sleep(500);
			filer('r',q,t);
			if(q!=0&&nowtm-t<10000)  break;
		}
		if(q!=x&&nowtm-t<10000)  return;
		filew('0');filer('0');
		printf("cannot find!\nPress 0 to end,other to continue...");
		if(getchar()=='0')  toend();
		upd();
	}
}
int main(){
	filer('1',q,t);
	if(q==0||nowtm-t>10000){
		filer('2',q,t);
		if(q==0||nowtm-t>10000){//1F2F
			ID=1;
			filew('w',1);
			wait();
		}
		else{//1F2T
			ID=1;
		}
	}
	else{
		filer('2',q,t);
		if(q==0||nowtm-t>10000){//1T2F
			ID=2;
			filew('w',2);
		}
		else{//1T2T
			fclose();
			MessageBox(NULL,"Error: cannot be used now!","Error",MB_ICONWARNING);
			return 0;
		}
	}
	clear();
	filew('0');
	printf("iscoming\n");
	wait();
	if(ID==1){
		filew('w',3);
		dataget();
	}
	else{
		wait();
	}
	return 0;
}