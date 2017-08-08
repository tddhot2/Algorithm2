/*
문제 해석
1) 메모이제이션을 하기위해서는 두 개의 공에 대한 좌표가 필요하다.
2) 두 개의 좌표가 같을 경우에만 그 좌표 이하로의 실패를 반환하여 더 이상 시도하지 않을 수 있다.

해결 전략
A) 각 공마다 2차원 DP를 만든다 : 이 경우, 한 공은 다른좌표지만, 한공은 같은 실패 좌표에 있을경우 성공/실패여부를 알 수 없다.
B) 판의 크기가 최대 row는 0~9/col은 0~9이다. 그렇다면, 2차원 배열에서 2자리수 인덱스까지 사용한다면~
- 빨간공의 row : ##의 앞 자리, col : ##의 뒷 자리
- 파란공의 row : ##의 앞 자리, col : ##의 뒷 자리
이렇게 구성하면, 모든 좌표 쌍에 대해 DP를 구할 수 있다?

: 하지만 위와 같은 방식은, 재귀구조로 넘어갈 때마다, 현재의 위치를 기억해야하고, 네 방향에 따른 위치를 전부 기억해서
실제 map값을 바꿔야하므로(배열을 배귀로 전달할수는 없으므로) 굉장히 복잡해진다.

C) count BFS : 해당 공들의 좌표에서 좌측으로 넘겼을 때, 우측으로 넘겼을 때, 이런식으로 해당 좌표를 Queue에 저장한다.

*/



#include <iostream>
#include <queue>
using namespace std;

int row, col;
int goalX, goalY;
char map[10][10];


typedef struct _balls {
	short redX;
	short redY;
	short blueX;
	short blueY;
}Balls;


//큐 반복문에 필요한 데이터들
int nowRedX;
int nowRedY;
int nowBlueX;
int nowBlueY;

int redFlag;
int blueFlag;

int moveRedX;
int	moveRedY;
int moveBlueX;
int moveBlueY;

void print_map() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}

void printPosition(int redx, int redy, int bluex, int bluey) {
	cout << "빨간공의 좌표" << endl;
	cout << redx << "," << redy << endl;
	cout << "파란공의 좌표" << endl;
	cout << bluex << "," << bluey << endl;
}

bool checkGoal(int x, int y) {
	if (x == goalX && y == goalY)
		return true;
	else
		return false;
}

void initializing() {
	redFlag = 0;
	blueFlag = 0;
	moveRedX = nowRedX;
	moveRedY = nowRedY;
	moveBlueX = nowBlueX;
	moveBlueY = nowBlueY;
}


int main() {
	// 행과 열을 입력받는다.
	cin >> row >> col;

	Balls init;

	// Map 배열에 해당 문자열을 입력받아 하나씩 넣는다.
	for (int i = 0; i < row; i++) {
		char str[11];
		scanf("%s", str);

		for (int j = 0; j < col; j++) {
			map[i][j] = str[j];
			if (str[j] == 'R') {
				init.redX = i;
				init.redY = j;
				map[i][j] = '.';
			}
			else if (str[j] == 'B') {
				init.blueX = i;
				init.blueY = j;
				map[i][j] = '.';
			}
			else if (str[j] == 'O') {
				goalX = i;
				goalY = j;
				map[i][j] = '.';
			}
		}
	}

	queue<Balls> q;
	q.push(init);

	// 열번의 시도에 성공하면 1을 출력후 종료
	for (int i = 0; i < 10; i++) {
		int qSize = q.size();

		for (int j = 0; j < qSize; j++) {
			//현재위치의 공에 대해 변수에 저장
			Balls temp;
			nowRedX = q.front().redX;
			nowRedY = q.front().redY;
			nowBlueX = q.front().blueX;
			nowBlueY = q.front().blueY;
			q.pop();

			// 좌측으로 돌렸을 때 이동
			initializing();
			while (map[moveRedX][moveRedY - 1] == '.') {
				if (moveRedY - 1 == moveBlueY && moveRedX == moveBlueX)
					break;
				moveRedY--;
				if (checkGoal(moveRedX, moveRedY)) {
					moveRedX = -1;
					moveRedY = -1;
					redFlag = 1;
					break;
				}
			}

			while (map[moveBlueX][moveBlueY - 1] == '.') {
				if (moveBlueY - 1 == moveRedY && moveRedX == moveBlueX)
					break;
				moveBlueY--;
				if (checkGoal(moveBlueX, moveBlueY)) {
					moveBlueX = -1;
					moveBlueY = -1;
					blueFlag = 1;
					break;
				}
			}

			while (map[moveRedX][moveRedY - 1] == '.') {
				if (moveRedY - 1 == moveBlueY && moveRedX == moveBlueX)
					break;
				moveRedY--;
				if (checkGoal(moveRedX, moveRedY)) {
					redFlag = 1;
					break;
				}
			}


			if (redFlag == 1 && blueFlag == 0) {
				cout << i+1 << endl;
				return 0;
			}
			else if (redFlag == 0 && blueFlag == 0) {
				temp.redX = moveRedX;
				temp.redY = moveRedY;
				temp.blueX = moveBlueX;
				temp.blueY = moveBlueY;
				q.push(temp);
			}
			// 좌측 끝




			// 우측으로 돌렸을 때 이동
			initializing();
			while (map[moveRedX][moveRedY + 1] == '.') {
				if (moveBlueY == moveRedY + 1 && moveBlueX == moveRedX)
					break;
				moveRedY++;
				if (checkGoal(moveRedX, moveRedY)) {
					moveRedX = -1;
					moveRedY = -1;
					redFlag = 1;
					break;
				}
			}
			while (map[moveBlueX][moveBlueY + 1] == '.') {
				if (moveBlueY + 1 == moveRedY && moveBlueX == moveRedX)
					break;
				moveBlueY++;
				if (checkGoal(moveBlueX, moveBlueY)) {
					moveBlueX = -1;
					moveBlueY = -1;
					blueFlag = 1;
					break;
				}
			}
			while (map[moveRedX][moveRedY + 1] == '.') {
				if (moveBlueY == moveRedY + 1 && moveBlueX == moveRedX)
					break;
				moveRedY++;
				if (checkGoal(moveRedX, moveRedY)) {
					redFlag = 1;
					break;
				}
			}

			if (redFlag == 1 && blueFlag == 0) {
				cout << i+1 << endl;
				return 0;
			}
			else if (redFlag == 0 && blueFlag == 0) {
				temp.redX = moveRedX;
				temp.redY = moveRedY;
				temp.blueX = moveBlueX;
				temp.blueY = moveBlueY;
				q.push(temp);
			}
			// 끝

			// 위측으로 돌렸을 때 이동
			initializing();
			while (map[moveRedX - 1][moveRedY] == '.') {
				if (moveBlueX == moveRedX - 1 && moveBlueY == moveRedY)
					break;
				moveRedX--;
				if (checkGoal(moveRedX, moveRedY)) {
					moveRedX = -1;
					moveRedY = -1;
					redFlag = 1;
					break;
				}
			}
			while (map[moveBlueX - 1][moveBlueY] == '.') {
				if (moveBlueX - 1 == moveRedX && moveBlueY == moveRedY)
					break;
				moveBlueX--;
				if (checkGoal(moveBlueX, moveBlueY)) {
					moveBlueX = -1;
					moveBlueY = -1;
					blueFlag = 1;
					break;
				}
			}
			while (map[moveRedX - 1][moveRedY] == '.') {
				if (moveBlueX == moveRedX - 1 && moveBlueY == moveRedY)
					break;
				moveRedX--;
				if (checkGoal(moveRedX, moveRedY)) {
					redFlag = 1;
					break;
				}
			}


			if (redFlag == 1 && blueFlag == 0) {
				cout << i+1 << endl;
				return 0;
			}
			else if (redFlag == 0 && blueFlag == 0) {
				temp.redX = moveRedX;
				temp.redY = moveRedY;
				temp.blueX = moveBlueX;
				temp.blueY = moveBlueY;
				q.push(temp);
			}
			// 끝

			// 아래측으로 돌렸을 때 이동
			initializing();
			while (map[moveRedX + 1][moveRedY] == '.') {
				if (moveBlueX == moveRedX + 1 && moveBlueY == moveRedY)
					break;
				moveRedX++;
				if (checkGoal(moveRedX, moveRedY)) {
					moveRedX = -1;
					moveRedY = -1;
					redFlag = 1;
					break;
				}
			}
			while (map[moveBlueX + 1][moveBlueY] == '.') {
				if (moveBlueX + 1 == moveRedX && moveBlueY == moveRedY)
					break;
				moveBlueX++;
				if (checkGoal(moveBlueX, moveBlueY)) {
					moveBlueX = -1;
					moveBlueY = -1;
					blueFlag = 1;
					break;
				}
			}
			while (map[moveRedX + 1][moveRedY] == '.') {
				if (moveBlueX == moveRedX + 1 && moveBlueY == moveRedY)
					break;
				moveRedX++;
				if (checkGoal(moveRedX, moveRedY)) {
					redFlag = 1;
					break;
				}
			}

			if (redFlag == 1 && blueFlag == 0) {
				cout << i+1 << endl;
				return 0;
			}
			else if (redFlag == 0 && blueFlag == 0) {
				temp.redX = moveRedX;
				temp.redY = moveRedY;
				temp.blueX = moveBlueX;
				temp.blueY = moveBlueY;
				q.push(temp);
			}
			// 끝
		}
	}

	cout << -1 << endl;
	return 0;
}