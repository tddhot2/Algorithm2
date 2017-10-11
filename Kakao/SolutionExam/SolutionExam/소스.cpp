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

	// �־��� ũ�� ž�� �ð��� int������ ��ȯ�ؼ� ������������ ����
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

	int people = 0; // ���� �ð������� ����� �ο��� ��
	int now_time = 900; // ���� �ð�
	int last_time = 0;
	int idx = 0; // �ð�ǥ�� ���������� ź������� �����ϴ� �ε���

	vector<int> queue;

	//9�ú��� n���� ���� t �������� �����Ƿ� �����ָ� �������� ��������� Ȯ��
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
		

		cout << "���� ���� : " << now_time << endl;
		cout << "���� ����ο� : " << people << endl;

		// ����� ����� m���� ũ�ٸ�, �� �߿��� Ż �� �ִ� ���� ���� �ð��� ã�ƾ���
		if (people >= m) {
			//���⼭ ž���� ������ �ð��� ã�� �־��ָ� �ȴ�.
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
			

		cout << "ž�� �� ���� ����ο� : " << people << endl;
		cout << "ž�� ���� ������ �ð� : " << last_time << endl;
		
		// t�ð��� ������ ��, �� �ð��� �Ѿ ��� 1�ð� �߰��� ������ ���� ����
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