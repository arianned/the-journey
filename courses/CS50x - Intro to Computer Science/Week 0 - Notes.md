# Week 0

## This is CS50

Harvard's introduction to the intellectual enterprises of computer science and the art of programming.

Computer science interacts with so many different fields. It can be applied in so many areas once you have the practical skills.

## Course Overview

73% of CS50 students have never taken a CS class before. It's more important where I end up relative to myself in Week 11 vs Week 0, rather than how I'm doing versus other people.

Most of what CS is about is problem solving:

> inputs (what we're trying to solve) -> {black box} -> outputs (solution)

We may implement some of what's in the black box, but ultimately, we only care about whether the problems get solved.

## Introducing Binary

We're used to **unary** input - where we utilise a single mark for every input that we want to count. For example, counting using our fingers or taking a tally on a piece of paper - those tally mark, those hashs, are unary.

Computers only understand **binary** - zeroes and ones - 0, 1. Humans are cleverer - we understand **decimals**, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.

Even though binary looks unfamiliar, it's just like the systems and ideas that we already know. Take the number **123**.

We know that a number like this is made up of columns - hundreds, tens and ones - we know that it's the combination of these which makes the number - not just the pattern of three symbol on the screen. It's 100x1, 10x2 and 1x3 - all added together - 100+20+3 = **123**.

Computers vary a little, but are still quite similar. Rather than using powers of ten like we do, 1, 10, 100, 1,000, 10,000, etc, they use powers of two - 2, 4, 8, 16, 32,64, 128, etc.

Where we map 100s, 10s and 1s, they map 4, 2, 1.

This means 000 in decimal also equals 000 in binary.

001 in decimal also equals 001 in binary.

But showing the decimal number 002 in binary, is different. We don't just take the 001 and add a 1 to our 2's column, making 011. That number would actually equal 3. Instead, 002 is represented as 010 in binary.

1 = 001  
2 = 010  
3 = 011  
4 = 100  
5 = 101  
6 = 110  
7 = 111  

It would seem as if computers can count no higher than 7 as we've used all our 1s and 0s. But what do we do, if we want to count higher than 999? We add a fourth digit to the left. So it is in binary - we add a fourth digit that represents 8s.

The numbers in the binary system are generally known by computer scientists as "bits" or "binary digits".

But how do we get from these "bits" to a computer? Think of electricity. If we call the absence of electricity flowing a zero because there's just nothing, we could arbitrarily, but globally, call the presence of electricity a one.

No power = 0  
Power = 1

## Binary Bulbs

A bit is a useful unit of measure - not unto itself - but if you have at least 8 bits, known as a **byte** - a byte of bits.

If we had bulbs arranged as follows:

> 128   64  32  16  8   4   2   1

We would represent the number **42** as:

> 00101010

We would represent the number **50** as:

> 00110010

## ASCII

We decided we wanted computers to be more than calculators. So the world decided on a system and a way of mapping letters to numbers - resulting in a capital A having the decimal representation of 65.

A = 65  
B = 66  
C = 67  
D = 68  
E = 69  
F = 70  
G = 71  
H = 72  
I = 73

So what would this mean:

> 72    73  33

H   I   !

(33 happens to represent an exclamation point in unicode, or ASCII as it was called back in the day.)

## RGB

For RGB, we use 2 sets of bits to indicate how much red, green or blue we want. A high number means lots of r/g/b whereas a low number means not much r/g/b.

The pattern of 8+8+8=24 bits left to right is how a computer would represent a colour.

That's just for a dot on screen - a single pixel. If you combine these vertically and horizontally into a grid, you get an image. If we combine images really fast, we get movies.

We've built from zeroes and ones, through to decimal numbers and how we represent them, to letters of the alphabet, then using a few more bits to represent colours.

As soon as we can represent colours, we have photographs, gifs and video.

## Taking Attendance

Now we move on to the fun stuff. We have to be capable of solving problems and that's where we get to **algorithms**.

How about taking attendance in a class?

As computer scientists we start from the number zero - if all the lights are off that's the lowest place we can start from.

- Step 0 - All attendees stand up and think of the number 1.
- Step 1 - Pair off with someone standing. Add your numbers together.
- Step 2 - One of you should sit down. If you're still standing, go back to Step 1. 

Doing this induces a loop - some sort of cycle. In our attendance example, you should end up with only one person standing - who has the total figure.

## Finding Mike Smith

Take the same algorithmic logic of the attendance and apply it to looking for "Mike Smith" in a phonebook.

Rather than flip through the pages one at a time, or even two at a time (which could cause us to miss Mike if he's sandwiched between the two pages). Rip the book in half, which takes us to **M**. Like with attendance, where half the people sit down, we've instantly just removed half the potential problem.

In theory you can repeat the problem - throwing away half of what you've got, until you're left with one single page that solves your problem (lets you call Mike).

Flipping through pages 1 at a time = 1,000 steps  
Flipping through pages 2 at a time = 500 steps  
Our other solution?

- 0 - **pick up** phone book
- 1 - **open to** middle of phone book
- 2 - **look at** names
- 3 - **_if_** _Smith is among names_
- 4 - -> **call** Mike
- 5 - **_else if_** _Smith is earlier in book_
- 6 - -> **open** to middle of left half of book
- 7 - -> {go back to Step 2}
- 8 - **_else if_** _Smith is later in book_
- 9 - -> **open** to middle of right half of book
- 10 - -> {go back to Step 2}
- 11 - **_else_**
- 12 - -> **quit**

Everything listed in bold above is an action. Formally known as a **function**.

Everything listed in bold italic above is a **_condition_** or branch. They are decision points where you might go one of multiple different ways.

Everything in italic is a _Boolean Expression_. They're questions. Boolean Expressions are either true or false, yes or no. It's the question who's answer you care about, so as in a condition to make a decision - get back an answer, go left or right, etc.

The items in the curly brackets {go back to Step 2} are what we call loops - a cycle that's making me do something again.

## A Good Algorithm

If the phone book doubled in size, from 1,000 to 2,000 pages, it only takes the algorithm one more step to find Mike. If the phone book had 4 billion pages, it only takes reducing it 32 times to get down to one - even though that's a huge number.

> The goal of the class is not just to solve things correctly - we can do that going through the phonebook a single page at a time - the goal is to do it correctly and **_well_**.

## Introducing Scratch

Scratch was developed by MIT's Media Lab to help students start to think and express themselves algorithmically, in a way more aligned with computational thinking.

Start by layering - begin with the simplest idea and then build on it. Simplify by creating functions once you have something that works.