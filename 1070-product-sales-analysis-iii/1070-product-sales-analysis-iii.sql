SELECT s.product_id,
       s.first_year,
       s.quantity,
       s.price
FROM (
    SELECT product_id,
           year,
           quantity,
           price,
           MIN(year) OVER(PARTITION BY product_id) AS first_year
    FROM sales
) AS s
WHERE year = first_year;