# checker-codes-hokama

We can use a stack to check if the parenting is balanced. Using the following idea:

● Whenever we open a '(', '[' or '{' symbol, we put it on a stack.

● Whenever we close a ')', ']' or '}' symbol, we remove the element from the top of the stack and check if it is the corresponding opening symbol. If not, it means that we have detected an imbalance.

● At the end of the code/expression we check if the stack is empty. If it is not, it means that we have opened a symbol that we have never closed.

● All other character types are ignored.

In this work you will implement a simple parenting checker. Which simply reads the text from the system's standard input and checks that in that text, parentheses, square brackets and braces are opened and closed in a balanced way. A code will be provided and you can use it at will.

The verifier will not check all cases. For example, if a symbol appears within a string, it will be considered a symbol and will throw an error.

Obviously our verifier also does not guarantee that a code/expression is correctly written, but it can be used as one of the steps of the complete verification. Your program should indicate which symbol caused the problem. If the symbol is a closing one, it should tell the line that there was this closing. And if it's an opening symbol that hasn't been closed, the program should indicate the symbol, but it doesn't have to indicate which line it was opened on.
