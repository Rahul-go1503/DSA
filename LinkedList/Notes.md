*****
Notes : Understanding of pointers

In C++ Premiere book it is written:
This removes the memory to which ps pointer points; it doesn’t remove the pointer ps itself. You can reuse ps, for example, to point to another new allocation. You should always balance a use of new with a use of delete; otherwise, you can wind up with a memory leak—that is, memory that has been allocated but can no longer be used. If a memory leak grows too large, it can bring a program seeking more memory to a halt.

*******
Think of memory as a big warehouse with lots of boxes to put things into. When you call "new", the warehouse staff finds an unused box large enough for your needs, records that box as being owned by you (so it's not given to someone else), and gives you the number of that box so you can put your stuff into it. This number would be the "pointer".

Now, when you "delete" that pointer, the reverse happens: the warehouse staff notes that this particular box is available again. Contrary to real warehouse staff they aren't doing anything with the box — so if you look into it after a "delete" you might see your old stuff. Or you might see somebody else’s stuff, if the box was reassigned in the meantime.

Technically, you are not allowed to look into your box once you have returned it to the pool, but this is a somewhat weird warehouse with no keys or guards, so you can still do whatever you want. However, it might cause problems with the new owner of the box, so it's expected that you follow the rules.

********
The delete operator frees the memory which was previously allocated using the new operator. This means that the memory is now available to be used by the system, for instance when there is another use of new later in the program. It does not clear the data in the memory, however. The pointer will still point to the same address in memory, but accessing that block will result in undefined behavior.
It is good practice to set a pointer to NULL (or nullptr in C++11) after deleteing it. Any subsequent deletes will be harmless.

*****
Question : Initialization of Slow and fast pointers


Notes :
We cant start s anf f ptr to null

required at least 1 node
even cases :
auto slow = head;
auto fast = head;
eq: 1 2 3 4 && 1 2 3
give middle node 3 & 2

auto slow = head;
auto slow = head->next;
eq: 1 2 3 4 && 1 2 3
give middle node 2 & 2

req at least 2 nodes
auto slow = head;
auto fast = head->next->next;
eq: 1 2 3 4 && 1 2 3
give prev to middle node 2 & 1


*****
Imp Concepts in LL
deletation
1. curr node ko
2. prev node ko
3. next node ko
reverse nodes


*****
A summary about how to solve Linked List problem, C++
https://leetcode.com/problems/add-two-numbers/discuss/1340/A-summary-about-how-to-solve-Linked-List-problem-C%2B%2B

*****
ListNode newNode; <- stack
ListNode *newNode = new ListNode(); <- heap

*****
Merge two LinkList
1. By changing two pointers at a time
    head1>head2:
    while(head2){
        auto nxt = head1 -> next;
        ptr -> next = head2;
        head2 = head2 ->next;
        head1 -> next -> next = nxt;
        head1 = nxt;
    }
2. By changing only one at a time
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
