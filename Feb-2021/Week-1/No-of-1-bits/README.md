### No. of 1 bits
Have a look on the question [here](https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/)

#### Approach
-  AND operation
    - num & 1 = 1 // if last bit of num is 1
    - num & 1 = 0 // Else

    - Eg.
        -  3(11) & 1 = 1
        - 2(10) & 1 = 0

- Left Shift
    - num << n // Last n bits of num will be lost.
    - 3(11 << 1) = 1
    - 3847(111100000111 << 1) = 11110000011

- Since the given number is of 32 bit precision, we need to perform the above operation 32 times.

