# grokking algorithms

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

**2.1** Suppose you're building an app to keep track of your finances.

1. Groceries
2. Movie
3. SFBC Membership

Every day, you write down everything you spent money on. At the end of the
month, you review your expenses and sum up how much you spent. So, you have
lots of inserts and a few reads. Should you use an array or a list?

> A list is better because reading from a list is O(n), but writing to a list
> is O(1). In contrast, an array allows O(1) reading, but writing to an array
> takes O(n). Since we are performing more writes than reads, **it makes sense
> to use a list**.

**2.2** Suppose you're building an app for restaurants to take customer orders.
Your app needs to store a list of orders. Servers keep adding orderts to the
list, and chefs take orders off the list and make them. It's an order queue:
servers add orders to the back of the queue, and the chef takes the first order
off the queue and cooks it.

Would you use an array or a linked list to implement this queue? (Hint: Linked
lists are good for inserts/deletes, and arrays are good for random access.
Which one are you going to be doing here?)

> The access to the list is not random; we only need to access the last
> element. Therefore, we can keep a pointer to it. Additionally, since there
> will be frequent additions and deletions, the list performs better than an
> array

**2.3** Let's run a thought experiment. Suppose Facebook keeps a list of
usernames. When someone tries to log in to Facebook, a search is done for their
username. If their name is in the list of usernames, they can log in. People
log in to Facebook pretty often, so there are a lot of searches through this
list of usernames. Suppose Facebook uses binary search to search the list.
Binary search needs random access -- you need to be able to get to the middle
of the list of usernames instantly. Knowing this, would you implement the list
as an array or a linked list?

>> Since we need random access, the array is the best solution.

**2.4** People sign up for Facebook pretty often, too. Suppose you decided to
use an array to store the list of users. What are the downsides of an array for
inserts? In particular, suppose you're using binary search to search for
logins. What happens when you add new users to an arry?

>> The downsides are that every time we run out of space for a new user in the
>> array, we will have to reallocate space for the array and move all users to
>> the new space.

**2.5** In reality, Facebook uses neither an array nor a linked list to store
user information. Let's consider hybrid data structure: an array of linked
lists. You have an array with 26 slots. Each slot points to a linked list. For
example, the first slot in the array points to a linked list containing all the
usernames starting with a. The second slot points to a linked list containing
all the usernames starting with b, and so on.

Suppose Adit B signs up for Facebook, and you want to add them to the list. You
go to slot 1 in the array, go to the linked list for slot 1, and add Adit B at
the end. Now, suppose you want to search for Zakhir H. You to slot 26, which
points to a linked list of all the Z names. Then you search through that list
to find Zakhir H.

Compare this hybrid data structure to arrays and linked lists. Is it slower or
faster than each for search and inserting? You don't have to give Big O run
times, just whether the new data structure would be faster os slower.

>> The hybrid data structure is much faster than a standard array for writing
>> new data, but it is still much slower for reading. However, the idea shows
>> promise. We can improve on it by creating a linked list of arrays, where
>> each array handles a specific range—such as the 1st, 2nd, 3rd letters, and
>> so on.
