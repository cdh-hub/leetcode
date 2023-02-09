/*
 * @lc app=leetcode.cn id=1797 lang=java
 *
 * [1797] 设计一个验证系统
 */

// @lc code=start
class AuthenticationManager {
    private int timeToLive;
    HashMap<String, Integer> map1;
    TreeMap<Integer, List<String>> map2;
    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
        map1 = new HashMap<>();
        map2 = new TreeMap<>();
    }
    
    public void generate(String tokenId, int currentTime) {
        update(currentTime);
        map1.put(tokenId, currentTime + timeToLive);
        if (map2.containsKey(currentTime + timeToLive)) {
            map2.get(currentTime + timeToLive).add(tokenId);
        }
        else {
            List<String> l = new ArrayList<>();
            l.add(tokenId);
            map2.put(currentTime + timeToLive, l);
        }
    }
    
    public void renew(String tokenId, int currentTime) {
        update(currentTime);
        if (map1.containsKey(tokenId)) {
            map1.put(tokenId, currentTime + timeToLive);
            if (map2.containsKey(currentTime + timeToLive)) {
                map2.get(currentTime + timeToLive).add(tokenId);
            }
            else {
                List<String> l = new ArrayList<>();
                l.add(tokenId);
                map2.put(currentTime + timeToLive, l);
            }
        }
    }
    
    public int countUnexpiredTokens(int currentTime) {
        update(currentTime);
        return map1.size();
    }

    private void update(int currentTime) {
        while (!map2.isEmpty() && map2.firstKey() <= currentTime) {
            for (String s: map2.firstEntry().getValue()) {
                if (map1.containsKey(s) && map1.get(s) <= currentTime) map1.remove(s);
            }
            map2.remove(map2.firstKey());
        }
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */
// @lc code=end

