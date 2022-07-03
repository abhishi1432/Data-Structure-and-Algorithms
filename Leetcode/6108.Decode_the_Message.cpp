class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> mp;
        char ch = 'a';
        for(int i=0;i<key.size();i++){
            if(key[i]!=' '){
                if(mp.find(key[i])==mp.end())
                    mp[key[i]] = ch++;
            }
        }
        for(int i=0;i<message.size();i++){
            if(message[i]!=' ')
                message[i] = mp[message[i]];
        }
        return message;
    }
};
