# binary search

## exercises

**1.1** Supose you have a sorted list of 128 names, and you're searching
through it using binary search. What's the maximum number of steps it would
take?
```
import math
math.log2(128)
7.0
```

**1.2** Suppose you double the size of the list. What's the maximum number of
steps now?
```
import math
math.log2(256)
8.0
```

Give the run time for each of scenarios **1.3**, **1.4**, **1.5**, **1.6** in
termos of Big O.

**1.3** You have a name, and you want to find the person's phone number in the
phone book.

> O(log(n))

**1.4** You have a phone number, and you want to find the person's name in the
phone book. (Hint: You'll have to search through the whole book!)

> O(n)

**1.5** You want to read the numbers of every person in the phone book.

> O(n)

**1.6** You want to read the numbers of just the As. (This is a tricky one! It
involves concepts that are covered more in chapter 4. Read the answer -- you
may be surprised!)

> O(n)
