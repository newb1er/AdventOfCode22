# Problem 1

https://adventofcode.com/2022/day/1

## Solution

### Read data

The input of inventories is separated by a blank line. To read the blank line, we should use `std::getline()` instead of `std::cin`

### Part 1: Find The Max One

This one is easy. We sum the calories in an elf's inventory while reading the data. Whenever we encounter a blank line, we update the `max_calo` variable. Then, our answer is stored in `max_calo` after we read all the input.

### Part 2: Sum of The Top Three

We can't just sum the calories up as we did above. Instead, we need to store every calorie each elf carries and create a leaderboard. We can order it by pushing these data into a heap, which is `std::priority_queue<T>` in c++. Tada, after we put all the data into the `priority_queue`, we can easily find the top three by poping three times.