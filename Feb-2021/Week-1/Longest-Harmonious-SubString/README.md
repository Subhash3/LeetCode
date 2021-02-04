## Longest Harmonious SubString

Check the problem description [here](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/)

#### Approach
- If the difference b/w min and max of an array is 1, then there can only be two unique elements in that array.
- Make a hashmap that maps a number to its frequency.
```c
arr = [1, 3, 2, 2, 5, 2, 3, 7]

// hashmap of frequencies looks something like
// {
//     1 => 1,
//     3 => 2,
//     2 => 3,
//     5 => 1,
//     7 => 1
// }
```
- This can be done in O(N) time where N is the no. of elements in the given array.

- For any x, y in the hashmap, the length of the array with only x, y as unique elements is frequency of x + frequency of y.
```c
    // Unique elements: [1, 3, 2, 5, 7]
    Subseq      Length
    [1, 3]      1 + 2
    [1, 2]      1 + 3
    [1, 5]      1 + 1
            .
            .
            .
```

- We're almost done! Just execute the above step to compute the lengths of all subsequences with just two elements in it.
- Now the constraint is, the difference of those two elements must be 1.
- So, compute the lengths of those sub sequences whose elements' difference is 1 and take the max of them.
- This can be done in O(M^2) time where M is the no. of unique elements in the given array.
- To optimise this, just sort the array(O(M logM)) and check every adjacent elements' pair(O(M)).

- Hence the total time complexity of this algo is:  
```python3
    O(N) + O(M) + O(M logM)
```