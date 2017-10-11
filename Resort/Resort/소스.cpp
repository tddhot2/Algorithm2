#include <iostream>
using namespace std;

// ���� ����
int n;
int m;
bool calendar[101];
int dp[101];
int ans = 9999999999;

void printDP() {
	for (int i = 1; i <= n; i++)
		cout << dp[i] << "\t";
	cout << "\n";
}

// ����Լ� ������ ��� ����� ��(���Ʈ ����)�� Ǯ���
// ����� ���� �������� ������, 3�ϱǰ� 5�ϱ��� ������ ������ �Ű����ڷ� �����Ͽ� ������ ǰ
int Solution(int now, int coupon) {
	// dp�� ���� ���� ��� �ٷ� ��ȯ
	if (dp[now] != -1)
		return dp[now];

	// ���� ������ ���̸�, ������ �� �� �ִ� ������ ��ŵ�Ѵ�.
	while (calendar[now] == 0)
		now++;

	// ������ ���Ŀ��� 0���̹Ƿ� 0�� ��ȯ
	if (now > n)
		return 0;
	
	int minimul;
	int temp;

	// �Ϸ��/3�ϱ�/5�ϱ� �� ������ ����� ���� ������ ���ذ��� ��ſ�, ������ ������ ���� �̿��Ѵ�.
	if (coupon >= 3) {
		minimul = Solution(now + 1,  0);

		temp = Solution(now + 1,  coupon)+10000;
		if (minimul > temp)
			minimul = temp;

		temp = Solution(now + 3,  coupon + 1)+25000;
		if (minimul > temp)
			minimul = temp;

		temp = Solution(now + 5,  coupon + 2)+37000;
		if (minimul > temp)
			minimul = temp;
	}
	else {
		minimul = Solution(now + 1,  coupon) + 10000;
		
		temp = Solution(now + 3,  coupon + 1)+25000;
		if (minimul > temp)
			minimul = temp;

		temp = Solution(now + 5,  coupon + 2)+37000;
		if (minimul > temp)
			minimul = temp;
	}
	cout << "������ " << now << "��" << endl;
	printDP();
	return dp[now] = minimul;
}

int main() {
	fill_n(calendar, 101, 1);
	fill_n(dp, 101, -1);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		calendar[a] = 0;
	}

	cout << Solution(1, 0) << endl;

	return 0;
}