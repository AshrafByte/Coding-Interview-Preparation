//
// Created by Ahmed hesen on 10/13/2024.
//

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1, j=b.size()-1, carry=0, sum;
        string ans;
        while(i>=0 || j>=0){
            sum=carry;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            ans += to_string(sum%2);
            carry = sum/2;
        }
        if(carry) ans+= to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};