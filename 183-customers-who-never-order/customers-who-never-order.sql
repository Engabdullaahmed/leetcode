# Write your MySQL query statement below
# we need to choose from orderid table orderid  
# which match with id customer table  and not in

SELECT name as Customers
FROM Customers 
WHERE id NOT IN (SELECT customerId FROM Orders);