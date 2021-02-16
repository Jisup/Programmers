#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

#define endl "\n"
#define tap "\t"
#define MAX 0


/*
* 기능개발은 순차적으로 이루어져야한다
* 뒤의 기능개발이 이루어져도 앞의 기능개발이 이루어지지않으면
* 앞의 기능개발이후 출시일에 뒤의 개발품목이 같이 배포된다.
* 전체적인 일수의 증가량은 같다
* 즉 일수의 증가는 공유이다 (줄어들지않음)
*
* 단, 1번기능이 3일 2번기능이 2일 3번기능이 5일일때, 1번과 2번기능이 3일째에 같이되고 3번기능이 5일째때 진행된다
* 즉 큐에서 뺄때 배포될 수 있는 기능의 수는 초기화 되어야하고
* 다음큐를 확인할때, 만약 그 일수동안 기능이 배포될수있다면 전체기능수++후 continue;
* 만약 그일수동안 배포될 수 없다면 전체기능수를 출력한후 0으로 초기화 한 다음에 남은작업처리량에따른 일수를 증가시킨다.
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
		//현재일수에 현재프로그램이 완성될 수 있다면, 다음으로넘어감
		if (day * out.speed >= out.program) {
			//전체적인 횟수 증가시켜주기, 일수는 변하지않음
			finish_program++;
			continue;
		}
		else {//될수 없다면 현재까지 완성된 프로그램 배포후, 초기화
			//cout << "개발완료 : " << finish_program << endl;
			//최대일수에 현재프로그램이 완성될 수 있는 일자를 더해줌
			//단 중간에는 day가 존재하기때문에, day에speed를 곱한값이 더해져야함
			cout << "개발완료 배포 횟수 : " << finish_program << endl;
			//처음으로 다시 초기화
			finish_program = 1;
			//현재일수로부터 만들어질 수 있는 작업량 = day*out.speed
			//현재 남아있는 작업량
			//45가 남았는데 7일이지났어 ->  45-35 = 10 값은 2일!이되겟죠?단. 남는수가있으면 +1일
			int remainder = out.program - day * out.speed;
			day += remainder / out.speed;
			if (remainder % out.speed != 0) day++;
		}
	}
	cout << "개발완료 배포 횟수 : " << finish_program << endl;
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
