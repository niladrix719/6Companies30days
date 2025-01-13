#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* l = head;
        Node* r = head;
        
        while(r -> next != NULL) {
            for(int i = 0; i < m - 1; i++) {
            l = l -> next;
            r = r -> next;
            
            if(r == NULL)
            return head;
        }
        
        for(int i = 0; i < n + 1; i++) {
            r = r -> next;
            
            if(r == NULL){
            l -> next = NULL;
            return head;
            }
        }
        
        l -> next = r;
        l = r;
        }
        
        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }

        int n = arr2[0], m = arr2[1];

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node* head = new Node(arr[0]);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        head = ob.linkdelete(head, n, m);
        printList(head);

        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}
