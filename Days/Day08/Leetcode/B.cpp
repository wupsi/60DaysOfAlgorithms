// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int first = 0, last = n - 1, mid;
        
        while(true){
            mid = (first + last) / 2;
            if(first > last)
                return mid + 1;
            
            if(isBadVersion(mid)) last = mid - 1;
            else first = mid + 1;
        }
    }
};