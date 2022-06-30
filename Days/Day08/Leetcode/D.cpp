class Solution {
public:
    int BinarySearch(vector<int>& vec, int size, int value){
        if(vec.empty()) return false;
        int first = 0, last = size - 1, mid;
        
        if(size == 1){
            if(vec[0] == value) return 0;
            return -1;
        }
        
        while(true){
            mid = (first + last) / 2;

            if(value < vec[first] or value > vec[last] or first > last)
                return -1;

            if(value > vec[mid])
                first = mid + 1;
            else if(value < vec[mid])
                last = mid - 1;
            else
                return mid;
        }
    }
    
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        vector<int> v;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        for(int i = 0; i < v1.size(); i++){
            if(v2.empty()) return v;
            int find = BinarySearch(v2, v2.size(), v1[i]);
            if(find != -1){
                v.push_back(v1[i]);
                v2.erase(v2.begin() + find);
            }
        }
        
        return v;
    }
};