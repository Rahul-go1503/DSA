#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        unordered_map<char,int> freq;
        char ans = str[0];
        int mx = 1;
        for(auto &ch : str){
            freq[ch]++;
            if(freq[ch]>mx) ans = ch , mx = freq[ch];
            else if(freq[ch]==mx && ch < ans) ans = ch;
        }
        return ans;
    }

};

// have a look... when we have only char a-z

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        vector<int>hash(26,0);
        
        //using hash table to store count of each character.
        for(auto i: str)
        hash[i-'a']++;
        int maxi = 0;
        char ch;
        
        //iterating over the hash table.
        for(int i = 0; i < 26; i++)
        {
            //we keep storing the maximum value in hash 
            //table and its corresponding character.
            if(hash[i] > maxi){
                maxi = hash[i];
                ch = i + 'a';
            }
        }
        //returning the character with maximum occurrences.
        return ch;
    }
};