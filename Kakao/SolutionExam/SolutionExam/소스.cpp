#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


int main() {
	int n, t, m;
	cin >> n >> t >> m;

	int numPeople;
	cin >> numPeople;

	vector<string> timetable;
	for (int i = 0; i < numPeople; i++) {
		string str;
		cin >> str;
		timetable.push_back(str);
	}


	vector<int> table;

	// 주어진 크루 탑승 시간을 int형으로 변환해서 오름차순으로 정렬
	for (int i = 0; i < timetable.size(); i++) {
		int time=0;
		if (timetable[i][0] != '0')
			time = 1000 * (timetable[i][0] - '0');
		time += 100 * (timetable[i][1] - '0');
		time += 10 * (timetable[i][3] - '0');
		time += (timetable[i][4] - '0');

		table.push_back(time);
	}
	sort(table.begin(), table.end());

	int people = 0; // 버스 시간때까지 대기한 인원의 수
	int now_time = 900; // 현재 시간
	int last_time = 0;
	int idx = 0; // 시간표에 마지막으로 탄사람까지 저장하는 인덱스

	vector<int> queue;

	//9시부터 n대의 차가 t 간격으로 있으므로 더해주며 그전까지 대기사람수를 확인
	for (int i = 0; i < n; i++) {

		if (idx < table.size()) {
			while (table[idx] <= now_time) {
				queue.push_back(table[idx]);
				people++;
				idx++;
				if (idx == table.size())
					break;
			}
		}
		

		cout << "버스 도착 : " << now_time << endl;
		cout << "현재 대기인원 : " << people << endl;

		// 대기한 사람이 m보다 크다면, 그 중에서 탈 수 있는 가장 빠른 시간을 찾아야함
		if (people >= m) {
			//여기서 탑승이 가능한 시간을 찾아 넣어주면 된다.
			if (queue[m - 2] == queue[m - 1]) {
				if ((queue[m - 2] - 1) % 100 >= 60) {
					last_time = queue[m - 2] - 41;
				}
				else {
					last_time = queue[m - 2] - 1;
				}
			}
			else {
				last_time = queue[m - 2];
			}
			people -= m;
		}
		else {
			people = 0;
			queue.clear();
			last_time = now_time;
		}
			

		cout << "탑승 후 남은 대기인원 : " << people << endl;
		cout << "탑승 가능 마지막 시간 : " << last_time << endl;
		
		// t시간을 더했을 때, 한 시간을 넘어갈 경우 1시간 추가와 나머지 분을 더함
		if ((now_time % 100) + t >= 60) {
			now_time = now_time + 100 + t;
			now_time -= 60;
		}
		else
			now_time += t;
	}

	char h1, h2, m1, m2;
	m2 = ((last_time % 10)==0)?'0': (last_time % 10)+'0';
	last_time /= 10;
	m1 = ((last_time % 10) == 0) ? '0' : (last_time % 10) + '0';
	last_time /= 10;
	h2 = ((last_time % 10) == 0) ? '0' : (last_time % 10) + '0';
	last_time /= 10;
	h1 = ((last_time % 10) == 0) ? '0' : (last_time % 10) + '0';
	cout << h1<<h2<<m1<<m2 << endl;
	string answer="";
	answer += m2;
	answer += m1;
	answer += ':';
	answer += h2;
	answer += h1;
	cout << answer << endl;
	return 0;
}