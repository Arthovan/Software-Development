/*
Create an interface named INumberProcessor and a class that implements it.
The interface should declare a single method:

std::vector<int> process(const std::vector<int>& input);


This method receives a vector of integers and should return another vector of integers where:

all odd numbers appear first,

followed by all even numbers,

while preserving the original order within each group.

Example

Input:
{4, 1, 3, 2, 8, 5}

Expected output:
{1, 3, 5, 4, 2, 8}

You can name your implementation class however you like (for example, OddEvenPartitioner).
*/


#include <iostream>
#include <set>
#include <vector>
class INumberProcessor {
public:
    virtual std::vector<int> process(const std::vector<int>& input) = 0;
    virtual ~INumberProcessor() = default;
};

class OddEvenPartitioner : public INumberProcessor {
public:
    std::vector<int> process(const std::vector<int>& input) override {
        std::vector<int> odds;
        std::vector<int> evens;
    
        for (int x : input) {
            if (x % 2 != 0)
                odds.push_back(x);
            else
                evens.push_back(x);
        }

        // Combine: evens after odds vector
        for(int x : evens) {
            odds.push_back(x);
        }
        return odds;
    }
};

int main()
{
    std::vector<int> input = {10, 5, 7, 9, 24, 11, 20, 86, 1};
    INumberProcessor* processor = new OddEvenPartitioner();
    std::vector<int> output = processor->process(input);
    std::cout<<"After sorting : ";
    for(int temp : output) {
        std::cout<<temp<<", ";
    }
    std::cout<<std::endl;

    delete processor;
    return 0;
}