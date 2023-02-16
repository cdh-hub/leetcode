--
-- @lc app=leetcode.cn id=1412 lang=mysql
--
-- [1412] 查找成绩处于中游的学生
--

-- @lc code=start
# Write your MySQL query statement below
select student_id, student_name from student
where student_id in (
    select student_id from exam
)
and student_id not in (
    select student_id from exam e
    where score >= all(
        select score from exam where e.exam_id = exam_id
    ) or score <= all(
        select score from exam where e.exam_id = exam_id
    )
)
-- @lc code=end

