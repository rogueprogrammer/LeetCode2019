
// https://leetcode.com/problems/minimum-cost-to-connect-sticks/submissions/
// 1 8 3 5
// 4 8 5 -> pay cost: 1+3 = 4
// 9 8 -> pay cost: 4 + 5 = 9
// 17  -> pay cost: 17
// total pay cost: 17+13 = 30
// strategy: maintain a sorted list (use heap) of all the sticks, each time you add stick to the list, you need to pop off the lowest two
// elements and add them to your cost.
int connectSticks(vector<int>& sticks){
    priority_queue<int, vector<int>, std::greater<int>> minheap(sticks.begin(), sticks.end());
    int cost = 0;
    while (minheap.size() > 1){
        int x = minheap.top();
        minheap.pop();
        x += minheap.top();
        minheap.pop();
        minheap.push(x);
        cost += x;
    }
    return cost;
}
