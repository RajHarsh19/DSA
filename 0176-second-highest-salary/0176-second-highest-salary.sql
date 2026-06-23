# Write your MySQL query statement below
select MAX(Salary) as SecondHighestSalary from employee where salary < (select MAX(salary) from employee);