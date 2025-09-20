/*  346. Moving Average from Data Stream
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:
MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.

Example 1:  Input   ["MovingAverage", "next", "next", "next", "next"]
                    [[3], [1], [10], [3], [5]]
            Output  [null, 1.0, 5.5, 4.66667, 6.0]
Explanation:
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
*/

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class MovingAverage {
    private:
        int windowSize = 0;
        vector<int> queue;
    public:
        MovingAverage(int size) {
            this->windowSize = size;
        }
        double next(int val) {
            queue.push_back(val);
            int windowSum = 0;
            // Reason for this below method of for loop is we need to always provide a windowSum upto the windowSize, just like sliding window.
            // if windowSize = 3 and queue size is 1 which results in in i = max( 0, 1-3). so i will be 0 until queue size more than 3 which inturn act as sliding window here
            for(int i = max(0, (int)queue.size()-windowSize); i < queue.size(); i++){
                windowSum += queue[i];
            }
            
            // we need to return the average of the number of elements in queue until windowSize so we use min of queue size and windowSize
            return (windowSum * 1.0) / min((int)queue.size(), windowSize);
        }
};

int main(int argc, char*argv[]) {
    MovingAverage obj(3);
    cout<<"val: "<<obj.next(4)<<endl;
    return 0;
}