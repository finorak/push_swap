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

**Concept Clarification:**
 Explaining why the norminette counts blank lines and closing braces toward the 25-line function limit, and why static functions still count toward the 5-function-per-file limit.

- README Structuring : Helped organize the sections and translation of this README.
- Understanding the command : to understand the how the command where used we relied on the document we provided in [Document](#document) and [Youtube](#youtube) sections
in which it gave us a ton of example in how to use it.

# Explanation of the Algorithms
There are 4 strategy that was asked to be implemented into this project
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


## Complex


## Adaptive
As said by the subject the Adaptive one will choose the best approach based on the disorder metric (how sorted is the list)
| O(n2) | O(n√n) | O(nlogn) |
| --| -- | -- |
| for disorder < 20% | for 20% <= disorder <= 50% | for disorder > 50% |
