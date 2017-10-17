#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000

vector<int> graph[1001];
vector<int> solo;
int N;

/*
* Description :
* Time complexity :
* Space complexity :
*/

bool flag = false;
bool seated[1000];

void solve(int now, int total) {
	if (total == N) {
		int i;
		for (i = 0; i < N; i++) 
			if (seated[i] == false)
				break;
		
		if (i == N)
			flag = true;
	}
	for (int i = 0; i < graph[now].size(); i++) {
		if (seated[graph[now][i]] == false) {
			seated[graph[now][i]] = true;
			solve(now + 1, total + 1);
			seated[graph[now][i]] = false;
		}
	}
}

int main() {
	int T, K, P, S;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		cin >> K;

		for (int i = 0; i < N; i++)
			seated[i] = false;
		flag = false;

		for (int i = 0; i < K; i++) {
			cin >> P >> S;
			graph[S].push_back(P);
		}

		solve(0, 0);
		if (flag == false)
			cout << "X" << endl;
		else
			cout << "O" << endl;

		for (int i = 0; i < N; i++) {
			graph[i].clear();
		}
		solo.clear();

		
	}
	return 0;
}
