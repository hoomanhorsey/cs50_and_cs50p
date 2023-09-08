
SELECT DISTINCT name FROM stars JOIN people ON stars.person_id = people.id WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004) ORDER BY birth;
-- ALTERNATIVE SOLUTION, NO JOINING
-- SELECT name FROM people WHERE people.id in(SELECT stars.person_id FROM stars WHERE stars.movie_id in (SELECT movies.id FROM movies WHERE year = 2004)) ORDER BY birth;