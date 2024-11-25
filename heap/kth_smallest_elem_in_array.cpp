/*
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < k; i++) {
        pq.push(nums[i]);
    }

    // Process the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > pq.top()) {
            pq.pop();         
            pq.push(nums[i]); // Add the current element
        }
    }

    return pq.top();
}
*/