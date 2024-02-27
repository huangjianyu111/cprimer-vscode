#include <queue>
#include <vector>
#include <stdio.h>

int main() {
    std::priority_queue<int> maxHeap;// Max priority queue
    maxHeap.push(13);
    maxHeap.push(90);
    printf("maxHeap top : %d \n", maxHeap.top());
    


    // Min priority queue
    // std::greater<int> makes the max priority queue act as a min priority queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(11);
    minHeap.push(2);
    printf("minHeap top: %d \n", minHeap.top());
    
}