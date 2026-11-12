class Solution {
    // O(Math.min(version1.length(), version2.length()) time. O(1) space.
    public int compareVersion(String version1, String version2) {
        int firstIdx = 0, secondIdx = 0;
        while (firstIdx < version1.length() || secondIdx < version2.length()) {
            // Parse current revision number in version1, or use 0 if there isn't one.
            // Note that leading 0's are just ignored.
            int first = 0;
            while (firstIdx < version1.length() && Character.isDigit(version1.charAt(firstIdx))) {
                first = first * 10 + version1.charAt(firstIdx++) - '0';
            }
            
            // Parse current revision number in version2, or use 0 if there isn't one.
            int second = 0;
            while (secondIdx < version2.length() && Character.isDigit(version2.charAt(secondIdx))) {
                second = second * 10 + version2.charAt(secondIdx++) - '0';
            }
            
            if (first != second) {
                //return first < second ? -1 : 1;
                return Integer.compare(first, second);  // The first unequal revision number determines the result of the comparison.
            } else {
                firstIdx++; secondIdx++;    // Skip the current '.' characters so we are ready to parse the next revision numbers.
            }
        }
        return 0;   // We didn't find an unequal revision number, so the two given versions must be equal.
    }
}