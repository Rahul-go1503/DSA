*****
depth child node me entry se phele, niche jate time --- depth = depth[vertex]+1;
height child node se exit ke baad, uper aate time  --- height = max(height[vertex],height[child]+1)
Subtree ke action uper aate time hote hai

Considering height and level of root node is zero.
1) The maximum number of nodes at level ‘l’ of a binary tree is 2l. 
2) The Maximum number of nodes in a binary tree of height ‘h’ is 2^(h+1) – 1
3) In a Binary Tree with N nodes, minimum possible height or the minimum number of levels is Log2(N+1)-1;
4) A Binary Tree with L leaves has at least |Log2L| levels.
5) In Binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children.
6) In a non empty binary tree, if n is the total number of nodes and e is the total number of edges, then e = n-1 

*****
> ineorder - jo mila stack me, curr-> null top print krdo, right me jao
> preorder - jo mila print kro right ko stack me rkho, curr -.Null to st se right uthao
> post
