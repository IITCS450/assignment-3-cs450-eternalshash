#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
  int pids[2];
  int tickets[2] = {10, 30}; // 1:3 Ratio
  
  printf(1, "Starting Ratio Test: 10 vs 30 tickets...\n");

  for (int i = 0; i < 2; i++) {
    pids[i] = fork();
    if (pids[i] == 0) { // Child
      settickets(tickets[i]);
      unsigned long count = 0;
      // Loop for a long time to gather data
      for (double d = 0; d < 1000000.0; d += 0.01) {
        count++;
      }
      printf(1, "Child %d (Tickets: %d) finished %d work units\n", i, tickets[i], count);
      exit();
    }
  }

  for (int i = 0; i < 2; i++) wait();
  exit();
}


