#ifndef __SIM_TRACE_H_
#define __SIM_TRACE_H_

#ifdef SLURM_SIMULATOR

#define MAX_USERNAME_LEN 30
#define MAX_RSVNAME_LEN  30
#define MAX_QOSNAME      30
#define TIMESPEC_LEN     30
#define MAX_RSVNAME      30
#define MAX_DEPNAME		 1024
#define MAX_WF_FILENAME_LEN	1024

typedef struct job_trace {
    int  job_id;
    char username[MAX_USERNAME_LEN];
    long int submit; /* relative or absolute? */
    int  duration;
    int  wclimit;
    int  tasks;
    char qosname[MAX_QOSNAME];
    char partition[MAX_QOSNAME];
    char account[MAX_QOSNAME];
    int  cpus_per_task;
    int  tasks_per_node;
    char reservation[MAX_RSVNAME];
    char dependency[MAX_DEPNAME];
    struct job_trace *next;
    char manifest_filename[MAX_WF_FILENAME_LEN];
    char *manifest;
} job_trace_t;

typedef struct rsv_trace {
    long int           creation_time;
    char *             rsv_command;
    struct rsv_trace * next;
} rsv_trace_t;

int read_job_trace_record(int fd, job_trace_t *record);
#endif
#endif
