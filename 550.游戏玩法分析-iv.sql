--
-- @lc app=leetcode.cn id=550 lang=mysql
--
-- [550] 游戏玩法分析 IV
--

-- @lc code=start
# Write your MySQL query statement below
select round((count(distinct a1.player_id) / (select count(distinct player_id) from Activity)), 2) fraction
from (select player_id, min(event_date) first_login from Activity group by player_id) a1, Activity a2
where a1.player_id = a2.player_id and datediff(a2.event_date, a1.first_login) = 1
-- @lc code=end

