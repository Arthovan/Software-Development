#include<iostream>
int main(){
    const double pi =3.14159;   // const will make it unchangeable
    double radius;
    std::cout<<"Enter the radius: ";
    std::cin >> radius;
    double circumference = 2 * pi * radius;

    std::cout << circumference << "cm"<<'\n';
	return 0;
}