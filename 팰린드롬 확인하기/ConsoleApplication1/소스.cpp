#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;
int visited[26];
char str[53];

void printArr() {
	for (int i = 0; i < 26; i++)
		cout << visited[i] << " ";
	cout << "\n";
}

int main() {
	
	fill_n(visited,26,0);
	
	cin >> str;

	int idx = 0;
	int ans = 0;

	while (str[idx] != 0) {		
		if (visited[(int)str[idx]-65] == 0) {
			stk.push(str[idx]);
			visited[(int)str[idx]-65] = 1;
		}
		else {
			if (stk.top() == str[idx])
				stk.pop();
			else {
				ans = stk.size();
			}
		}
		//printArr();
		idx++;
	}

	cout << ans << endl;
	return 0;
}