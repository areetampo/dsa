class Solution {
    //O(num of words * word length * 26) time, O(num of words * word length * 26) space for new Strings created
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> hsOfWords = new HashSet<>();//all words of list
        HashSet<String> alrTaken = new HashSet<>();//words alr taken from list and added to queue | otherwise
        for (int i = 0; i < wordList.size(); i++) {//adding all words in hsOfWords for constant lookup time
            hsOfWords.add(wordList.get(i));
        }
        Queue<String> q = new LinkedList<>();
        q.add(beginWord); 
        alrTaken.add(beginWord);
        q.add("");
        int count = 1;
        //count = ans -> starting from begin word (strings in path = 1), when null in q -> 2nd String in counted in path
        char[] diff;//for creation of various strings with single letter diff
        String diffStr;//to convert the charArray to string and check if present in hsOfWords
        char thatIdxOrigChar;
        //to store the letter to be changed + not make same string + change it back again going to next letter
        String peek;
        while (!q.isEmpty()) {
            peek = q.remove();
            if (peek.equals("")) {
                if (q.isEmpty()) return 0;//endWord not found and queue got empty means no path exists
                count++; q.add("");//strings still in q so update count++ for next path
            }
            else if (peek.equals(endWord)) break;
            else {
                diff = peek.toCharArray();
                for (int i = 0; i < diff.length; i++) {
                    thatIdxOrigChar = diff[i];
                    for (int j = 0; (j < 26); j++) {
                        if (j == thatIdxOrigChar-'a') continue;//orig word only
                        diff[i] = (char) (j + 97);
                        diffStr = new String(diff);
                        if (hsOfWords.contains(diffStr) && !alrTaken.contains(diffStr))
                        q.add(diffStr); alrTaken.add(diffStr);
                    }
                    diff[i] = thatIdxOrigChar;
                }
            }
        }
        return count;
    }
}