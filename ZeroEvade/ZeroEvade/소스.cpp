/*
���� �ؼ�
1) �޸������̼��� �ϱ����ؼ��� �� ���� ���� ���� ��ǥ�� �ʿ��ϴ�.
2) �� ���� ��ǥ�� ���� ��쿡�� �� ��ǥ ���Ϸ��� ���и� ��ȯ�Ͽ� �� �̻� �õ����� ���� �� �ִ�.

�ذ� ����
A) �� ������ 2���� DP�� ����� : �� ���, �� ���� �ٸ���ǥ����, �Ѱ��� ���� ���� ��ǥ�� ������� ����/���п��θ� �� �� ����.
B) ���� ũ�Ⱑ �ִ� row�� 0~9/col�� 0~9�̴�. �׷��ٸ�, 2���� �迭���� 2�ڸ��� �ε������� ����Ѵٸ�~
- �������� row : ##�� �� �ڸ�, col : ##�� �� �ڸ�
- �Ķ����� row : ##�� �� �ڸ�, col : ##�� �� �ڸ�
�̷��� �����ϸ�, ��� ��ǥ �ֿ� ���� DP�� ���� �� �ִ�?

: ������ ���� ���� �����, ��ͱ����� �Ѿ ������, ������ ��ġ�� ����ؾ��ϰ�, �� ���⿡ ���� ��ġ�� ���� ����ؼ�
���� map���� �ٲ���ϹǷ�(�迭�� ��ͷ� �����Ҽ��� �����Ƿ�) ������ ����������.

C) count BFS : �ش� ������ ��ǥ���� �������� �Ѱ��� ��, �������� �Ѱ��� ��, �̷������� �ش� ��ǥ�� Queue�� �����Ѵ�.

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


//ť �ݺ����� �ʿ��� �����͵�
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
	cout << "�������� ��ǥ" << endl;
	cout << redx << "," << redy << endl;
	cout << "�Ķ����� ��ǥ" << endl;
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
	// ��� ���� �Է¹޴´�.
	cin >> row >> col;

	Balls init;

	// Map �迭�� �ش� ���ڿ��� �Է¹޾� �ϳ��� �ִ´�.
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

	// ������ �õ��� �����ϸ� 1�� ����� ����
	for (int i = 0; i < 10; i++) {
		int qSize = q.size();

		for (int j = 0; j < qSize; j++) {
			//������ġ�� ���� ���� ������ ����
			Balls temp;
			nowRedX = q.front().redX;
			nowRedY = q.front().redY;
			nowBlueX = q.front().blueX;
			nowBlueY = q.front().blueY;
			q.pop();

			// �������� ������ �� �̵�
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
			// ���� ��




			// �������� ������ �� �̵�
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
			// ��

			// �������� ������ �� �̵�
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
			// ��

			// �Ʒ������� ������ �� �̵�
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
			// ��
		}
	}

	cout << -1 << endl;
	return 0;
}