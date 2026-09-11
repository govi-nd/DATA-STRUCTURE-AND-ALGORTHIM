# Write your MySQL query statement below

select name , bonus 
from employee as e
 left join bonus as b
 on e.empId = b.empID 
 where b.bonus < 1000 OR b.bonus is null ;
 