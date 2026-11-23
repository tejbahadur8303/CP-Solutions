
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node) {

        char ch = board[i][j];

        if(ch == '#' || node->children[ch - 'a'] == nullptr)
            return;

        node = node->children[ch - 'a'];

        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";  // Avoid duplicates
        }

        board[i][j] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 &&
               ni < board.size() &&
               nj < board[0].size()) {

                dfs(board, ni, nj, node);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for(string word : words) {
            insert(word);
        }

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};
