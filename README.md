## Repo for Lab Week 10
Complete assignment as assigned.
Part 1:
Signal disposition- action that a process takes when it receives a signal

Signal Handler - funtion or method that says what to do when a certain signal is received

Terminate - ends the process
Terminate adn core dump - ends process and core dumps for debug
Ignore - nothing happens
Stop - pauses execution
continue - resumes a stopped process

Part 2:
CTRL + C 
kill -SIGINT "PID"
both worked

When exit is removed it goes back to infinit loop

Part 3:

Sig fault keeps happing because it returns to where the sig fault happened

to sends SIGUSR1 
kill -SIGUR1 PID

