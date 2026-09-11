# Write your MySQL query statement below
select w.id 
from weather as w
join weather as wt 
on wt.recordDate = DATE_SUB(w.recordDate,INTERVAL 1 DAY)
where w.temperature > wt.temperature;