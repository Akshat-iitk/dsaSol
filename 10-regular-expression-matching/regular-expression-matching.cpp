class Solution {
public:
    bool func(int ind1, int ind2, string& s, string& p) {

        // Both strings completely matched
        if (ind1 < 0 && ind2 < 0)
            return true;

        // Pattern exhausted but string remains
        if (ind2 < 0)
            return false;

        // String exhausted
        // Remaining pattern must consist entirely of x* pairs
        if (ind1 < 0) {
            if (ind2 >= 1 && p[ind2] == '*')
                return func(ind1, ind2 - 2, s, p);

            return false;
        }

        // Current pattern character is '*'
        if (p[ind2] == '*') {

            // '*' cannot be the first character
            if (ind2 == 0)
                return false;

            // Option 1: use x* as zero occurrences
            bool ans = func(ind1, ind2 - 2, s, p);

            // Option 2: consume one character if it matches x
            if (p[ind2 - 1] == '.' || p[ind2 - 1] == s[ind1]) {
                ans = ans || func(ind1 - 1, ind2, s, p);
            }

            return ans;
        }

        // Current characters match
        if (p[ind2] == '.' || p[ind2] == s[ind1]) {
            return func(ind1 - 1, ind2 - 1, s, p);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return func(s.size() - 1, p.size() - 1, s, p);
    }
};
