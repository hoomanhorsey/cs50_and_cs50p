SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE (year = 2010) ORDER BY rating DESC, title;


-- Join version - doesn't work.
-- SELECT stars.movie_id, people.id FROM stars JOIN people ON stars.movie_id = people.id WHERE person_id IS (SELECT id FROM people WHERE (name = "Johnny Depp") AND (name = "Helena Bonham Carter"));


