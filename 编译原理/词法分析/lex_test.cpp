#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <cctype>
#include <algorithm> 
using namespace std;

string line;
int len;
int index;
char ch;
vector<string> ID;
vector<int> NUM;
string word;

int indexSym = 0, indexId = 0, indexNum = 0;

string keyWords[13] = {"const","var","procedure","begin","end","odd","if","then","call","while","do","read","write"};

/**
 * return the position of the word in the keyWords array.
 * if the word is not a keyword, return 0.
 * @param  word 
 * @return the positon of the word in the keyWords array, or return 0 
 * while the word is not a keyword.
 */
int isKeyword(string word) {
	for (int i = 0; i < 13; ++i)
	{
		if (word.compare(keyWords[i]))
		{
			return (i + 1);
		}
	}
	return 0;
}

void getNextChar() {
	ch = tolower(line[index++]);
} 

void getBc() {
	while(ch == ' ' || ch == '\t') {
		getNextChar();
	}
}

void retract() {
	index--;
	ch = ' ';
}

void getSysm() {
	while(index <= len - 1) {
		getNextChar();
		getBc();
		
		if(index > len) {
			continue;
		}
		
		if(isalpha(ch)) {
			word = "";
			
			while(isalpha(ch) || isdigit(ch)) {
				word += ch;
				getNextChar();
			}
			retract();
			int p = isKeyword(word);
			if(p > 0) {
				cout<<word<<"\t\t\t\t\t"<<p<<"\t" <<"-"<<endl;
			} else {
				vector<string>::iterator ite = std::find(ID.begin(), ID.end(), word);
				if(ite == ID.end()) {
					cout<<word<<"\t\t\t\t\t"<<"14"<<"\t"<<indexId<<endl;
					indexId++;
					ID.push_back(word);
				} else {
					cout<<word<<"\t\t\t\t\t"<<"14"<<"\t"<<distance(ID.begin(), ite);
				}
			}
		} else if (isdigit(ch)) {
			word = "";
			while(isdigit(ch)) {
				word += ch;
				getNextChar();
			}
			retract();
			int num = atoi(word.c_str());
			vector<int>::iterator iter = std::find(NUM.begin(), NUM.end(), num);
			if(iter == NUM.end()) {
				cout<<word<<"\t\t\t\t\t"<<"15"<<"\t"<<indexNum<<endl;
				indexNum++;
				NUM.push_back(num);
			} else {
				cout<<word<<"\t\t\t\t\t"<<"15"<<"\t"<<distance(NUM.begin(), iter)<<endl;
			}
		} else if(ch == '+') {
			cout<<"+"<<"\t\t\t\t\t"<<"16"<<"\t"<<"-"<<endl;
		} else if(ch == '-') {
			cout<<"-"<<"\t\t\t\t\t"<<"17"<<"\t"<<"-"<<endl;
		} else if(ch == '*') {
			cout<<"*"<<"\t\t\t\t\t"<<"18"<<"\t"<<"-"<<endl;
		} else if(ch == '/') {
			cout<<"/"<<"\t\t\t\t\t"<<"19"<<"\t"<<"-"<<endl;
		} else if(ch == '=') {
			cout<<"-"<<"\t\t\t\t\t"<<"20"<<"\t"<<"-"<<endl;
		} else if(ch == '<') {
			if(line[index] == '=') {
				cout<<"<="<<"\t\t\t\t\t"<<"21"<<"\t"<<"-"<<endl;
			} else {
				cout<<"<"<<"\t\t\t\t\t"<<"22"<<"\t"<<"-"<<endl;
			}
		} else if(ch == '>') {
			if(line[index] == '=') {
				cout<<">="<<"\t\t\t\t\t"<<"23"<<"\t"<<"-"<<endl;
			} else {
				cout<<">"<<"\t\t\t\t\t"<<"24"<<"\t"<<"-"<<endl;
			}
		} else if(ch == ':') {
			if(line[index] == '=') {
				cout<<":="<<"\t\t\t\t\t"<<"25"<<"\t"<<"-"<<endl;
			} else {
				cout<<"Error! There is no usage of using a single ':' as a operator!"<<endl;
			}
		} else if(ch == '#') {
			cout<<"#"<<"\t\t\t\t\t"<<"26"<<"\t"<<"-"<<endl;
		} else if(ch == ',') {
			cout<<","<<"\t\t\t\t\t"<<"27"<<"\t"<<"-"<<endl;
		} else if(ch == ';') {
			cout<<";"<<"\t\t\t\t\t"<<"28"<<"\t"<<"-"<<endl;
		} else if(ch == '(') {
			cout<<"("<<"\t\t\t\t\t"<<"29"<<"\t"<<"-"<<endl;
		} else if(ch == ')') {
			cout<<")"<<"\t\t\t\t\t"<<"30"<<"\t"<<"-"<<endl;
		} else if(ch == '.') {
			cout<<"."<<"\t\t\t\t\t"<<"31"<<"\t"<<"-"<<endl;
			cout<<"The End."<<endl;
		} else {
			cout<<"There is something wrong whith your program, please check it carefully!"<<endl;
			exit(0);
		}
	}
}

int main() {
	// string fileName;
	// cout << "Please input the file name:";
	// cin >> fileName;
	// ifstream f(fileName.c_str());
	// cout << "getSysm:"<<endl;
	// cout<<"symbol"<<"\t\t\t\t"<<"class"<<"\t"<<"address"<<endl;
	// while(getline(f, line, '\n')) {
	// 	len = line.length();
	// 	cout<<len<<endl;
	// 	index = 0;
	// 	getSysm();
	// }
	// return 0;
	string filename;//文件名 
	cout << "Please input the file name: ";
	cin >> filename;//输入要处理的文件名 
	
	ifstream f(filename.c_str());//创建一个fstream文件流对象
	
	cout<<"SYM:"<<endl;
	cout<<"symbol"<<"\t\t\t\t\t"<<"class"<<"\t"<<"address"<<endl;//题头 
	while(getline(f,line,'\n')) {
		//transform(line.begin(),line.end(),line.begin(),tolower);//全部转为小写
		//cout<<line<<endl;//输出读取的内容 
		cout<<"come in"<<endl;
		len=line.length();//获取当前行字符串长度
		index=0;
		getSysm();
	}
}

