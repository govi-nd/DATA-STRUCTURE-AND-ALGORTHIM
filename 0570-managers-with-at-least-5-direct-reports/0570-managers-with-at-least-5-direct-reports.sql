SELECT b.name as name
FROM employee AS a
LEFT JOIN employee AS b
ON a.managerId = b.id
group by b.name 
 having count(b.id)>=5;
