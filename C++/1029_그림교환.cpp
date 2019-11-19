#include <iostream>
#include <stdio.h>
using namespace std;

int dp[1<<15][15][10];
int sellPic(int N, int** cost, int state, int artist, int c, int depth);

int main() {
	int N;
	cin >> N;
	
	int **cost = new int*[N];
	for(int i = 0; i < N; i++){
		cost[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d",&cost[i][j]);
		}
	}
	
	cout << sellPic(N,cost,1,0,0,1);
	
	return 0;
}

// state�� �湮 ����, artist�� ������ ��ȣ, c�� ���� �������� �� cost, depth�� �����ߴ� ������� ��(����)
int sellPic(int N, int** cost, int state, int artist, int c, int depth){
	if(dp[state][artist][c] != 0){ //�̹� ����� �Ϸ�Ǿ��ٴ� ��
		return dp[state][artist][c];
	}
	
	dp[state][artist][c] = depth; // ���� ���̸� ����
	for(int i = 0; i < N; i++){
		if(state&(1<<i) || cost[artist][i] < c){ //�̹� �湮�߰ų�, �� ���ݺ��� �� ������ ���� ��
			continue;
		}
		
		int tmp = sellPic(N,cost,(state|(1<<i)),i,cost[artist][i],depth+1); //��������� �����Ͽ�
		if(dp[state][artist][c] < tmp){//�� ū ���� ������ max���� �ٲ��ְ� return
			dp[state][artist][c] = tmp;
		}
	}
	
	return dp[state][artist][c];
}