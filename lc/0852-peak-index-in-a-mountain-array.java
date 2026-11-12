class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int s = 0; int e = arr.length-1;
        // int mid = s + (e-s)/2;
        while (s <= e) {
            if (arr[s+(e-s)/2 -1] < arr[s+(e-s)/2] && arr[s+(e-s)/2] > arr[s+(e-s)/2 + 1]) 
            return s+(e-s)/2;
            else if (arr[s+(e-s)/2 - 1] > arr[s+(e-s)/2]) e = s+(e-s)/2;
            else s = s+(e-s)/2;
            // mid = s + (e-s)/2;
        }
        return -1;
    }
}