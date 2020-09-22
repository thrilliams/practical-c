This exercise is designed to get you more familiar with C's syntax and peculiarities. You'll be writing some code dealing with one of the most famous unproven conjectures in mathematics.

# The conjecture
The Collatz Conjecture (Links to an external site.) is a statement about the behavior of a certain numeric sequence. Here's how that sequence is defined:

First, pick a positive, nonzero integer and call it n.

1. If n is 1, you're done! Otherwise, continue.
2. Do one of the following to calculate a new value for n:
    - If n is even, divide it by 2.
    - If n is odd, triple it and add 1 (i.e., 3n + 1).
3. Repeat the process from step 1.

The conjecture states that, no matter what n you choose, this process will eventually terminate – that is, you will eventually end up with a 1.

The number of times you have to repeat the process until you get a 1 for some n is called the stopping time of n. Let's look at some examples:

| n   | Sequence                  | Stopping time |
| --- | ------------------------- | ------------- |
| 1   | 1                         | 0             |
| 2   | 2, 1                      | 1             |
| 3   | 3, 10, 5, 16, 8, 4, 2, 1  | 7             |
| 8   | 8, 4, 2, 1                | 3             |
| 20  | 20, 10, 5, 16, 8, 4, 2, 1 | 7             |

Computer-aided checks have shown the conjecture holds for numbers up to 268, but so far a rigorous proof for all integers is elusive. Famously eccentric mathematician Paul Erdős stated that "mathematics may not be ready for such problems" as this.

# Your assignment
Your job is to answer this question: what is the number less than 100,000 with the largest Collatz stopping time? And, what is its stopping time?

Do this by writing a function that takes an integer n and returns its stopping time. Your main function will then call your new function in a loop to find the largest stopping time.

You should format your output using printf in the format "\<number> has a stopping time of \<time>." For example, if were checking for the largest stopping time of numbers less than 100, your program would output something like this:

```
97 has a stopping time of 118
```

# Some tips
Name your stopping time function meaningfully. C generally uses the lower_underscore convention, like Python.

Don't worry too much about the integer types you use; the numbers we're dealing with aren't big enough for it to matter much. You might mark certain things unsigned if you think it makes sense.

You do not need to use arrays for this assignment. We haven't talked about them yet and they're rather tricky in C. Think about ways you could approach the problem without them. (Hint: you only need to keep track of a maximum value. How might you handle that?)

Recursion is probably not your best bet. It will be tricky to implement in this scenario and we haven't yet learned how to debug our programs, so fixing errors will be a pain. Stick to loops. How long do we need to continue doing a process? And what do we do at each step of the way? Those observations should translate directly into a while loop.

Your new function should not produce any output of its own. Its job is simple: take in a number, return a number. The main function will use your new function to produce output.

# Assessment
Your code will be assessed with the following rubric:

- Correctly named and declared a function with the appropriate types.
- Function uses a loop to calculate the stopping time of its argument.
- Function returns that stopping time. It does not generate extraneous output.
- The main function loops over all numbers in the range, finding the stopping time function of each.
- main finds the maximum stopping time and the number that generates it.
- The output is correctly formatted.

# Submitting your response
Please submit your code by pushing it to a Github repository. Paste a link to the repository as your submission to this assignment on Canvas. I will use Github to leave comments on your code.

If you make the repository public, I can see it without any extra steps. If you feel like making the repository private, that's fine, but you will need to add me as a collaborator. My Github username is misterfifths.

# Bonus round!
(purely optional, but fun!)

Some numbers have a surprisingly large stopping time compared to the number itself. For instance, the number 41 has a stopping time of 109. It's interesting to consider the ratio of a stopping time to the number as a way to quantify that difference. Returning to the previous example, 109 / 41 is roughly 2.66, meaning that 41 has a stopping time more than two-and-a-half times larger than itself.

What number less 100,000 has the highest ratio to its stopping time? Output the number, its stopping time, and the ratio, rounded to the 2 decimal points.