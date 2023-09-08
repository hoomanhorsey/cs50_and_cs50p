-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Theft details 28 July 2021, Humphrey St
-- 10.15am (crime scene report description)

-- Within 10 minutes of theft, security footage (interviews ID 161)
-- Theif withdrawing money from ATM at Leggett St, time unclear (interviews ID 162)
-- Earliest flight out of Fiftyville tomorrow (i.e. 29 July 2021) (interviews id 163). Asked ACCOMPLICE on phone to buy ticket

-- Selects crime id based on filtering of day, month and mention of 'duck' in description
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND description LIKE '%duck%';

-- Selects transcripts from 3 witnesses, filtered by mentions of bakery. Also includes one from a different day.

SELECT * FROM interviews WHERE transcript LIKE '%bakery%';sqlite> SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| id  |  name   | year | month | day |                                                                                                                                                     transcript                                                                                                                                                      |
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |


-- Selects licence plate number from bakery, 10 mins after robbery.
SELECT * FROM bakery_security_logs WHERE day = 28 AND hour = 10 AND minute BETWEEN 15 and 25;
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
+-----+------+-------+-----+------+--------+----------+---------------+


SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location LIKE '%leggett%';
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 275 | 86363979       | 2021 | 7     | 28  | Leggett Street | deposit          | 10     |
| 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+

SELECT * FROM phone_calls WHERE day = 28 AND month = 7 and duration < 60;

+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+

-- Selecting airports to find code for Fiftyville.
SELECT * FROM airports;
+----+--------------+-----------------------------------------+---------------+
| id | abbreviation |                full_name                |     city      |
+----+--------------+-----------------------------------------+---------------+
| 1  | ORD          | O'Hare International Airport            | Chicago       |
| 2  | PEK          | Beijing Capital International Airport   | Beijing       |
| 3  | LAX          | Los Angeles International Airport       | Los Angeles   |
| 4  | LGA          | LaGuardia Airport                       | New York City |
| 5  | DFS          | Dallas/Fort Worth International Airport | Dallas        |
| 6  | BOS          | Logan International Airport             | Boston        |
| 7  | DXB          | Dubai International Airport             | Dubai         |
| 8  | CSF          | Fiftyville Regional Airport             | Fiftyville    |
| 9  | HND          | Tokyo International Airport             | Tokyo         |
| 10 | CDG          | Charles de Gaulle Airport               | Paris         |
| 11 | SFO          | San Francisco International Airport     | San Francisco |
| 12 | DEL          | Indira Gandhi International Airport     | Delhi         |
+----+--------------+-----------------------------------------+---------------+

-- Selecting flights originating from Fiftyville (origin airport id = 8), finding first flight, flying to La Guardia.

 SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 AND month = 7 ORDER BY hour;
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
| 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
| 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
| 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
+----+-------------------+------------------------+------+-------+-----+------+--------+

-- Selecting passengers on flight id 36, Fiftyville to La Guardia at 8.20am, 29 of July.
SELECT * FROM passengers WHERE flight_id  = 36;
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   |
| 36        | 1695452385      | 3B   |
| 36        | 5773159633      | 4A   |
| 36        | 1540955065      | 5C   |
| 36        | 8294398571      | 6C   |
| 36        | 1988161715      | 6D   |
| 36        | 9878712108      | 7A   |
| 36        | 8496433585      | 7B   |
+-----------+-----------------+------+



RUN A selection from People filtering between phone number, passport number and licenc eplate?

Account number?




SELECT name FROM people WHERE id IN
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |

   -- phone number - from phone calls

(SELECT id FROM phone_calls WHERE day = 28 AND month = 7 and duration < 60)
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 and duration < 60);
+---------+
|  name   |
+---------+
| Kenny   |
| Sofia   | Sofia
| Benista |
| Taylor  |
| Diana   |
| Kelsey  | Kelsey
| Bruce   |
| Carina  | Bruce
+---------+
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |

    -- passport - from passengerse

(SELECT * FROM passengers WHERE flight_id  = 36)
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id  = 36);
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   |
+--------+
|  name  |
+--------+
| Kenny  |
| Sofia  | Sofia
| Taylor |
| Luca   | Luca
| Kelsey | Kelsey
| Edward |
| Bruce  | Bruce
| Doris  |
+--------+

    --  licence plate - bakery security logs
(SELECT * FROM bakery_security_logs WHERE day = 28 AND hour = 10 AND minute BETWEEN 15 and 25)

SELECT name From people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND hour = 10 AND minute BETWEEN 15 and 25);
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
+---------+
|  name   |
+---------+
| Vanessa |
| Barry   |
| Iman    |
| Sofia   | Sofia
| Luca    | Luca
| Diana   |
| Kelsey  | Kelsey
| Bruce   | Bruce
+---------+

 SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location LIKE '%leggett%'));
+---------+
|  name   |
+---------+
| Kenny   |
| Iman    |
| Benista |
| Taylor  |
| Brooke  |
| Luca    |
| Diana   |
| Bruce   | Bruce
| Kaelyn  |
+---------+

SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location LIKE '%leggett%';
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |


(SELECT * FROM passengers WHERE flight_id  = 36)

SE

SELECT * FROM people WHERE phone_number IN

    (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 and duration < 60) ORDER BY passport_number;


-- full details of thief, then manually queried accomplice by looking at receiver of calls made by phone number at the
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+


