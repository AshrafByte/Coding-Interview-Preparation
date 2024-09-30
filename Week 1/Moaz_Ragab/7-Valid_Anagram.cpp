class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26] = {0}, arr2[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            arr1[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            arr2[t[i] - 'a']++;
        }
        int i = 0;
        while (i < 26) {
            char c1 = i;

            if (arr1[c1] != arr2[c1]) {
                return false;
            }
            i++;
        }
        return true;
    }
};