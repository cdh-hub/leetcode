class Solution {
    private HashMap<String, String> hm = new HashMap<>();
    private String find(String s) {
        if (s.equals(hm.get(s))) return s;
        String s1 = find(hm.get(s));
        hm.put(s, s1);
        return s1;
    }
    private void union(String s1, String s2) {
        hm.put(find(s1), find(s2));
    }
    public boolean areSentencesSimilarTwo(String[] sentence1, String[] sentence2, List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) return false;
        int n = sentence1.length;
        for (List<String> similarPair: similarPairs) {
            if (!hm.containsKey(similarPair.get(0))) hm.put(similarPair.get(0), similarPair.get(0));
            if (!hm.containsKey(similarPair.get(1))) hm.put(similarPair.get(1), similarPair.get(1));
            union(similarPair.get(0), similarPair.get(1));
        }
        for (int i = 0; i < n; i++) {
            if (!hm.containsKey(sentence1[i])) hm.put(sentence1[i], sentence1[i]);
            if (!hm.containsKey(sentence2[i])) hm.put(sentence2[i], sentence2[i]);
            if (!find(sentence1[i]).equals(find(sentence2[i]))) return false;
        }
        return true;
    }
}