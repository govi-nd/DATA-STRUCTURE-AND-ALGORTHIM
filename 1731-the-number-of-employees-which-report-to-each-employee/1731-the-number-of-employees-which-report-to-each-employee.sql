# Write your MySQL query statement below
select b.employee_id , b.name , count(a.employee_id) as reports_count , ROUND(AVG(a.age)) as average_age
from employees as a
 left join employees as b
on a.reports_to = b.employee_id
group by b.employee_id
having b.employee_id IS NOT NULL 
order by b.employee_id;