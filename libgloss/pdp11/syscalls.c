/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>
 
void _exit();                   /* 2.11BSD /usr/src/lib/libc/pdp/sys/_exit.s */
int close(int file);            /* 2.11BSD /usr/src/sys/kern_descrip.c */
char **environ; /* pointer to array of char * strings that define the current environment variables */
int execve(char *name, char **argv, char **env);    /* 2.11BSD /usr/src/sys/kern_exec.c */
int fork();                     /* 2.11BSD /usr/src/lib/libc/pdp/sys/fork.s */
int fstat(int file, struct stat *st);   /* 2.11BSD /usr/src/sys/kern_descrip.c */
int getpid();                   /* 2.11BSD /usr/src/sys/kern_prot.c */
int isatty(int file);           /* 2.11BSD /usr/src/lib/libc/gen/isatty.c */
int kill(int pid, int sig);     /* 2.11BSD /usr/src/sys/ker_sig.c */
int link(char *old, char *new); /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
int lseek(int file, int ptr, int dir);  /* 2.11BSD /usr/src/sys/ufs_syscalls2.c */
int open(const char *name, int flags, ...); /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
int read(int file, char *ptr, int len); /* 2.11BSD /usr/src/sys/sys_generic.c */
caddr_t sbrk(int incr);         /* 2.11BSD /usr/src/lib/libc/pdp/sys/sbrk.s */
int stat(const char *file, struct stat *st);    /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
clock_t times(struct tms *buf); /* 2.11BSD /usr/src/lib/libc/compat-4.1/times.c */
int unlink(char *name);         /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
int wait(int *status);          /* 2.11BSD /usr/src/lib/libc/gen/wait.c */
int write(int file, char *ptr, int len);    /* 2.11BSD /usr/src/sys/sys_generic.c */
int gettimeofday(struct timeval *p, struct timezone *z);    /* 2.11BSD /usr/src/sys/kern_time.c */
