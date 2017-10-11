#include <iostream>
using namespace std;

#define INF 100001

int dist[101][101];
int n;
int m;

void print_dist() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << dist[i][j] << " ";
		cout << "\n";
	}
}


int main() {
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
			


	// Graph 배열에 한 지점에서 다른 지점까지의 비용 입력 완료
	for (int i = 0; i < m; i++) {
		int v, w, cost;
		scanf("%d %d %d", &v, &w, &cost);
		if(dist[v][w]==INF)
			dist[v][w] = cost;
		else
		{
			if (dist[v][w] > cost)
				dist[v][w] = cost;
		}
	}


	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] < dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][j];
				else
					dist[i][j] = dist[i][k] + dist[k][j];
			}

	print_dist();

	return 0;
}