class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
        return false;

        int[] freq = new int[26];
        Arrays.fill(freq, 0);
        for (int i = 0; i < s.length(); i++) {//not returned false above so means same size 
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }
        for (int i : freq) {
            if (i != 0) 
            return false;
        }
        return true;
    }
}
// if (s.length() != t.length())
// return false;
// HashMap<Character, Integer> hm = new HashMap<>();
// for (int i = 0; i < s.length(); i++) {//means length same if reached here
//     hm.put(s.charAt(i), hm.getOrDefault(s.charAt(i), 0) + 1);
//     hm.put(t.charAt(i), hm.getOrDefault(t.charAt(i), 0) - 1);
// }
// for (Character keys : hm.keySet()) {
//     if (hm.get(keys) != 0) 
//     return false;
// }
// return true;

//OR REMOVING KEY METHOD

// if (s.length() != t.length())
// return false;
// HashMap<Character, Integer> hm = new HashMap<>();
// for (int i = 0; i < s.length(); i++) {
//     hm.put(s.charAt(i), hm.getOrDefault(s.charAt(i), 0) + 1);
// }
// for (int i = 0; i < t.length(); i++) {
//     if (hm.containsKey(t.charAt(i))) {
//         if (hm.get(t.charAt(i)) > 1)
//         hm.put(t.charAt(i), hm.get(t.charAt(i)) - 1);
//         else hm.remove(t.charAt(i));
//     }
//     else return false;
// }
// return hm.isEmpty();