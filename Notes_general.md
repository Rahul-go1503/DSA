INT_MIN is int in nature means you cannot store INT_MIN -1 in int datatype

vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
vector<int> dir={-1 -1 1 1 -1 0 1 0 -1};

INT_MAX
LONG_MAX
LLONG_MAX


Question: Can you explain how did u determine the potential swap distance?

Answer:

When you map a 2 dimensional ( row * column ) matrix to 1 dimensional array, the swap to left and right are still -1 and 1 respectively in terms of index change in 1-D array. In contrast, the swap to up and down are -column and column as of index change.

That is, for any given index (i, j) in the matrix, it will be mapped to (i * column + j) in the array. Since in the matrix (i, j) could swap with (i, j - 1), (i, j + 1), (i - 1, j), and (i + 1, j), in the array (i * column + j) would swap with (i * column + j - 1), (i * column + j + 1), ((i - 1) * column + j) and ((i + 1) * column + j) accordingly.

We can easily conclude the swap displacement are -1, 1, -column, and column correspondingly.

e.g.: Let's consider (1, 2) in the following 3 * 5 matrix

column # -->               0     1     2     3     4
                      0  (0,0) (0,1) (0,2) (0,3) (0,4)
                      1  (1,0) (1,1) (1,2) (1,3) (1,4)
                      2  (2,0) (2,1) (2,2) (2,3) (2,4)
we can swap (1, 2) with (1, 1), (1, 3), (0, 2), and (2, 2)

When mapped to 1 dimensional array, it can be obtained that (1 * 5 + 2) swap with (1 * 5 + 2 - 1), (1 * 5 + 2 + 1), ((1 - 1) * 5 + 2) and ((1 + 1) * 5 + 2):

  0    1    2    3    4    5    6    7    8    9   10   11   12   13   
(0,0)(0,1)(0,2)(0,3)(0,4)(1,0)(1,1)(1,2)(1,3)(1,4)(2,0)(2,1)(2,2)(2,3)

 14
(2,4)
Obviously, we can swap 7 with, 6 (= 7 - 1), 8 (= 7 + 1), 2 (= 7 - 5), 12 (= 7 + 5), where 5 is matrix column (width).

The displacements in the above case are -1, 1, -5, and 5.

Hope the above answers your question.


# INT_MIN = -2147483648;
# INT_MAX = 2147483647;

- 1463847412 reverse max
- (0 to 2147483647)
- if (mid > x/mid) 