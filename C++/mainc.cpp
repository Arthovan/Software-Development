class Student {
    private: 
    int roll_no;
    string name;

    public:

    Student(string name):name(name){}

    void update_No(int value){
        this->roll_no = value;
    }
};
class A{
    A() {
        cout<<"Class A created";
    }
    virtual ~A() {
        cout<<"Class A deleted";
    }
};

class B{
     B() {
        cout<<"Class B created";
    }
    ~B() {
        cout<<"Class B deleted";
    }
};

int main(){
A *tempa = new A();  
  B *tempb = tempa;
  delete a;

  return 0;
}

mutex_init();

cond_init();

cond[5];
int buffer;


void produce() {
    mutex_lock();
    for(int i = 0; i < 5; ++i) {
        while(cond[i]!= 1 && buffer != 5) {
            cond_wait(mutex, cond)
        }
    }
}

string temp = "temp";
int left = 0;
int right = 3;

while(left < right) {
  char val = temp[left];
  temp[left] = temp[right];
  temp[right] = val;
  left++;
  right--;
}