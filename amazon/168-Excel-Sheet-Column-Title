class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int original = columnNumber;
         while (columnNumber > 26) {
            int divide = columnNumber / 26;
            int r = columnNumber % 26;

            if (columnNumber % 26 != 0) {
                char c;
                char c2;

                if (divide <= 26)
                    c = divide + 64;

                if (r)
                    c2 = r + 64;

                if (r)
                    ans = c2 + ans;

                if (divide <= 26)
                    ans = c + ans;
            } else {
                divide--;
                char c1 = divide + 64;
                char c2 = 'Z';

                if (divide <= 26)
                    c1 = divide + 64;

                ans = c2 + ans;

                if (divide <= 26)
                    ans = c1 + ans;
            }
            columnNumber = divide;
        }

        if (original <= 26) {
            char c = original + 64;
            ans += c;
        }

        return ans;
    }
};
