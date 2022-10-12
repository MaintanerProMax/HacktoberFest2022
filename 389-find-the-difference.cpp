class Solution {
public:
    // Using Ascii values
    char findTheDifference(string s, string t) {
        int s1 = 0;
        for(int i=0;i<s.length();i++){
            s1 += (int)s[i];
        }
        int t1 = 0;
        for(int i=0;i<t.length();i++){
            t1 += (int)t[i];
        }
        
        int diff = abs(t1 - s1);
        return (char)diff;
    }
};
