# Write your MySQL query statement below
SELECT name as Employee from Employee e1 WHERE(salary > 
(SELECT salary from Employee e2 WHERE (e2.id = e1.managerId) ))