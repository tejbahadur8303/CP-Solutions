
class Node {
public:
    Node *children[26];
    bool isEnd;

    Node() {
        isEnd = false;  // Corrected

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Node *root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *temp = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (!temp->children[i]) {
                temp->children[i] = new Node();
            }

            temp = temp->children[i];
        }

        temp->isEnd = true;
    }

    Node *walk(string s) {
        Node *temp = root;

        for (char ch : s) {
            int i = ch - 'a';

            temp = temp->children[i];

            if (!temp) {
                return NULL;
            }
        }

        return temp;
    }

    bool search(string word) {
        Node *temp = walk(word);
        return temp && temp->isEnd;
    }

    bool startsWith(string prefix) {
        return walk(prefix) != NULL;
    }
};
