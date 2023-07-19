# SELECT ifnull(max(salary), null) AS SecondHighestSalary
# FROM employee 
# WHERE salary < (SELECT MAX(salary) FROM employee);

select (select distinct salary from employee order by salary desc limit 1 offset 1 ) as SecondHighestSalary;