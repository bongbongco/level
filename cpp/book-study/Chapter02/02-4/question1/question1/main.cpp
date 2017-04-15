//
//  main.cpp
//  question1
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    char str[100] = "Hello, World!";
    char strtemp[100] = "";
    std::cout<<"strlen : "<<std::strlen(str)<<std::endl;
    std::cout<<"strcat : "<<std::strcat(str, " I'm LSY")<<std::endl;
    
    std::cout<<"strcpy : "<<std::strcpy(strtemp, str)<<std::endl;
    std::cout<<"strcmp : "<<std::strcmp(strtemp, str)<<std::endl;
    return 0;
}
