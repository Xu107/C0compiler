#include <string>
#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;
enum fct {
	LIT, LOD, STO, CAL, INT, JMP, JPC, ADD, SUB, MUL, DIV, RED, WRT, RET
};
fct string_to_fct(string s)
{
	if (s == "LIT")
		return LIT;
	if (s == "LOD")
		return LOD;
	if (s == "STO")
		return STO;
	if (s == "CAL")
		return CAL;
	if (s == "INT")
		return INT;
	if (s == "JMP")
		return JMP;
	if (s == "JPC")
		return JPC;
	if (s == "ADD")
		return ADD;
	if (s == "SUB")
		return SUB;
	if (s == "MUL")
		return MUL;
	if (s == "DIV")
		return DIV;
	if (s == "RED")
		return RED;
	if (s == "WRT")
		return WRT;
	if (s == "RET")
		return RET;
}
struct instruction {
	enum fct f;
	int l;
	int a;
};
const int codemaxsize = 500;
const int stacksize = 50;
instruction code[codemaxsize];
int base(int, int*, int);
void interpret();
int main()
{
	ifstream in("C0MiddleProgram.txt");
//	ofstream out("2.txt");
	string filename;
	string line;
	string str1, str2, str3;
	int instructionsum = 0;
	if (in) // 有该文件
	{
		while (getline(in, line)) // line中不包括每行的换行符
		{
			cout << line << endl;
			istringstream is(line);
			is >> str1 >> str2 >> str3;//已经处理完成。
			//cout << "("<<i<<") "<<str2 << " " << str3 << " " << str4 << endl;
			code[instructionsum].f = string_to_fct(str1);
			code[instructionsum].l = stoi(str2);
			code[instructionsum].a = stoi(str3);
			instructionsum++;
			//out << line << endl; // 输入到2.txt中
		}
	}
	else // 没有该文件
	{
		cout << "no such file" << endl;
	}
	for (int i = 0; i < instructionsum; i++)
	{
		cout<<"("<<i<<") "<<code[i].f<<" "<<code[i].l<<" "<<code[i].a<<endl;
	}

	interpret();
	system("pause");
	return 0;
}
void interpret()
{
	int p, b, t;
	struct instruction i;
	int s[stacksize];
	cout << "start C0\n";
	t = 0; b = 0; p = 0;
	s[0] = s[1] = s[2] = 0;
	do {
		i = code[p];
		p++;
		switch (i.f)
		{
		case LIT:
			s[t] = i.a;
			t++;
			break;
		case LOD:
			if(i.a==0&&i.l==0)
			{
				s[t]=s[0];
				t++;
			}
			else
			{
				s[t] = s[base(i.l, s, b) + i.a];
				t++;
			}

			break;
		case STO:
			t--;
			if(i.a==0&&i.l==0)
			{
				s[0]=s[t];
			}
			else
			s[base(i.l, s, b) + i.a] = s[t];
			break;
		case CAL:
			s[t] = b;
			s[t + 1] = 0;//b->0
			s[t + 2] = p;
			b = t;
			p = i.a;
			break;
		case INT:
			t += i.a;
			break;
		case JMP:
			p = i.a;
			break;
		case JPC:
			t--;
			if (s[t] == 0)
				p = i.a;
			break;
		case ADD:
			t--;
			s[t - 1] = s[t] + s[t - 1];
			break;
		case SUB:
			t--;
			s[t - 1] = s[t - 1] - s[t];
			break;
		case MUL:
			t--;
			s[t - 1] = s[t - 1] * s[t];
			break;
		case DIV:
			t--;
			s[t - 1] = s[t - 1] / s[t];
			break;
		case RED:
			cin >> s[t];
			t++;
			break;
		case WRT:
			cout << s[t - 1]<<endl;
			t--;
			break;
		case RET:
			t = b;
			p = s[t + 2];
			b = s[t];
			if (b == 0)
				return;
			break;
		}
	} while (p != 0);
}
int base(int l, int* s, int b)
{
	int bt;

	bt = b;
	while (l > 0)
	{
		bt = s[bt];
		l--;
	}
	return bt;
}


