#ifndef _dissect_readlog_h
#define _dissect_readlog_h

extern int print_log;
extern unsigned long long total_duration;
extern int no_memory_analysis;

char *read_log (FILE *fs);

#endif /* _dissect_readlog_h */
