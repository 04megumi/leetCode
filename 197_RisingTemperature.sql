select w1.id
from Weather w1, Weather w2
where w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY) and w1.Temperature > w2.Temperature