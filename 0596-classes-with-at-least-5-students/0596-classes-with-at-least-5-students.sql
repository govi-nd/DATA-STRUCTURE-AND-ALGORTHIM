SELECT  DISTINCT class
FROM (
    SELECT class,
           COUNT(student) OVER(
               PARTITION BY class
           ) AS no_of_students
    FROM courses
) AS c
where no_of_students>=5;