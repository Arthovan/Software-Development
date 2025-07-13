/* A virtual function (also known as virtual methods) is a member function that is declared within a base class and is re-defined (overridden) by a derived class. 
When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the method.

    *   Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call.
    *   They are mainly used to achieve Runtime polymorphism.
    *   Functions are declared with a virtual keyword in a base class.
    *   The resolving of a function call is done at runtime.
*/
// Example : 1
#include<iostream>

using namespace std;

#define EXAMPLE2

#ifdef EXAMPLE1
class Base{
    public:
    virtual void display1(){
        cout<<"Base Class 1"<<endl;
    }
    void display2(){
        cout<<"Base Class 2"<<endl;
    }
};

class Derived : public Base{
    public:
    void display1(){
        cout<<"Derived Class 1"<<endl;
    }
    void display2(){
        cout<<"Derived Class 2"<<endl;
    }
};

int main()
{
    Derived des;
    Base *ptr;
    ptr = &des;
    ptr->display1();    // display1 is declared with the virtual keyword so it will be bound at runtime. As it is a virtual function in Base Class, so it displayed which class the pointer currently pointing too
    ptr->display2();    // display2 is non-virtual so it will be bound during compile time. As the function is not virtual so it displayed the function of the pointer type

    return 0;
}
#endif

#ifdef EXAMPLE2
class Shape{
    public:
    double base, height;
    Shape(double a, double b){
        base = a;
        height = b;
    }
    virtual double area(){
        cout<<"Base Class Area function"<<endl;
        return 0;
    }
};

class Rectangle : public Shape{
    public:
    Rectangle(double x, double y) : Shape(x,y){};
    double area(){
        cout<<"Rectangle Class Area: ";
        return base*height;
    }
};

class Triangle : public Shape{
    public:
    Triangle(double p, double q) : Shape(p,q){};
    double area(){
        cout<<"Triangle Class Area: ";
        return base*height/2;
    }
};

int main(){
    

    // 1st Remove virtual in Shape area function and run this, next Add virtual in Shape area function and run this
    Shape *s;
    Triangle t(10.0,12.0);
    s = &t;                 //  Dynamic binding or Late binding
    cout<<s->area()<<endl;
    
    Rectangle r(14.0,15.0);
    s = &r;                 //  dynamic binding or Late binding
    cout<<s->area()<<endl;

    cout<<t.area()<<endl;   //  Static binding or Early binding   
    cout<<r.area()<<endl;   //  Static binding or Early binding      

    return 0;
}


#endif
