class Solution {
public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* l = head;
        Node* r = head;

        while (r->next != NULL) {
            for (int i = 0; i < m - 1; i++) {
                l = l->next;
                r = r->next;

                if (r == NULL)
                    return head;
            }

            for (int i = 0; i < n + 1; i++) {
                r = r->next;

                if (r == NULL) {
                    l->next = NULL;
                    return head;
                }
            }

            l->next = r;
            l = r;
        }

        return head;
    }
};
