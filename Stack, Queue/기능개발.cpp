#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0


/*
* ��ɰ����� ���������� �̷�������Ѵ�
* ���� ��ɰ����� �̷������ ���� ��ɰ����� �̷������������
* ���� ��ɰ������� ����Ͽ� ���� ����ǰ���� ���� �����ȴ�.
* ��ü���� �ϼ��� �������� ����
* �� �ϼ��� ������ �����̴� (�پ��������)
*
* ��, 1������� 3�� 2������� 2�� 3������� 5���϶�, 1���� 2������� 3��°�� ���̵ǰ� 3������� 5��°�� ����ȴ�
* �� ť���� ���� ������ �� �ִ� ����� ���� �ʱ�ȭ �Ǿ���ϰ�
* ����ť�� Ȯ���Ҷ�, ���� �� �ϼ����� ����� �����ɼ��ִٸ� ��ü��ɼ�++�� continue;
* ���� ���ϼ����� ������ �� ���ٸ� ��ü��ɼ��� ������� 0���� �ʱ�ȭ �� ������ �����۾�ó���������� �ϼ��� ������Ų��.
*/

int team;

typedef struct data {
	int program;
	int speed;
}Data;

queue <Data> q;
void solve() {
	Data first = q.front(); q.pop();
	int day = first.program / first.speed;
	if (first.program % first.speed != 0) day++;
	cout << day << endl;
	int finish_program = 1;

	while (!q.empty()) {
		Data out = q.front(); q.pop();
		//�����ϼ��� �������α׷��� �ϼ��� �� �ִٸ�, �������γѾ
		if (day * out.speed >= out.program) {
			//��ü���� Ƚ�� ���������ֱ�, �ϼ��� ����������
			finish_program++;
			continue;
		}
		else {//�ɼ� ���ٸ� ������� �ϼ��� ���α׷� ������, �ʱ�ȭ
			//cout << "���߿Ϸ� : " << finish_program << endl;
			//�ִ��ϼ��� �������α׷��� �ϼ��� �� �ִ� ���ڸ� ������
			//�� �߰����� day�� �����ϱ⶧����, day��speed�� ���Ѱ��� ����������
			cout << "���߿Ϸ� ���� Ƚ�� : " << finish_program << endl;
			//ó������ �ٽ� �ʱ�ȭ
			finish_program = 1;
			//�����ϼ��κ��� ������� �� �ִ� �۾��� = day*out.speed
			//���� �����ִ� �۾���
			//45�� ���Ҵµ� 7���������� ->  45-35 = 10 ���� 2��!�̵ǰ���?��. ���¼��������� +1��
			int remainder = out.program - day * out.speed;
			day += remainder / out.speed;
			if (remainder % out.speed != 0) day++;
		}
	}
	cout << "���߿Ϸ� ���� Ƚ�� : " << finish_program << endl;
}
int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc-- > 0) {
		cin >> team;
		for (int i = 0; i < team; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			q.push({ 100 - temp1, temp2 });
		}
		solve();
		cout << endl;
	}
}
