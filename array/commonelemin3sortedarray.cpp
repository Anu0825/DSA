#include <bits/stdc++.h>
using namespace std;
// This function returns common elements in A[], B[], C[]
vector<int> commonElements(int A[], int B[], int C[],
                           int n1, int n2, int n3)
{
    // Initialize starting indexes for A[], B[] and C[]
    int i = 0, j = 0, k = 0;
    vector<int> common;
    // Iterate through three arrays while all arrays have
    // elements
    while (i < n1 && j < n2 && k < n3) {
        // If A[i] = B[j] = C[k], push A[i] to common
        // elements
        if (A[i] == B[j] && B[j] == C[k]) {
            common.push_back(A[i]);
            i++;
            j++;
            k++;
            // Skip duplicate elements in A[]
            while (i < n1 && A[i] == A[i - 1])
                i++;

            // Skip duplicate elements in B[]
            while (j < n2 && B[j] == B[j - 1])
                j++;

            // Skip duplicate elements in C[]
            while (k < n3 && C[k] == C[k - 1])
                k++;
        }

        // If A[i] < B[j], then ith element cannot be common
        else if (A[i] < B[j])
            i++;

        // If B[j] < C[k], then jth element cannot be common
        else if (B[j] < C[k])
            j++;
        // If C[k] is smallest, then kth element cannot be
        // common
        else
            k++;
    }

    return common;
}

// Driver code
int main()
{
    // Sample Input
    int A[] = { 1, 5, 10, 20, 30 };
    int B[] = { 5, 13, 15, 20 };
    int C[] = { 5, 20 };
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    vector<int> common= commonElements(A, B, C, n1, n2, n3);
    cout << "Common Elements: ";
    for (int ele : common) {
        cout << ele << " ";
    }

    return 0;
}
