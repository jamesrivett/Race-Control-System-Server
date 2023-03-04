# Startup

* To launch the mosquitto server run `docker-compose up -d`

* To connect to mosquitto terminal execute in a terminal `docker exec -it rcs-broker sh`
 - To subscribe to a message `mosquitto_sub -h {host} -t {msg_type}`
 - To send a message `mosquitto_pub -h {host} -t {msg_type} -m {msg_content}`

# Task List

* Create python server application that subscribes to a predefined message list
 - can send to specific kart
 - can send to everyone
 - listens to kart health
 - listens to race director (person is charge)
 - has active track health machine state diagram

* Create per-kart authentication and identifiers to identify who is sending a message
 - Karts connect with predefined authentication and identifier
 - Karts can only send to certain topics
 - Karts can subscribe to any topic