/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();

        //finding the peak element in mountain array
        int s = 0, e = n-1, m = -1;
        while (s < e) {
            m = s + (e-s)/2;
            int el = mountainArr.get(m);
            int el1 = mountainArr.get(m+1);
            if (el1 > el) {
                s = m+1;
            }
            else e = m;
        }

        int idx = s;//index of peak element in mountain array

        //finding if target exists in left half
        s = 0; e = idx; m = -1;
        while (s <= e) {
            m = s + (e-s)/2;
            int el = mountainArr.get(m);
            if (target == el) return m;
            else if (target > el) s = m+1;
            else e = m-1;
        }

        //finding if target exists in right half
        s = idx+1; e = n-1; m = -1;
        while (s <= e) {
            m = s + (e-s)/2;
            int el = mountainArr.get(m);
            if (target == el) return m;
            else if (target > el) e = m-1;
            else s = m+1;
        }
        
        return -1;//target not present 
    }
}