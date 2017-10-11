#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[101][101];
int visited[101];
int check[101];
vector<int> blueTeam;
int n;
queue<int> q;
vector<int> removeList;

void printVec() {
	for (int i = 0; i < blueTeam.size(); i++)
		cout << blueTeam[i] << " ";
	cout << "\n";

}

int main() {
	
	cin >> n; // 전체 사람의 수

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			graph[i][j] = 1;


	// 사람마다 싫어하는 정보에 따라, 그래프내 정점간 간선 제거
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		visited[i] = 0;
		check[i] = 0;
		for (int j = 0; j < k; j++) {
			int number;
			cin >> number;
			graph[i][number] = 0;
			graph[number][i] = 0;
		}
	}


	blueTeam.push_back(1);
	visited[1] = 1;
	for (int i = 2; i <= n; i++)
		if (graph[1][i] == 1) {
			q.push(i);
			blueTeam.push_back(i);
		}
			

	

	while (!q.empty()) {
		
		int now = q.front();
		q.pop();
		visited[now] = 1;

		for (int i = 0; i < blueTeam.size(); i++) {
			if (graph[now][blueTeam[i]] == 0) {
				removeList.push_back(now);
			}
			else {
				if (visited[blueTeam[i]] == 0) {
					q.push(blueTeam[i]);
				}
			}
		}

		for (int i = 0; i < removeList.size(); i++) {
			vector<int>::iterator rp = lower_bound(blueTeam.begin(), blueTeam.end(), removeList[i]);
			blueTeam.erase(rp);
		}
		removeList.clear();
	}



	cout << blueTeam.size() << endl;
	for (int i = 0; i < blueTeam.size(); i++)
		cout << blueTeam[i] << " ";
		

	cout << "\n";
	cout << n - blueTeam.size() << endl;
	
	for (int i = 0; i < blueTeam.size(); i++) {
		check[blueTeam[i]] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (check[i] == 0)
			cout << i << " ";
	return 0;
}