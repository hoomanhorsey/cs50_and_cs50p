
-- In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.

SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = "Helena Bonham Carter" AND movie_id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Johnny Depp"))) ORDER BY title;

-- SELECT * FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter';



-- sqlite> SELECT * FROM people JOIN stars ON person_id = people.id WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter';

-- SELECT *  FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Johnny Depp" OR name =  "Helena Bonham Carter"));

-- SELECT id FROM people WHERE name = "Johnny Depp" OR name = "Helena Bonham Carter";


 -- PSEUDOCODE

 -- SELECT title FROM movie ....WHERE ......name = 'Johnny Depp' AND 'Helena Bonham Carter'.


 -- SELECT * FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON stars.movie_id = movies.id WHERE name = 'Johnny Depp' OR name = 'Helena Bonham Carter';










