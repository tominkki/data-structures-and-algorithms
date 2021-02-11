##  Exercise 1.

Start with the stack methods, and write a function copy_stack with the following
specifications:

```cpp
Error_code copy_stack(Stack &dest, Stack &source);
```

precondition: None.

postcondition: Stack dest has become an exact copy of Stack source; source
is unchanged. If an error is detected, an appropriate code is
returned; otherwise, a code of success is returned.

**Write three versions of your function:**

- Simply use an assignment statement: dest = source;

- Use the Stack methods and a temporary Stack to retrieve entries from the
  Stack source and add each entry to the Stack dest and restore the Stack
  source.

- Write the function as a friend to the class Stack. Use the private data
  members of the Stack and write a loop that copies entries from source to
  dest. Friend functions have access to all members of a C++ class, even private ones.
	
Which of these is easiest to write? Which will run most quickly if the stack is
nearly full? Which will run most quickly if the stack is nearly empty? Which
would be the best method if the implementation might be changed? In which
could we pass the parameter source as a constant reference?
