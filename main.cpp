#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <string>
using namespace std;
string name[105],aw[55];
int pernum,score[105],awanum,g,stop=0,one,per,num,ch=0,alli;
int have[105][55],min1=1,max1,donum[105],each[55],awlimit[55],awmax[55];
long long seed=114514;

void welcome(){
	cout<<"欢迎使用有Ballantyne出品的抽奖软件，祝大家单抽出金，十连双黄，啊不对，是抽出自己想要的礼品"<<endl;
	Sleep(50);	
	cout<<"              ----------------------------"<<endl;
	Sleep(50);	
	cout<<"              |版本号:v1.1.1             |"<<endl;
	Sleep(50);
	cout<<"              |更新内容详见README.md     |"<<endl;	
	Sleep(50);
	cout<<"              |--------------------------|"<<endl;
	Sleep(50);
	cout<<"              |特别鸣谢：                |"<<endl;
	Sleep(50);
	cout<<"              |1.Bug测试:徐誉宁、李铭西; |"<<endl;
	Sleep(50);
	cout<<"              |2.Debug辅助:李铭西        |"<<endl;
	Sleep(50);
	cout<<"---------------------------------------------------------"<<endl;
	Sleep(50);
	cout<<" 源代码地址:https://gitee.com/Ender_Dragon/award-extract"<<endl;
	Sleep(50);
	cout<<"---------------------------------------------------------"<<endl;
	Sleep(50);
	cout<<"输入字母o/O打开,输入其他任何字符不打开:";
	char ch;
	cin>>ch;
	if(ch=='o'||ch=='O'){
		system("start https://gitee.com/Ender_Dragon/award-extract");
		cout<<"已打开"<<endl;
	}
	else cout<<"不打开"<<endl;
	return; 
}

void check(){
	ch=0;
	for(int i=1;i<awanum+1;i++){
		if((each[i]==awmax[i]&&i!=have[per][alli])||(each[have[per][alli]]>awmax[i]&&i==have[per][alli])) ch++;
	}
	return;
} 

void back(){
loop:
	cout<<endl;
	cout<<"输入B/b返回:";
	char a;
	cin>>a;
	if(a=='b'||a=='B')	return;
	else{
		cout<<"error"<<endl;
		goto loop;
	}
	return;
}

void awaout(){
	remove("AwardForEachOne.txt");
	fstream outaw;
	outaw.open("AwardForEachOne.txt",ios::out);
	for(int i=1;i<pernum+1;i++){
		outaw<<i<<"."<<name[i]<<":";
		if(donum[i]==0) outaw<<"无";
		for(int j=1;j<donum[i]+1;j++){
			outaw<<aw[have[i][j]]<<"\t";
		}
		outaw<<endl;
	}
	outaw<<endl<<"各种奖品对应数量:"<<endl;;
	for(int i=1;i<awanum+1;i++){
		outaw<<i<<"."<<aw[i]<<":"<<each[i]<<"份;"<<endl;
	}
	outaw.close();
	return;
}

void g4(){
	int do1,done1,change;
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":"<<score[i]<<"\t"<<"\t";
		if(i%2==0) cout<<endl;
	}
	cout<<endl;
	cout<<"请输入转让人:";
	cin>>do1;
	if(do1>pernum||do1<1){
		cout<<"查无此人"<<endl;
		system("pause");
		goto loop;
	}
	if(score[do1]==0){
		cout<<"已经没有分数啦!"<<endl;
		system("pause");
		goto loop;
	}
	cout<<"请输入被转让人:";
	cin>>done1;
	if(done1>pernum||done1<1){
		cout<<"查无此人"<<endl;
		system("pause");
		goto loop;
	}
lp:
	cout<<name[do1]<<"最多转让"<<score[do1]<<"分，请输入转让的分数:";
	cin>>change;
	if(change<0){
		cout<<"error"<<endl;
		goto lp;
	}else if(change>score[do1]){
		cout<<"嗯？想无中生有？没门!"<<endl;
		goto lp;
	}else{
		score[do1]=score[do1]-change;
		score[done1]=score[done1]+change;
		cout<<"操作完成!"<<endl;
	}
	system("pause");
loop:
	return;
}

void chouqu(){
	int q;
	for(int i=1;i<num+1;i++){
chou:
		q=(rand()%(max1-min1+1))+min1;
		srand(seed++);
		alli=i;
		have[per][i]=q;
		each[have[per][i]]++;	
		check();
		if(ch==awanum){
			stop=2;
			each[have[per][i]]--;
			score[per]=score[per]+(num-i+1)*one;
			donum[per]=donum[per]-(num-i+1);
			cout<<"恭喜抽取到:"<<endl;
			for(int k=1;k<donum[per]+1;k++){
				cout<<"\t"<<k<<"."<<aw[have[per][k]]<<endl;
			}
			cout<<"礼品已抽完,后面的同学无法抽取"<<endl;
			goto Stop;
		}
		if(each[have[per][i]]>awmax[have[per][i]]){
			each[have[per][i]]--;
			goto chou;
		}
		awlimit[have[per][i]]--;
	}
	cout<<"恭喜抽取到:"<<endl;
	if(donum[per]==0){
		cout<<"无"<<endl;
	}else{
		for(int i=1;i<num+1;i++){
			cout<<"\t"<<i<<"."<<aw[have[per][i]]<<endl;
		}
	}
Stop:
	cout<<endl; 
	back();
	return;
}

void total1(){
	for(int i=1;i<awanum+1;i++){
		cout<<i<<"."<<aw[i]<<":"<<each[i]<<"份"<<"\t\t";
		if(i%2==0) cout<<endl;
	}
	return;
}

void start(){
	cout<<"请输入每次抽奖所需分数:";
	cin>>one;
	cout<<"-----------------------------------重要信息-----------------------------------"<<endl;
	Sleep(25);
	cout<<"所有格式如下:"<<endl;
	Sleep(25);
	cout<<"  1.抽奖人数:即参与人数，将影响分数的读取"<<endl;
	Sleep(25);
	cout<<"             存放在与程序同目录的“score.txt”文本文档中"<<endl;
	Sleep(25);
	cout<<"             内部格式为一个名字，换行输入分数;"<<endl;
	Sleep(25);
	cout<<"  2.奖品数量:此为奖品的总类数，而非奖品所准备的份数"<<endl;
	Sleep(25);
	cout<<"             存放在与程序同目录的“award.txt”文本文档中"<<endl;
	Sleep(25);
	cout<<"             内部格式为一个奖品的名称，换行输入准备的份数"<<endl;
	Sleep(25);
	cout<<"  3.随机种子:随机抽奖的依赖，随便输入一个不超过1000000的数即可"<<endl;
	Sleep(25);
	cout<<"注意:1.奖品种类不要超过55"<<endl;
	Sleep(25);
	cout<<"     2.人数不要超过100"<<endl;
	Sleep(25);
	cout<<"     3.目前未添加排序功能"<<endl;
	Sleep(25);
	cout<<"     4.所有存放在“XX.txt”中的名称/数量，请不要出现空格，否则一定会出错"<<endl;
	Sleep(25);
	cout<<"-----------------------------------重要信息-----------------------------------"<<endl;
	Sleep(25);
	cout<<"请输入抽奖人数：";
	cin>>pernum;
	cout<<"请输入奖品数量：";
	cin>>awanum;
	cout<<"读取信息中......"<<endl;
	for(int i=1;i<awanum+1;i++) each[i]=0;
	max1=awanum;
	fstream getna;
	getna.open("score.txt",ios::in);
	for(int i=1;i<pernum+1;i++){
		getna>>name[i]>>score[i];	
	}
	getna.close();
	fstream getaw;
	getaw.open("award.txt",ios::in);
	for(int i=1;i<awanum+1;i++){
		getaw>>aw[i]>>awlimit[i];
		awmax[i]=awlimit[i];
	}
	getaw.close();
	cout<<"读取完成！"<<endl;
	cout<<"请输入随机种子:";
	cin>>seed;
	cout<<"设置成功!"<<endl;
	system("pause");
	return;
}

void g2(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":";
		if(donum[i]==0) cout<<"无";
		for(int j=1;j<donum[i]+1;j++){
			cout<<aw[have[i][j]]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<"奖品总量统计:"<<endl;
	total1();
	cout<<endl; 
	back();
	return;
}

void awlist(){
	system("cls");
	for(int i=1;i<awanum+1;i++){
		cout<<i<<"."<<aw[i]<<":总计"<<awmax[i]<<"份/剩余"<<awlimit[i]<<"份;"<<endl;
	}
	cout<<endl;
	system("pause");
	return;
}

void g1(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":"<<score[i]<<"/"<<score[i]/one<<"次;"<<"\t"<<"\t";
		if(i%2==0) cout<<endl;
	}
	cout<<endl;
	cout<<"请输入抽奖人:";
	cin>>per;
	if(per<1||per>pernum){
		cout<<"查无此人"<<endl;
		system("pause");
		return;
	}
	if(score[per]/one==0){
		cout<<"没有分数啦!"<<endl;
		system("pause");
		return;
	}
	cout<<name[per]<<"最多可抽奖"<<score[per]/one<<"次，请输入抽奖次数:";
getnum:
	cin>>num;
	if(num<0){
		cout<<"error"<<endl;
		cout<<"请输入正确抽奖次数:";
		goto getnum;
	}else if(score[per]>num*one||score[per]==num*one){
		score[per]=score[per]-num*one;
		donum[per]=num;
		chouqu();
	}else{
		cout<<"请不要白日做梦"<<endl;
		cout<<"请输入抽奖次数:";
		goto getnum;
	}
	return;
}

void g5(){
	system("cls");
	cout<<"列表:"<<endl;
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":";
		for(int j=1;j<donum[i]+1;j++){
			cout<<aw[have[i][j]]<<"\t";
		}
		cout<<endl;
	}
	int do1,done1,change;
	cout<<"请输入转让人:";
	cin>>do1;
	if(do1>pernum||do1<1){
		cout<<"查无此人"<<endl;
		system("pause");
		goto loop;
	}
	if(donum[do1]==0){
		cout<<"还没有奖品呀，无法转让"<<endl;
		system("pause");
		goto loop;
	}
	cout<<"请输入被转让人:";
	cin>>done1;
	if(done1>pernum||done1<1){
		cout<<"查无此人"<<endl;
		system("pause");
		goto loop;
	}
	cout<<name[do1]<<"已有奖品列表:"<<endl;
	for(int i=1;i<donum[do1]+1;i++){
		cout<<"\t"<<i<<"."<<aw[have[do1][i]]<<endl;
	}
lp:
	cout<<"请输入转让的奖品编号:";
	cin>>change;
	if(change<0||change==0||change>donum[do1]){
		cout<<"不存在该奖品"<<endl;
		goto lp;
	}else{
		have[done1][donum[done1]+1]=have[do1][change];
		if(change==donum[do1]){
			have[do1][donum[do1]]=0;
			donum[do1]--;
			donum[done1]++;
		}else{
			have[do1][change]=have[do1][donum[do1]];
			have[do1][donum[do1]]=0;
			donum[do1]--;
			donum[done1]++;
		}
		cout<<"转让成功"<<endl;
	}
	system("pause");
loop:
	return;
}

void g6(){
	system("cls");
	int q;
	for(int k=1;k<pernum+1;k++){
		num=score[k]/one;
		if(num==0){
			cout<<name[k]<<"没有足够的分数,无法抽取"<<endl;
			continue;
		}
		per=k;
		donum[k]=num;
		score[k]=score[k]-num*one;
		for(int i=1;i<num+1;i++){
chou:
			q=(rand()%(max1-min1+1))+min1;
			srand(seed++);
			alli=i;
			have[per][i]=q;
			each[have[per][i]]++;	
			check();
			if(ch==awanum){
				stop=2;
				if(num!=1&&i!=1) cout<<name[k]<<"已完成,获得"<<num<<"份奖品;"<<endl;
				cout<<"礼品已抽完,后面的同学无法抽取"<<endl;
				each[have[per][i]]--;
				score[per]=score[per]+(num-i+1)*one;
				donum[per]=donum[per]-(num-i+1);
				goto Stop;
			}
			if(each[have[per][i]]>awmax[have[per][i]]){
				each[have[per][i]]--;
				goto chou;
			}
			awlimit[have[per][i]]--;
		}
		cout<<name[k]<<"已完成,获得"<<num<<"份奖品;"<<endl;
		Sleep(1);
	}
Stop:
	cout<<"所有操作已完成"<<endl;
	system("pause");
	return;
}

void g0(){
	system("cls");
	int ge;
	cout<<"0.返回"<<endl;
	cout<<"1.退出不保存"<<endl;
	cout<<"2.退出并保存"<<endl;
	cout<<"请输入操作:";
	cin>>ge;
	if(ge==0){
		return;
	}else if(ge==1){
		stop=3;
		return;
	}else if(ge==2){
		stop=1;
		return;
	}else{
		
	}
}

void g7(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":"<<score[i]<<"分"<<"/"<<score[i]/one<<"次;"<<endl;
	}
	cout<<"请输入抽奖人:";
	int ge;
	cin>>ge;
	int genum=score[ge]/one;
	if(genum<1){
		cout<<"没有分数咧!"<<endl;
		system("pause");
		return;
	}
	cout<<name[ge]<<"最多抽奖"<<genum<<"次,请输入抽奖次数:";
loop:
	cin>>num;
	if(num>genum){
		cout<<"别想抽那么多次"<<endl;
		cout<<"请输入抽奖次数:";
		goto loop;
	}else if(num<1){
		cout<<"error"<<endl;
		system("pause");
		return;
	}else{
		system("cls");
		for(int i=1;i<awanum+1;i++){
			cout<<i<<"."<<aw[i]<<endl;
		}
		cout<<"请依次输入获得奖品(每次输入后换行):"<<endl;
		int geaw;
		for(int i=1;i<genum+1;i++){
lp:
			cout<<"\t"<<i<<":";
			cin>>geaw;
			if(geaw<1||geaw>awanum){
				cout<<"乱整,请重新输入"<<endl;
				goto lp;
			}else{
				donum[ge]++;
				have[ge][i]=geaw;
				each[geaw]++;
			}
		}
	}
	cout<<"已录入!"<<endl;
	system("pause");
	return;
}

void g129(){
	system("cls");
	cout<<"-----------------------------v1.1.0---------2023.1.10--------------------"<<endl;
	Sleep(50);
	cout<<"首次提交程序"<<endl;
	Sleep(50);
	cout<<"-----------------------------v1.1.1---------2023.1.11--------------------"<<endl;
	Sleep(50);
	cout<<"1.修复一些bug"<<endl;
	Sleep(50);
	cout<<"2.添加一键快速抽取时显示每人抽取得到个数的功能"<<endl;
	Sleep(50);
	cout<<"3.添加手动抽取时，可用次数为0时的禁止抽取的功能"<<endl;
	Sleep(50);
	cout<<"-----------------------------v1.2.0---------2023.1.13--------------------"<<endl;
	Sleep(50);
	cout<<"添加仅记录奖品的功能"<<endl;
	Sleep(50);
	cout<<"-----------------------------v1.2.1---------2023.1.14--------------------"<<endl;
	Sleep(50);
	cout<<"1.添加程序内查看更新日志的功能"<<endl;
	Sleep(50);
	cout<<"2.添加程序开始时可选打开源代码网址的功能"<<endl;
	Sleep(50);
	cout<<"-------------------------------------------------------------------------"<<endl;
	system("pause");
	return;
}

void ui(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":"<<score[i]<<"\t"<<"\t";
		if(i%2==0) cout<<endl;
	}
	cout<<endl<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"|0.退出                                 |"<<endl;
	cout<<"|1.抽奖                                 |"<<endl;
	cout<<"|2.查看已获得的奖品                     |"<<endl;
	cout<<"|3.查看可能获得的奖品                   |"<<endl;
	cout<<"|4.转让分数                             |"<<endl;
	cout<<"|5.转让奖品                             |"<<endl;
	cout<<"|6.快速全部抽奖                         |"<<endl;
	cout<<"|7.仅记录                               |"<<endl;
	cout<<"|129.更新历史                           |"<<endl;
	cout<<"-----------------------------------------"<<endl;
again:
	cout<<"请输入操作:";
	cin>>g;
	if(stop!=2){
		if(g==0) g0();
		else if(g==1) g1();
		else if(g==2) g2();
		else if(g==3) awlist;
		else if(g==4) g4();
		else if(g==5) g5();
		else if(g==6) g6();
		else if(g==7) g7();
		else if(g==129) g129();
		else{
			cout<<"error"<<endl;
			goto again;
		}
	}else{
		if(g==0) g0();
		else if(g==1){
			cout<<"所有奖品已抽完,无法继续"<<endl;
			goto again; 
		}else if(g==2) g2();
		else if(g==3) awlist();
		else if(g==4) g4();
		else if(g==5) g5();
		else if(g==6){
			cout<<"所有奖品已抽完,无法继续"<<endl;
			goto again; 
		}else if(g==7) g7;
		else if(g==129) g129();
		else{
			cout<<"error"<<endl;
			goto again;
		}
	}
}

int main(){
	system("title 奖品抽取v1.1.1-Powered by Ballantyne");
	welcome();
	start();
	for(;;){
		seed++;
		check();
		if(ch==awanum) stop=2;
		ui();
		if(stop==1) goto Stop1;
		if(stop==3) goto Stop2;
	}
Stop1:
	system("cls");
	cout<<"正在输出奖品列表......"<<endl;
	awaout();
	cout<<"完成！"<<endl;
	cout<<"列表已输出至当前目录的AwardForEachOne.txt文件中"<<endl; 
	cout<<"已结束程序"<<endl; 
    system("pause");
	return 0;
Stop2:
	system("pause");
	return 0;
}
