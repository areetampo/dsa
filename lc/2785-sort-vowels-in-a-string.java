class Solution {
    public String sortVowels(String s) {
        char[] str = s.toCharArray();
        
        HashSet<Character> vowelSet = new HashSet<>(Set.of('A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'));
        
        ArrayList<Character> vowelOrder = new ArrayList<>();
        for (Iterator<Character> i = vowelSet.iterator(); i.hasNext(); ) {
            vowelOrder.add(i.next());
        }
        Collections.sort(vowelOrder);
        
        
        HashMap<Character, Integer> freq = new HashMap<>();
        
        for (char ch : str) {
            if (vowelSet.contains(ch))
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }
        for (Iterator<Character> i = vowelSet.iterator(); i.hasNext(); ) {
            char theChar = i.next();
            freq.put(theChar, freq.getOrDefault(theChar, 0));
        }
        
        int idx = 0;
        for (int i = 0; i < str.length; i++) {
            if (vowelSet.contains(str[i])) {
                while (freq.get(vowelOrder.get(idx)) == 0) idx++;
                str[i] = vowelOrder.get(idx);
                freq.put(vowelOrder.get(idx), freq.get(vowelOrder.get(idx)) - 1);
            }
            
        }
        
        return new String(str);
    }
}