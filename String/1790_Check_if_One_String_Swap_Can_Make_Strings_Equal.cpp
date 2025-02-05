class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;  

        vector<int> mismatchIndices;

       
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                mismatchIndices.push_back(i);
                if (mismatchIndices.size() > 2)  
                    return false;
            }
        }

        return mismatchIndices.size() == 2 &&
               s1[mismatchIndices[0]] == s2[mismatchIndices[1]] &&
               s1[mismatchIndices[1]] == s2[mismatchIndices[0]];
    }
};
