'''
Goal: Find how many anagrams of a pattern exist in a given string. (Count Occurences of Anagrams)

Step-by-step Logic:
Build Frequency Map:
Create a hashmap (frequency map) of the pattern's characters.
Each key = a character, each value = how many times it appears in the pattern.
Also keep a count of distinct characters — this helps track when a window forms an anagram.

Slide a Window over the String:
Use a sliding window of the same size as the pattern.
As you include new characters (j pointer) in the window:
    If character is in the map, decrease its count.
    If any character's count hits zero, it means that character's full quota is found — so decrement the count variable.

Check for Anagram:
Once the window size equals the pattern length:
    If count is zero, all characters match in required quantity — you found an anagram!

Slide the Window:
Before moving forward, remove the effect of the character going out of the window (i pointer).
If the outgoing character is in the map, increment its count back.
    If after incrementing, the count becomes 1, it means we’re now missing one full character — so increment count.

Why use count?
Instead of checking if all map values are zero (which takes O(K) time), we track that with count, which gives us the answer in O(1) time.
'''

def count_anagrams(s: str, pattern: str) -> int:
    from collections import defaultdict

    # Step 1: Build frequency map of the pattern
    freq_map = defaultdict(int)
    for ch in pattern:
        freq_map[ch] += 1

    count = len(freq_map)  # Number of distinct characters needed
    ans = 0
    i = 0
    k = len(pattern)  # Size of window

    # Step 2: Slide the window over the string
    for j in range(len(s)):
        # Decrease frequency of current character if it's in pattern
        if s[j] in freq_map:
            freq_map[s[j]] -= 1
            if freq_map[s[j]] == 0:
                count -= 1

        # When window size matches pattern length
        if j - i + 1 == k:
            # If count is zero, all pattern characters matched
            if count == 0:
                ans += 1

            # Step 3: Slide the window
            if s[i] in freq_map:
                freq_map[s[i]] += 1
                if freq_map[s[i]] == 1:
                    count += 1
            i += 1

    return ans

# Example usage:
text = "aabaacbaca"
pattern = "aaba"
result = count_anagrams(text, pattern)
print(f"Number of anagrams: {result}")
