#define CLOCKS_PER_SEC ((clock_t)1000)
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
typedef unsigned long int Type;
vector<vector<Type> >ans;
//����n������Ĺ�ģ,nums,��ǰ��Ҫ���ɵľ���ĸ���
void Table(Type n,int nums);
//���������
void printTab();
//���ƾ��󣬸���src�����꣬dst�������Լ����Ƶľ����ά��n
void copyMat(pair<int,int>src,pair<int,int>dst,int n);
int main() {
	int k = 0;
	clock_t start, end;
	while (true)
	{
		cout << "������k = ";
		cin >> k;
		start = clock();
		Type n = 1;
		for (int i = 0; i < k; i++)//�������Ĵ�С��n*n
		{
			n = n << 1;
		}
		ans.resize(n);
		for (int i = 0; i < n; i++)
		{
			ans[i].resize(n);
			ans[0][i] = i + 1;//�ѵ�һ�г�ʼ��
		}
		Table(n,1);
		printTab();
		end = clock();
		printf("������ʱΪ:%lfs��\n", double((end - start) / CLOCKS_PER_SEC));
		system("pause");
		system("cls");
	}
}
void Table(Type n,int nums) {//���������ճ̱�
	if (n == 1)return;//�����ģ��С�ľ���1*1
	Table(n >> 1,nums<<1);
	int dim = n >> 1;
	for (int i = 0; i < nums; i++)
	{
		//��б������
		copyMat(make_pair(0, i*n), make_pair(dim, i*n + dim), dim);
		//��б������
		copyMat(make_pair(0, i*n + dim), make_pair(dim, i*n), dim);
	}
}
void printTab() {
	int len = ans.size();
	for (int i = 0; i < len; i++)
	{
		printf("��-");
	}
	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("|");
		for (int j = 0; j < len; j++)
		{
			printf("%2d|", ans[i][j]);
		}
		cout << endl;
		for (int i = 0; i < len; i++)
		{
			cout << "��-";
		}
		cout << endl;
	}
}
void copyMat(pair<int,int>src,pair<int,int>dst ,int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans[dst.first + i][dst.second + j] = ans[src.first + i][src.second + j];
		}
	}
}