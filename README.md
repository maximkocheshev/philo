# Philosophers
### ***The specific rules for the mandatory part are:***
• Each philosopher should be a ***thread***.

• One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.

• To avoid philosophers duplicating forks, you should protect the forks state with a ***mutex*** for each of them.
### ***The specific rules for the bonus part are:***
• All the forks are in the middle of the table.

• They have no states in memory but the number of available forks is represented by a ***semaphore***.

• Each philosopher should be a ***process*** and the main process should not be a philosopher.
