/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>

void _exit();                   /* 2.11BSD /usr/src/lib/libc/pdp/sys/_exit.s */
int system(const char *command);     /* 2.11BSD /usr/src/lib/libc/gen/system.c */
char* malloc(unsigned nbytes);  /* 2.11BSD /usr/src/lib/libc/gen/malloc.c */
char* getenv(char *name);       /* ? */
int execve(char *name, char **argv, char **env);    /* 2.11BSD /usr/src/sys/sys/kern_exec.c */
int fork();                     /* 2.11BSD /usr/src/lib/libc/pdp/sys/fork.s */
caddr_t sbrk(int incr);         /* 2.11BSD /usr/src/lib/libc/pdp/sys/sbrk.s */
int getpid();                   /* 2.11BSD /usr/src/sys/sys/kern_prot.c ? */
char **environ; /* pointer to array of char * strings that define the current environment variables */
int fstat(int file, struct stat *st);   /* 2.11BSD /usr/src/sys/sys/kern_descrip.c ? */
int isatty(int file);           /* 2.11BSD /usr/src/lib/libc/gen/isatty.c */
int kill(int pid, int sig);     /* 2.11BSD /usr/src/sys/sys/ker_sig.c */
clock_t times(struct tms *buf); /* 2.11BSD /usr/src/lib/libc/compat-4.1/times.c */
int gettimeofday(struct timeval *p, struct timezone *z);    /* 2.11BSD /usr/src/sys/kern_time.c */
int wait(int *status);          /* 2.11BSD /usr/src/lib/libc/gen/wait.c */
int stat(const char *file, struct stat *st);    /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
 
/* For stdio.h */
int open(const char *name, int flags, ...); /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
int close(int file);            /* 2.11BSD /usr/src/sys/sys/kern_descrip.c */
int link(char *old, char *new); /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
int unlink(char *name);         /* 2.11BSD /usr/src/sys/ufs_syscalls.c */
int write(int file, char *ptr, int len);    /* 2.11BSD /usr/src/sys/sys_generic.c */
int read(int file, char *ptr, int len); /* 2.11BSD /usr/src/sys/sys_generic.c */
int lseek(int file, int ptr, int dir);  /* 2.11BSD /usr/src/sys/ufs_syscalls2.c */

/* Pure useless stubs */
void _exit (void) {
}

int system (const char *command) {
    return -1;
}

int execve (char *name, char **argv, char **env) {
    return -1;
}

int fork (void) {
    return -1;
}

int getpid (void) {
    return -1;
}

int fstat (int file, struct stat *st) {
    return -1;
}

int isatty (int file) {
    return -1;
}

int kill (int pid, int sig) {
    return -1;
}

int gettimeofday (struct timeval *p, struct timezone *z) {
    return -1;
}

int wait (int *status) {
    return -1;
}

int stat(const char *file, struct stat *st) {
    return -1;
}
 
int open(const char *name, int flags, ...) {
    return -1;
}

int close(int file) {
    return -1;
}

int link(char *old, char *new) {
    return -1;
}

int unlink(char *name) {
    return -1;
}

int write(int file, char *ptr, int len) {
    return -1;
}

int read(int file, char *ptr, int len) {
    return -1;
}

int lseek(int file, int ptr, int dir) {
    return -1;
}
