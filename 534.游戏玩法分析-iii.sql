--
-- @lc app=leetcode.cn id=534 lang=mysql
--
-- [534] 游戏玩法分析 III
--

-- @lc code=start
# Write your MySQL query statement below
select a2.player_id, a2.event_date, sum(a1.games_played) games_played_so_far
from Activity a1, Activity a2
where a1.player_id = a2.player_id and a1.event_date <= a2.event_date
group by a2.player_id, a2.event_date
-- @lc code=end

