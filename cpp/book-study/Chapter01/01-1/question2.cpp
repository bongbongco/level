#include <iostream>

using namespace std;

int main() {
	char name[10];
	char phone[30];

	cout << "이름을 입력해주세요 : ";
	cin >> name;

	cout << "휴대전화 번호를 입력해주세요 : ";
	cin >> phone;

	cout << "이름 : " << name << "휴대전화 번호 : " << phone << endl;
	return 0;
}
