class Solution {
    public int longestMountain(int[] arr) {//O(n)
        if (arr.length < 3) return 0;
        int n = arr.length;

        int i = 0; int j = 0;
        int ans = 0;
        while (i <= n-3) {
            while (i < n-1 && arr[i] >= arr[i+1]) {//dec or equal sequence
                i++;
            }
            if (i >= n-2) return ans;//no mountain will be present now
            j = i;
            while (j < n-1 && arr[j] < arr[j+1]) j++;
            if (j == n-1) return ans;
            if (arr[j] == arr[j+1]) i = j+1;
            else {
                while (j < n-1 && arr[j] > arr[j+1]) j++;
                ans = Math.max(ans, j-i+1); 
            } 
            i = j;
        }
        return ans;
    }
}