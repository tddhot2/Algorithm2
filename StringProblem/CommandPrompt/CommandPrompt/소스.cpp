#include <iostream>
#include <string>
#include <queue>
using namespace std;

char map[12][6];
bool visited[12][6];

void init_visited() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visited[i][j] = false;
}

void print_map() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			cout << map[i][j];
		cout << "\n";
	}
	cout << "\n";
}

void print_visited() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			cout << visited[i][j];
		cout << "\n";
	}
	cout << "\n";
}

int main() {

	for (int i = 0; i < 12; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 6; j++)
			map[i][j] = str.at(j);
	}

	int ans = 0;
	bool flag = false;
	init_visited();

	while (1) {
		// 제거할 뿌요 있나 검사하기
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.'&&visited[i][j]==false) {
					char std_ch = map[i][j];
					visited[i][j] = true;

					queue<pair<int, int>> q;
					vector<pair<int, int>> remove_vec;

					q.push(make_pair(i, j));


					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						remove_vec.push_back(make_pair(x, y));
						q.pop();

						//우측 검사
						if (y + 1 < 6)
							if (map[x][y + 1] == std_ch&&visited[x][y + 1] == false) {
								q.push(make_pair(x, y + 1));
								visited[x][y + 1] = true;
							}

						//아래측 검사
						if (x + 1 < 12)
							if (map[x + 1][y] == std_ch&&visited[x + 1][y] == false) {
								q.push(make_pair(x + 1, y));
								visited[x + 1][y] = true;
							}

						//좌측 검사
						if (y - 1 >= 0)
							if (map[x][y - 1] == std_ch&&visited[x][y - 1] == false) {
								q.push(make_pair(x, y - 1));
								visited[x][y - 1] = true;
							}

						//위측 검사
						//아래측 검사
						if (x - 1 >= 0)
							if (map[x - 1][y] == std_ch&&visited[x - 1][y] == false) {
								q.push(make_pair(x - 1, y));
								visited[x - 1][y] = true;
							}
					}

					if (remove_vec.size() >= 4) {
						flag = true; // true이면 재검사
						for (int i = 0; i < remove_vec.size(); i++)
							map[remove_vec[i].first][remove_vec[i].second] = '.';
					}
					
				}
			}
		}

		// 제거한 뒤 .위에 있는 문자들 아래로 땡김
		for (int i = 0; i < 6; i++) {
			int row_idx = 11;
			int dot_idx = -1;
			while (row_idx >= 0) {
				//아래서 위로 올라가며 .부터 발견
				while (map[row_idx][i] != '.') {
					row_idx--;
					if (row_idx < 0)
						break;
				}
					

				dot_idx = row_idx;

				while (map[row_idx][i] == '.') {
					row_idx--;
					if (row_idx < 0)
						break;
				}
					
				if (row_idx >= 0) {
					char ch = map[row_idx][i];
					map[row_idx][i] = map[dot_idx][i];
					map[dot_idx][i] = ch;
					row_idx = dot_idx-1;
				}
			}
		}

		if (flag == true) {
			init_visited();
			ans++;
			flag = false;
		}
		else
			break;
	}

	cout << ans << endl;
	return 0;
}