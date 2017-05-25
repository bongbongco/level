//
//  main.cpp
//  teset
//
//  Created by Seungyong Lee on 2017. 5. 26..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class CStack {
private:
    int m_stack[10000] ;
    int m_stackPointer;
public:
    int m_cnt;
    std::vector<std::string> m_commandList;
    std::string m_command;
    
    
    CStack(){
        std::fill_n(m_stack, 10000, '\0');
        m_stackPointer = 0;
    }

    void Push(int _data);
    int Pop();
    int Size();
    bool Empty();
    int Top();
};

void CStack::Push(int _data) {
    m_stack[m_stackPointer] = _data;
    m_stackPointer++;
}
int CStack::Pop() {
    if (m_stack[0] != '\0') {
        int removeValue = m_stack[0];
        int tmp;
        for(int i=0; i<m_stackPointer; i++){
        //Editting point    
        }
        
            }
        m_stackPointer--;
        return removeValue;
    }
    return -1;
}
int CStack::Size() {
    for(int i=0; i<10000; i++){

        if(m_stack[i]=='\0'){
            return i+1;
        }
    }
    return 0;
}
bool CStack::Empty() {
    return m_stack[0] != '\0'? false:true;
}
int CStack::Top() {
    return m_stack[0];
}

int main(int argc, const char * argv[]) {
    CStack stack;
    std::cin>>stack.m_cnt;
    std::cin.ignore();
    for(int i=0; i<stack.m_cnt; i++){
        getline(std::cin, stack.m_command);
        stack.m_commandList.push_back(stack.m_command);
    }
    for(int i=0; i<stack.m_commandList.size(); i++) {
        if(stack.m_commandList.at(i).find("push") != std::string::npos) {
            int data = 0;
            std::string tmp = stack.m_commandList.at(i);
            tmp.replace(0, 5, "");
            for (int j=0; j<tmp.size(); j++){
                data += (tmp[j] - '0') * (j>0 ? 10*j : 1);
            }
            stack.Push(data);
            std::cout<<data<<std::endl;
        }
        else if(stack.m_commandList.at(i).find("pop") != std::string::npos) {
            std::cout<<stack.Pop()<<std::endl;
        }
        else if(stack.m_commandList.at(i).find("size") != std::string::npos) {
            std::cout<<stack.Size()<<std::endl;
        }
        else if(stack.m_commandList.at(i).find("empty") != std::string::npos) {
            std::cout<<((stack.Empty())?1:0)<<std::endl;
        }
        else if(stack.m_commandList.at(i).find("top") != std::string::npos) {
            std::cout<<stack.Top()<<std::endl;
        }
    }
    
    return 0;
}

