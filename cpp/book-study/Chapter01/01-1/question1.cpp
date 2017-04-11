#include <iostream>

using namespace std;

int main() {
	int tmp = 0;
	int result = 0;
	
	for(int i=1; i<=5; i++){
		cout << i << "번째 정수 입력 : ";
		cin >> tmp;
		result += tmp;	
	}

	cout << "합계 : " << result << endl;

	return 0;
}
