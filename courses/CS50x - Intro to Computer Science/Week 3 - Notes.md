# Week 3

Now we're going to take some of the ideas from previous weeks as being for granted under our belts. In particular, debugging, where 3 CS50-specific tools were talked about:

```
help50
eprintf
debug50
```

We also talked about strings and `\0`, where `\0` is used to denote the end of a sring.

In previous weeks we've been using `int main(void)` which signals that the program takes no command line inputs. We can still call functions, but when you run the program, but we don't supply any input. But last week we introduced

```
int main(int argc, string argv[])
```

This means that `main` can take two inputs from the command line - it can take `argc` and `argv` - argument count and argument vector, aka an array.

Today is about ideas, algorithms and problem-solving. 

## Linear Search

If you're trying to find a number in a line-up, you can simply go from left to right, or from right to left - if you don't want to just guess at random. How would we write psuedocode for this?

```
for each element in array
    if element you're looking for
        return true
return false
```

The `return false` in the above example would only be triggered if none of the elements contained what you were looking for - which is why it's aligned with the `for` loop and not contained within anything else.

Why would this not be fine?

```
for each element in array
    if element you're looking for
        return true
    else
        return false
```

This example would return `false` if the very first element in the array isn't what you're looking for - rather than cycling through all of the elements.

## Binary Search

Rather than just working from left to right, this lets us take an approach similar to the phone book example in Week 0.

```
look at middle of array
if element you're looking for
    return true
else if element is to the left
    search left half of array
else if element is to the right
    search right half of array
else
    return false
```

How do we search the left and right halves of the list? We need to use our solution inside of our solution. Our lines that tell us to search the left and right halves of the array are not equivalent to asking the same question again. What we're doing is `recursive` - we're using **recursive calls**, which means for a function, in this case the pseudocode, to call itself - to use its own definition again and again. Instinctively this is bad, unless you keep doing it on smaller and smaller problems.

We can use this principle for searching and for sorting.

## Selection Sort

```
4 2 6 8 1 3 7 5
```

You can take the smallest number, move it to the far left, then go all the way through, find the next smallest number and put that one in the next position - each time shifting all of the other elements to the right.

Sorting takes time - it can start off quickly, but then eventually will drag. How can do we go about doing this in a way that's more scalable?

We should always aim to do things in the least amount of work possibly because it all ads up. If sorting numbers, rather than putting the smallest one at the end and shifting the others down, it's faster to swap the lowest number with whatever is occupying it's space - this way you're only moving two numbers at any given time.

But to find the smallest element, you have to keep going all the way through the list again and again. 

### Selection Sort Psuedocode

```
for i from 0 to n-1
    find smallest element between i'th and i-1'th 
    swap smallest with i'th element
```

## Bubble Sort

Now let's try a different approach. 

```
4 2 6 8 1 3 7 5
```

Look at the first two numbers - are they in or out of order? Swap them if needed. Don't look at the rest of the problem. If you then keep comparing the pairs, the higher number **bubbles** its way to the top so now you have one less element to worry about and all of the other numbers bubbled one step closer to their positions. Then the `n-1'th` number gets bubbled to the top and so on. Once it's sorted, the computer knows because it doesn't have to do any more swaps.

### Bubble Sort Pseudocode

```
repeat until no swaps
    for i from 0 to n-2
        if i'th and i+1'th elements out of order
            swap them
```

## Insertion Sort

Time for another approach.

```
4 2 6 8 1 3 7 5
```

This involves taking the first value, and putting it into a new array, which is by default, sorted. Then you take the second value (`2`) and you move it into the array, and have to shift `4` down to do it. As you go through the values, sometimes you'll have to shift quite a few values, but, you'll end up with fewer values to sort so it's still faster than more basic approaches. You deal with the elements as you encounter them.

### Insertion Sort Pseudocode

```
for i from 1 to n-1
    call 0'th through i-1'th elements the "sorted side"
    remove i'th element
    insert it into the sorted side in order
```

## Algorithm Running Time

How do we choose which one to use? And why? Look at how long it takes to run - could be minutes, seconds, steps, anything - as long as you're consistent when you compare the results between algorithms.

Let's dig deeper.

### Bubble Sort Time

If we started with `n` values to sort, our first pass looked at `n-1` pairs. (We had 8 people, so we had 7 pairs.) But then our n'th value bubbles all the way to the top and we don't need to consider it again (8 wound up at the end.) 

The second time through bubble sort, you only needed to consider 6 pairs - `n-2`. And so on.

```
(n-1) + (n-2) + ... + 1 = 
n(n-1) /2 =
(n²-n) /2 = 
n²/2 - n/2
```

Great, but what does this _mean_?

When talking about the efficiency of algorithms, you should generally really care about the component that is the biggest order of magnitude - the number that contributes the most to the total cost. The `-2` or `/2` in the sum pale into insignificance next to the `n²`. That's the essence of the formula.

## Big O Notation

This means that for Bubble Sort, we'll generally say that the running time is on the _order_ of `n²`:

```
O(n²)
```

(Big `O` is mathematical notation for **the order of**.) It's the upper bound of the running time for thi algorithm.

Examples would include things like:

```
O(n²)
O(n log n)
O(n)
O(log n)
O(1) // this is where the number of steps needed is constant - it could be 1 step or 1,000, but the same regardless of the number of values
```

Bubble Sort, Selection Sort and Insertion Sort all have running times of `O(n²)`, despite being different in execution. They do share a commonality - all of them are comparison based. Some of them will require a fewer number of steps numerically, but they're all `n²` for the reason that they all involve comparisons as many as `n` times `n` times.

What search would be:

```
O(n)
```

That would be **linear search**. 

What search would be logarithmic?

```
O(log n)
```

That would be **binary search**. 

What would be 

```
O(1)
```

That would be something like `printf`, or even just adding two numbers together in a single step. Checking an `if` condition, returning a value - statements generally might be just constant time.

## Omega Notation Ω

This is the opposite of **Big O Notation**. It's looking at the best case scenario. How few steps might you solve problems with? Let's look at some examples.

```
Ω(n²) 
Ω(n log n)
Ω(n)
Ω(log n)
Ω(1)
```

Regardless of the sort of the list, which algorithm would still have required `n²` steps? **Selection sort** - as you don't know, even if the list is sorted that the lowest value _is_ the lowest value - you still have to go through the list.

What about **bubble sort**? Because you compare as you go, without going back and can do it in one pass IF everything is already sorted, it's `Ω(n)`. 

Can you sort `n` elements in logarithmic time or constant time? `Ω(log n)` or `Ω(1)`? It's like saying, can you sort `n` elements without even looking at some of the elements? The short answer is **no**. Because you can't know the list is sorted without even looking at all of the elements first. But for **linear search** and **binary search**, the omega running time is `Ω(1)` as you might find the answer in your first step.

## Theta Notation Θ

Sometimes these numbers coincide. If your Big O and Omega notation coincide, you can claim that your algorithm has a running time of capital Theta - Θ.

So far, from what we've seen, in sorting, the best case we've seen is `O(n²)`, in terms of the worst case. Given that search and sort are all around us, it'd be great to have better solutions.

If you sort for a name in the contacts section of your phone, iOS and Android have their own algorithms that do smarter things than we've done here.

The algorithms we've used so far aren't poorly implemented, they're just poorly designed. There are other algorithms, such as **merge sort** which are far, far quicker.

## Recursion

Here's our pseudocode for searching for Mike Smith back in Week 0:

```
0 pick up phone book
1 open to middle of phone book
2 look at names
3 if Smith is among names
4       call Mike
5 else if Smith is earlier in the book
6       open to middle of left half of book
7       go back to step 2
8 else if Smtih is later in book
9       open to middle of right half of book
10      go back to step 2
11 else
12      quit
```

What if we tweaked this formula slighty?

```
0 pick up phone book
1 open to middle of phone book
2 look at names
3 if Smith is among names
4       call Mike
5 else if Smith is earlier in the book
6       search for Mike in left half of book
7    
8 else if Smtih is later in book
9       search for Mike in right half of book
10    
11 else
12      quit
```

Rather than inducing a loop and going to a specific line number, we're just generally saying to "search for Mike". This approach, this cyclical use of your own definition is known as **recursion**. We can use recursion to implement **merge sort**.

## Merge Sort

Merge sort is demonstrative of a class of algorithms that don't behave in the same way as our other sorting algorithms.

### Merge Sort Pseduocode

```
on input of n elements
    if n < 2
        return
    else
        sort left half of elements
        sort right half of elements
        merge sorted halves
```

Example:

```
4   8   6   2   1   7   5   3
```

Merge sort splits the list in half, then in half again and so on until you're looking at just the leftmost two elements.

It also requires some extra memory, or RAM to make this work.

When you start to merge the lists, you compare right and left sides, but you never go back - you simply go through a linear process of sorting - on the leftmost side of each half, which number is lower - then compare and move forward.

Sorting the above numbers required more RAM. But, because we're dividing things in half, in half and in half, the running time is actually `log n`. You do `log n` things, but you incur `n` steps of merging. That means our running time would be

```
O(n log n)
```

Let's think about this again, by looking at the first bit of our pseudocode:

```
if n < 2
    return
```
If we wanted to calculate our running time, we could do it as follows:

```
T (n) = O (1)

// if n < 2
// T = running time

```

If we wanted to factor in what happens if `n` is greater than 2, it looks a little like this:

```
T(n) = T(n/2) + T(n/2) + O(n)

// if n >= 2
```

What happens if you multiply all of this out, to cover all of the iterations that would take place?

We come back to 
```
O(n log n)
```

## sigma0

Let's now try and apply this to C code. 

```
#include <cs50.h>
#include <stdio.>

int sigma(int m);

int main(void)
{
    int n;
    do
    {
        printf("Positive integer please: ");
        n = get_int():
    }
    while (n < 1);

    int answer = sigma(n);

    printf("%i\n", answer);
}

int sigma(int m)
{
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += i;
    }
    return sum;
}
```

In the above we have created a function called `sigma`. which takes an integer `m` as its sole argument. It's going to return a number. `main` takes no command line arguments. But inside of `main` is code that is going to pester a use for a positive integer until they give us one. Then we call the `sigma` function, passing in whatever the user's input was, sorting it in `answer` and the printing it out. 

If we want to dig in to how `sigma` works, we have to scroll down and look at the function. `sigma` takes a function `m` as input and returns an `int`. We created a counter variable, called `sum` which is initialised at zero. Then using a `for` loop, iterating from 1 up to `m`, we are going to add the individual numbers to `sum`. We aren't using `sum ++` as this would just add 1 each time. We want to add in whatever `i` is, whether it's 1 or 2 or 3, counting all the way up to `m`. Then we `return sum`.

## sigma1

`sigma` afford us the opportunity for **recursion**. It's not necessarily better, or more correct than our other code, but something we can try.

`sigma1` has identical code inside of main, but we can implement `sigma` differently. We can implement `sigma` as a function in such a way that it calls itself.

```
int sigma(int m)
{
    if (m <= 0)
    {
        return 0;
    }
    else
    {
        return (m + sigma(m - 1));
    }
}
```

If `m` is less than or equal to 0, (in case the human input is messing with us and to avoid getting stuck within an infinite loop), then `return 0`. Then in our `else` condition, is one line of code that implements the entire function. What we've defined here, is that if the goal is to count up all of the numbers between 1 and `m`, logically that's the same as counting up all the numbers from `m` to 1. That means we can start with `m`, and then add in every number that's 1 less, until we get to 1. 

While it doesn't look like a good thing for `sigma` to call `sigma`, it's only doing until `m` = 0 - it doesn't do it indefinitely.

You shouldn't actually implement code like this as calling up functions repeatedly can take up a lot of memory and cause your computer to crash. We just wanted to illustrate the capability we have to map intuition into actual code. 

## Shorts

### Computational Complexity


### Bubble Sort


### Selection Sort


### Insertion Sort


### Merge Sort


### Linear Search


### Binary Search


