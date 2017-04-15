#include<iostream>
int BoxVolume(int length, int width, int height);
int BoxVolume(int width, int height);
int BoxVolume(int height);
int BoxVolume();

int main()
{
	std::cout<<"[3, 3, 3] : "<<BoxVolume(3, 3, 3)<<std::endl;
	std::cout<<"[5, 5, D] : "<<BoxVolume(5, 5)<<std::endl;
	std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
	std::cout<<"[D, D, D] : "<<BoxVolume()<<std::endl;

	return 0;
}

int BoxVolume(int length, int width, int height) 
{
	return length*width*height;
}

int BoxVolume(int width, int height)
{
	return 1*width*height;
}

int BoxVolume(int height)
{
	return 1*1*height;
}

int BoxVolume()
{
	return 1*1*1;
}
