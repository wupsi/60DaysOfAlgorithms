class Solution {
public:
    
    int searchInsert(vector<int>& v, int x) {

        if(x < v[0]) return 0;
        if(x > v[v.size() - 1]) return v.size();
        
        int first = 0, last = v.size() - 1, mid;
        
        while(true){
            mid = (first + last) / 2;
            
            if(first > last) return mid + 1;
            
            if(x > v[mid]) first = mid + 1;
            else if(x < v[mid]) last = mid - 1;
            else return mid;
        
        }
    }
};