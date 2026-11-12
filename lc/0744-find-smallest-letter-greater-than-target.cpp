class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0, j = letters.size() -1;
        int mid;
        while (i <= j) {
            mid = (i+j)/2;
            if (target == letters[mid]) {
                if (letters[mid] == letters[letters.size() - 1])//means target is last element 
                return letters[0];
                else {
                    for (int k = mid; k < letters.size(); k++) {
                        if (letters[k] != letters[mid])
                        return letters[k];
                    }
                }
            }
            if (target > letters[mid])
            i = mid + 1;
            else j = mid -1;
        }
        if (letters[mid] > target) {
            return letters[mid];
        }
        else return letters[ (mid+1) % (letters.size()) ];
    }
};