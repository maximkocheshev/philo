# Philosophers
### ***The specific rules for the mandatory part are:***
• Each philosopher should be a ***thread***.

• One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.

• To avoid philosophers duplicating forks, you should protect the forks state with a ***mutex*** for each of them.
```
$> make
$> ./philo 5 800 200 200 1
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
0 5 has taken a fork
201 1 is sleeping
201 3 is sleeping
201 5 has taken a fork
201 5 is eating
201 4 has taken a fork
201 2 has taken a fork
201 2 has taken a fork
201 2 is eating
402 1 is thinking
402 5 is sleeping
402 3 is thinking
402 2 is sleeping
402 4 has taken a fork
402 4 is eating
402 1 has taken a fork
402 1 has taken a fork
402 1 is eating
402 3 has taken a fork
603 5 is thinking
603 All philosophers eat at least 1 times!
```
>Random values.
### ***The specific rules for the bonus part are:***
• All the forks are in the middle of the table.

• They have no states in memory but the number of available forks is represented by a ***semaphore***.

• Each philosopher should be a ***process*** and the main process should not be a philosopher.
```
$> make bonus
$> cd philo_bonus
$> ./philo_bonus 5 800 200 200 1
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
1 2 has taken a fork
1 2 has taken a fork
1 2 is eating
1 3 has taken a fork
200 1 is sleeping
200 3 has taken a fork
200 4 has taken a fork
200 3 is eating
201 2 is sleeping
201 5 has taken a fork
201 4 has taken a fork
201 4 is eating
400 1 is thinking
400 3 is sleeping
400 1 has taken a fork
400 5 has taken a fork
400 5 is eating
401 4 is sleeping
401 2 is thinking
401 1 has taken a fork
401 2 has taken a fork
401 1 is eating
600 3 is thinking
600 5 is sleeping
600 All philosophers eat 1 times!
```
