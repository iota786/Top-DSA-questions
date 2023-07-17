# Write your MySQL query statement below
#select customer_id from Customer as c inner join Product as p on c.product_key=p.product_key;
select customer_id
from customer c
group by customer_id
having count(distinct product_key)=(select count(distinct product_key) from product)
