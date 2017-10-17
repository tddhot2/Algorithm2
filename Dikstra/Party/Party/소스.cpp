#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// INF means there is no path yet
#define INF 1000000000

// Weighted Abjacent List
vector<pair<int,int>> abj_list[1001];

// a element in dist array means total cost of path found until round
int dist[1001][1001];

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
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x));

	// caution : priority queue is orginally max-heap so we should
	// make minus cost for using that like min-heap
	while (!pq.empty()) {
		int u = pq.top().second;
		int cost = - pq.top().first;
		pq.pop();

		// check abjacent vertex abjacent with u vertex
		for (int i = 0; i < abj_list[u].size(); i++) {
			int new_dist = cost + abj_list[u][i].first;
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
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		abj_list[u].push_back(make_pair(w, v));
	}


	// every shortes path is no in first round
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	for(int i=1;i<=n;i++)
		shortest_path(n, m, i);

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int temp = dist[i][x] + dist[x][i];
		if (ans < temp)
			ans = temp;
	}

	cout << ans << endl;
	return 0;
}