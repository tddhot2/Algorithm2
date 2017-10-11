#include <iostream>
using namespace std;

// 전역 변수
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

// 재귀함수 구조로 모든 경우의 수(브루트 포스)로 풀어보기
// 경우의 수는 세가지가 있으나, 3일권과 5일권은 쿠폰의 개수를 매개인자로 전달하여 문제를 품
int Solution(int now, int coupon) {
	// dp에 값이 있을 경우 바로 반환
	if (dp[now] != -1)
		return dp[now];

	// 만약 못가는 날이면, 다음에 갈 수 있는 날까지 스킵한다.
	while (calendar[now] == 0)
		now++;

	// 최종날 이후에는 0원이므로 0을 반환
	if (now > n)
		return 0;
	
	int minimul;
	int temp;

	// 하루권/3일권/5일권 세 가지의 경우의 수로 나누어 더해가는 대신에, 쿠폰의 개수에 따라 이용한다.
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
	cout << "오늘은 " << now << "일" << endl;
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