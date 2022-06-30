class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int first = 0, last = letters.size() - 1, mid;
        char x = '0';
        if(letters[last] <= target or letters[first] > target) return letters[0];
        
        
        while(true){
            mid = (first + last) / 2;
            if(first > last){
                x = letters[mid];
                break;
            }
            
            if(target > letters[mid]) first = mid + 1;
            else if(target < letters[mid]) last = mid - 1;
            else{
                x = letters[mid];
                break;                
            }
        }
        
        while(x == letters[mid]) ++mid;
        return letters[mid];
    }
};