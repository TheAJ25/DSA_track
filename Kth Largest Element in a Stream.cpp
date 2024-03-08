// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8





class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap; 
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int x: nums){
            add(x);
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>kth){
            minheap.pop();
        }
        return minheap.top();
    }
};
