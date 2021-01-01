#define CLOCKS_PER_SEC ((clock_t)1000)
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
typedef unsigned long int Type;
vector<vector<Type> >ans;
//传入n，矩阵的规模,nums,当前需要生成的矩阵的个数
void Table(Type n,int nums);
//输出比赛表
void printTab();
//复制矩阵，给出src的坐标，dst的坐标以及复制的矩阵的维度n
void copyMat(pair<int,int>src,pair<int,int>dst,int n);
int main() {
	int k = 0;
	clock_t start, end;
	while (true)
	{
		cout << "请输入k = ";
		cin >> k;
		start = clock();
		Type n = 1;
		for (int i = 0; i < k; i++)//求出矩阵的大小：n*n
		{
			n = n << 1;
		}
		ans.resize(n);
		for (int i = 0; i < n; i++)
		{
			ans[i].resize(n);
			ans[0][i] = i + 1;//把第一行初始化
		}
		Table(n,1);
		printTab();
		end = clock();
		printf("程序用时为:%lfs。\n", double((end - start) / CLOCKS_PER_SEC));
		system("pause");
		system("cls");
	}
}
void Table(Type n,int nums) {//制作比赛日程表
	if (n == 1)return;//到达规模最小的矩阵：1*1
	Table(n >> 1,nums<<1);
	int dim = n >> 1;
	for (int i = 0; i < nums; i++)
	{
		//正斜方向复制
		copyMat(make_pair(0, i*n), make_pair(dim, i*n + dim), dim);
		//反斜方向复制
		copyMat(make_pair(0, i*n + dim), make_pair(dim, i*n), dim);
	}
}
void printTab() {
	int len = ans.size();
	for (int i = 0; i < len; i++)
	{
		printf("—-");
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
			cout << "—-";
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