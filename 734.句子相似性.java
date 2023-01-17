class Solution {
    public boolean areSentencesSimilar(String[] sentence1, String[] sentence2, List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) return false;
        int n = sentence1.length;
        HashMap<String, HashSet<String>> hm = new HashMap<String, HashSet<String>>();
        for (List<String> similarPair : similarPairs) {
            if (hm.containsKey(similarPair.get(0))) hm.get(similarPair.get(0)).add(similarPair.get(1)); 
            else {
                HashSet<String> hs = new HashSet<String>();
                hs.add(similarPair.get(1));
                hm.put(similarPair.get(0), hs);
            }
            if (hm.containsKey(similarPair.get(1))) hm.get(similarPair.get(1)).add(similarPair.get(0)); 
            else {
                HashSet<String> hs = new HashSet<String>();
                hs.add(similarPair.get(0));
                hm.put(similarPair.get(1), hs);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!sentence1[i].equals(sentence2[i]) && (!hm.containsKey(sentence1[i]) || !hm.get(sentence1[i]).contains(sentence2[i]))) return false;
        }
        return true;
    }
}