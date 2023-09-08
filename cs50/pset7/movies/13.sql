
-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.
-- Initial attemps
-- SELECT name FROM people WHERE people.id IN (SELECT stars.movie_id FROM stars WHERE stars.person_id IN (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth IS '1958')));

-- SELECT name FROM people WHERE people.id IN (SELECT stars.person_id FROM stars WHERE stars.movie_id IN (SELECT stars.movie_id FROM stars WHERE stars.person_id IN (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth IS '1958')));

 -- SELECT name FROM people WHERE people.id IN ( SELECT stars.person_id FROM stars JOIN people ON stars.movie_id = people.id WHERE (name != 'Kevin Bacon') IN (SELECT stars.person_id FROM stars WHERE stars.movie_id IN (SELECT stars.movie_id FROM stars WHERE stars.person_id IN (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth IS '1958'))));



-- name of people!

-- SELECT COUNT(name) FROM(

SELECT name FROM people WHERE name IS NOT "Kevin Bacon" AND people.id IN

-- (SELECT stars.person_id FROM stars JOIN people ON stars.movie_id = people.id IN

--  #alternative# (SELECT stars.person_id FROM stars JOIN people ON stars.movie_id = people.id WHERE (name = "%*%") AND (name != 'Kevin Bacon') IN

 -- person_ids of people starring in KB movies.
 (SELECT stars.person_id FROM stars WHERE stars.movie_id IN

 -- movie_ids for movies starring Kevin Bacon, based on people.id
 (SELECT stars.movie_id FROM stars WHERE stars.person_id IN

 -- selects Kevin's people.id
 (SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth IS '1958'--
 )
 )
 )
 ORDER BY name
-- )
 ;