# PHILOSOPHER

## Description 

This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

<img width="1483" alt="Screen Shot 2023-05-23 at 4 28 41 PM" src="https://github.com/hecikmc/philosopher-42Cursus/assets/121127625/22125a63-22ec-4604-8d7e-1b049b555023">

* Project developed in 'C' language.
* The project compiles with the 'norma' (Norminette).
* The makefile compiles the program (and the libft needed) with the name: **philo**

## Mandatory part

One or more philosophers sit at a round table, in the center of the table is a large bowl of spaghetti. Philosophers can only **eat, think, or sleep:**

* While they are eating, they cannot think or sleep.
* While they are thinking, they cannot sleep or eat.
* And of course, while they are sleeping, they cannot eat or think.

There are also forks on the table, one per philosopher. To be able to eat each philosopher must take **two forks**, one from his left hand and another one from his right hand, borrowing a nearby fork.
When a philosopher finishes eating, he will put down his forks and immediately go to sleep. Once he wakes up, he will start thinking.
The simulation will stop when a philosopher dies of starvation.
The deal is that **all philosophers eat in turns and never die (if it is possible)**.

Philosophers don't talk to each other and they don't know if another philosopher is going to die.

<img width="717" alt="Screen Shot 2023-05-23 at 5 09 01 PM" src="https://github.com/hecikmc/philosopher-42Cursus/assets/121127625/2c27aff4-da9f-4b62-af00-a6cc5e41e83d">
