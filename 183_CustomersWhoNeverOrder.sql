# Write your MySQL query statement below
SELECT c.name AS Customers
From Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
WHERE o.id IS NULL