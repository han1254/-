#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
//#include <sstream>
using namespace std;
 
/*类别：
	1	CONST,
	2	VAR,
	3	procedure,
	4	begin,
	5	end,
	6	odd,	//判断是否为奇数 
	7	if,
	8	then,
	9	call,
	10	while,
	11	do,
	12	read,
	13	write,
		
	14	S_ID,	//变量标识符
	15	S_INT,	//常量
	
	//运算符 
	16	ADD,	//'+'
	17	SUB,	//'-'
	18	STAR,	//'*'
	19	DIV,	//'/'
	20	ASSIGN,	//'='，赋值 
	21	LESS,	//'<'
	22	GREAT,	//'>'
	23	LESSEQ,	//'<='
	24  GREATEQ,//'>='
	25  EQ,		//':='
	26  NEQ,	//'#'，不等于
	    
	//界符 
	27  COMMA	//','
	28  SEM		//';'
	29 	LEFT,	//'('
	30  RIGHT,	//')'
	
	31	.		//程序结束符 
*/ 
 
//全局变量 
string line;//每一行字符串
int len;//当前字符串长度 
int index;//索引 
char ch;//当前字符 
//map<string,pair<int,string> > SYM;//关键字表:symbol class address 
vector<string> ID;//标识符表 
vector<int> NUM;//常数表 
string word;//存放单词 
int indexSYM=0,indexID=0,indexNUM=0;//符号表、标识符表、常数表的索引值
 
//关键字 
string keyword[13] = {"const","var","procedure","begin","end","odd","if","then","call","while","do","read","write"}; 
 
//判断是否是关键字，是则返回编码，否则返回0 
int  isKeyword(string word) {
	for(int i=0;i<13;i++) {
		if(word.compare(keyword[i])==0)
			return (i+1);
	}
	return 0;
}
//将下一字符读入并将搜索指示器向前移 
void GetChar() {
		
		ch=tolower(line[index]);//得到当前字符，转为小写 
		//cout<<ch<<endl;
		index++;//指针前移
		//cout<<index<<endl;
	
}
 
//判断ch中的字符是否为空格或\t 
void GetBC() { 
	while(ch==' ' || ch=='\t') {//空格则继续读入下一个字符 
		GetChar();
		//cout << "index="<<index<<endl; 
	}
	
}
 
//将搜索指示器回调一个字符位置，将ch置为空白符 
void Retract() {
	index--;
	ch=' '; 
} 
 
//词法分析 
void GetSYM() {
	 
	while(index<=len-1) {//没有到达行尾则一直查看当前字符 
		GetChar();
		//cout<<ch<<endl;
		GetBC();
		//读取空格之后需要特别判断是否读完这一行，对于在最后面的空格很有用 
		if(index>len)
			continue;
		
		//是字母开头，则为标识符或关键字 
		if(isalpha(ch)) {
			word="";
			//word+=ch;
			//是字母或者数字，则一直读入 
			while(isalpha(ch) || isdigit(ch)) {				
				
				/*if(index==len) {//到达行尾则退出 
					break;
				}*/		
				word+=ch;//单词拼接		
				GetChar();
			}
			Retract();//回调 
			int p=isKeyword(word);
			if(p>0) {//是关键字 
				cout<<word<<"\t"<<p<<"\t"<<"-"<<endl;
			} else {//是标识符 
				vector<string>::iterator ite=std::find(ID.begin(),ID.end(),word);//查表
				if(ite==ID.end()) {//表中不存在 
					cout<<word<<"\t"<<"14"<<"\t"<<indexID<<endl;
					indexID++;
					ID.push_back(word); 
				} else {//表中存在 
					cout<<word<<"\t"<<"14"<<"\t"<<distance(ID.begin(),ite)<<endl;//返回已经存在于表中的下标 
				}
				
			}	
		} else if(isdigit(ch)) {//是数字打头 
			word="";
			while(isdigit(ch)) {
				word+=ch;
				/*if(index==len) {//到达行尾则退出 
					cout<<"?"<<endl;
					break;
				}*/
				GetChar();			
			}
			Retract();//回调一个字符
			int num=atoi(word.c_str());//转换为int 
			vector<int>::iterator iter=std::find(NUM.begin(),NUM.end(),num);//查表
			if(iter==NUM.end()) {//表中不存在 
				cout<<word<<"\t"<<"15"<<"\t"<<indexNUM<<endl;
				indexNUM++;
				NUM.push_back(num); 
			} else {//表中存在 
				cout<<word<<"\t"<<"15"<<"\t"<<distance(NUM.begin(),iter)<<endl;//返回已经存在于表中的下标 
			}
			
		} else if(ch=='+') {
			cout<<"+"<<"\t"<<"16"<<"\t"<<"-"<<endl;
		} else if(ch=='-') {
			cout<<"-"<<"\t"<<"17"<<"\t"<<"-"<<endl;
		} else if(ch=='*') {
			cout<<"*"<<"\t"<<"18"<<"\t"<<"-"<<endl;
		} else if(ch=='/') {
			cout<<"/"<<"\t"<<"19"<<"\t"<<"-"<<endl;
		} else if(ch=='=') {
			cout<<"="<<"\t"<<"20"<<"\t"<<"-"<<endl;
		} else if(ch=='<') {
			if(line[index]=='=') {
				cout<<"<="<<"\t"<<"23"<<"\t"<<"-"<<endl;
				index++;
			} else
				cout<<"<"<<"\t"<<"21"<<"\t"<<"-"<<endl;
		} else if(ch=='>') {
			if(line[index]=='=') {
				cout<<">="<<"\t"<<"24"<<"\t"<<"-"<<endl;
				index++;
			} else
				cout<<">"<<"\t"<<"22"<<"\t"<<"-"<<endl;
		} else if(ch==':') {
			//cout<<"hh"<<line[index+1];
			if(line[index]=='=') {
				cout<<":="<<"\t"<<"25"<<"\t"<<"-"<<endl;
				index++;
			} else {//错误 
				cout<<"Program error1!"<<endl;
				exit(0);
			}
		} else if(ch=='#') {
			cout<<"#"<<"\t"<<"26"<<"\t"<<"-"<<endl;
		} else if(ch==',') {
			cout<<","<<"\t"<<"27"<<"\t"<<"-"<<endl;
		} else if(ch==';') {
			cout<<";"<<"\t"<<"28"<<"\t"<<"-"<<endl;
		} else if(ch=='(') {
			cout<<"("<<"\t"<<"29"<<"\t"<<"-"<<endl;
		} else if(ch==')') {
			cout<<")"<<"\t"<<"30"<<"\t"<<"-"<<endl;
		} else if(ch=='.') {
			cout<<"."<<"\t"<<"31"<<"\t"<<"-"<<endl;
			cout<<"End！"<<endl;
			exit(0);
		} else {
			cout<<"Program error2!"<<endl;
			exit(0);
		}
	}
}
 
int main() {
	string filename;//文件名 
	cout << "Please input the file name: ";
	cin >> filename;//输入要处理的文件名 
	
	ifstream f(filename.c_str());//创建一个fstream文件流对象
	
	cout<<"SYM:"<<endl;
	cout<<"symbol"<<"\t"<<"class"<<"\t"<<"address"<<endl;//题头 
	int i=0;
	while(getline(f,line,'\n')) {
		//transform(line.begin(),line.end(),line.begin(),tolower);//全部转为小写
		//cout<<line<<endl;//输出读取的内容 
		len=line.length();//获取当前行字符串长度
		index=0;
		GetSYM();
	}
	
	
	
	cout<<"NUM:"<<endl;
	cout<<"index"<<"\t"<<"value"<<endl;
	for(int i=0;i<indexNUM;i++) {
		cout<<i<<"\t"<<NUM[i]<<endl; 
	}
	
	return 0; 
} 