class Solution {
public:
    int firstUniqChar(string s) {
       int * arr = new int[26]();
       for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        int index = c - 'a';
        arr[index]++;
       } 

       for(int i = 0 ; i < s.length(); i++) {
        char c = s[i];
        int index = c - 'a';
        if(arr[index] == 1)
        return i;
       }

       return -1;
    }
};
