select T1.user_id, 
round(T1.avg_trial, 2) as trial_avg_duration,
round(T2.avg_paid, 2) as paid_avg_duration
from 
(select user_id, avg(1.0*activity_duration) as avg_trial 
from UserActivity where activity_type = 'free_trial' 
group by user_id) T1
join 
(select user_id, avg(1.0*activity_duration) as avg_paid 
from UserActivity where activity_type = 'paid' 
group by user_id) T2
on T1.user_id = T2.user_id
