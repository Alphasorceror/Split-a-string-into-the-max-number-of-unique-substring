class Solution {
public:
    unordered_set<string> A;
int maxUniqueSplit(string &s, int p = 0) {
    if (p == s.size())
        return 0;
    int res = -1;
    for (int i = 1; p + i <= s.size(); ++i) {
        auto B = A.insert(s.substr(p, i));
        if (B.second) {
            int n_res = maxUniqueSplit(s, p + i);
            if (n_res != -1)
                res = max(res, 1 + n_res);
            A.erase(B.first);
        }    
    }
    return res;
}
};
