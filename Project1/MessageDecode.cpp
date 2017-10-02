/*
[NF]
https://www.glassdoor.com/Interview/Decode-ways-on-leetcode-A-message-containing-letters-from-A-Z-is-being-encoded-to-numbers-from1-26-Determine-the-total-n-QTN_1903703.htm
Decode ways on leetcode. A message containing letters from  A-Z is being encoded to numbers from1-26. Determine the total number of ways to decode a given message

Build a system related to phone numbers. How to design and the scale of the system


1
¡å
If the system is CRUD operations to add phone number, modify it and assign it to the customer.. i will start new Spring-Boot Application with 3 tiers 
(API, Domain (Core), Infrastructure) DDD tactical Approach and then start to thinking about my Domain and aggregate root if the system depends on customers 
mobile phones and if there is any dependency for it such as (Verified mobile phone or not .. etc) 
after all of this i will start thinking about persistence layer if i need something transactional or not and i need to think about number of requests 
per minute and number of calls per minutes to the persistence.
the i have to provide interfaces for this service to deal with it such as HTTP REST API or consume Any Queue Messages (ActiveMQ, ZeroMQ, RabbitMQ or AWS SQS)
so now we have DDD micro-service with scalable code you can scale it as much as you can for example use (AWS EC2 t2.medium 2 Cores).
if i used MySQL it will handle between 9K - 15K request per minute for response time < 60 ms (roughly speaking)
*/

