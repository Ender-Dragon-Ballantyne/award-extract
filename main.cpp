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
	cout<<"��";
	Sleep(25);	
	cout<<"��";
	Sleep(25);	
	cout<<"��";
	Sleep(25);	
	cout<<"��";
	Sleep(25);	
	cout<<"ӭ";
	Sleep(25);	
	cout<<"ʹ";
	Sleep(25);	
	cout<<"��";
	Sleep(25);	
	cout<<"��";
	Sleep(25);
	cout<<"B";
	Sleep(25);	
	cout<<"a";
	Sleep(25);	
	cout<<"l";
	Sleep(25);	
	cout<<"l";
	Sleep(25);	
	cout<<"a";
	Sleep(25);	
	cout<<"n";
	Sleep(25);	
	cout<<"t";
	Sleep(25);	
	cout<<"y";
	Sleep(25);
	cout<<"n";
	Sleep(25);
	cout<<"e";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"Ʒ";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"ף";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"ʮ";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"˫";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"ϲ";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"��";
	Sleep(25);
	cout<<"Ʒ";
	Sleep(25);
	cout<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"|�ر���л��                |"<<endl;
	cout<<"|1.Bug����:��������������; |"<<endl;
	cout<<"|2.Debug����:������        |"<<endl;
	cout<<"----------------------------"<<endl;
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
	cout<<"����B/b����:";
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
		if(donum[i]==0) outaw<<"��";
		for(int j=1;j<donum[i]+1;j++){
			outaw<<aw[have[i][j]]<<"\t";
		}
		outaw<<endl;
	}
	outaw<<endl<<"���ֽ�Ʒ��Ӧ����:"<<endl;;
	for(int i=1;i<awanum+1;i++){
		outaw<<i<<"."<<aw[i]<<":"<<each[i]<<"��;"<<endl;
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
	cout<<"������ת����:";
	cin>>do1;
	if(do1>pernum||do1<1){
		cout<<"���޴���"<<endl;
		system("pause");
		goto loop;
	}
	if(score[do1]==0){
		cout<<"�Ѿ�û�з�����!"<<endl;
		system("pause");
		goto loop;
	}
	cout<<"�����뱻ת����:";
	cin>>done1;
	if(done1>pernum||done1<1){
		cout<<"���޴���"<<endl;
		system("pause");
		goto loop;
	}
lp:
	cout<<name[do1]<<"���ת��"<<score[do1]<<"�֣�������ת�õķ���:";
	cin>>change;
	if(change<0){
		cout<<"error"<<endl;
		goto lp;
	}else if(change>score[do1]){
		cout<<"�ţ����������У�û��!"<<endl;
		goto lp;
	}else{
		score[do1]=score[do1]-change;
		score[done1]=score[done1]+change;
		cout<<"�������!"<<endl;
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
			cout<<"��ϲ��ȡ��:"<<endl;
			for(int k=1;k<donum[per]+1;k++){
				cout<<"\t"<<k<<"."<<aw[have[per][k]]<<endl;
			}
			cout<<"��Ʒ�ѳ���,�����ͬѧ�޷���ȡ"<<endl;
			goto Stop;
		}
		if(each[have[per][i]]>awmax[have[per][i]]){
			each[have[per][i]]--;
			goto chou;
		}
		awlimit[have[per][i]]--;
	}
	cout<<"��ϲ��ȡ��:"<<endl;
	if(donum[per]==0){
		cout<<"��"<<endl;
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
		cout<<i<<"."<<aw[i]<<":"<<each[i]<<"��"<<"\t\t";
		if(i%2==0) cout<<endl;
	}
	return;
}

void start(){
	cout<<"������ÿ�γ齱�������:";
	cin>>one;
	cout<<"-----------------------------------��Ҫ��Ϣ-----------------------------------"<<endl;
	cout<<"���и�ʽ����:"<<endl;
	cout<<"  1.�齱����:��������������Ӱ������Ķ�ȡ"<<endl;
	cout<<"             ����������ͬĿ¼�ġ�score.txt���ı��ĵ���"<<endl;
	cout<<"             �ڲ���ʽΪһ�����֣������������;"<<endl;
	cout<<"  2.��Ʒ����:��Ϊ��Ʒ�������������ǽ�Ʒ��׼���ķ���"<<endl;
	cout<<"             ����������ͬĿ¼�ġ�award.txt���ı��ĵ���"<<endl;
	cout<<"             �ڲ���ʽΪһ����Ʒ�����ƣ���������׼���ķ���"<<endl;
	cout<<"  3.�������:����齱���������������һ��������1000000��������"<<endl;
	cout<<"ע��:1.��Ʒ���಻Ҫ����55"<<endl;
	cout<<"     2.������Ҫ����100"<<endl;
	cout<<"     3.Ŀǰδ����������"<<endl;
	cout<<"     4.���д���ڡ�XX.txt���е�����/�������벻Ҫ���ֿո񣬷���һ�������"<<endl;
	cout<<"-----------------------------------��Ҫ��Ϣ-----------------------------------"<<endl;
	cout<<"������齱������";
	cin>>pernum;
	cout<<"�����뽱Ʒ������";
	cin>>awanum;
	cout<<"��ȡ��Ϣ��......"<<endl;
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
	cout<<"��ȡ��ɣ�"<<endl;
	cout<<"�������������:";
	cin>>seed;
	cout<<"���óɹ�!"<<endl;
	system("pause");
	return;
}

void g2(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":";
		if(donum[i]==0) cout<<"��";
		for(int j=1;j<donum[i]+1;j++){
			cout<<aw[have[i][j]]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<"��Ʒ����ͳ��:"<<endl;
	total1();
	cout<<endl; 
	back();
	return;
}

void awlist(){
	system("cls");
	for(int i=1;i<awanum+1;i++){
		cout<<i<<"."<<aw[i]<<":�ܼ�"<<awmax[i]<<"��/ʣ��"<<awlimit[i]<<"��;"<<endl;
	}
	cout<<endl;
	system("pause");
	return;
}

void g1(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":"<<score[i]<<"\t"<<"\t";
		if(i%2==0) cout<<endl;
	}
	cout<<endl;
	cout<<"������齱��:";
	cin>>per;
	cout<<name[per]<<"���ɳ齱"<<score[per]/one<<"�Σ�������齱����:";
getnum:
	cin>>num;
	if(num<0){
		cout<<"error"<<endl;
		cout<<"��������ȷ�齱����:";
		goto getnum;
	}else if(score[per]>num*one||score[per]==num*one){
		score[per]=score[per]-num*one;
		donum[per]=num;
		chouqu();
	}else{
		cout<<"�벻Ҫ��������"<<endl;
		cout<<"������齱����:";
		goto getnum;
	}
	return;
}

void g5(){
	system("cls");
	cout<<"�б�:"<<endl;
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":";
		for(int j=1;j<donum[i]+1;j++){
			cout<<aw[have[i][j]]<<"\t";
		}
		cout<<endl;
	}
	int do1,done1,change;
	cout<<"������ת����:";
	cin>>do1;
	if(do1>pernum||do1<1){
		cout<<"���޴���"<<endl;
		system("pause");
		goto loop;
	}
	if(donum[do1]==0){
		cout<<"��û�н�Ʒѽ���޷�ת��"<<endl;
		system("pause");
		goto loop;
	}
	cout<<"�����뱻ת����:";
	cin>>done1;
	if(done1>pernum||done1<1){
		cout<<"���޴���"<<endl;
		system("pause");
		goto loop;
	}
	cout<<name[do1]<<"���н�Ʒ�б�:"<<endl;
	for(int i=1;i<donum[do1]+1;i++){
		cout<<"\t"<<i<<"."<<aw[have[do1][i]]<<endl;
	}
lp:
	cout<<"������ת�õĽ�Ʒ���:";
	cin>>change;
	if(change<0||change==0||change>donum[do1]){
		cout<<"�����ڸý�Ʒ"<<endl;
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
		cout<<"ת�óɹ�"<<endl;
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
				if(num!=1&&i!=1) cout<<name[k]<<"�����;"<<endl;
				cout<<"��Ʒ�ѳ���,�����ͬѧ�޷���ȡ"<<endl;
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
		cout<<name[k]<<"�����;"<<endl;
		Sleep(1);
	}
Stop:
	cout<<"���в��������"<<endl;
	system("pause");
	return;
}

void g0(){
	system("cls");
	int ge;
	cout<<"0.����"<<endl;
	cout<<"1.�˳�������"<<endl;
	cout<<"2.�˳�������"<<endl;
	cout<<"���������:";
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

void ui(){
	system("cls");
	for(int i=1;i<pernum+1;i++){
		cout<<i<<"."<<name[i]<<":"<<score[i]<<"\t"<<"\t";
		if(i%2==0) cout<<endl;
	}
	cout<<endl<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"|0.�˳�                                 |"<<endl;
	cout<<"|1.�齱                                 |"<<endl;
	cout<<"|2.�鿴�ѻ�õĽ�Ʒ                     |"<<endl;
	cout<<"|3.�鿴���ܻ�õĽ�Ʒ                   |"<<endl;
	cout<<"|4.ת�÷���                             |"<<endl;
	cout<<"|5.ת�ý�Ʒ                             |"<<endl;
	cout<<"|6.����ȫ���齱                         |"<<endl;
	cout<<"-----------------------------------------"<<endl;
again:
	cout<<"���������:";
	cin>>g;
	if(stop!=2){
		if(g==0) g0();
		else if(g==1) g1();
		else if(g==2) g2();
		else if(g==3) awlist;
		else if(g==4) g4();
		else if(g==5) g5();
		else if(g==6) g6();
		else{
			cout<<"error"<<endl;
			goto again;
		}
	}else{
		if(g==0) g0();
		else if(g==1){
			cout<<"���н�Ʒ�ѳ���,�޷�����"<<endl;
			goto again; 
		}else if(g==2) g2();
		else if(g==3) awlist();
		else if(g==4) g4();
		else if(g==5) g5();
		else if(g==6){
			cout<<"���н�Ʒ�ѳ���,�޷�����"<<endl;
			goto again; 
		}else{
			cout<<"error"<<endl;
			goto again;
		}
	}
}

int main(){
	system("title ��Ʒ��ȡ-Powered by Ballantyne");
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
	cout<<"���������Ʒ�б�......"<<endl;
	awaout();
	cout<<"��ɣ�"<<endl;
	cout<<"�б����������ǰĿ¼��AwardForEachOne.txt�ļ���"<<endl; 
	cout<<"�ѽ�������"<<endl; 
    system("pause");
	return 0;
Stop2:
	system("pause");
	return 0;
}