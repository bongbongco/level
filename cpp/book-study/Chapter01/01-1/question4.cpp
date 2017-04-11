#include<iostream>

using namespace std;

int main() {
	int money = 0;

	cout << "판매금액을 입력해주세요(-1 to end) : ";
	cin >> money;
	while(money!= -1){
		cout << "이번 달 급여: " << 50 + (money * 0.12) << endl;
	
		cout << "판매금액을 입력해주세요(-1 to end) : ";
		cin >> money;
	}
	return 0;
}
