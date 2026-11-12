class Solution {
    private static class customComparator implements Comparator<Integer> {
        @Override 
        public int compare(Integer a, Integer b) {
            int aBits = 0;
            int bBits = 0;
            int aCopy = a;
            int bCopy = b;
            while (aCopy != 0) {
                aCopy &= aCopy-1;
                aBits++;
            }
            while (bCopy != 0) {
                bCopy &= bCopy-1;
                bBits++;
            }
            return (aBits == bBits || aBits > bBits && a > b || aBits < bBits && a < b) ? a - b : b - a;
        }
    }
    public int[] sortByBits(int[] arr) {
        Integer[] ans = new Integer[arr.length];
        for (int i = 0; i < arr.length; ++i) ans[i] = arr[i];
        Arrays.sort(ans, new customComparator());
        for (int i = 0; i < arr.length; ++i) arr[i] = ans[i];
        return arr;
    }
}