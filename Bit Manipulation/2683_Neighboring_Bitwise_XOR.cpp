class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res =0;
        for(int els: derived)
            res^=els;
        if(res)
            return false;
        else
            return true;
    }
};