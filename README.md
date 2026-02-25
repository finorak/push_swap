*This project has been created as part of the 42 curriculum by finorako, maratojo.*

# Description
Sorting element is quit the easy tasks, but there is a catch with the push swap project, the main goal is the same but the process is quit not the same.
It is to sort it using the minimum amount of the given instructions bellow.

| sa (sb) | ss | pa (pb) | ra (rb) | rra (rrb) | rr (rrr) |
| -- | -- | -- | -- | -- | -- |
| swap the first two element or a(b) | swap both a and bat the same time | push the first element of b (a) into a (b) | rotate a (b) clockwise | reverse rotate a (b) non clockwise | roate (reverse rotate) a (b) |

# Instructions
To run this project you just have to follow the steps bellow (we assume you are in the same directory as the project):
- Open bash (or your chosen tty) then run `make` (`make bonus` to run the bonus)
- After that you just run the program using this command for example `ARG="3 4 1 0 5"; ./push_swap $ARG` or (`ARG="3 4 1 0 5"; ./push_swap $ARG | ./checker $ARG` to run the bonus)
- The output will then be put on the standard output

# Ressources
## Youtube
- [7.10 Radix Sort/Bucket Sort in Data Structure | Sorting Algorithm](https://www.youtube.com/watch?v=JMlYkE8hGJM)
- [7.7 Merge Sort in Data Structure | Sorting Algorithms| DSA Full Course](https://www.youtube.com/watch?v=jlHkDBEumP0)
- [push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)](https://www.youtube.com/watch?v=OaG81sDEpVk)
- [Push_Swap: An Easy and Efficient Sorting Algorithm](https://medium.com/@julien-ctx/push-swap-an-easy-and-efficient-algorithm-to-sort-numbers-4b7049c2639a)
- [Merge sort](https://www.geeksforgeeks.org/dsa/merge-sort/)
## Document
- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
## Tester
- [Push-swap-tester by julien-ctx/](https://github.com/julien-ctx/push-swap-tester)
- [Push-swap-visualizer](https://github.com/o-reo/push_swap_visualizer.git)


# Explanation of the Algorithms
There are 4 strategy that was asked to be implemented into this project, but the main core is that we use a third stack (where we sort the value in it), we then use that sorted stack and use
the index we got from the sorted stack (in our case the third stack is an array), and
place the correct index (because the push swap project only allow non duplicate value so we can use this method) so that we work with 0 - (n - 1) value 

| Simple | Medium | Complex | Adaptive |
| -- | -- | -- | -- |
| An algorithm that run on O(n2) time complexity | An algorithm that run on O(n√n) time complexity | An algorithm that run on O(nlogn) time complexity | Will choose the best approach depending on the value of the disorder |

## Simple
There was a large set of algorithm to choose to do in the simple algorithm but here we have chosen **insertion sort**
we opted for **insertion sort** because it outperform the other sorting algorithm if the data given is partially sorted which have a time complexity of o(n) in the best case scenario
which is better than selection sort for example. At worst time scenario we get O(n2).
How it works, we first of all find the minimum value in the stack a we then rotate a or reverse rotate it (depending on it's position) till it get to the top of the stack a
we then push it into stack b, till a is sorted or if not sorted at all do those operations till there is only one element in a (which is the biggest element in the stack a at this point)
after that we can see that b is is sorted in descending order, we then push a till there is no element at all in b.
And that's how our simple strategy works.

## Medium
The medium algorithm reuses the same logic as the [Simple](#simple) one but instead of finding the minimum value each time, we divide the stack into chunks and push them into stack b.
We went with size / 30 for the average case and size / 11 if the size is equal to 100. We chose those numbers after several test cases — with those values we consistently stayed under the operation limits required by the project.
The core idea is a sliding wimdow. we define a range of acceptable rank **[0, chunk + index]** and scan through `a` looking for any element that fits inside it. Every time we find one and push it to `b`, the window expands by 1, gradually accepting more and more elements until `a` is completely empty.
Concretely :
- For each element at the top of `a`, we ask : does its rank fall inside **[0, chunk + index]** ? If yes, it goes to b and the window grows. If no, we rotate `a` and look at the next one.
- This scanning continues until the window has grown large enough to swallow every remaining element in `a`.
- Once `a` is empty, we recover everything from `b` back into `a` by repeatedly pulling out the largest remaining element. Since `a`receives elements from largest to smallest, it naturally ends up sorted smallest at the top.

The time complexity lands at O(n√n) because the chunk size scales with √n, which controls how many passes we need over the full stack.

## Complex
The complex algorithm is quit particular, in it reused the same logic as the [Medium](#medium) one but added another 'else if' statement.
Mathematically speaking we do not have an O(nlogn) algorithm but in practice we have an average case scenario of O(nlogn) and a best case scenario of O(n).
Here we could get in the worst case scenario an O(n2) time complexity buit the 'else if' statement ensure we do not exceed an O(nlogn) time complexity.
How it works:
<<<<<<< HEAD
- - We first of all divide it into chunk (we went with size / 16) for the average case but went with 30 if the size is equal to 500 (where here size is the size of the stack), we choose those number arbitrary after several test case (the document we followed suggest going for size / 11 but after changing that value to
our liking we noticed that with those number we had a lot of optimisation in which we then go with those number).
- - For every node in the stack, we look for it's index if it's less or equal to the variable index we created an example is given bellow: `(*stack)->index <= index`
if it's true we push to b and rotate it, why ?Because with that we will put the minimum value into b (as if starting a new chunck) and then rotate b, to keep that value in the middle of stack b.
- - If the value is not the minimum, we check if the value is in that range (chunk + index) `(*stack)-> index <= range + index` if yes we just push it into b to put that value at the top of the stack or the bottom of stack a.
- - If all those test fail, we just rotate a to check for the next value.
- - After doing those operations we just push the remaining into the stack a by checking the max value (as we said before the max value is weather at the top/bottom of the stack) and do a push a until there is no node in b anymore.
=======
- We first of all divide it into chunk (we went with size / 16) for the average case but went with 30 if the size is equal to 500 (where here size is the size of the stack), we choose those number arbitrary after several test case (the document we followed suggest going for size / 11 but after changing that value to 
our liking we noticed that with those number we had a lot of optimisation in which we then go with those number).
- For every node in the stack, we look for it's index if it's less or equal to the variable index we created an example is given bellow: `(*stack)->index <= index`
if it's true we push to b and rotate it, why ?Because with that we will put the minimum value into b (as if starting a new chunck) and then rotate b, to keep that value in the middle of stack b
- If the value is not the minimum, we check if the value is in that range (chunk + index) `(*stack)-> index <= range + index` if yes we just push it into b to put that value at the top of the stack or the bottom of stack a.
- If all those test fail, we just rotate a to check for the next value.
- After doing those operations we just push the remaining into the stack a by checking the max value (as we said before the max value is weather at the top/bottom of the stack) and do a push a until there is no node in b anymore.
>>>>>>> refs/remotes/origin/main

## Adaptive
As said by the subject the Adaptive one will choose the best approach based on the disorder metric (how sorted is the list)
| O(n2) | O(n√n) | O(nlogn) |
| --| -- | -- |
| for disorder < 20% | for 20% <= disorder <= 50% | for disorder > 50% |



## AI Usage
AI was used for the following tasks:

**Research and learning:**
- Used AI to understand algorithmic complexity concepts (Big O notation).
- Clarified stack manipulation techniques

**Documentation Assistance:**
- Used AI to structure this README.
- Translated content from French to English.
- Formatted tables and code blocks.

**Note Used For:**
- Direct code generation for algorithm implementations
- Writing core sorting logic
- The sorting algorithms (selection sort, medium sort, complex sort)

**Understanding the command :** to understand the how the command where used we relied on the document we provided in [Document](#document) and [Youtube](#youtube) 
sections in which it gave us a ton of example in how to use it.

# Contributions

### **finorako :**
- The core structure, like using struct instead of an array.
- The bench_mark function that display the details (like the number of instructions, count of each instructions).
- Error handler.
- Argument parsing.
- Explaining the algorithm.
- Handled some optimisation.
- The get_next_line (for the bonus that **maratojo** did).
- The ft_printf function.
### **maratojo :**
- The split function.
- Provided the libft
- Handling value that exceed the range of int.
- Sort util file and the function within it
- Strategy handling.
- The checker bonus.
