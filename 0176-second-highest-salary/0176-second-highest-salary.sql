# Write your MySQL query statement be
select max(salary) as SecondhighestSalary 
from Employee where salary < (select max(salary) from Employee);