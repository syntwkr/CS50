-- Keep a log of any SQL queries you execute as you solve the mystery.

-- getting the the id of crime scene report >> 295
SELECT description FROM crime_scene_reports WHERE month = 07 AND day = 28 AND street = "Chamberlin Street";
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts
-- mentions the courthouse.

-- getting transcripts of interviews
SELECT name, transcript FROM interviews WHERE month = 07 AND day = 28;
-- Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- parking lot
SELECT name FROM people
JOIN courthouse_security_logs ON courthouse_security_logs.license_plate = people.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25
ORDER BY name;
-- suspects: Amber, Danielle, Elizabeth, Ernest, Evelyn, Patrick, Roger, Russell.

-- ATM
SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND transaction_type = "withdraw"
AND atm_transactions.atm_location = "Fifer Street")
ORDER BY name;
-- suspects: Bobby, Danielle, Elizabeth, Ernest, Madison, Roy, Russell, Victoria.

-- calls
SELECT name FROM people WHERE phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2020 AND month = 7 AND day = 28
    AND duration < 60)
    ORDER BY name;
-- suspects: Bobby, Ernest, Evelyn, Kimberly, Madison, Roger, Russell, Victoria.

-- updated suspects: Ernest and Russell

-- first flight
SELECT city, flights.id FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.id IN (SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29
ORDER BY hour, minute ASC LIMIT 1);
-- London! Flight id 36

SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36;
-- passengers; Doris, Roger, Ernest, Edward, Evelyn, Madison, Bobby, Danielle
-- that's how we know that Russel didn't go to London. Ernest did!

-- oh, by the way, whom he called?
SELECT name FROM people
WHERE phone_number IN
(SELECT receiver FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28
AND caller = (SELECT phone_number FROM people WHERE name = "Ernest")
AND duration < 60);
-- Berthold!