class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)return 0;
        set<string>wordSet(wordList.begin(),wordList.end());
        if(!wordSet.count(endWord))return 0;
        queue<string>q;
        q.push(beginWord);
        set<string>st;
        st.insert(beginWord);
        int t = 1;
        while(q.size()){
            int n = q.size();
            t++;
            // cout<<n<<endl;
            // cout<<t<<endl;
            for(int i=0;i<n;i++){
                string str = q.front();q.pop();
                //cout<<str<<endl;
                for(int i=0;i<str.size();i++){
                    char ogch = str[i];
                    for(char ch='a';ch<='z';ch++){
                        str[i]=ch;
                        //cout<<str<<" ";
                        if(wordSet.count(str)){\
                            if(str==endWord)return t;
                            if(!st.count(str)){
                                st.insert(str);
                                q.push(str);
                            }
                        }
                        str[i]=ogch;
                    }
                }
            }
        }
        return 0;
    }
};
