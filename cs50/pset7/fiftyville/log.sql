

SELECT name FROM people

    WHERE phone_number in

-- phone number from phone_calls

    (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 and duration < 60)

-- licence plate from bakery security logs
    AND license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND hour = 10 AND minute BETWEEN 15 and 25)

-- passport - from passengerse

   AND passport_number IN
   (SELECT passport_number FROM passengers WHERE flight_id IN
    (SELECT id FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 ORDER BY hour LIMIT 1))
-- person id from bank accounts
    AND id IN
        (SELECT person_id FROM bank_accounts WHERE account_number IN
            (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location LIKE '%leggett%'));


-- Airport

 SELECT city FROM airports WHERE id IN
    (SELECT destination_airport_id FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 ORDER BY hour LIMIT 1);


-- Accomplice

-- full details of thief, then query phone records based on phone number of identified thiefa, at time of call, to identify accomplice by looking at receiver of calls made by phone number a

|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+


SELECT name FROM People WHERE phone_number =
    (SELECT receiver FROM phone_calls WHERE
        day = 28 AND month = 7 and duration < 60
        AND
        caller = '(367) 555-5533');





-- GUIDE


SELECT {id value} FROM {table a} WHERE {items in filter column} = {value};

    output is 'id values' from 'people table', where items in 'age' column < 30


SELECT * FROM people;


people table

columns

id     |    name    |     age    |     birthday month

1            andrew        46            december

2            sophie        35            september

3            olivia        28            august

4            debby        25              june