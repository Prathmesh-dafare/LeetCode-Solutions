class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        // if endWord not present, impossible
        if (!st.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (st.count(word)) {
                            q.push(word);
                            st.erase(word); // avoid revisiting
                        }
                    }

                    word[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};