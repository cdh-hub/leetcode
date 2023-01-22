--
-- @lc app=leetcode.cn id=569 lang=mysql
--
-- [569] 员工薪水中位数
--

-- @lc code=start
# Write your MySQL query statement below
-- select * from Employee e1
-- left join Employee e2 on e1.company = e2.company and e1.salary <= e2.salary
-- left join Employee e3 on e1.company = e3.company and e1.salary >= e3.salary
-- group by e1.company
-- having count(e2.salary) - count(e3.salary) between -1 and 1
select t1.id, t1.company, e3.salary from 
    (select e1.id, e1.company, count(e2.salary) c from Employee e1, Employee e2
    where e1.company = e2.company and e1.salary <= e2.salary
    group by e1.id, e1.company) t1, 
    (select e1.id, e1.company, count(e2.salary) c from Employee e1, Employee e2
    where e1.company = e2.company and e1.salary >= e2.salary
    group by e1.id, e1.company) t2, Employee e3
where t1.id = t2.id and t1.id = e3.id and t1.company = t2.company and t1.company = e3.company and t1.c - t2.c between -1 and 1


-- @lc code=end

