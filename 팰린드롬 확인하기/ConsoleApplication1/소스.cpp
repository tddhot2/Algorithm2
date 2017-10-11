#include <iostream>
using namespace std;

int map[1001][3];
int n, k;
int ans = 0;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		int a, b, c;
		scanf("%d %d %d", &map[tmp][0], &map[tmp][1], &map[tmp][2]);
	}

	for (int i = 1; i <= n; i++) {

		if (i != k)
		{
			if (map[i][0] > map[k][0])
				ans++;
			else if (map[i][0] == map[k][0]) {
				if (map[i][1] > map[k][1])
					ans++;
				else if (map[i][1] == map[k][1]) {
					if (map[i][2] > map[k][2])
						ans++;
				}
			}

		}

		cout << ans + 1 << endl;
		return 0;
	}
}