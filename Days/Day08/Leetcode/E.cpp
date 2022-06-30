/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        unsigned int first = 0, last = n - 1, mid;
        
        while(true){
            mid = (first + last) / 2;
            
            if(first > last) return mid + 1;
            
            if(guess(mid) == -1) last = mid - 1;
            else if(guess(mid) == 1) first = mid + 1;
            else return mid;
        }
    }
};