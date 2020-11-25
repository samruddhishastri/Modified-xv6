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
  int a, b;
  if(argc <= 1){
    printf(1,"time: invalid arguments\n");
    exit();
  }
  
  int pid = fork();
  if(pid == 0){
    exec(argv[1], argv + 1);
    exit();
  }
  waitx(&a, &b);

  printf(1, "\nwtime:       %d\n", a);
  printf(1, "rtime:       %d\n", b);

  exit();
}