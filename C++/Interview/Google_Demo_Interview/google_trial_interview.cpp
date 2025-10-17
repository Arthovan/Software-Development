#include<iostream>
#include<unordered_map>
#include<algorithm>

inline constexpr int N = 1000000000;

class Data {
    private:
	    char* str;
    
    public:
	    Data(){
            str = new char[N];
            std::fill_n(str, N, '\0');
        }
        ~Data() {
            delete[] str;
        }
    
        void edit(int i, char c) {
            if(i > 0 && i < N)
	            str[i] = c;
        }

        static bool isEqual(const Data& val1,const Data& val2) {
            for(int i = 0; i < N; ++i) {
		        if(val1.str[i] !=  val2.str[i])
			        return false;
            }
            return true;
        }
};

class Data2 {
private:
	std::unordered_map<int, char> map;

public:
	void edit(int i, char c) {
		if ( c == '0') {
			map.erase(i);
		} else {
		    map[i] = c;
        }
    }

	bool equals(const Data2& other) {
		if (map.size() != other.map.size()) {
			return false;
		}
		
        for(const auto& [key, val] : map) {
            auto it = other.map.find(key);
            if(it == other.map.end() || it->second != val)
                return false;
        }
        return true;
	}
};
		
int main() {
	Data obj1,obj2;
	obj1.edit(0, 'H');
    obj2.edit(0, 'H');
    std::cout<<"Data Equal: "<<Data::isEqual(obj1,obj2)<<std::endl;

    Data2 ob1,ob2;
	ob1.edit(1, 'A');
    ob2.edit(1, 'A');
    std::cout<<"Data2 Equal: "<<ob1.equals(ob2)<<std::endl;
    return 0;
}
