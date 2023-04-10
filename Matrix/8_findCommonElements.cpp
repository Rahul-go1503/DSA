#include<bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    unordered_set<int> s1;
    for(int i=0;i<m;i++) s1.insert(mat[0][i]);

    for(int i=1;i<n;i++){
        unordered_set<int> s2;
        for(int j=0;j<m;j++){
            if(s1.count(mat[i][j])) s2.insert(mat[i][j]);
        }
        s1 = s2;
    }

    vector<int> res(s1.size());
    int i = 0;
    for(auto &x : s1) res[i++] = x;
    return res;
}

// A Program to prints common element in all
// rows of matrix
#include <bits/stdc++.h>
using namespace std;

// Specify number of rows and columns
#define M 4
#define N 5

// prints common element in all rows of matrix
void printCommonElements(int mat[M][N])
{
    unordered_set<int> s1;

	// inserting 1st row elements
    for(int i=0;i<N;i++) s1.insert(mat[0][i]);

	// traverse the matrix
    for(int i=1;i<M;i++)
    {
        // set 2 is used to store common elements between row i-1 & i;
        unordered_set<int> s2;
        for(int j=0;j<N;j++)
        {
            // if element is present in the set1 insert into set 2
            if(s1.count(mat[i][j])) s2.insert(mat[i][j]);
        }
        s1 = s2;
    }


    // printing the output
    for(auto &x : s1) cout<<x<<" ";
}

// driver program to test above function
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}

 /*
    Time Complexity: O(N*M)
    Space Complexity: O(M)
    
    Where 'N' and 'M' denotes the number of rows 
    and the number of columns in the matrix respectively.
*/

#include <unordered_map>

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Finding the number of rows and columns
    int n = mat.size();
    int m = mat[0].size();

    // Defining the HashMap to store common elements
    unordered_map<int, int> commonElements;

    // Adding the elements of first row to HashMap
    for (int j = 0; j < m; j++)
    {
        commonElements[mat[0][j]] = 1;
    }

    // Iterating through the elements of the matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Checking whether the current element is present in all the previously traversed rows
            if (commonElements.find(mat[i][j]) != commonElements.end() && commonElements[mat[i][j]] == i)
            {
                commonElements[mat[i][j]]++;
            }
        }
    }

    // Defining the output array
    vector<int> ans;

    // Traversing the HashMap
    for (pair<int, int> p : commonElements)
    {
        // Adding all elements that are present in all the matrix rows to the output array
        if (p.second == n)
        {
            ans.push_back(p.first);
        }
    }

    // Returning the output array
    return ans;
}
