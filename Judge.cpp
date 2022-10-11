//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
using namespace std;
#define MAX 90
int sum = 8*8  ;	//���������**********************************************************************
int value;	//��Ч��������
int flag1, flag2, flag3, flag4, flag5;
string cur;
struct stuMessage {//һ�ſ��е�ѧ����Ϣ
	string na = "";    //����
	int sno = 0;     //ѧ��
	string sex = "";       //�Ա�
	double GPA = 0;     //����
	int attend[20] = { 0 }; //���������0����ȱ�ڣ�1��������
	double rate = 0;	//��ǰ������
	// int onTime;     //�ܵĳ��ڴ���--���ڼ��㵱ǰ������
	// int flag;       //��ǰ�ǵڼ��οΣ�����������
};
struct stuMessage curse1[MAX];	//����Ϊȫ�ֱ���
struct stuMessage curse2[MAX];
struct stuMessage curse3[MAX];
struct stuMessage curse4[MAX];
struct stuMessage curse5[MAX];

/*Ŀ�꣺E=���ſγ���Ч��������/���������----���
	ͨ��������������1.�ϴο������ 2.��ǰ������ 3.����
*/
//�ն˽���
void star(string cur);//��ʼ
void openFile(string cur, struct stuMessage* curse, int flag);//���뿼����Ϣ��
//����1��������
void judge1(struct stuMessage* curse);
//����2����������
void judge2(struct stuMessage* curse, int flag);
//����3�����ϴο���
void judge3(struct stuMessage* curse, int flag);

string Utf8ToGbk(const char* src_str)		//UTF-8����תΪGBK���룬�����ȡcsv�ļ�ʱ�������������
{
	int len = MultiByteToWideChar(CP_UTF8, 0, src_str, -1, NULL, 0);
	wchar_t* wszGBK = new wchar_t[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, src_str, -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
	string strTemp(szGBK);
	if (wszGBK) delete[] wszGBK;
	if (szGBK) delete[] szGBK;
	return strTemp;
}

void Stringsplit(string str, const const char split, vector<string>& res)		//split�ָ��ַ�������
{
	istringstream iss(str);	// ������
	string token;			// ���ջ�����
	while (getline(iss, token, split))	// ��splitΪ�ָ���
	{
		res.push_back(token);
	}
}

int main() {
	//��ȡҪ�����Ŀγ�������ѡ���ļ�������
	star(cur);
	/*double e = value * 1.0 / sum;
	printf("E = %.8f\n", e);*/
	return 0;
}

void star(string cur) {
	while (1) {
		printf("�����Ҫ�����Ŀγ�(��q�˳�)��\n");
		cin >> cur;
		if (cur == "q") {    // �˳�
			break;
		}
		if (cur == "1") openFile(cur, curse1, flag1);
		else if(cur == "2") openFile(cur, curse2, flag2);
		else if(cur == "3") openFile(cur, curse3, flag3);
		else if(cur == "4")openFile(cur, curse4, flag4);
		else if(cur == "5")openFile(cur, curse5, flag5);
	}
	return;
}

void openFile(string cur, struct stuMessage* curse, int flag) {
	//��ȡ
	int i = 0, j = 0;
	if (cur == "1") {
		ifstream fin("d:\Class1.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "2") {
		ifstream fin("d:\Class2.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "3") {
		ifstream fin("d:\Class3.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "4") {
		ifstream fin("d:\Class4.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	else if (cur == "5") {
		ifstream fin("d:\Class5.csv");
		string line;
		while (getline(fin, line)) {
			const char* src_str = line.c_str();
			string dst_str = Utf8ToGbk(src_str);
			vector<string>strlist;
			Stringsplit(dst_str, ',', strlist);
			curse[i].na = strlist[0], curse[i].sex = strlist[1], curse[i].sno = std::stoi(strlist[2]), curse[i].GPA = std::stof(strlist[3]);
			for (j = 4; j < strlist.size(); j++) {
				curse[i].attend[j - 4] = std::stoi(strlist[j]);
			}
			i++;
		}
	}
	
	
	//����**********************************************************************************
	for (flag; flag < 8; flag++) {
		if(flag==0)judge1(curse);
		if (flag != 0) {
			judge2(curse, flag);
			judge3(curse, flag);
		}
		/*for (i = 0; i < MAX; i++) {
			for (j = 0; j < 20; j++) {
				cout << curse[i].attend[j] << " ";
			}
			cout << endl;
		}
		cout << flag << "____________" << endl;*/
		for (i = 0; i < 8; i++) {
			if (curse[i].attend[flag] == 0)
				value++;
		}
	}
	/*for (i = 0; i < 8; i++) {
		if (curse[i].attend[19] == 0)
			value++;
	}*/
	double e = value * 1.0 / sum;
	printf("E = %.8f\n", e);
	cout << value << " " << sum << endl;
	value = 0;

	return;
}
//����
void judge1(struct stuMessage* curse) {
	struct stuMessage x;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = 0; j < MAX - i-1; j++) {
			if (curse[j].GPA > curse[j + 1].GPA) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}
void judge2(struct stuMessage* curse, int flag) {
	if (flag == 0) {
		exit(0);
	}
	int va = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < flag; j++) {
			if (curse[i].attend[j] == 1) {
				va++;
			}
		}
		curse[i].rate = va * 1.0 / flag;
	}
	struct stuMessage x;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = 0; j < MAX - i-1; j++) {
			if (curse[j].rate > curse[j + 1].rate) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}
void judge3(struct stuMessage* curse, int flag) {
	if (flag == 0) {
		exit(0);
	}
	struct stuMessage x;
	for (int i = 0; i < MAX-1; i++)
	{
		for (int j = 0; j < MAX - i-1; j++) {
			if (curse[j].attend[flag - 1] > curse[j + 1].attend[flag - 1]) {
				x = curse[j + 1];
				curse[j + 1] = curse[j];
				curse[j] = x;
			}
		}
	}
	return;
}