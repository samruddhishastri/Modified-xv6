#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int
main(int argc, char *argv[])
{
  int priority, pid;
  if(argc <= 2){
    printf(1,"setPriority: invalid arguments\n");
    exit();
  }

  priority = atoi(argv[1]), pid = atoi(argv[2]);

  if(priority < 0 || priority > 100){
    printf(1, "setPriority: Invalid priority\n");
    exit();
  }
  int ret = set_priority(priority, pid);
  if(ret != -1)
    printf(1,"Successfully set the priority of process with pid %d from %d to %d\n", pid, ret, priority);
  else{
      printf(1,"Failure in setting the priority of process with pid %d to %d\n", pid, priority);
  }
  exit();
}