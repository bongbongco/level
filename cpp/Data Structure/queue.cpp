#include <iostream>

class CQueue {
public:
	int m_queueSize;
	int m_queue[10000];
	CQueue(){
		m_queueSize = 0;
		int m_queue = {};
	}
	void Push(int _data);
	int Pop();
	int Size();
	int Empty();
	int Front();
	int Back();
};

	void CQueue::Push(int _data) {
		m_queue[m_queueSize] = _data;
		m_queueSize ++;
	}
	int CQueue::Pop(){
		if(m_queueSize > 0) {
				int tmp = m_queue[0];
				
				for(int i=m_queueSize -1; i > 0; i--){
					m_queue[i-1] = m_queue[i];

					if(i == m_queueSize - 1)
						m_queue[i] = '\0';
				}
				return tmp;
		}
		return -1;
	}
	int CQueue::Size(){
		return m_queueSize;
	}
	int CQueue::Empty(){
		return (m_queueSize > 0 ? 1 : 0);
	}
	int CQueue::Front(){
		return m_queue[0];
	}
	int CQueue::Back(){
		return m_queue[m_queueSize - 1];
	}

int main() {
	CQueue queue;
	int func = 0;
	int data = 0;
	char command[50];
	while(true){
		data = 0;
		getline(cin, command);
		func = command[0] + command[1];
		switch(func){
			case 229: //Push
			for(int i=6; i<50; i++){
				if(command[i] == '\0')
					break;
				data += command[i] - '0';
			}
			queue.Push(data);
			break;
			case 223: //Pop
			std::cout<<queue.Pop()<<std::endl;
			break;
			case 220: //Size
			std::cout<<queue.Size()<<std::endl;
			break;
			case 210: //Empty
			std::cout<<queue.Empty()<<std::endl;
			break;
			case 216: //Front 
			std::cout<<queue.Front()<<std::endl;
			break;
			case 195: //Back
			std::cout<<queue.Back()<<std::endl;
			break;
		}
	}
	
	return 0;
}
