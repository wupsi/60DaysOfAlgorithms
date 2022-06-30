class Solution {
public:
    bool BinarySearch(vector<int>& vec, int size, int value){
        if(vec.empty()) return false;
        int first = 0, last = size - 1, mid;
        
        while(true){
            mid = (first + last) / 2;

            if(value < vec[first] or value > vec[last] or first > last)
                return false;

            if(value > vec[mid])
                first = mid + 1;
            else if(value < vec[mid])
                last = mid - 1;
            else
                return true;
        }
    }
    
    vector<int> intersection(vector<int>& v1, vector<int>& v2) {
        vector<int> v;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        
        for(int i = 0; i < v1.size(); i++){
            bool inv2 = BinarySearch(v2, v2.size(), v1[i]);
            if(inv2){
                bool inv = BinarySearch(v, v.size(), v1[i]);
                if(!inv) v.push_back(v1[i]);
            }
        }
        
        return v;
    }
};