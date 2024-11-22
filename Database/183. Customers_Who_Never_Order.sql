SELECT Name as Customers
FROM Customers
WHERE Id 
NOT IN ( SELECT customerId FROM Orders);
