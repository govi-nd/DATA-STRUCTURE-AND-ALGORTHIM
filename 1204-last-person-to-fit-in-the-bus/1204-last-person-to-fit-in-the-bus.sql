SELECT person_name
FROM (
    SELECT turn,
           person_name,
           SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
) AS q
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;