/* cygserver_process.h

   Copyright 2001, 2002 Red Hat Inc.

   Written by Robert Collins <rbtcollins@hotmail.com>

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

#ifndef _CYGSERVER_PROCESS_
#define _CYGSERVER_PROCESS_

#include <assert.h>

#include "threaded_queue.h"

class process_cleanup : public queue_request
{
public:
  process_cleanup (class process *const theprocess)
    : _process (theprocess)
  {
    assert (_process);
  }

  virtual ~process_cleanup ();

  virtual void process ();

private:
  class process *const _process;
};

class process;

class cleanup_routine
{
  friend class process;

public:
  cleanup_routine () : _next (NULL) {}
  virtual ~cleanup_routine ();

  /* MUST BE SYNCHRONOUS */
  virtual void cleanup (DWORD winpid) = 0;

private:
  cleanup_routine *_next;
};

class process_cache;

class process
{
  friend process_cache;
  friend process_cleanup;

public:
  process (DWORD winpid);
  ~process ();

  HANDLE handle () const { return _hProcess; }

  void hold () { EnterCriticalSection (&_access); }
  void release () { LeaveCriticalSection (&_access); }

private:
  const DWORD _winpid;
  class process *_next;
  long _cleaning_up;
  cleanup_routine *_routines_head;
  DWORD _exit_status;		// Set in the constructor and in exit_code ().
  HANDLE _hProcess;
  /* used to prevent races-on-delete */
  CRITICAL_SECTION _access;
  
  DWORD exit_code ();
  bool add (cleanup_routine *);
  void cleanup ();
};

class process_cache
{
  // Number of special (i.e., non-process) handles in _wait_array.
  // See wait_for_processes () and sync_wait_array () for details.
  enum {
    SPECIALS_COUNT = 2
  };

  class submission_loop : public queue_submission_loop
  {
  public:
    submission_loop (process_cache *const cache, threaded_queue *const queue)
      : queue_submission_loop (queue, true),
	_cache (cache)
    {
      assert (_cache);
    }

  private:
    process_cache *const _cache;

    virtual void request_loop ();
  };

  friend submission_loop;

public:
  process_cache (unsigned int initial_workers);
  ~process_cache ();

  class process *process (DWORD winpid);

  bool running () const { return _queue.running (); }

  bool start () { return _queue.start (); }
  bool stop () { return _queue.stop (); }

private:
  threaded_queue _queue;
  submission_loop _submitter;

  size_t _processes_count;
  class process *_processes_head; // A list sorted by winpid.

  // Access to the _wait_array and related fields is not thread-safe,
  // since they are used solely by wait_for_processes () and its callees.

  HANDLE _wait_array[MAXIMUM_WAIT_OBJECTS];
  class process *_process_array[MAXIMUM_WAIT_OBJECTS];

  HANDLE _cache_add_trigger;	// Actually both add and remove.
  CRITICAL_SECTION _cache_write_access; // Actually both read and write access.

  void wait_for_processes (HANDLE interrupt);
  size_t sync_wait_array (HANDLE interrupt);
  void check_and_remove_process (const size_t index);

  class process *find (DWORD winpid, class process **previous = NULL);
};

#endif /* _CYGSERVER_PROCESS_ */
