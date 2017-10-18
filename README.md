To find "k" largest elements in an array
=======
This is the most optimized solution. Time complexity: O(k + (n-k)Logk) 
n : total number of elements in an array. 
1) Build a Min Heap of the first k elements of the given array. O(k)

2) For each element, after the kth element, compare it with root of Min Heap.
 a) If the element is greater than the root then make it root and call heapify for Min Heap (which O(logk) )
 b) Else ignore it.
// The step 2 is O((n-k)*logk)

3) Now finally, Min Heap will have k largest elements and root of the Min Heap is the kth largest element.



