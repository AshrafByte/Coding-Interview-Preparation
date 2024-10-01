class Solution {
public:
    string addBinary(string a, string b) {

        int x = a.size();
        int y = b.size();
        if (x > y) {
            int z = x - y;
            while (z--) {
                b = "0" + b;
            }
        } else if (y > x) {
            int z = y - x;
            while (z--) {
                a = "0" + a;
            }
        }
        string ans;
        int over = 0;
        int siz = max(x, y);
        siz--;
        for (; siz >= 0; siz--) {
            if (over) {
                if (a[siz] == '0' && b[siz] == '0') {
                    ans = "1" + ans;
                    over--;
                } else if (a[siz] == '1' && b[siz] == '1') {
                    ans = "1" + ans;

                } else {
                    ans = "0" + ans;
                }
            } else {
                if (a[siz] == '0' && b[siz] == '0') {
                    ans = "0" + ans;
                } else if (a[siz] == '1' && b[siz] == '1') {
                    ans = "0" + ans;
                    over++;
                } else {
                    ans = "1" + ans;
                }
            }
        }
        if (over == 1) ans = "1" + ans;
        return ans;
    }
};