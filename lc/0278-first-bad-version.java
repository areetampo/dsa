/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        //api knows which is the bad version
        int start = 1, end = n;
        int mid = (end-start)/2 + start;
        while (start <= end) {
            mid = (end-start)/2 + start;
            if (isBadVersion(mid)) {//true means 'a' bad version found
                end = mid - 1;//bad num found but look for before also
            }
            else {
                start = mid + 1;//bad not found so look for after 
            }
        }
        return start;//for testcase when n = 3 and bad veersion = 2 :-
        // s = 1, e = 3
        // m = 2
        // 2 is the bad version doing e - 1 so e = 1 and s = 1
        // m = 1 
        // 1 is not bad version doing s + 1 so s = 2 and e = 1
        // as s <= e is false and s exceeded e
        // returning s

        // also when mid = (s+e)/2 is returned when either mid found or s==e then correct
        // but in case of s becoming > e, we return the s 


    }
}