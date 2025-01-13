#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void merge(char * arr, int f, int mid, int l) {
        int len1 = mid + 1 - f;
        int len2 = l - mid;
        
        char arr1[len1];
        char arr2[len2];
        
        for(int i = 0; i < len1; i++) {
            arr1[i] = arr[i + f];
        }
        
        for(int i = 0; i < len2; i++) {
            arr2[i] = arr[i + mid + 1];
        }
        
        int p1 = 0;
        int p2 = 0;
        int index = f;
        
        while(p1 < len1 && p2 < len2) {
            if(arr1[p1] >= arr2[p2]) {
                arr[index] = arr2[p2];
                p2++;
                index++;
            }
            else {
                arr[index] = arr1[p1];
                p1++;
                index++;
            }
        }
        
        if(p1 == len1) {
            for(int i = p2; i < len2; i++) {
                arr[index] = arr2[i];
                index++;
            }
        }
        else {
            for(int i = p1; i < len1; i++) {
                arr[index] = arr1[i];
                index++;
            }
        }
    }
  
    void mergeSort(char * arr, int f, int l) {
        if(f >= l) return;
        
        int mid = (f + l) / 2;
        
        mergeSort(arr, f, mid);
        mergeSort(arr, mid + 1, l);
        
        merge(arr, f, mid, l);
    }

    void matchPairs(int n, char nuts[], char bolts[]) {
        int f = 0;
        int l = n - 1;

        mergeSort(nuts, f, l);
        mergeSort(bolts, f, l);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
