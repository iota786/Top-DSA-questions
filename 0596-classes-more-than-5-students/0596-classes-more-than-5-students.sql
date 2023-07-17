# Write your MySQL query statement below
#select class from Courses where (select class,count(student) from Courses group by class) >=5;
select class from courses group by class having count( class) >= 5;