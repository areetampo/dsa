class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        ArrayList<String> ans = new ArrayList<>();
        
        for (int i = 0; i < words.size(); i++) {
            String curr = words.get(i);
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < curr.length(); j++) {//"abc.mno.xyz"
                if (curr.charAt(j) == separator) {
                    if(sb.length() != 0)
                    ans.add(sb.toString());
                    sb.delete(0, sb.length());
                }
                else sb.append(curr.charAt(j));
            }
            if(sb.length() != 0)
            ans.add(sb.toString());//to add the last str segment
        }
        return ans;
    }
}