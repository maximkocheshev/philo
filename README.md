# Philosophers
### ***The specific rules for the mandatory part are:***
- Each philosopher should be a ***thread***.
- One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
- To avoid philosophers duplicating forks, you should protect the forks state with a ***mutex*** for each of them.
### ***Run:***
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
>The program should take the following arguments: 
>- number_of_philosophers: is the number of philosophers and also the number of forks (< 200).
>- time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting their last meal or the beginning of the simulation, it dies (< 60).
>- time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks (< 60).
>- time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping (< 60).
>- number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
### ***The specific rules for the bonus part are:***
- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a ***semaphore***.
- Each philosopher should be a ***process*** and the main process should not be a philosopher.
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
>Random values.
