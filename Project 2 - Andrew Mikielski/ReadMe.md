Write a program using a stack to replicate the “Reverse Notation Calculator.” The “Reverse
Notation Calculator” allows the user to enter numbers on to a stack. When an arithmetic operation
is chosen the top two numbers are popped oﬀ the stack. The operation is performed on the two
numbers and the answer is pushed onto the stack. The user can also just pop the top number oﬀ
the stack and clear the stack.

Look at the output text file to see how the program behaves. Be sure to use the exact menu options.
The stack and the menu are always displayed after each task is done. Remember to check if there
are at least two numbers on the stack before performing an operation. If there are not enough
numbers on the stack, put the stack back to how it was before the operation was attempted. Also
check for division by zero. If division by zero will occur, put the stack back to how it was before the
operation was attempted.

Create your own version of the stack data structure that only works for integers. You should call it
“IntStack.” Do not use my example template class stack. Only access the stack without violating
the rules of a stack (LIFO). When displaying the stack, go from bottom to top.
Again, use the output file supplied to see how the program works.