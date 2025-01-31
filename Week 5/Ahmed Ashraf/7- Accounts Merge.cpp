class UnionFind {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> owner;

    // Find function with path compression
    string find(string email) {
        if (parent[email] != email) {
            parent[email] = find(parent[email]);
        }
        return parent[email];
    }

    // Union function
    void unionSets(string email1, string email2) {
        string parent1 = find(email1);
        string parent2 = find(email2);
        if (parent1 != parent2) {
            parent[parent2] = parent1;
        }
    }
};
class Solution
{
    public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        UnionFind uf;

        // Step 1: Initialize the parent and owner for each email
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (uf.parent.find(email) == uf.parent.end()) {
                    uf.parent[email] = email;
                    uf.owner[email] = name;
                }
                uf.unionSets(account[1], email); // Union all emails in the same account
            }
        }

        // Step 2: Group emails by their root parent
        unordered_map<string, vector<string>> groups;
        for (const auto& [email, _] : uf.parent) {
            string root = uf.find(email);
            groups[root].push_back(email);
        }

        // Step 3: Format the result
        vector<vector<string>> result;
        for (const auto& [root, emails] : groups) {
            vector<string> account;
            account.push_back(uf.owner[root]); // Add the owner's name
            account.insert(account.end(), emails.begin(), emails.end());
            sort(account.begin() + 1, account.end()); // Sort the emails
            result.push_back(account);
        }

        return result;
    }
};