/*Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list 
represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each 
unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint 
that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11*/

#include <climits>
#include <iostream>
using namespace std;

// return the maximum element from the array
int getMax(int arr[], int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// return the sum of the elements in the array
int getSum(int arr[], int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
		total += arr[i];
	return total;
}

// find minimum required painters for given maxlen
// which is the maximum length a painter can paint
int numberOfPainters(int arr[], int n, int maxLen)
{
	int total = 0, numPainters = 1;

	for (int i = 0; i < n; i++) {
		total += arr[i];

		if (total > maxLen) {

			// for next count
			total = arr[i];
			numPainters++;
		}
	}

	return numPainters;
}

int partition(int arr[], int n, int k)
{
	int lo = getMax(arr, n);
	int hi = getSum(arr, n);

	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		int requiredPainters
			= numberOfPainters(arr, n, mid);

		// find better optimum in lower half
		// here mid is included because we
		// may not get anything better
		if (requiredPainters <= k)
			hi = mid;

		// find better optimum in upper half
		// here mid is excluded because it gives
		// required Painters > k, which is invalid
		else
			lo = mid + 1;
	}

	// required
	return lo;
}

// driver function
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << partition(arr, n, k) << endl;
	return 0;
}
