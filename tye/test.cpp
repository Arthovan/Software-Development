struct A { A() { cout << "A"; } ~A() { cout << "~A"; } };
struct B { B() { cout << "B"; } ~B() { cout << "~B"; } };
struct C : A { B b; C() { cout << "C"; } ~C() { cout << "~C"; } };
int main() { C c; }

class Base { public: ~Base() { cout << "~Base"; } };
class Derived : public Base { public: ~Derived() { cout << "~Derived"; } };
int main() { Base* p = new Derived(); delete p; }

int i = 5;
cout << i++ << " " << ++i << " " << i;