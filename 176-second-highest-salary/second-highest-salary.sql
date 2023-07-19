SELECT ifnull(max(salary), null) AS SecondHighestSalary
FROM employee 
WHERE salary < (SELECT MAX(salary) FROM employee);