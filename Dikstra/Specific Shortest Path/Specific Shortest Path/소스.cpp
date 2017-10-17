#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// INF means there is no path yet
long long int INF = 1000000000000;

// Weighted Abjacent List
vector<pair<long long int, int>> abj_list[1001];

// a element in dist array means total cost of path found until round
long long int dist[1001][1001];

void print_dist_arr(int n) {
	for (int i = 1; i <= n; i++) {
		cout << i << "½ÃÀÛ : ";
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void shortest_path(int n, int m, int x) {
	// start vertex has 0 cost from itself to itself
	dist[x][x] = 0;

	// priority_queue make time-complexity of dikstra algorithm to O(nlogn)
	priority_queue<pair<long long int, int>> pq;
	pq.push(make_pair(0, x));

	// caution : priority queue is orginally max-heap so we should
	// make minus cost for using that like min-heap
	while (!pq.empty()) {
		int u = pq.top().second;
		long long int cost = -pq.top().first;
		pq.pop();

		// check abjacent vertex abjacent with u vertex
		for (int i = 0; i < abj_list[u].size(); i++) {
			long long int new_dist = cost + abj_list[u][i].first;
			int next_vertex = abj_list[u][i].second;

			// new path's cost is lower than old path's cost
			if (new_dist < dist[x][next_vertex]) {
				dist[x][next_vertex] = new_dist;
				pq.push(make_pair(new_dist*-1, abj_list[u][i].second));
			}
		}
		//print_dist_arr(n);
	}
}

int main() {
	int N, E;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b;
		long long int c;
		cin >> a >> b;
		cin >> c;
		abj_list[a].push_back(make_pair(c, b));
		abj_list[b].push_back(make_pair(c, a));
	}


	// every shortes path is no in first round
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = INF;


	int v1, v2;
	cin >> v1 >> v2;

	shortest_path(N, E, 1);
	shortest_path(N, E, v1);
	shortest_path(N, E, v2);
	shortest_path(N, E, N);

	long long int temp = dist[1][v1] + dist[v1][v2] + dist[v2][N];
	long long int temp2 = dist[1][v2] + dist[v2][v1] + dist[v1][N];

	if (temp > INF&&temp2 > INF) {
		cout << -1 << endl;
	}
	else {
		if (temp > temp2)
			cout << temp2 << endl;
		else
			cout << temp << endl;
	}


	return 0;
}