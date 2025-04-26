SELECT score, 
       (SELECT COUNT(DISTINCT score) + 1 FROM Scores S2 WHERE S2.score > S1.score) AS 'rank'
FROM Scores S1 
ORDER BY score DESC;
