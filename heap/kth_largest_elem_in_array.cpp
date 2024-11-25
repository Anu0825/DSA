/*
int findKthLargest(vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert the first k elements into the heap
    for (int i = 0; i < k; i++) {
        pq.push(nums[i]);
    }

    // Process the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > pq.top()) {
            pq.pop();         // Remove the smallest element in the heap
            pq.push(nums[i]); // Add the current element
        }
    }

    // The top element is the k-th largest
    return pq.top();
}
*/