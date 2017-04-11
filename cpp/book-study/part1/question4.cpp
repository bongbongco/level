#include<iostream>

using namespace std;

int main() {
	int money = 0;

	while(money!= -1){
	cout << "판매금액을 입력해주세요 : ";
	cin >> money;

	cout << "이번 달 급여: " << 50 + money * 0.12;
	}
	return 0;
}
