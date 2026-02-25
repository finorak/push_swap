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

**Understanding the command :** to understand the how the command where used we relied on the document we provided in [Document](#document) and [Youtube](#youtube) sections
in which it gave us a ton of example in how to use it.
