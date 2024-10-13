//
// Created by Ahmed hesen on 10/13/2024.
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return findbad(0, n);
    }
    int findbad(int start, int end){
        int mid = start + (end - start)/2;
        if(start==end) return start;
        if(isBadVersion(mid)) return findbad(start, mid);
        else return findbad(mid+1, end);
    }
};