class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int testedDevices = 0;
        for (int i = 0; i < batteryPercentages.length; ++i) {
            if (batteryPercentages[i] - testedDevices <= 0) continue;
            else testedDevices++;
        }
        return testedDevices;
    }
}