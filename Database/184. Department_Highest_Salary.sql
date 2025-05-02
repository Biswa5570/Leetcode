select D.name Department, E1.name Employee, Salary 
from Employee E1 join Department D on E1.departmentId = D.id
where salary = (select max(salary) 
from Employee E2 where E2.departmentId = E1.departmentId)
