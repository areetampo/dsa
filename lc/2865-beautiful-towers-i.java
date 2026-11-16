class Solution {
    public long maximumSumOfHeights(List<Integer> maxHeights) {
        int n = maxHeights.size();
        long ans = 0;
        
        for (int i = 0; i < maxHeights.size(); i++) {
            long currAns = 0;
            int currPeak = maxHeights.get(i);

            int prevMax = currPeak;
            for (int j = i-1; j >= 0; j--) {//0 <-> max-1, prevMax = previous max of the right 
                prevMax = Math.min(prevMax, maxHeights.get(j));
                currAns += prevMax;
            }

            prevMax = currPeak;
            for (int j = i+1; j < n; j++) {//max+1 <-> n-1, prevMax = previous max of the left 
                prevMax = Math.min(prevMax, maxHeights.get(j));
                currAns += prevMax;
            }

            currAns += currPeak;
            
            ans = Math.max(ans, currAns);
        }
        
        return ans;
    }
}