class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans;
        int colLen = img.size();
        int rowLen = img[0].size();
        for (int i = 0; i < img.size(); i++) {
            vector<int> row;
            for (int j = 0; j < img[0].size(); j++) {
                int c = 1;
                long long sum = 0;
                sum += img[i][j];
                if (i - 1 >= 0) {
                    c++;
                    sum += img[i - 1][j];
                    if (j + 1 < rowLen) {
                        c++;
                        sum += img[i - 1][j + 1];
                    }
                }
                if (j - 1 >= 0) {
                    c++;
                    sum += img[i][j - 1];
                    if (i + 1 < colLen) {
                        c++;
                        sum += img[i + 1][j - 1];
                    }
                }

                if (j - 1 >= 0 && i - 1 >= 0) {
                    c++;
                    sum += img[i - 1][j - 1];
                }

                if (i + 1 < colLen) {
                    c++;
                    sum += img[i + 1][j];
                }
                if (j + 1 < rowLen) {
                    c++;
                    sum += img[i][j + 1];
                }

                if (i + 1 < colLen && j + 1 < rowLen) {
                    c++;
                    sum += img[i + 1][j + 1];
                }

                int val = sum / c;

                row.push_back(val);
            }

            ans.push_back(row);
        }

        return ans;
    }
};
