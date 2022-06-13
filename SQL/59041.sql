-- MySQL
SELECT a.NAME as NAME, a.CNT as COUNT FROM (SELECT NAME, COUNT(NAME) AS CNT FROM ANIMAL_INS WHERE NAME IS NOT NULL GROUP BY NAME) a WHERE CNT > 1 ORDER BY NAME ASC;