#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, const char * argv[]) {
    int idx = 5;
    srand(time(NULL));
    while(idx--){
        int r = rand()%100 + 1;
        std::cout<<"random : "<<r<<std::endl;
    }
    return 0;
}
