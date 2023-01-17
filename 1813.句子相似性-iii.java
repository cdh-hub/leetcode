/*
 * @lc app=leetcode.cn id=1813 lang=java
 *
 * [1813] 句子相似性 III
 */

// @lc code=start
class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] sentences1 = sentence1.split(" ");
        String[] sentences2 = sentence2.split(" ");
        int index1 = 0, index2 = 0;
        while (index1 < Math.min(sentences1.length, sentences2.length) && sentences1[index1].equals(sentences2[index1])) index1++;
        while (Math.min(sentences1.length, sentences2.length) - index2 > 0 && sentences1[sentences1.length - index2 - 1].equals(sentences2[sentences2.length - index2 - 1])) index2++;
        if (index1 + index2 >= Math.min(sentences1.length, sentences2.length)) return true;
        return false;
    }
}
// @lc code=end

