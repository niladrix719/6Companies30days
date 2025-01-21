class Pair {

public:
    char ch;
    int freq = 0;

    Pair(char c) { ch = c; }
};

class Solution {
public:
    string frequencySort(string s) {
        string ans;
        vector<Pair> arr(128, 0);

        for (int i = 0; i < arr.size(); i++) {
            char c = char(i);
            Pair p(c);
            arr[i] = p;
        }

        for (int i = 0; i < s.size(); i++) {
            arr[s[i]].freq++;
        }

        sort(arr.begin(), arr.end(),
             [](const auto& a, const auto& b) { return a.freq > b.freq; });

        for (int i = 0; i < 128; i++) {
            int in = int(arr[i].ch);
            for (int j = 0; j < arr[i].freq; j++) {
                ans += arr[i].ch;
            }
        }

        return ans;
    }
};
