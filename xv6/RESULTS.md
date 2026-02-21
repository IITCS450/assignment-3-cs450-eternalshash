Objective:
	Validate the lottery scheduler allocates CPU time properly based on the number
	of tickets assigned to a process
Using the Chameleon Clould CM
Test lottery program: it validates that the settickets handles 
invalid inputs (0 tickets) by returning -1 then assigning valid ticket counts
Workload:
	Burn() used to ensure process stays RUNNABLE
	Scheduler has to choose between them 
Analysis:
	Need to double check all the validation checks
	Variations over short runs 
	Over time a process with more tickets will win the lottery more often
	In turn will recieve more CPU cycles
Verification:
	The testlottery program confirmed the settickers syscall correctly validating
	PASS: settickets validation
Setup:
	Two processes were created with 1:3 ticket ratio (10 to 30 tickets)
Workload: 
	Each process executed a CPU bound(ed) loop 
	Counter ? 
Observations:
	Child 0 10 100,000,000
	Child 1 30 300,000,000
So the process with 3x the tickets completed at exactly 3x the work units
demonstrating that the scheduler successfully allocates CPU time based on 
the ticket proportion 


