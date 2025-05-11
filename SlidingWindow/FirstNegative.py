'''
First Negative Number in every Window of Size K

Goal: Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Initialize: Create an empty queue q, and set pointers i = 0 (start) and j = 0 (end).
Expand Window: As j moves through the array
    If a[j] is negative, add (a[j], j) (value and index) to q.
    If the window size (j - i + 1) is less than k, just increment j.
Window Size k: When the window size reaches k:
    Remove elements from q whose indices are outside the window [i, j].
    If q is empty, print 0 (no negative number), otherwise print the first negative number (q[0][0]).
    Slide Window: Increment both i and j to move the window forward.
'''

# 1) Brute Force Method 
def bruteFirstNegativeInt(arr , k):
    final_list = []
    l=0
    r = k-l-1
    count = 0
    while(count < len(arr)-k+1):
        temp_arr = arr[l:r+1]
        for i in temp_arr:
            if i < 0:
                final_list.append(i)
                break
            if temp_arr[-1] == i:
                final_list.append(0)
        count+=1
        l+=1
        r+=1
    return final_list

# Sliding Window Method
def slideFirstNegativeInt(a,k):
    q=[] # empty queue
    i=j=0
    while j<len(a):
        # common step (just like summing in the prev que)
        if a[j] < 0: q.append((a[j], j))  # adding the value and index of the negative number into the queue
        if j-i+1<k: j+=1
        # calculation when the window size is reached
        else:
           # this while loop checks for the first negative number in the queue within range [i,j]
            while q and not i <= q[0][1] <= j: q.pop(0)  
            if not q: print(0,end=" ")
            else:print(q[0][0],end=" ")
            i,j=i+1,j+1