--
-- @lc app=leetcode.cn id=512 lang=mysql
--
-- [512] 游戏玩法分析 II
--

-- @lc code=start
# Write your MySQL query statement below
select player_id, device_id from Activity
where (player_id, event_date) in (
    select player_id, min(event_date)
    from Activity group by player_id)
-- @lc code=end

