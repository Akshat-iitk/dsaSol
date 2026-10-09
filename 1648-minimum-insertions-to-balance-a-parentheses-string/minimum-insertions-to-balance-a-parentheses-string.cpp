class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int flag = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (flag % 2 == 1) {
                    ans++;
                    flag--;
                }
                flag += 2;
            } else {
                flag--;

                if (flag < 0) {
                    ans++;
                    flag = 1;
                }
            }
        }

        return ans + flag;
    }
};