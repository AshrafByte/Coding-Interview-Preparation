class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, string> parent;
        
        function<string(string)> find = [&](string s) {
            return parent[s] == s ? s : parent[s] = find(parent[s]);
        };
        
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                emailToName[account[i]] = name;
                if (parent.find(account[i]) == parent.end()) {
                    parent[account[i]] = account[i];
                }
                parent[find(account[i])] = find(account[1]);
            }
        }
        
        unordered_map<string, set<string>> unions;
        for (auto& email : parent) {
            unions[find(email.first)].insert(email.first);
        }
        
        vector<vector<string>> result;
        for (auto& group : unions) {
            vector<string> emails(group.second.begin(), group.second.end());
            emails.insert(emails.begin(), emailToName[group.first]);
            result.push_back(emails);
        }
        
        return result;
    }
};