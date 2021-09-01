#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
const int list_n=3;
struct xc_node{
	int lastt,waitt;void (*funcpos)();
}xc_list[list_n+1];//duoxiancheng
int pic[110][4],mark=0,rps=2,roadspeed=200;double h=1;
bool kbd[128];//keyboard roadpos
bool randp(int x,int y){return rand()%y<x;}
void GetDesktopMaxXY(int &l,int &r,int &h,int &b){
	HWND hd=GetDesktopWindow();
	RECT rect;GetClientRect(hd,&rect);
	l=rect.left,r=rect.right,b=rect.top,h=rect.bottom;
	return;
}
bool keydown(char c){
	if(GetAsyncKeyState((int)c)&&0x8000)  return 1;
}
void paint(int x,int y){
	WORD wColor=((x&0x0F)<<4)+(y&0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wColor);
}
void gotoxy(int x,int y){
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,{x-1,y-1});
}
void scls(){printf("%c[2K",27);}
void moveroad(int t){
	printf("%d",t);
	if(t==1)  gotoxy(20,29),rps=1;
	else if(t==2)  gotoxy(23,29),rps=2;
	else if(t==3)  gotoxy(26,29),rps=3;
}

void show_block(int x,int y,int v){
	x=16+3*x,y=31-3*y;
	if(v>100)  paint(8,15);
	v%=100;gotoxy(x,y);
	if(v==0)  {printf("   ");gotoxy(x,y+1);printf("   ");gotoxy(x,y+2);printf("   ");} 
	else if(v==1)  {printf("   ");gotoxy(x,y+1);printf("# #");gotoxy(x,y+2);printf("###");} 
	else if(v==2)  {printf("   ");gotoxy(x,y+1);printf("###");gotoxy(x,y+2);printf("# #");} 
	else if(v==3)  {printf(" # ");gotoxy(x,y+1);printf("# #");gotoxy(x,y+2);printf("# #");} 
	else if(v==4)  {printf("###");gotoxy(x,y+1);printf("###");gotoxy(x,y+2);printf("###");} 
	else if(v==5)  {printf(" * ");gotoxy(x,y+1);printf("***");gotoxy(x,y+2);printf(" * ");} 
	paint(0,15);
}
void map_ready(int t){
	if(randp(1,1)){
		int y=5*rand()%5+5;
		if(randp(1,3)){
			int x=rand()%3+1;
			for(int i=t;i<=t+y;i++)  pic[i][x]+=100;
		}
		else{
			if(randp(1,2))
				for(int i=t;i<=t+y;i++)  pic[i][2]+=100;
			else{
				for(int i=t;i<=t+y;i++)  pic[i][1]+=100;
				for(int i=t;i<=t+y;i++)  pic[i][3]+=100;
			}
		}
	}
	if(randp(1,8)){
		int y=5*rand()%9+5;
		if(randp(1,3)){
			int x=rand()%3+1;
			for(int i=t;i<=t+y;i++)  pic[i][x]+=5;
		}
		else{
			if(randp(1,2))
				for(int i=t;i<=t+y;i++)  pic[i][2]+=5;
			else{
				for(int i=t;i<=t+y;i++)  pic[i][1]+=5;
				for(int i=t;i<=t+y;i++)  pic[i][3]+=5;
			}
		}
	}
	if(randp(1,2)){
		int x=rand()%3+1;
		if(pic[t-2][x]%100>=1&&pic[t-2][x]%100<=4)  return;
		if(pic[t-1][x]%100>=1&&pic[t-1][x]%100<=4)  return;
		pic[t][x]-=pic[t][x]%100;
		pic[t][x]+=rand()%4+1;
	}
	return;
}

void restart(){
	gotoxy(1,31);paint(0,15);scls();paint(15,0);
	gotoxy(1,31);printf("3\n");moveroad(rps);Sleep(1000);
	gotoxy(1,31);printf("2\n");moveroad(rps);Sleep(1000);
	gotoxy(1,31);printf("1\n");moveroad(rps);Sleep(1000);
	gotoxy(1,31);printf(" \n");moveroad(rps);Sleep(1000);
	paint(0,15);gotoxy(1,31);scls();moveroad(rps);
}
void map_show(){
	system("cls");
	for(int i=1;i<=3;i++){
		for(int j=1;j<=10;j++){
			show_block(i,j,pic[j][i]);
		}
	}
	return;
}
void start_ready1(){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize=sizeof cfi;
	cfi.nFont=0;
	cfi.dwFontSize.X=0;
	cfi.dwFontSize.Y=20;
	cfi.FontFamily=FF_DONTCARE;
	cfi.FontWeight=FW_NORMAL;
	wcscpy(cfi.FaceName,L"Raster");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&cfi);
	int l,r,h,b;GetDesktopMaxXY(l,r,h,b);
	if(r-l<500||h-b<690){printf("error resolution!\n");Sleep(1000);getchar();exit(0);}
	HWND hWnd=FindWindow("ConsoleWindowClass",NULL);
	MoveWindow(hWnd,(l+r)/2-250,10,500,700,true);
	printf("__________________\n");
	return;
}
void start_ready2(){
	for(int i=6;i<=10;i++)  map_ready(i);
	map_show();gotoxy(1,31);
	printf("press to start");getchar();
	restart();
}

void xc1(){//wasd
	if(keydown('w'))  kbd['w']=1;
	else if(kbd['w']==1){
		kbd['w']=0;
		if(h<1)  h=1;
		else h=2;
	}
	if(keydown('s'))  kbd['s']=1;
	else if(kbd['s']==1){
		kbd['s']=0;
		if(h<1)  h=0;
		else h=1;
	}
	if(keydown('a'))  kbd['a']=1;
	else if(kbd['a']==1){
		kbd['a']=0;
		if(rps!=1)  rps--;
		moveroad(rps);
	}
	if(keydown('d'))  kbd['d']=1;
	else if(kbd['d']==1){
		kbd['d']=0;
		if(rps!=3)  rps++;
		moveroad(rps);
	}
	return;
}
void xc2(){
	gotoxy(1,1);printf("mark:%d",mark);
	moveroad(rps);
//	Sleep(300);
	return;
}
void xc3(){
//	system("cls");
//	Sleep(100);
	return;
}



int main(){
	srand(time(NULL));
	start_ready1();getchar();system("cls");
	start_ready2();
	
	xc_list[1].waitt=10,xc_list[1].funcpos=&xc1;
	xc_list[2].waitt=roadspeed,xc_list[2].funcpos=&xc2;
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
/*
pic:  ......         
      4 4 4     
      3 3 3     
      2 2 2     
      1 1 1     
             
0:    

              
1:    # #      
      ###       
      
            
2:    ###                    
      # #          
      
       #    
3:    # #         
      # #            
                
      ###          
4:    ###            
      ###		
	         
	   * 	          
5:    ***         
       *
					
						
		 xxxxx 				
        y
		y     
*/
