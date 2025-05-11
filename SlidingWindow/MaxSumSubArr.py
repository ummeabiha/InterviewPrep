'''
Maximum Sum Subarray of size K

Goal: Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

Initialize: Set i = 0, j = 0, max_sum = -inf, and current_sum = 0.
Expand Window: Increment j until the window size reaches k.
Compute Sum: When window size is k, calculate the sum and update max_sum if necessary.
Slide Window: Move both i and j, adjust the current_sum (subtract nums[i], add nums[j])
'''

def max_sum_subarray(Arr, K):
    i = 0               # Start pointer of the window
    j = 0               # End pointer of the window
    N = len(Arr)        # Length of the input array
    sm = 0              # Variable to store the sum of the current window
    res = float('-inf') # Variable to store the maximum sum (initially negative infinity)

    # Traverse the array with the 'j' pointer
    while j < N:
        sm += Arr[j]    # Add the current element (Arr[j]) to the sum

        # If the window size reaches 'K'
        if j - i + 1 == K:
            res = max(res, sm)  # Update the result with the maximum sum found so far
            sm -= Arr[i]         # Remove the element at the start of the window (Arr[i])
            i += 1               # Slide the window by moving the start pointer (i)

        j += 1  # Move the end pointer (j) to the right
    
    return res  # Return the maximum sum found

Arr = [2, 1, 5, 1, 3, 2]
K = 3
print(max_sum_subarray(Arr, K))  # Output: 9 (from subarray [5, 1, 3])
