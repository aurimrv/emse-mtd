
typedef long unsigned int size_t;
typedef __gnuc_va_list;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE
{
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef __ssize_t cookie_read_function_t (void *__cookie, char *__buf,
                                          size_t __nbytes);
typedef __ssize_t cookie_write_function_t (void *__cookie, const char *__buf,
                                           size_t __nbytes);
typedef int cookie_seek_function_t (void *__cookie, __off64_t *__pos, int __w);
typedef int cookie_close_function_t (void *__cookie);
typedef struct _IO_cookie_io_functions_t
{
  cookie_read_function_t *read;
  cookie_write_function_t *write;
  cookie_seek_function_t *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove (const char *__filename) ;
extern int rename (const char *__old, const char *__new) ;
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) ;
extern int fclose (FILE *__stream) ;
extern FILE *tmpfile (void)
  ;
extern char *tmpnam (char[20]) ;
extern char *tmpnam_r (char __s[20]) ;
extern char *tempnam (const char *__dir, const char *__pfx)
   ;
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern FILE *fopen (const char * __filename,
      const char * __modes)
  ;
extern FILE *freopen (const char * __filename,
        const char * __modes,
        FILE * __stream) ;
extern FILE *fdopen (int __fd, const char *__modes)
  ;
extern FILE *fopencookie (void * __magic_cookie,
     const char * __modes,
     cookie_io_functions_t __io_funcs)
  ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc)
  ;
extern void setbuf (FILE * __stream, char * __buf)
  ;
extern int setvbuf (FILE * __stream, char * __buf,
      int __modes, size_t __n) ;
extern void setbuffer (FILE * __stream, char * __buf,
         size_t __size) ;
extern void setlinebuf (FILE *__stream) ;
extern int fprintf (FILE * __stream,
      const char * __format, ...) ;
extern int printf (const char * __format, ...);
extern int sprintf (char * __s,
      const char * __format, ...) ;
extern int vfprintf (FILE * __s, const char * __format,
       __gnuc_va_list __arg) ;
extern int vprintf (const char * __format, __gnuc_va_list __arg);
extern int vsprintf (char * __s, const char * __format,
       __gnuc_va_list __arg) ;
extern int snprintf (char * __s, size_t __maxlen,
       const char * __format, ...)
     ;
extern int vsnprintf (char * __s, size_t __maxlen,
        const char * __format, __gnuc_va_list __arg)
     ;
extern int vasprintf (char ** __ptr, const char * __f,
        __gnuc_va_list __arg)
     ;
extern int __asprintf (char ** __ptr,
         const char * __fmt, ...)
     ;
extern int asprintf (char ** __ptr,
       const char * __fmt, ...)
     ;
extern int vdprintf (int __fd, const char * __fmt,
       __gnuc_va_list __arg)
     ;
extern int dprintf (int __fd, const char * __fmt, ...)
     ;
extern int fscanf (FILE * __stream,
     const char * __format, ...) ;
extern int scanf (const char * __format, ...) ;
extern int sscanf (const char * __s,
     const char * __format, ...) ;
extern int fscanf (FILE * __stream, const char * __format, ...) ;
extern int scanf (const char * __format, ...) ;
extern int sscanf (const char * __s, const char * __format, ...) ;
extern int vfscanf (FILE * __s, const char * __format,
      __gnuc_va_list __arg)
     ;
extern int vscanf (const char * __format, __gnuc_va_list __arg)
     ;
extern int vsscanf (const char * __s,
      const char * __format, __gnuc_va_list __arg)
     ;
extern int vfscanf (FILE * __s, const char * __format, __gnuc_va_list __arg)
     ;
extern int vscanf (const char * __format, __gnuc_va_list __arg)
     ;
extern int vsscanf (const char * __s, const char * __format, __gnuc_va_list __arg)
     ;
extern int fgetc (FILE *__stream) ;
extern int getc (FILE *__stream) ;
extern int getchar (void);
extern int getc_unlocked (FILE *__stream) ;
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream) ;
extern int fputc (int __c, FILE *__stream) ;
extern int putc (int __c, FILE *__stream) ;
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream) ;
extern int putc_unlocked (int __c, FILE *__stream) ;
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream) ;
extern int putw (int __w, FILE *__stream) ;
extern char *fgets (char * __s, int __n, FILE * __stream)
     ;
extern __ssize_t __getdelim (char ** __lineptr,
                             size_t * __n, int __delimiter,
                             FILE * __stream) ;
extern __ssize_t getdelim (char ** __lineptr,
                           size_t * __n, int __delimiter,
                           FILE * __stream) ;
extern __ssize_t getline (char ** __lineptr,
                          size_t * __n,
                          FILE * __stream) ;
extern int fputs (const char * __s, FILE * __stream)
  ;
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream) ;
extern size_t fread (void * __ptr, size_t __size,
       size_t __n, FILE * __stream)
  ;
extern size_t fwrite (const void * __ptr, size_t __size,
        size_t __n, FILE * __s) ;
extern size_t fread_unlocked (void * __ptr, size_t __size,
         size_t __n, FILE * __stream)
  ;
extern size_t fwrite_unlocked (const void * __ptr, size_t __size,
          size_t __n, FILE * __stream)
  ;
extern int fseek (FILE *__stream, long int __off, int __whence)
  ;
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream) ;
extern int fseeko (FILE *__stream, __off_t __off, int __whence)
  ;
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE * __stream, fpos_t * __pos)
  ;
extern int fsetpos (FILE *__stream, const fpos_t *__pos) ;
extern void clearerr (FILE *__stream) ;
extern int feof (FILE *__stream) ;
extern int ferror (FILE *__stream) ;
extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;
extern void perror (const char *__s) ;
extern int fileno (FILE *__stream) ;
extern int fileno_unlocked (FILE *__stream) ;
extern int pclose (FILE *__stream) ;
extern FILE *popen (const char *__command, const char *__modes)
  ;
extern char *ctermid (char *__s)
  ;
extern void flockfile (FILE *__stream) ;
extern int ftrylockfile (FILE *__stream) ;
extern void funlockfile (FILE *__stream) ;
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);


extern void *memcpy (void * __dest, const void * __src,
       size_t __n) ;
extern void *memmove (void *__dest, const void *__src, size_t __n)
     ;
extern void *memccpy (void * __dest, const void * __src,
        int __c, size_t __n)
    ;
extern void *memset (void *__s, int __c, size_t __n) ;
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     ;
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     ;
extern void *memchr (const void *__s, int __c, size_t __n)
      ;
extern char *strcpy (char * __dest, const char * __src)
     ;
extern char *strncpy (char * __dest,
        const char * __src, size_t __n)
     ;
extern char *strcat (char * __dest, const char * __src)
     ;
extern char *strncat (char * __dest, const char * __src,
        size_t __n) ;
extern int strcmp (const char *__s1, const char *__s2)
     ;
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     ;
extern int strcoll (const char *__s1, const char *__s2)
     ;
extern size_t strxfrm (char * __dest,
         const char * __src, size_t __n)
    ;
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     ;
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l)
     ;
extern char *strdup (const char *__s)
     ;
extern char *strndup (const char *__string, size_t __n)
     ;
extern char *strchr (const char *__s, int __c)
     ;
extern char *strrchr (const char *__s, int __c)
     ;
extern char *strchrnul (const char *__s, int __c)
     ;
extern size_t strcspn (const char *__s, const char *__reject)
     ;
extern size_t strspn (const char *__s, const char *__accept)
     ;
extern char *strpbrk (const char *__s, const char *__accept)
     ;
extern char *strstr (const char *__haystack, const char *__needle)
     ;
extern char *strtok (char * __s, const char * __delim)
     ;
extern char *__strtok_r (char * __s,
    const char * __delim,
    char ** __save_ptr)
     ;
extern char *strtok_r (char * __s, const char * __delim,
         char ** __save_ptr)
     ;
extern char *strcasestr (const char *__haystack, const char *__needle)
     ;
extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
    
   
    ;
extern void *__mempcpy (void * __dest,
   const void * __src, size_t __n)
     ;
extern void *mempcpy (void * __dest,
        const void * __src, size_t __n)
     ;
extern size_t strlen (const char *__s)
     ;
extern size_t strnlen (const char *__string, size_t __maxlen)
     ;
extern char *strerror (int __errnum) ;
extern int strerror_r (int __errnum, char *__buf, size_t __buflen)
    ;
extern char *strerror_l (int __errnum, locale_t __l) ;

extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     ;
extern void bcopy (const void *__src, void *__dest, size_t __n)
  ;
extern void bzero (void *__s, size_t __n) ;
extern char *index (const char *__s, int __c)
     ;
extern char *rindex (const char *__s, int __c)
     ;
extern int ffs (int __i) ;
extern int ffsl (long int __l) ;
 extern int ffsll (long long int __ll)
     ;
extern int strcasecmp (const char *__s1, const char *__s2)
     ;
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     ;
extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     ;
extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     ;

extern void explicit_bzero (void *__s, size_t __n)
    ;
extern char *strsep (char ** __stringp,
       const char * __delim)
     ;
extern char *strsignal (int __sig) ;
extern char *__stpcpy (char * __dest, const char * __src)
     ;
extern char *stpcpy (char * __dest, const char * __src)
     ;
extern char *__stpncpy (char * __dest,
   const char * __src, size_t __n)
     ;
extern char *stpncpy (char * __dest,
        const char * __src, size_t __n)
     ;
extern size_t strlcpy (char * __dest,
         const char * __src, size_t __n)
  ;
extern size_t strlcat (char * __dest,
         const char * __src, size_t __n)
  ;

typedef int wchar_t;

typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
 typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) ;
extern double atof (const char *__nptr)
     ;
extern int atoi (const char *__nptr)
     ;
extern long int atol (const char *__nptr)
     ;
 extern long long int atoll (const char *__nptr)
     ;
extern double strtod (const char * __nptr,
        char ** __endptr)
     ;
extern float strtof (const char * __nptr,
       char ** __endptr) ;
extern long double strtold (const char * __nptr,
       char ** __endptr)
     ;
extern long int strtol (const char * __nptr,
   char ** __endptr, int __base)
     ;
extern unsigned long int strtoul (const char * __nptr,
      char ** __endptr, int __base)
     ;

extern long long int strtoq (const char * __nptr,
        char ** __endptr, int __base)
     ;

extern unsigned long long int strtouq (const char * __nptr,
           char ** __endptr, int __base)
     ;

extern long long int strtoll (const char * __nptr,
         char ** __endptr, int __base)
     ;

extern unsigned long long int strtoull (const char * __nptr,
     char ** __endptr, int __base)
     ;
extern char *l64a (long int __n) ;
extern long int a64l (const char *__s)
     ;

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t ;
static __uint16_t
__bswap_16 (__uint16_t __bsx)
{
  return __builtin_bswap16 (__bsx);
}
static __uint32_t
__bswap_32 (__uint32_t __bsx)
{
  return __builtin_bswap32 (__bsx);
}
 static __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set * __readfds,
     fd_set * __writefds,
     fd_set * __exceptfds,
     struct timeval * __timeout);
extern int pselect (int __nfds, fd_set * __readfds,
      fd_set * __writefds,
      fd_set * __exceptfds,
      const struct timespec * __timeout,
      const __sigset_t * __sigmask);

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef union
{
  unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct
{
  int __data ;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

extern long int random (void) ;
extern void srandom (unsigned int __seed) ;
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) ;
extern char *setstate (char *__statebuf) ;
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data * __buf,
       int32_t * __result) ;
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     ;
extern int initstate_r (unsigned int __seed, char * __statebuf,
   size_t __statelen,
   struct random_data * __buf)
     ;
extern int setstate_r (char * __statebuf,
         struct random_data * __buf)
     ;
extern int rand (void) ;
extern void srand (unsigned int __seed) ;
extern int rand_r (unsigned int *__seed) ;
extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;
extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3])
     ;
extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3])
     ;
extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     ;
extern void lcong48 (unsigned short int __param[7]) ;
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data * __buffer,
        double * __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data * __buffer,
        double * __result) ;
extern int lrand48_r (struct drand48_data * __buffer,
        long int * __result)
     ;
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data * __buffer,
        long int * __result)
     ;
extern int mrand48_r (struct drand48_data * __buffer,
        long int * __result)
     ;
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data * __buffer,
        long int * __result)
     ;
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) ;
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     ;
extern __uint32_t arc4random (void)
     ;
extern void arc4random_buf (void *__buf, size_t __size)
     ;
extern __uint32_t arc4random_uniform (__uint32_t __upper_bound)
     ;
extern void *malloc (size_t __size)
     ;
extern void *calloc (size_t __nmemb, size_t __size)
     ;
extern void *realloc (void *__ptr, size_t __size)
     ;
extern void free (void *__ptr) ;
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
    
    
    ;
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     ;

extern void *alloca (size_t __size) ;

extern void *valloc (size_t __size)
     ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
    
     ;
extern void abort (void) ;
extern int atexit (void (*__func) (void)) ;
extern int at_quick_exit (void (*__func) (void)) ;
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;
extern void exit (int __status) ;
extern void quick_exit (int __status) ;
extern void _Exit (int __status) ;
extern char *getenv (const char *__name) ;
extern int putenv (char *__string) ;
extern int setenv (const char *__name, const char *__value, int __replace)
     ;
extern int unsetenv (const char *__name) ;
extern int clearenv (void) ;
extern char *mktemp (char *__template) ;
extern int mkstemp (char *__template) ;
extern int mkstemps (char *__template, int __suffixlen) ;
extern char *mkdtemp (char *__template) ;
extern int system (const char *__command) ;
extern char *realpath (const char * __name,
         char * __resolved) ;
typedef int (*__compar_fn_t) (const void *, const void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) ;
extern int abs (int __x) ;
extern long int labs (long int __x) ;
 extern long long int llabs (long long int __x)
     ;
extern div_t div (int __numer, int __denom)
     ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     ;
 extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     ;
extern char *ecvt (double __value, int __ndigit, int * __decpt,
     int * __sign) ;
extern char *fcvt (double __value, int __ndigit, int * __decpt,
     int * __sign) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     ;
extern char *qecvt (long double __value, int __ndigit,
      int * __decpt, int * __sign)
     ;
extern char *qfcvt (long double __value, int __ndigit,
      int * __decpt, int * __sign)
     ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     ;
extern int ecvt_r (double __value, int __ndigit, int * __decpt,
     int * __sign, char * __buf,
     size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int * __decpt,
     int * __sign, char * __buf,
     size_t __len) ;
extern int qecvt_r (long double __value, int __ndigit,
      int * __decpt, int * __sign,
      char * __buf, size_t __len)
     ;
extern int qfcvt_r (long double __value, int __ndigit,
      int * __decpt, int * __sign,
      char * __buf, size_t __len)
     ;
extern int mblen (const char *__s, size_t __n) ;
extern int mbtowc (wchar_t * __pwc,
     const char * __s, size_t __n) ;
extern int wctomb (char *__s, wchar_t __wchar) ;
extern size_t mbstowcs (wchar_t * __pwcs,
   const char * __s, size_t __n)
    ;
extern size_t wcstombs (char * __s,
   const wchar_t * __pwcs, size_t __n)
    
 
  ;
extern int rpmatch (const char *__response) ;
extern int getsubopt (char ** __optionp,
        char *const * __tokens,
        char ** __valuep)
     ;
extern int getloadavg (double __loadavg[], int __nelem)
     ;


enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
extern const unsigned short int **__ctype_b_loc (void)
     ;
extern const __int32_t **__ctype_tolower_loc (void)
     ;
extern const __int32_t **__ctype_toupper_loc (void)
     ;
extern int isalnum (int) ;
extern int isalpha (int) ;
extern int iscntrl (int) ;
extern int isdigit (int) ;
extern int islower (int) ;
extern int isgraph (int) ;
extern int isprint (int) ;
extern int ispunct (int) ;
extern int isspace (int) ;
extern int isupper (int) ;
extern int isxdigit (int) ;
extern int tolower (int __c) ;
extern int toupper (int __c) ;
extern int isblank (int) ;
extern int isascii (int __c) ;
extern int toascii (int __c) ;
extern int _toupper (int) ;
extern int _tolower (int) ;
extern int isalnum_l (int, locale_t) ;
extern int isalpha_l (int, locale_t) ;
extern int iscntrl_l (int, locale_t) ;
extern int isdigit_l (int, locale_t) ;
extern int islower_l (int, locale_t) ;
extern int isgraph_l (int, locale_t) ;
extern int isprint_l (int, locale_t) ;
extern int ispunct_l (int, locale_t) ;
extern int isspace_l (int, locale_t) ;
extern int isupper_l (int, locale_t) ;
extern int isxdigit_l (int, locale_t) ;
extern int isblank_l (int, locale_t) ;
extern int __tolower_l (int __c, locale_t __l) ;
extern int tolower_l (int __c, locale_t __l) ;
extern int __toupper_l (int __c, locale_t __l) ;
extern int toupper_l (int __c, locale_t __l) ;


typedef float float_t;
typedef double double_t;
extern int __fpclassify (double __value)
     ;
extern int __signbit (double __value)
     ;
extern int __isinf (double __value)
  ;
extern int __finite (double __value)
  ;
extern int __isnan (double __value)
  ;
extern int __iseqsig (double __x, double __y) ;
extern int __issignaling (double __value)
     ;
 extern double acos (double __x) ; extern double __acos (double __x) ;
 extern double asin (double __x) ; extern double __asin (double __x) ;
 extern double atan (double __x) ; extern double __atan (double __x) ;
 extern double atan2 (double __y, double __x) ; extern double __atan2 (double __y, double __x) ;
 extern double cos (double __x) ; extern double __cos (double __x) ;
 extern double sin (double __x) ; extern double __sin (double __x) ;
 extern double tan (double __x) ; extern double __tan (double __x) ;
 extern double cosh (double __x) ; extern double __cosh (double __x) ;
 extern double sinh (double __x) ; extern double __sinh (double __x) ;
 extern double tanh (double __x) ; extern double __tanh (double __x) ;
 extern double acosh (double __x) ; extern double __acosh (double __x) ;
 extern double asinh (double __x) ; extern double __asinh (double __x) ;
 extern double atanh (double __x) ; extern double __atanh (double __x) ;
 extern double exp (double __x) ; extern double __exp (double __x) ;
extern double frexp (double __x, int *__exponent) ; extern double __frexp (double __x, int *__exponent) ;
extern double ldexp (double __x, int __exponent) ; extern double __ldexp (double __x, int __exponent) ;
 extern double log (double __x) ; extern double __log (double __x) ;
 extern double log10 (double __x) ; extern double __log10 (double __x) ;
extern double modf (double __x, double *__iptr) ; extern double __modf (double __x, double *__iptr) ;
 extern double expm1 (double __x) ; extern double __expm1 (double __x) ;
 extern double log1p (double __x) ; extern double __log1p (double __x) ;
extern double logb (double __x) ; extern double __logb (double __x) ;
 extern double exp2 (double __x) ; extern double __exp2 (double __x) ;
 extern double log2 (double __x) ; extern double __log2 (double __x) ;
 extern double pow (double __x, double __y) ; extern double __pow (double __x, double __y) ;
extern double sqrt (double __x) ; extern double __sqrt (double __x) ;
 extern double hypot (double __x, double __y) ; extern double __hypot (double __x, double __y) ;
 extern double cbrt (double __x) ; extern double __cbrt (double __x) ;
extern double ceil (double __x) ; extern double __ceil (double __x) ;
extern double fabs (double __x) ; extern double __fabs (double __x) ;
extern double floor (double __x) ; extern double __floor (double __x) ;
extern double fmod (double __x, double __y) ; extern double __fmod (double __x, double __y) ;
extern int isinf (double __value)
  ;
extern int finite (double __value)
  ;
extern double drem (double __x, double __y) ; extern double __drem (double __x, double __y) ;
extern double significand (double __x) ; extern double __significand (double __x) ;
extern double copysign (double __x, double __y) ; extern double __copysign (double __x, double __y) ;
extern double nan (const char *__tagb) ; extern double __nan (const char *__tagb) ;
extern int isnan (double __value)
  ;
extern double j0 (double) ; extern double __j0 (double) ;
extern double j1 (double) ; extern double __j1 (double) ;
extern double jn (int, double) ; extern double __jn (int, double) ;
extern double y0 (double) ; extern double __y0 (double) ;
extern double y1 (double) ; extern double __y1 (double) ;
extern double yn (int, double) ; extern double __yn (int, double) ;
 extern double erf (double) ; extern double __erf (double) ;
 extern double erfc (double) ; extern double __erfc (double) ;
extern double lgamma (double) ; extern double __lgamma (double) ;
extern double tgamma (double) ; extern double __tgamma (double) ;
extern double gamma (double) ; extern double __gamma (double) ;
extern double lgamma_r (double, int *__signgamp) ; extern double __lgamma_r (double, int *__signgamp) ;
extern double rint (double __x) ; extern double __rint (double __x) ;
extern double nextafter (double __x, double __y) ; extern double __nextafter (double __x, double __y) ;
extern double nexttoward (double __x, long double __y) ; extern double __nexttoward (double __x, long double __y) ;
extern double remainder (double __x, double __y) ; extern double __remainder (double __x, double __y) ;
extern double scalbn (double __x, int __n) ; extern double __scalbn (double __x, int __n) ;
extern int ilogb (double __x) ; extern int __ilogb (double __x) ;
extern double scalbln (double __x, long int __n) ; extern double __scalbln (double __x, long int __n) ;
extern double nearbyint (double __x) ; extern double __nearbyint (double __x) ;
extern double round (double __x) ; extern double __round (double __x) ;
extern double trunc (double __x) ; extern double __trunc (double __x) ;
extern double remquo (double __x, double __y, int *__quo) ; extern double __remquo (double __x, double __y, int *__quo) ;
extern long int lrint (double __x) ; extern long int __lrint (double __x) ;

extern long long int llrint (double __x) ; extern long long int __llrint (double __x) ;
extern long int lround (double __x) ; extern long int __lround (double __x) ;

extern long long int llround (double __x) ; extern long long int __llround (double __x) ;
extern double fdim (double __x, double __y) ; extern double __fdim (double __x, double __y) ;
extern double fmax (double __x, double __y) ; extern double __fmax (double __x, double __y) ;
extern double fmin (double __x, double __y) ; extern double __fmin (double __x, double __y) ;
extern double fma (double __x, double __y, double __z) ; extern double __fma (double __x, double __y, double __z) ;
extern double scalb (double __x, double __n) ; extern double __scalb (double __x, double __n) ;
extern int __fpclassifyf (float __value)
     ;
extern int __signbitf (float __value)
     ;
extern int __isinff (float __value)
  ;
extern int __finitef (float __value)
  ;
extern int __isnanf (float __value)
  ;
extern int __iseqsigf (float __x, float __y) ;
extern int __issignalingf (float __value)
     ;
 extern float acosf (float __x) ; extern float __acosf (float __x) ;
 extern float asinf (float __x) ; extern float __asinf (float __x) ;
 extern float atanf (float __x) ; extern float __atanf (float __x) ;
 extern float atan2f (float __y, float __x) ; extern float __atan2f (float __y, float __x) ;
 extern float cosf (float __x) ; extern float __cosf (float __x) ;
 extern float sinf (float __x) ; extern float __sinf (float __x) ;
 extern float tanf (float __x) ; extern float __tanf (float __x) ;
 extern float coshf (float __x) ; extern float __coshf (float __x) ;
 extern float sinhf (float __x) ; extern float __sinhf (float __x) ;
 extern float tanhf (float __x) ; extern float __tanhf (float __x) ;
 extern float acoshf (float __x) ; extern float __acoshf (float __x) ;
 extern float asinhf (float __x) ; extern float __asinhf (float __x) ;
 extern float atanhf (float __x) ; extern float __atanhf (float __x) ;
 extern float expf (float __x) ; extern float __expf (float __x) ;
extern float frexpf (float __x, int *__exponent) ; extern float __frexpf (float __x, int *__exponent) ;
extern float ldexpf (float __x, int __exponent) ; extern float __ldexpf (float __x, int __exponent) ;
 extern float logf (float __x) ; extern float __logf (float __x) ;
 extern float log10f (float __x) ; extern float __log10f (float __x) ;
extern float modff (float __x, float *__iptr) ; extern float __modff (float __x, float *__iptr) ;
 extern float expm1f (float __x) ; extern float __expm1f (float __x) ;
 extern float log1pf (float __x) ; extern float __log1pf (float __x) ;
extern float logbf (float __x) ; extern float __logbf (float __x) ;
 extern float exp2f (float __x) ; extern float __exp2f (float __x) ;
 extern float log2f (float __x) ; extern float __log2f (float __x) ;
 extern float powf (float __x, float __y) ; extern float __powf (float __x, float __y) ;
extern float sqrtf (float __x) ; extern float __sqrtf (float __x) ;
 extern float hypotf (float __x, float __y) ; extern float __hypotf (float __x, float __y) ;
 extern float cbrtf (float __x) ; extern float __cbrtf (float __x) ;
extern float ceilf (float __x) ; extern float __ceilf (float __x) ;
extern float fabsf (float __x) ; extern float __fabsf (float __x) ;
extern float floorf (float __x) ; extern float __floorf (float __x) ;
extern float fmodf (float __x, float __y) ; extern float __fmodf (float __x, float __y) ;
extern int isinff (float __value)
  ;
extern int finitef (float __value)
  ;
extern float dremf (float __x, float __y) ; extern float __dremf (float __x, float __y) ;
extern float significandf (float __x) ; extern float __significandf (float __x) ;
extern float copysignf (float __x, float __y) ; extern float __copysignf (float __x, float __y) ;
extern float nanf (const char *__tagb) ; extern float __nanf (const char *__tagb) ;
extern int isnanf (float __value)
  ;
extern float j0f (float) ; extern float __j0f (float) ;
extern float j1f (float) ; extern float __j1f (float) ;
extern float jnf (int, float) ; extern float __jnf (int, float) ;
extern float y0f (float) ; extern float __y0f (float) ;
extern float y1f (float) ; extern float __y1f (float) ;
extern float ynf (int, float) ; extern float __ynf (int, float) ;
 extern float erff (float) ; extern float __erff (float) ;
 extern float erfcf (float) ; extern float __erfcf (float) ;
extern float lgammaf (float) ; extern float __lgammaf (float) ;
extern float tgammaf (float) ; extern float __tgammaf (float) ;
extern float gammaf (float) ; extern float __gammaf (float) ;
extern float lgammaf_r (float, int *__signgamp) ; extern float __lgammaf_r (float, int *__signgamp) ;
extern float rintf (float __x) ; extern float __rintf (float __x) ;
extern float nextafterf (float __x, float __y) ; extern float __nextafterf (float __x, float __y) ;
extern float nexttowardf (float __x, long double __y) ; extern float __nexttowardf (float __x, long double __y) ;
extern float remainderf (float __x, float __y) ; extern float __remainderf (float __x, float __y) ;
extern float scalbnf (float __x, int __n) ; extern float __scalbnf (float __x, int __n) ;
extern int ilogbf (float __x) ; extern int __ilogbf (float __x) ;
extern float scalblnf (float __x, long int __n) ; extern float __scalblnf (float __x, long int __n) ;
extern float nearbyintf (float __x) ; extern float __nearbyintf (float __x) ;
extern float roundf (float __x) ; extern float __roundf (float __x) ;
extern float truncf (float __x) ; extern float __truncf (float __x) ;
extern float remquof (float __x, float __y, int *__quo) ; extern float __remquof (float __x, float __y, int *__quo) ;
extern long int lrintf (float __x) ; extern long int __lrintf (float __x) ;

extern long long int llrintf (float __x) ; extern long long int __llrintf (float __x) ;
extern long int lroundf (float __x) ; extern long int __lroundf (float __x) ;

extern long long int llroundf (float __x) ; extern long long int __llroundf (float __x) ;
extern float fdimf (float __x, float __y) ; extern float __fdimf (float __x, float __y) ;
extern float fmaxf (float __x, float __y) ; extern float __fmaxf (float __x, float __y) ;
extern float fminf (float __x, float __y) ; extern float __fminf (float __x, float __y) ;
extern float fmaf (float __x, float __y, float __z) ; extern float __fmaf (float __x, float __y, float __z) ;
extern float scalbf (float __x, float __n) ; extern float __scalbf (float __x, float __n) ;
extern int __fpclassifyl (long double __value)
     ;
extern int __signbitl (long double __value)
     ;
extern int __isinfl (long double __value)
  ;
extern int __finitel (long double __value)
  ;
extern int __isnanl (long double __value)
  ;
extern int __iseqsigl (long double __x, long double __y) ;
extern int __issignalingl (long double __value)
     ;
 extern long double acosl (long double __x) ; extern long double __acosl (long double __x) ;
 extern long double asinl (long double __x) ; extern long double __asinl (long double __x) ;
 extern long double atanl (long double __x) ; extern long double __atanl (long double __x) ;
 extern long double atan2l (long double __y, long double __x) ; extern long double __atan2l (long double __y, long double __x) ;
 extern long double cosl (long double __x) ; extern long double __cosl (long double __x) ;
 extern long double sinl (long double __x) ; extern long double __sinl (long double __x) ;
 extern long double tanl (long double __x) ; extern long double __tanl (long double __x) ;
 extern long double coshl (long double __x) ; extern long double __coshl (long double __x) ;
 extern long double sinhl (long double __x) ; extern long double __sinhl (long double __x) ;
 extern long double tanhl (long double __x) ; extern long double __tanhl (long double __x) ;
 extern long double acoshl (long double __x) ; extern long double __acoshl (long double __x) ;
 extern long double asinhl (long double __x) ; extern long double __asinhl (long double __x) ;
 extern long double atanhl (long double __x) ; extern long double __atanhl (long double __x) ;
 extern long double expl (long double __x) ; extern long double __expl (long double __x) ;
extern long double frexpl (long double __x, int *__exponent) ; extern long double __frexpl (long double __x, int *__exponent) ;
extern long double ldexpl (long double __x, int __exponent) ; extern long double __ldexpl (long double __x, int __exponent) ;
 extern long double logl (long double __x) ; extern long double __logl (long double __x) ;
 extern long double log10l (long double __x) ; extern long double __log10l (long double __x) ;
extern long double modfl (long double __x, long double *__iptr) ; extern long double __modfl (long double __x, long double *__iptr) ;
 extern long double expm1l (long double __x) ; extern long double __expm1l (long double __x) ;
 extern long double log1pl (long double __x) ; extern long double __log1pl (long double __x) ;
extern long double logbl (long double __x) ; extern long double __logbl (long double __x) ;
 extern long double exp2l (long double __x) ; extern long double __exp2l (long double __x) ;
 extern long double log2l (long double __x) ; extern long double __log2l (long double __x) ;
 extern long double powl (long double __x, long double __y) ; extern long double __powl (long double __x, long double __y) ;
extern long double sqrtl (long double __x) ; extern long double __sqrtl (long double __x) ;
 extern long double hypotl (long double __x, long double __y) ; extern long double __hypotl (long double __x, long double __y) ;
 extern long double cbrtl (long double __x) ; extern long double __cbrtl (long double __x) ;
extern long double ceill (long double __x) ; extern long double __ceill (long double __x) ;
extern long double fabsl (long double __x) ; extern long double __fabsl (long double __x) ;
extern long double floorl (long double __x) ; extern long double __floorl (long double __x) ;
extern long double fmodl (long double __x, long double __y) ; extern long double __fmodl (long double __x, long double __y) ;
extern int isinfl (long double __value)
  ;
extern int finitel (long double __value)
  ;
extern long double dreml (long double __x, long double __y) ; extern long double __dreml (long double __x, long double __y) ;
extern long double significandl (long double __x) ; extern long double __significandl (long double __x) ;
extern long double copysignl (long double __x, long double __y) ; extern long double __copysignl (long double __x, long double __y) ;
extern long double nanl (const char *__tagb) ; extern long double __nanl (const char *__tagb) ;
extern int isnanl (long double __value)
  ;
extern long double j0l (long double) ; extern long double __j0l (long double) ;
extern long double j1l (long double) ; extern long double __j1l (long double) ;
extern long double jnl (int, long double) ; extern long double __jnl (int, long double) ;
extern long double y0l (long double) ; extern long double __y0l (long double) ;
extern long double y1l (long double) ; extern long double __y1l (long double) ;
extern long double ynl (int, long double) ; extern long double __ynl (int, long double) ;
 extern long double erfl (long double) ; extern long double __erfl (long double) ;
 extern long double erfcl (long double) ; extern long double __erfcl (long double) ;
extern long double lgammal (long double) ; extern long double __lgammal (long double) ;
extern long double tgammal (long double) ; extern long double __tgammal (long double) ;
extern long double gammal (long double) ; extern long double __gammal (long double) ;
extern long double lgammal_r (long double, int *__signgamp) ; extern long double __lgammal_r (long double, int *__signgamp) ;
extern long double rintl (long double __x) ; extern long double __rintl (long double __x) ;
extern long double nextafterl (long double __x, long double __y) ; extern long double __nextafterl (long double __x, long double __y) ;
extern long double nexttowardl (long double __x, long double __y) ; extern long double __nexttowardl (long double __x, long double __y) ;
extern long double remainderl (long double __x, long double __y) ; extern long double __remainderl (long double __x, long double __y) ;
extern long double scalbnl (long double __x, int __n) ; extern long double __scalbnl (long double __x, int __n) ;
extern int ilogbl (long double __x) ; extern int __ilogbl (long double __x) ;
extern long double scalblnl (long double __x, long int __n) ; extern long double __scalblnl (long double __x, long int __n) ;
extern long double nearbyintl (long double __x) ; extern long double __nearbyintl (long double __x) ;
extern long double roundl (long double __x) ; extern long double __roundl (long double __x) ;
extern long double truncl (long double __x) ; extern long double __truncl (long double __x) ;
extern long double remquol (long double __x, long double __y, int *__quo) ; extern long double __remquol (long double __x, long double __y, int *__quo) ;
extern long int lrintl (long double __x) ; extern long int __lrintl (long double __x) ;

extern long long int llrintl (long double __x) ; extern long long int __llrintl (long double __x) ;
extern long int lroundl (long double __x) ; extern long int __lroundl (long double __x) ;

extern long long int llroundl (long double __x) ; extern long long int __llroundl (long double __x) ;
extern long double fdiml (long double __x, long double __y) ; extern long double __fdiml (long double __x, long double __y) ;
extern long double fmaxl (long double __x, long double __y) ; extern long double __fmaxl (long double __x, long double __y) ;
extern long double fminl (long double __x, long double __y) ; extern long double __fminl (long double __x, long double __y) ;
extern long double fmal (long double __x, long double __y, long double __z) ; extern long double __fmal (long double __x, long double __y, long double __z) ;
extern long double scalbl (long double __x, long double __n) ; extern long double __scalbl (long double __x, long double __n) ;
extern int __fpclassifyf128 ( __value)
     ;
extern int __signbitf128 ( __value)
     ;
extern int __isinff128 ( __value)
  ;
extern int __finitef128 ( __value)
  ;
extern int __isnanf128 ( __value)
  ;
extern int __iseqsigf128 ( __x, __y) ;
extern int __issignalingf128 ( __value)
     ;
extern int signgam;
enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };

struct Surf {
 int TYPE;
 double RADIUS;
  int RADIUS_UNIT;
 int AXIS;
};
struct Disp {
 int COORD_TYPE;
 int PCOORD;
 int QCOORD;
 double XCOORD;
 double YCOORD;
};
struct Grid {
 char NAME[30 +1];
 int LEVEL;
 int TYPE;
 int ORIENT;
 double ANGLE;
 int ANGLE_UNIT;
 double PSTEP;
 double QSTEP;
 int PQSTEP_UNIT;
 double PX;
 double PY;
 double QX;
 double QY;
 int PQXY_UNIT;
 double ROT_ANGLE;
};
struct Port {
 int PORTNUM;
 double AMP;
 int AMP_UNIT;
 double PSC;
 int PSC_UNIT;
 double PSH;
 int PSH_UNIT;
 double PPA;
 int PPA_UNIT;
 double PHEPOL;
 int PHEPOL_UNIT;
 int OMIT_POL;
 struct Port *NEXT;
};
struct Elem {
 int TYPE;
 char NAME[30 +1];
 int LEVEL;
 int GEOMETRY;
 double RADIUS;
 int RADIUS_UNIT;
 double PDIM;
 double QDIM;
 int PQDIM_UNIT;
 int MODEL;
 double EXP;
 double ANGLEE;
 double ANGLEH;
 int ANGLE_UNIT;
 double TAPERE;
 double TAPERH;
 int TAPER_UNIT;
 int POLARIZATION;
 double PHEPOL;
 int PHEPOL_UNIT;
 int DIRECTION;
 double GAIN;
 int GAIN_UNIT;
 int NPORTS;
 struct Port *PORT_PTR;
};
struct Array {
 char NAME[30 +1];
 struct Surf SURF;
 struct Grid *GRID_PTR;
 struct Elem *ELEM_PTR;
 struct Group *GROUP_PTR;
 struct AddGroup *ADDGROUP_PTR;
 struct Disp DISP;
};
struct PQExp { int dummy; };
struct GrAmpExc {
 int TYPE;
 double UNIF_VAL;
 double CENTRE;
 double P1_ET;
 double P2_ET;
 double Q1_ET;
 double Q2_ET;
 int AMP_UNIT;
 struct PQExp *PQEXP_PTR;
};
struct GrPhaExc {
 int TYPE;
 double UNIF_VAL;
 double CENTRE;
 double P1_EP;
 double P2_EP;
 double Q1_EP;
 double Q2_EP;
 int DIRECTION;
 int OMIT_ANGLE;
 double ANGLE_START;
 double ANGLE_STEP;
 int OMIT_PHASE;
 double PHASE_START;
 double PHASE_STEP;
 double U;
 double V;
 double THETA;
 double PHI;
 struct PQExp *PQEXP_PTR;
 int ANGLE_UNIT;
 int PHASE_UNIT;
};
struct Err {
 int AMP_TYPE;
 double AMP_STDEV;
 double AMP_LINOFFS;
 double AMP_LINSTEP;
 double AMP_2NDCENT;
 double AMP_2NDPET;
 double AMP_2NDQET;
 int AMP_UNIT;
 int PHASE_TYPE;
 double PHASE_STDEV;
 double PHASE_LINOFFS;
 double PHASE_LINSTEP;
 double PHASE_2NDCENT;
 double PHASE_2NDPSID;
 double PHASE_2NDQSID;
 double PHASE_QUANTSTEP;
 int PHASE_UNIT;
};
struct Fail {
 int NUM_FAULTY_EL;
 double FIXED_AMP;
 double FIXED_PHASE;
};
struct Group {
 char NAME[30 +1];
 struct Grid *GRID_PTR;
 struct Elem *ELEM_PTR;
 struct AddRem *ADDREM_PTR;
 struct GrAmpExc *GRAMPEXC_PTR;
 struct GrPhaExc *GRPHAEXC_PTR;
  struct Err *ERR_PTR;
 struct Fail *FAIL_PTR;
 struct Group *NEXT;
 int NUM_OF_NODES;
 int SHAPE;
 double PSIZE;
 double QSIZE;
 struct Geomnode *GEOMNODE_PTR;
 int BUILT;
 struct Group *SUPER_GROUP_PTR[5];
};
struct AddGroup {
 char NAME[30 +1];
 int COORD_TYPE;
 int PCOORD;
 int QCOORD;
 double XCOORD;
 double YCOORD;
 struct Group *GROUP_PTR;
 struct AddGroup *NEXT;
};
struct AddRem {
 int ADDREM_TYPE;
 int BLOCK_TYPE;
 struct Node *NODE_PTR;
 struct AddRem *NEXT;
};
struct Node {
 int OMIT_ORIENT;
 int PCOORD;
 int QCOORD;
 double THEA;
 double PHEA;
 double PSEA;
 int ANGLE_UNIT;
 struct Node *NEXT;
};
struct charac {
 char info;
 int LINE_NUM;
 struct charac *PREV;
 struct charac *NEXT;
};
char UserNames[20 +1][30 +1];
char Keywords[125 +1][20 +1];
char ErrorMessages[100 +1][100 +1];
struct Geomnode {
 int LOC_P;
 int LOC_Q;
 double XA;
 double YA;
 double ZA;
 double THEA;
 double PHEA;
 double PSEA;
 struct Geomport *GEOMPORT_PTR;
 struct Geomnode *NEXT;
 struct Geomnode *SUBGROUP_PTR;
 int SHAPE;
 double PSIZE;
 double QSIZE;
};
struct Geomport {
 double AMP;
 double PSH;
 double PSC;
 double PPA;
 double PHEPOL;
 struct Geomport *NEXT;
};
char MOSErrors[20 +1][100 +1];
char GLOBLE_FILENAME[30 + 1];
void parserro(struct charac * err_ptr, int errcode, char *s);
void kwdsinit(void);
void emsginit(void);
void unaminit(void);
void moseinit(void);
void glvainit(void);
char TapeGet(struct charac ** tp);
void waitcont(void);
int isletter(char ch);
int InKWords(char *WORD);
int InUNames(char *WORD);
void interror(char *subname);
int InserUN(char *WORD);
int EndOfTape(struct charac ** p);
void floatsup(void);
void nomefile(char fn[30 + 1]);
void prnfile(struct charac * firstel);
int answer(char domanda[100]);
int readfil3(char filename[30 + 1], struct charac ** firstel, struct charac ** lastel);
int GetKeyword(char *kw, struct charac ** tp);
int GetUName(char word[30 + 1], struct charac ** tp);
int GetReal(double *reale, struct charac ** tp);
int GetUReal(struct charac * p1, struct charac ** pp2, double *ureal_ptr);
int Get1Real(struct charac * p1, struct charac ** pp2, double *ureal_ptr);
int GetInt(struct charac * p1, struct charac ** pp2, int *intero_ptr);
int GetNatur(struct charac * p1, struct charac ** pp2, int *natur_ptr);
int lenunit(struct charac ** tp, int *unit);
int
angunit(struct charac * p1, struct charac ** pp2,
 int *angle_unit_ptr);
int ampunit(struct charac ** tp, int *unit_ptr);
int
squgrdef(struct charac * p1, struct charac ** pp2,
  double *pstep_ptr,
  int *pstep_unit_ptr);
int
recgrdef(struct charac * p1, struct charac ** pp2,
  double *pstep_ptr,
  double *qstep_ptr,
  int *pqstep_unit_ptr);
int
hexgrdef(struct charac * p1, struct charac ** pp2,
  double *pstep_ptr,
  int *pstep_unit_ptr);
int
trigrdef(struct charac * p1, struct charac ** pp2,
  double *angle_ptr,
  int *angle_unit_ptr,
  double *pstep_ptr,
  double *qstep_ptr,
  int *pqstep_unit_ptr,
  double *px_ptr,
  double *py_ptr,
  double *qx_ptr,
  double *qy_ptr,
  int *pqxy_unit_ptr);
int
griddef1(struct charac * p1, struct charac ** pp2,
  struct Grid ** grid_ptr);
int
doubstep(struct charac * p1, struct charac ** pp2,
  double *pstep_ptr,
  double *qstep_ptr,
  int *pqstep_unit_ptr);
int
angclaus(struct charac * p1, struct charac ** pp2,
  double *angle_ptr,
  int *angle_unit_ptr);
int
angstep(struct charac * p1, struct charac ** pp2,
 double *angle_ptr,
 int *angle_unit_ptr,
 double *pstep_ptr,
 double *qstep_ptr,
 int *pqstep_unit_ptr);
int
versdef(struct charac * p1, struct charac ** pp2,
 double *px_ptr,
 double *py_ptr,
 double *qx_ptr,
 double *qy_ptr,
 int *pqxy_unit_ptr);
int
sinstep(struct charac * p1, struct charac ** pp2,
 double *step_ptr,
 int *step_unit_ptr);
int
recspec(struct charac * p1, struct charac ** pp2,
 double *pdim_ptr,
 double *qdim_ptr,
 int *pqdim_unit_ptr);
int
geomspec(struct charac * p1, struct charac ** pp2,
  int *geometry_ptr,
  double *radius_ptr,
  int *radius_unit_ptr,
  double *pdim_ptr,
  double *qdim_ptr,
  int *pqdim_unit_ptr);
int
circspec(struct charac * p1, struct charac ** pp2,
  double *radius_ptr,
  int *radius_unit_ptr);
int extmod(struct charac * p1, struct charac ** pp2);
int
gaussel(struct charac * p1, struct charac ** pp2,
 double *anglee_ptr,
 double *angleh_ptr,
 int *angle_unit_ptr,
 double *tapere_ptr,
 double *taperh_ptr,
 int *taper_unit_ptr);
int
cosinus(struct charac * p1, struct charac ** pp2,
 double *exp_ptr);
int
modspec(struct charac * p1, struct charac ** pp2,
 int *model_ptr,
 double *exp_ptr,
 double *anglee_ptr,
 double *angleh_ptr,
 int *angle_unit_ptr,
 double *tapere_ptr,
 double *taperh_ptr,
 int *taper_unit_ptr);
int
angval(struct charac * p1, struct charac ** pp2,
       double *angle_ptr,
       int *angle_unit_ptr);
int
polor(struct charac * p1, struct charac ** pp2,
      double *phiangle_ptr,
      int *phiangle_unit_ptr);
int
linpol(struct charac * p1, struct charac ** pp2,
       double *angle_ptr,
       int *angle_unit_ptr);
int
circpol(struct charac * p1, struct charac ** pp2,
 int *direction_ptr);
int
polspec(struct charac * p1, struct charac ** pp2,
 int *polarization_ptr,
 double *phepol_ptr,
 int *phepol_unit_ptr,
 int *direction_ptr);
int
gainunit(struct charac * p1, struct charac ** pp2,
  int *gain_unit_ptr);
int
gainval(struct charac * p1, struct charac ** pp2,
 double *gain_ptr,
 int *gain_unit_ptr);
int
gainspec(struct charac * p1, struct charac ** pp2,
  double *gain_ptr,
  int *gain_unit_ptr);
int
sinelem(struct charac * p1, struct charac ** pp2,
 struct Elem ** elem_ptr);
int
pshdef1(struct charac * p1, struct charac ** pp2,
 double *psh_ptr,
 int *psh_unit_ptr);
int
pscdef1(struct charac * p1, struct charac ** pp2,
 double *psc_ptr,
 int *psc_unit_ptr);
int
ppadef1(struct charac * p1, struct charac ** pp2,
 double *ppa_ptr,
 int *ppa_unit_ptr);
int
polorbis(struct charac * p1, struct charac ** pp2,
  double *phepol_ptr,
  int *phepol_unit_ptr);
int
ampval(struct charac * p1, struct charac ** pp2,
       double *amp_ptr,
       int *amp_unit_ptr);
int
portamp(struct charac * p1, struct charac ** pp2,
 double *amp_ptr,
 int *amp_unit_ptr);
int
portdef(struct charac * p1, struct charac ** pp2,
 struct Port * PORT_PTR,
 int *portnum_ptr);
int
portspec(struct charac * p1, struct charac ** pp2,
  int *nports_ptr,
  struct Port ** port_ptr);
int
elemdef(struct charac * p1, struct charac ** pp2,
 struct Elem ** elem_ptr);
int
nodorien(struct charac * p1, struct charac ** pp2,
  double *theta_ptr,
  double *phi_ptr,
  double *psi_ptr,
  int *angle_unit_ptr);
int
nodecoor(struct charac * p1, struct charac ** pp2,
  int *pcoord_ptr,
  int *qcoord_ptr);
int
nodedef(struct charac * p1, struct charac ** pp2,
 struct Node ** node_ptr);
int
blockdef(struct charac * p1, struct charac ** pp2,
  struct Node ** node_ptr);
int
adddef(struct charac * p1, struct charac ** pp2,
       struct AddRem ** addrem_ptr);
int
remdef(struct charac * p1, struct charac ** pp2,
       struct AddRem ** addrem_ptr);
int
adremdef(struct charac * p1, struct charac ** pp2,
  struct AddRem ** addrem_ptr);
int
grgeodef(struct charac * p1, struct charac ** pp2,
  struct AddRem ** addrem_ptr);
int
hexdef(struct charac * p1, struct charac ** pp2,
       struct Node ** node_ptr);
int
polydef(struct charac * p1, struct charac ** pp2,
 struct Node ** node_ptr);
int
greldef(struct charac * p1, struct charac ** pp2,
 struct Grid ** grid_ptr,
 struct Elem ** elem_ptr);
int
secoramp(struct charac * p1, struct charac ** pp2,
  double *centre_ptr,
  double *p1_et_ptr,
  double *p2_et_ptr,
  double *q1_et_ptr,
  double *q2_et_ptr,
  int *amp_unit_ptr);
int
unifamp(struct charac * p1, struct charac ** pp2,
 double *unif_val_ptr,
 int *amp_unit_ptr);
int
grampexc(struct charac * p1, struct charac ** pp2,
  struct GrAmpExc ** grampexc_ptr);
int
angledir(struct charac * p1, struct charac ** pp2,
  double *theta_ptr,
  double *phi_ptr,
  int *angle_unit_ptr);
int
uvval(struct charac * p1,
      struct charac ** pp2, double *val_ptr);
int
uvdir(struct charac * p1, struct charac ** pp2,
      double *u_ptr,
      double *v_ptr);
int
beampha(struct charac * p1, struct charac ** pp2,
 double *u_ptr,
 double *v_ptr,
 double *theta_ptr,
 double *phi_ptr,
 int *angle_unit_ptr);
int
phaserot(struct charac * p1, struct charac ** pp2,
  double *phase_start_ptr,
  double *phase_step_ptr,
  int *phase_unit_ptr);
int
anglerot(struct charac * p1, struct charac ** pp2,
  double *angle_start_ptr,
  double *angle_step_ptr,
  int *angle_unit_ptr);
int
serotdir(struct charac * p1, struct charac ** pp2,
  int *direction_ptr);
int
serotpar(struct charac * p1, struct charac ** pp2,
  double *angle_start_ptr,
  double *angle_step_ptr,
  int *omit_phase_ptr,
  double *phase_start_ptr,
  double *phase_step_ptr,
  int *angle_unit_ptr,
  int *phase_unit_ptr);
int
serotpha(struct charac * p1, struct charac ** pp2,
  int *direction_ptr,
  int *omit_angle_ptr,
  double *angle_start_ptr,
  double *angle_step_ptr,
  int *omit_phase_ptr,
  double *phase_start_ptr,
  double *phase_step_ptr,
  int *angle_unit_ptr,
  int *phase_unit_ptr);
int
secorpha(struct charac * p1, struct charac ** pp2,
  double *centre_ptr,
  double *p1_ep_ptr,
  double *p2_ep_ptr,
  double *q1_ep_ptr,
  double *q2_ep_ptr,
  int *phase_unit_ptr);
int
unifpha(struct charac * p1, struct charac ** pp2,
 double *unif_val_ptr,
 int *phase_unit_ptr);
int
grphaexc(struct charac * p1, struct charac ** pp2,
  struct GrPhaExc ** grphaexc_ptr);
int
grexcdef(struct charac * p1, struct charac ** pp2,
  struct GrAmpExc ** grampexc_ptr,
  struct GrPhaExc ** grphaexc_ptr);
int
groupdef(struct charac * p1, struct charac ** pp2,
  struct Group ** group_ptr);
int intmin(int a, int b);
int intmax(int a, int b);
double doubmin(double a, double b);
double doubmax(double a, double b);
double dcos(double x);
double dsin(double x);
double dacos(double x);
double dasin(double x);
double datan(double x);
int mmconv(double *x_ptr, int unit);
int degconv(double *x_ptr, int unit);
int linconv(double *x_ptr, int unit);
int grwrite(struct Group * group_ptr, char filename[30 + 1]);
int
mksnode(struct AddRem * addrem_ptr,
 struct Geomnode ** first_node_ptr,
 struct Geomnode ** last_node_ptr,
 double pstep,
 double qstep,
 double angle,
 int *nodes_num_ptr,
 int elem_shape,
 double elem_pdim,
 double elem_qdim);
int
mksblock(struct AddRem * addrem_ptr,
  struct Geomnode ** first_node_ptr,
  struct Geomnode ** last_node_ptr,
  double pstep,
  double qstep,
  double angle,
  int *nodes_num_ptr,
  int elem_shape,
  double elem_pdim,
  double elem_qdim);
int
mkshex(struct AddRem * addrem_ptr,
       struct Geomnode ** first_node_ptr,
       struct Geomnode ** last_node_ptr,
       double pstep,
       double qstep,
       double angle,
       int *nodes_num_ptr,
       int elem_shape,
       double elem_pdim,
       double elem_qdim);
int addscan(struct Group * group_ptr);
int
extremes(struct Geomnode * gnode_ptr,
  int *pnum_ptr,
  int *qnum_ptr);
int simgroup(struct Group * group_ptr);
int fixnodor(struct Node * node_ptr);
int fixsgrel(struct Group * group_ptr);
int fixsgrid(struct Grid * grid);
int fixselem(struct Elem * elem);
int
extsize(struct Geomnode * gnode_ptr,
 double elem_pdim,
 double elem_qdim,
 double *xsize_ptr,
 double *ysize_ptr);
int
sgrrot(struct Geomnode * start_ptr,
       double XC,
       double YC,
       double phi);
int fixgramp(struct GrAmpExc * g);
int fixport(struct Elem * elem_ptr);
int
sgrampun(struct GrAmpExc * grampexc_ptr,
  struct Geomnode * gnode_ptr,
  struct Port * port_ptr);
int simamp(struct Group * group_ptr);
int
pqlimits(struct Geomnode * gnode_ptr,
  struct Geomnode ** pmin_ptr,
  struct Geomnode ** pmax_ptr,
  struct Geomnode ** qmin_ptr,
  struct Geomnode ** qmax_ptr);
int
sgramp2n(struct GrAmpExc * grampexc_ptr,
  struct Geomnode * gnode_ptr,
  struct Port * port_ptr,
  int group_shape);
double
secorder(double a,
  double b,
  double c,
  double d,
  double e,
  double x,
  double y);
int simpol(struct Group * group_ptr);
int simpha(struct Group * group_ptr);
int fixgrpha(struct GrPhaExc * gphaexc_ptr);
int
sgrphaun(struct GrPhaExc * grphaexc_ptr,
  struct Geomnode * geomnode_ptr,
  struct Port * port_ptr);
int
sgrpha2n(struct GrPhaExc * grphaexc_ptr,
  struct Geomnode * geomnode_ptr,
  struct Port * port_ptr,
  int group_shape);
int
gnodfind(struct Geomnode * gnode_list_start_ptr,
  struct Geomnode ** gnode_ptr,
  int p,
  int q);
void
gnodevis(int p,
  int q,
  double angle,
  double phase,
  struct Geomnode * gnode_list_start_ptr);
void
seqrotrg(double angle_start,
  double angle_step,
  double phase_start,
  double phase_step,
  struct Geomnode * g);
void
seqrothg(double angle_start,
  double angle_step,
  double phase_start,
  double phase_step,
  struct Geomnode * g);
int sgrphasr(struct Group * group_ptr);
int
main(int argc, char *argv[])
{
 struct charac *first = ((void *)0), *last = ((void *)0);
 struct charac *cp = ((void *)0);
 struct Group *group_ptr = ((void *)0);
 int error = 0;
 char fn[30 + 1];
 if (argc != 2) {
  printf("\n\tUSAGE: %s [<source-file-name>]\n\n", "space.exe");
  exit(1);
 }
 strcpy(GLOBLE_FILENAME, argv[1]);
 glvainit();
 nomefile(fn);
 if (readfil3(fn, &first, &last) != 0) {
  exit(1);
 };
 prnfile(first);
 error = groupdef(first, &cp, &group_ptr);
 waitcont();
 if (error != 0) {
  exit(1);
 };
 if (error = simgroup(group_ptr)) {
  exit(1);
 };
 if (error = simamp(group_ptr)) {
  exit(1);
 };
 if (error = simpha(group_ptr)) {
  exit(1);
 };
 simpol(group_ptr);
 waitcont();
 grwrite(group_ptr, fn);
}
int
adddef(struct charac * p1, struct charac ** pp2,
       struct AddRem ** addrem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 struct Node *no_ptr = ((void *)0), **node_ptr = &no_ptr;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[79], curr_ptr));
 if (error != 0) {
  *addrem_ptr = ((void *)0);
  return 1;
 };
 error = nodedef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  parserro(*curr_ptr, 58, " ");
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("adddef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 0;
  (*addrem_ptr)->BLOCK_TYPE = 0;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = blockdef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  parserro(*curr_ptr, 59, " ");
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("adddef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 0;
  (*addrem_ptr)->BLOCK_TYPE = 1;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = polydef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  parserro(*curr_ptr, 60, " ");
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("adddef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 0;
  (*addrem_ptr)->BLOCK_TYPE = 2;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = hexdef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  parserro(*curr_ptr, 61, " ");
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("adddef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 0;
  (*addrem_ptr)->BLOCK_TYPE = 3;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 *addrem_ptr = ((void *)0);
 parserro(*curr_ptr, 62, " ");
 return 17;
}
int
addscan(struct Group * group_ptr)
{
 struct AddRem *add_ptr = ((void *)0);
 struct Geomnode *ap1_ptr = ((void *)0), **app1_ptr = &ap1_ptr, *ap2_ptr = ((void *)0), **app2_ptr = &ap2_ptr;
 struct Geomnode *primo_ptr = ((void *)0), *ultimo_ptr = ((void *)0);
 int new_nodes = 0, *new_nodes_ptr = &new_nodes;
 int pnum = 0, *pnum_ptr = &pnum, qnum = 0, *qnum_ptr = &qnum;
 int elem_shape;
 double elem_pdim, elem_qdim;
 double pstep, qstep, angle, rot_angle;
 int nodes_num, group_shape;
 double group_psize, group_qsize, *group_psize_ptr = &group_psize, *group_qsize_ptr = &group_qsize;
 pstep = (group_ptr->GRID_PTR)->PSTEP;
 qstep = (group_ptr->GRID_PTR)->QSTEP;
 angle = (group_ptr->GRID_PTR)->ANGLE;
 rot_angle = (group_ptr->GRID_PTR)->ROT_ANGLE;
 elem_pdim = (group_ptr->ELEM_PTR)->PDIM;
 elem_qdim = (group_ptr->ELEM_PTR)->QDIM;
 if ((group_ptr->ELEM_PTR)->GEOMETRY == 0) {
  elem_shape = 3;
 } else {
  elem_shape = 2;
 };
 add_ptr = (group_ptr->ADDREM_PTR);
 nodes_num = 0;
 group_shape = 0;
 while (add_ptr != ((void *)0)) {
  if (add_ptr->ADDREM_TYPE == 1) {
   group_shape = 5;
   add_ptr = add_ptr->NEXT;
   continue;
  };
  switch (add_ptr->BLOCK_TYPE) {
  case 0:
   mksnode(add_ptr, app1_ptr, app2_ptr, pstep, qstep, angle, new_nodes_ptr, elem_shape, elem_pdim, elem_qdim);
   if (group_shape == 0) {
    if ((group_ptr->ELEM_PTR)->GEOMETRY == 0)
     group_shape = 3;
    else
     group_shape = 2;
   } else
    group_shape = 5;
   break;
  case 1:
   mksblock(add_ptr, app1_ptr, app2_ptr, pstep, qstep, angle, new_nodes_ptr, elem_shape, elem_pdim, elem_qdim);
   if ((group_shape == 0) && (angle == 90)) {
    group_shape = 3;
   } else
    group_shape = 5;
   break;
  case 2:
   printf("\nFunzione  mkpoly() non disponibile. ");
   exit(1);
   break;
  case 3:
   if (elem_shape != 2) {
    printf("%s", ErrorMessages[7]);
    return 7;
   }
   mkshex(add_ptr, app1_ptr, app2_ptr, pstep, qstep, angle, new_nodes_ptr, elem_shape, elem_pdim, elem_qdim);
   if (group_shape == 0)
    group_shape = 2;
   else
    group_shape = 5;
   break;
  default:
   interror("addscan() -1- ");
  };
  nodes_num = nodes_num + *new_nodes_ptr;
  if (primo_ptr == ((void *)0))
   primo_ptr = *app1_ptr;
  else
   ultimo_ptr->NEXT = *app1_ptr;
  ultimo_ptr = *app2_ptr;
  ultimo_ptr->NEXT = ((void *)0);
  add_ptr = add_ptr->NEXT;
 };
 if (rot_angle != 0) {
  sgrrot(primo_ptr, 0, 0, rot_angle);
  group_shape = 5;
 };
 if (group_shape == 2) {
  group_psize = 2 * pstep + 2 * (elem_pdim / 2);
  group_qsize = group_psize;
 } else if (group_shape == 3) {
  extremes(primo_ptr, pnum_ptr, qnum_ptr);
  group_psize = ((*pnum_ptr) - 1) * (pstep) + (2 * (elem_pdim / 2));
  group_qsize = ((*qnum_ptr) - 1) * (qstep) + (2 * (elem_qdim / 2));
 } else {
  extsize(primo_ptr, elem_pdim, elem_qdim, group_psize_ptr, group_qsize_ptr);
 };
 group_ptr->NUM_OF_NODES = nodes_num;
 group_ptr->SHAPE = group_shape;
 group_ptr->PSIZE = group_psize;
 group_ptr->QSIZE = group_qsize;
 group_ptr->GEOMNODE_PTR = primo_ptr;
 return 0;
}
int
adremdef(struct charac * p1, struct charac ** pp2,
  struct AddRem ** addrem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *addrem_ptr = ((void *)0);
 error = adddef(*curr_ptr, curr_ptr, addrem_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[62]);
  return 17;
 };
 if (error == 1) {
  error = remdef(*curr_ptr, curr_ptr, addrem_ptr);
 };
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[63]);
  return 17;
 };
 if (error == 1) {
  return 1;
 };
 return 17;
}
int
ampunit(struct charac ** tp, int *unit_ptr)
{
 struct charac *curr, **curr_ptr;
 curr_ptr = &curr;
 *curr_ptr = *tp;
 *unit_ptr = 0;
 if (GetKeyword(Keywords[15], curr_ptr) == 0)
  *unit_ptr = 0;
 else if (GetKeyword(Keywords[63], curr_ptr) == 0)
  *unit_ptr = 1;
 else if (GetKeyword(Keywords[64], curr_ptr) == 0)
  *unit_ptr = 2;
 else
  return 1;
 *tp = *curr_ptr;
 return 0;
}
int
ampval(struct charac * p1, struct charac ** pp2,
       double *amp_ptr,
       int *amp_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetReal(amp_ptr, curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = ampunit(curr_ptr, amp_unit_ptr);
 if (error != 0)
  *amp_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
angclaus(struct charac * p1,
  struct charac ** pp2, double *angle_ptr, int *angle_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *angle_ptr = 0;
 *angle_unit_ptr = 0;
 error = (GetKeyword(Keywords[23], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetReal(angle_ptr, curr_ptr));
 if (error != 0) {
  *angle_ptr = 0;
  return 19;
 };
 error = angunit(*curr_ptr, curr_ptr, angle_unit_ptr);
 if (error != 0)
  *angle_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
angledir(struct charac * p1, struct charac ** pp2,
  double *theta_ptr,
  double *phi_ptr,
  int *angle_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[70], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetReal(theta_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 73, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[71], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[71]);
  return 17;
 };
 error = angval(*curr_ptr, curr_ptr, phi_ptr, angle_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 73, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
anglerot(struct charac * p1, struct charac ** pp2,
  double *angle_start_ptr,
  double *angle_step_ptr,
  int *angle_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[23], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[95], curr_ptr));
 error = 0;
 error = (GetReal(angle_start_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 75, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[16], curr_ptr));
 error = 0;
 error = angval(*curr_ptr, curr_ptr, angle_step_ptr, angle_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 75, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
angstep(struct charac * p1,
 struct charac ** pp2, double *angle_ptr, int *angle_unit_ptr,
 double *pstep_ptr, double *qstep_ptr, int *pqstep_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error1, error2;
 *curr_ptr = p1;
 error1 = 0;
 error2 = 0;
 *angle_ptr = 0;
 *angle_unit_ptr = 0;
 *pstep_ptr = 0;
 *qstep_ptr = 0;
 *pqstep_unit_ptr = 0;
 error1 = angclaus(*curr_ptr, curr_ptr, angle_ptr, angle_unit_ptr);
 if (error1 == 1) {
  *angle_ptr = 0;
  *angle_unit_ptr = 0;
 };
 error2 = doubstep(*curr_ptr, curr_ptr, pstep_ptr, qstep_ptr, pqstep_unit_ptr);
 if ((error1 == 1) && (error2 == 1)) {
  *angle_ptr = 0;
  *angle_unit_ptr = 0;
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  return 1;
 };
 if (error2 != 0) {
  parserro(*curr_ptr, error2, " ");
  *angle_ptr = 0;
  *angle_unit_ptr = 0;
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
angunit(struct charac * p1,
 struct charac ** pp2, int *angle_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 *curr_ptr = p1;
 *angle_unit_ptr = 0;
 if (GetKeyword(Keywords[51], curr_ptr) == 0)
  *angle_unit_ptr = 0;
 else if (GetKeyword(Keywords[52], curr_ptr) == 0)
  *angle_unit_ptr = 1;
 else
  return 20;
 *pp2 = *curr_ptr;
 return 0;
}
int
angval(struct charac * p1, struct charac ** pp2,
       double *angle_ptr,
       int *angle_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetReal(angle_ptr, curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = angunit(*curr_ptr, curr_ptr, angle_unit_ptr);
 if (error != 0)
  *angle_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int answer(char domanda[100])
{
    char s[2];
    printf("\n%s (Y/N): ", domanda);
    if (fgets(s, sizeof(s), stdin) == ((void *)0)) {
        return 0;
    }
    if ((s[0] == 'N') || (s[0] == 'n'))
        return 0;
    else
        return 1;
}
int
beampha(struct charac * p1, struct charac ** pp2,
 double *u_ptr,
 double *v_ptr,
 double *theta_ptr,
 double *phi_ptr,
 int *angle_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[96], curr_ptr));
 error = 0;
 error = uvdir(*curr_ptr, curr_ptr, u_ptr, v_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[73]);
  return 17;
 };
 if (error == 1) {
  error = angledir(*curr_ptr, curr_ptr, theta_ptr, phi_ptr, angle_unit_ptr);
 };
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[73]);
  return 17;
 };
 parserro(*curr_ptr, 73, " ");
 return 17;
}
int
blockdef(struct charac * p1, struct charac ** pp2,
  struct Node ** node_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 int pcoord, *pcoord_ptr = &pcoord;
 int qcoord, *qcoord_ptr = &qcoord;
 struct Node *primo_ptr = ((void *)0), *ultimo_ptr = ((void *)0), *app_ptr = ((void *)0);
 *curr_ptr = p1;
 error = 0;
 *node_ptr = ((void *)0);
 error = (GetKeyword(Keywords[76], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = nodecoor(*curr_ptr, curr_ptr, pcoord_ptr, qcoord_ptr);
 if (error == 1) {
  parserro(*curr_ptr, 56, " ");
  return 17;
 };
 if (error == 17) {
  parserro(*curr_ptr, 56, " ");
  return 17;
 };
 app_ptr = (struct Node *) malloc(sizeof(struct Node));
 if (app_ptr == ((void *)0)) {
  parserro(*curr_ptr, 55, " ");
  interror("blockdef()");
  exit(1);
 };
 app_ptr->PCOORD = pcoord;
 app_ptr->QCOORD = qcoord;
 app_ptr->THEA = 0;
 app_ptr->PHEA = 0;
 app_ptr->PSEA = 0;
 app_ptr->ANGLE_UNIT = 0;
 app_ptr->NEXT = ((void *)0);
 primo_ptr = app_ptr;
 ultimo_ptr = app_ptr;
 error = nodecoor(*curr_ptr, curr_ptr, pcoord_ptr, qcoord_ptr);
 if (error == 1) {
  parserro(*curr_ptr, 56, " ");
  return 17;
 };
 if (error == 17) {
  parserro(*curr_ptr, 57, " ");
  return 17;
 };
 app_ptr = (struct Node *) malloc(sizeof(struct Node));
 if (app_ptr == ((void *)0)) {
  parserro(*curr_ptr, 55, " ");
  interror("blockdef()");
  exit(1);
 };
 app_ptr->PCOORD = pcoord;
 app_ptr->QCOORD = qcoord;
 app_ptr->THEA = 0;
 app_ptr->PHEA = 0;
 app_ptr->PSEA = 0;
 app_ptr->ANGLE_UNIT = 0;
 app_ptr->NEXT = ((void *)0);
 ultimo_ptr->NEXT = app_ptr;
 ultimo_ptr = app_ptr;
 *node_ptr = primo_ptr;
 *pp2 = *curr_ptr;
 return 0;
}
int
circpol(struct charac * p1, struct charac ** pp2,
 int *direction_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error = 0;
 *curr_ptr = p1;
 *direction_ptr = 0;
 error = (GetKeyword(Keywords[38], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[65], curr_ptr));
 if (error == 0) {
  *direction_ptr = 0;
  *pp2 = *curr_ptr;
  return 0;
 };
 error = (GetKeyword(Keywords[66], curr_ptr));
 if (error == 0) {
  *direction_ptr = 1;
  *pp2 = *curr_ptr;
  return 0;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
circspec(struct charac * p1, struct charac ** pp2,
  double *radius_ptr,
  int *radius_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error = 0;
 *curr_ptr = p1;
 error = (GetKeyword(Keywords[38], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[5], curr_ptr));
 error = 0;
 error = (Get1Real(*curr_ptr, curr_ptr, radius_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  return 17;
 };
 error = lenunit(curr_ptr, radius_unit_ptr);
 if (error != 0)
  *radius_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
cosinus(struct charac * p1, struct charac ** pp2,
 double *exp_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error = 0;
 *curr_ptr = p1;
 error = (GetKeyword(Keywords[34], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetReal(exp_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 26, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
double
dacos(double x)
{
 return acos(x) * 180/3.141592654;
}
double
dasin(double x)
{
 return asin(x) * 180/3.141592654;
}
double
datan(double x)
{
 return atan(x) * 180/3.141592654;
}
double
dcos(double x)
{
 return cos(x * 3.141592654/180);
}
int
degconv(double *x_ptr, int unit)
{
 switch (unit) {
  case 0:
  break;
 case 1:
  *x_ptr *= 180/3.141592654;
  break;
 default:
  interror("degconv");
 }
 return 0;
}
double
doubmax(double a, double b)
{
 if (a > b)
  return a;
 else
  return b;
}
double
doubmin(double a, double b)
{
 if (a < b)
  return a;
 else
  return b;
}
int
doubstep(struct charac * p1,
  struct charac ** pp2, double *pstep_ptr, double *qstep_ptr, int *pqstep_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *pstep_ptr = 0;
 *qstep_ptr = 0;
 *pqstep_unit_ptr = 0;
 error = (GetKeyword(Keywords[19], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetUReal(*curr_ptr, curr_ptr, pstep_ptr));
 if (error != 0) {
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  return error;
 };
 error = (GetKeyword(Keywords[20], curr_ptr));
 if (error != 0) {
  return 17;
 };
 error = (GetUReal(*curr_ptr, curr_ptr, qstep_ptr));
 if (error != 0) {
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  return error;
 };
 error = lenunit(curr_ptr, pqstep_unit_ptr);
 if (error != 0)
  *pqstep_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
double
dsin(double x)
{
 return sin(x * 3.141592654/180);
}
int
elemdef(struct charac * p1, struct charac ** pp2,
 struct Elem ** elem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 char name[30 + 1];
 *curr_ptr = p1;
 error = 0;
 *elem_ptr = (struct Elem *) malloc(sizeof(struct Elem));
 if (*elem_ptr == ((void *)0)) {
  parserro(*curr_ptr, 55, " ");
  interror("elemdef()");
 };
 error = (GetKeyword(Keywords[28], curr_ptr));
 if (error != 0) {
  *elem_ptr = ((void *)0);
  return 1;
 };
 error = GetUName(name, curr_ptr);
 if (error == 0) {
  strcpy((*elem_ptr)->NAME, name);
  (*elem_ptr)->TYPE = 1;
  *pp2 = *curr_ptr;
  return 0;
 };
 error = sinelem(*curr_ptr, curr_ptr, elem_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 *elem_ptr == ((void *)0);
 return 17;
}
void
emsginit(void)
{
 int i;
 for (i = 0; (i <= 100); i++)
  ErrorMessages[i][0] = '\0';
 strcpy(ErrorMessages[0], "** ERROR 0: NO ERRORS");
 strcpy(ErrorMessages[1], "** ERROR 1: Keyword expected: ");
 strcpy(ErrorMessages[2], "** ERROR 2: User name expected: ");
 strcpy(ErrorMessages[3], "** ERROR 3: User name already used: ");
 strcpy(ErrorMessages[4], "** ERROR 4: Unexpected end of file.");
 strcpy(ErrorMessages[5], "** ERROR 5: Illegal user name: ");
 strcpy(ErrorMessages[6], "** ERROR 6: Keywords may not be used as user names: ");
 strcpy(ErrorMessages[7], "** WARNING 7: User name too long: ");
 strcpy(ErrorMessages[8], "** ERROR 8: Missing array name declaration.");
 strcpy(ErrorMessages[9], "** ERROR 9: Missing array surface definition.");
 strcpy(ErrorMessages[10], "** ERROR 10: Incorrect array surface definition.");
 strcpy(ErrorMessages[11], "** ERROR 11: No valid real value found.");
 strcpy(ErrorMessages[12], "** ERROR 12: Negative value found: ");
 strcpy(ErrorMessages[13], "** ERROR 13: Real not found.");
 strcpy(ErrorMessages[14], "** ERROR 14: No length unit found, millimetres assumed.");
 strcpy(ErrorMessages[15], "** ERROR 15: Incorrect cylinder AXIS declaration. Axis must be X or Y.");
 strcpy(ErrorMessages[16], "** ERROR 16: Incorrect GRID definition.");
 strcpy(ErrorMessages[17], "** ERROR 17: Incorrect definition.");
 strcpy(ErrorMessages[18], "** ERROR 18: Missing double step definition.");
 strcpy(ErrorMessages[19], "** ERROR 19: No valid angle value found.");
 strcpy(ErrorMessages[20], "** ERROR 20: No angle unit found, degrees assumed.");
 strcpy(ErrorMessages[21], "** ERROR 21: Can not open input file:");
 strcpy(ErrorMessages[22], "** ERROR 22: Out of memory during input file reading.");
 strcpy(ErrorMessages[23], "** ERROR 23: Empty input file:");
 strcpy(ErrorMessages[24], "** ERROR 24: Incorrect ELEMENT definition.");
 strcpy(ErrorMessages[25], "** ERROR 25: Incorrect RECTANGULAR element definition.");
 strcpy(ErrorMessages[26], "** ERROR 26: Missing COSINUS parameter.");
 strcpy(ErrorMessages[27], "** ERROR 27: No valid amplitude value found.");
 strcpy(ErrorMessages[28], "** ERROR 28: Incorrect CIRCULAR element definition ");
 strcpy(ErrorMessages[29], "** ERROR 29: Missing GAUSSIAN parameter(s).");
 strcpy(ErrorMessages[30], "** ERROR 30: Incorrect element ORIENTATION definition.");
 strcpy(ErrorMessages[31], "** ERROR 31: Incorrect element LINEAR polarization definition.");
 strcpy(ErrorMessages[32], "** ERROR 32: Incorrect element CIRCULAR polarization definition.");
 strcpy(ErrorMessages[33], "** ERROR 33: No angle unit found, dB assumed.");
 strcpy(ErrorMessages[34], "** ERROR 34: Incorrect element GEOMETRY definition.");
 strcpy(ErrorMessages[35], "** ERROR 35: Incorrect element MODEL definition.");
 strcpy(ErrorMessages[36], "** ERROR 36: Incorrect element POLARIZATION definition.");
 strcpy(ErrorMessages[37], "** ERROR 37: No phase value found.");
 strcpy(ErrorMessages[38], "** ERROR 38: Incorrect element POL_ORIENT definition.");
 strcpy(ErrorMessages[39], "** ERROR 39: Incorrect element PORT AMPLITUDE definition.");
 strcpy(ErrorMessages[40], "** ERROR 40: Incorrect element PORT phase definition.");
 strcpy(ErrorMessages[41], "** ERROR 41: Natural number expected.");
 strcpy(ErrorMessages[42], "** ERROR 42: Integer not found.");
 strcpy(ErrorMessages[43], "** ERROR 43: Number too long: ");
 strcpy(ErrorMessages[44], "** ERROR 44: Natural not found.");
 strcpy(ErrorMessages[45], "** ERROR 45: Null value found.");
 strcpy(ErrorMessages[46], "** ERROR 46: Too few PORT definitions.");
 strcpy(ErrorMessages[47], "** ERROR 47: Incorrect definition at PORT: ");
 strcpy(ErrorMessages[48], "** ERROR 48: Incorrect element GAIN definition.");
 strcpy(ErrorMessages[49], "** ERROR 49: Incorrect element PORTS definition.");
 strcpy(ErrorMessages[50], "** ERROR 50: Missing P coordinate.");
 strcpy(ErrorMessages[51], "** ERROR 51: Missing Q coordinate.");
 strcpy(ErrorMessages[52], "** ERROR 52: Missing NODE coordinates.");
 strcpy(ErrorMessages[53], "** ERROR 53: Incorrect NODE coordinates definition.");
 strcpy(ErrorMessages[54], "** ERROR 54: Incorrect NODE ORIENTATION definition.");
 strcpy(ErrorMessages[55], "** ERROR 55: Out of memory during input data reading.");
 strcpy(ErrorMessages[56], "** ERROR 56: Missing BLOCK coordinate(s).");
 strcpy(ErrorMessages[57], "** ERROR 57: Incorrect BLOCK coordinates definition.");
 strcpy(ErrorMessages[58], "** ERROR 58: Incorrect NODE definition.");
 strcpy(ErrorMessages[59], "** ERROR 59: Incorrect BLOCK definition.");
 strcpy(ErrorMessages[60], "** ERROR 60: Incorrect POLYGON definition.");
 strcpy(ErrorMessages[61], "** ERROR 61: Incorrect HEXAGON definition.");
 strcpy(ErrorMessages[62], "** ERROR 62: Incorrect ADD statement.");
 strcpy(ErrorMessages[63], "** ERROR 63: Incorrect REMOVE statement.");
 strcpy(ErrorMessages[64], "** ERROR 64: Incorrect ADD or REMOVE statement.");
 strcpy(ErrorMessages[65], "** ERROR 65: 3 or more node coordinates expected.");
 strcpy(ErrorMessages[66], "** ERROR 66: Incorrect or missing node coordinates.");
 strcpy(ErrorMessages[67], "** ERROR 67: Missing ELEMENT definition after GRID definition.");
 strcpy(ErrorMessages[68], "** ERROR 68: Missing SECOND ORDER parameter(s).");
 strcpy(ErrorMessages[69], "** ERROR 69: Incorrect SECOND ORDER amplitude definition.");
 strcpy(ErrorMessages[70], "** ERROR 70: Incorrect GROUP EXCITATION AMPLITUDE definition.");
 strcpy(ErrorMessages[71], "** ERROR 71: Missing POINTING parameter(s).");
 strcpy(ErrorMessages[72], "** ERROR 72: U or V value out of range [-1,1].");
 strcpy(ErrorMessages[73], "** ERROR 73: Incorrect POINTING direction definition.");
 strcpy(ErrorMessages[74], "** ERROR 74: Incorrect PHASE parameters.");
 strcpy(ErrorMessages[75], "** ERROR 75: Incorrect ANGLE parameters.");
 strcpy(ErrorMessages[76], "** ERROR 76: Incorrect SECOND ORDER phase definition.");
 strcpy(ErrorMessages[77], "** ERROR 77: Incorrect ROTATION SEQUENTIAL phase definition.");
 strcpy(ErrorMessages[78], "** ERROR 78: Incorrect POINTING phase definition.");
 strcpy(ErrorMessages[79], "** ERROR 79: Incorrect AMPLITUDE excitation definition.");
 strcpy(ErrorMessages[80], "** ERROR 80: Incorrect PHASE excitation definition.");
 strcpy(ErrorMessages[81], "** ERROR 81: Missing GROUP name.");
 strcpy(ErrorMessages[82], "** ERROR 82: Incorrect GROUP definition, group: ");
 strcpy(ErrorMessages[83], "** ERROR 83: Missing coordinate(s) in: ADD_GROUP ");
 strcpy(ErrorMessages[84], "** ERROR 84: Missing DISPLACE coordinate(s).");
 strcpy(ErrorMessages[85], "** ERROR 85: Missing MOVE coordinate(s).");
 strcpy(ErrorMessages[86], "** ERROR 86: Missing coordinate(s) in: PLACE_GROUP ");
 strcpy(ErrorMessages[87], "** ERROR 87: Missing GROUP definition in array: ");
 strcpy(ErrorMessages[88], "** ERROR 88: Incorrect GROUP definition in array:");
 strcpy(ErrorMessages[89], "** ERROR 89: Incorrect DISPLACE_AT statement.");
 strcpy(ErrorMessages[90], "** ERROR 90: Incorrect MOVE_TO statement.");
 strcpy(ErrorMessages[91], "** ERROR 91: Missing ADD_GROUP or PLACE_GROUP statement.");
 strcpy(ErrorMessages[92], "** ERROR 92: Incorrect ADD_GROUP or PLACE_GROUP statement.");
 strcpy(ErrorMessages[93], "** ERROR 93: Incorrect PORTS number.");
 strcpy(ErrorMessages[94], "** ERROR 94: At least one ADD statement is required.");
 strcpy(ErrorMessages[95], "** ERROR 95: ");
 strcpy(ErrorMessages[96], "** ERROR 96: ");
 strcpy(ErrorMessages[97], "** ERROR 97: ");
 strcpy(ErrorMessages[98], "** ERROR 98: ");
 strcpy(ErrorMessages[99], "** ERROR 99: ");
}
int
EndOfTape(struct charac ** p)
{
 if ((*p) == ((void *)0)) {
  return 1;
 };
 return 0;
}
int
extmod(struct charac * p1, struct charac ** pp2)
{
 struct charac *curr, **curr_ptr = &curr;
 int error = 0;
 *curr_ptr = p1;
 error = (GetKeyword(Keywords[33], curr_ptr));
 if (error != 0) {
  return 1;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
extremes(struct Geomnode * gnode_ptr,
  int *pnum_ptr,
  int *qnum_ptr
)
{
 struct Geomnode *app_ptr;
 int pmin = 0x7fffffff, pmax = (-0x7fffffff - 1), qmin = 0x7fffffff, qmax = (-0x7fffffff - 1);
 app_ptr = gnode_ptr;
 while (app_ptr != ((void *)0)) {
  if ((app_ptr->LOC_P) < pmin)
   pmin = app_ptr->LOC_P;
  if ((app_ptr->LOC_P) > pmax)
   pmax = app_ptr->LOC_P;
  if ((app_ptr->LOC_Q) < qmin)
   qmin = app_ptr->LOC_Q;
  if ((app_ptr->LOC_Q) > qmax)
   qmax = app_ptr->LOC_Q;
  app_ptr = app_ptr->NEXT;
 };
 *pnum_ptr = pmax - pmin + 1;
 *qnum_ptr = qmax - qmin + 1;
 return 0;
}
int
extsize(struct Geomnode * gnode_ptr,
 double elem_pdim,
 double elem_qdim,
 double *xsize_ptr,
 double *ysize_ptr
)
{
 struct Geomnode *app_ptr;
 double xmin = ((double)1.79769313486231570814527423731704357e+308L), xmax = ((double)2.22507385850720138309023271733240406e-308L), ymin = ((double)1.79769313486231570814527423731704357e+308L), ymax = ((double)2.22507385850720138309023271733240406e-308L);
 app_ptr = gnode_ptr;
 while (app_ptr != ((void *)0)) {
  if ((app_ptr->XA) < xmin)
   xmin = app_ptr->XA;
  if ((app_ptr->XA) > xmax)
   xmax = app_ptr->XA;
  if ((app_ptr->YA) < ymin)
   ymin = app_ptr->YA;
  if ((app_ptr->YA) > ymax)
   ymax = app_ptr->YA;
  app_ptr = app_ptr->NEXT;
 };
 *xsize_ptr = (xmax - xmin) + (2 * (elem_pdim / 2));
 *ysize_ptr = (ymax - ymin) + (2 * (elem_qdim / 2));
 return 0;
}
int
fixgramp(struct GrAmpExc * g)
{
 double unif_val, *unif_val_ptr = &unif_val;
 double centre, *centre_ptr = &centre;
 double p1_et, *p1_et_ptr = &p1_et;
 double p2_et, *p2_et_ptr = &p2_et;
 double q1_et, *q1_et_ptr = &q1_et;
 double q2_et, *q2_et_ptr = &q2_et;
 int amp_unit;
 unif_val = g->UNIF_VAL;
 centre = g->CENTRE;
 p1_et = g->P1_ET;
 p2_et = g->P2_ET;
 q1_et = g->Q1_ET;
 q2_et = g->Q2_ET;
 amp_unit = g->AMP_UNIT;
 switch (g->TYPE) {
 case 0:
  if (unif_val == 0)
   unif_val = 1;
  linconv(unif_val_ptr, amp_unit);
  break;
 case 1:
  linconv(centre_ptr, amp_unit);
  linconv(p1_et_ptr, amp_unit);
  linconv(p2_et_ptr, amp_unit);
  linconv(q1_et_ptr, amp_unit);
  linconv(q2_et_ptr, amp_unit);
  break;
 case 2:
  printf("\nPQEXPR: not available");
  exit(1);
  interror("fixgramp()");
  break;
 default:
  interror("\nfixgramp(): group amplitude type not correct");
 }
 g->UNIF_VAL = unif_val;
 g->CENTRE = centre;
 g->P1_ET = p1_et;
 g->P2_ET = p2_et;
 g->Q1_ET = q1_et;
 g->Q2_ET = q2_et;
 g->AMP_UNIT = 0;
 return 0;
}
int
fixgrpha(struct GrPhaExc * g)
{
 switch (g->TYPE) {
 case 0:
  if (g->UNIF_VAL == 0)
   g->UNIF_VAL = 0;
  degconv(&(g->UNIF_VAL), g->PHASE_UNIT);
  break;
 case 1:
  degconv(&(g->CENTRE), g->PHASE_UNIT);
  degconv(&(g->P1_EP), g->PHASE_UNIT);
  degconv(&(g->P2_EP), g->PHASE_UNIT);
  degconv(&(g->Q1_EP), g->PHASE_UNIT);
  degconv(&(g->Q2_EP), g->PHASE_UNIT);
  break;
 case 2:
  printf("\nPQEXPR: not available");
  exit(1);
  interror("fixgrpha()");
  break;
 case 3:
  if (g->OMIT_ANGLE == 0) {
   degconv(&(g->ANGLE_START), g->ANGLE_UNIT);
   degconv(&(g->ANGLE_STEP), g->ANGLE_UNIT);
  };
  if (g->OMIT_PHASE == 0) {
   degconv(&(g->PHASE_START), g->PHASE_UNIT);
   degconv(&(g->PHASE_STEP), g->PHASE_UNIT);
  };
  break;
 case 4:
  degconv(&(g->THETA), g->ANGLE_UNIT);
  degconv(&(g->PHI), g->ANGLE_UNIT);
  break;
 default:
  interror("\nfixgrpha(): GROUP_EXCITATION phase law type not correct");
 }
 g->PHASE_UNIT = 0;
 return 0;
}
int
fixnodor(struct Node * node_ptr)
{
 if ((node_ptr->OMIT_ORIENT) == 1) {
  node_ptr->THEA = 0;
  node_ptr->PHEA = 0;
  node_ptr->PSEA = 0;
  node_ptr->ANGLE_UNIT = 0;
 } else if ((node_ptr->ANGLE_UNIT) == 1) {
  node_ptr->THEA *= 180/3.141592654;
  node_ptr->PHEA *= 180/3.141592654;
  node_ptr->PSEA *= 180/3.141592654;
  node_ptr->ANGLE_UNIT = 0;
 }
 return 0;
}
int
fixport(struct Elem * elem_ptr)
{
 struct Port *app_ptr;
 double amp, *amp_ptr = &amp;
 double ang, *ang_ptr = &ang;
 app_ptr = elem_ptr->PORT_PTR;
 while (app_ptr != ((void *)0)) {
  amp = app_ptr->AMP;
  linconv(amp_ptr, app_ptr->AMP_UNIT);
  app_ptr->AMP = amp;
  ang = app_ptr->PSC;
  degconv(ang_ptr, app_ptr->PSC_UNIT);
  app_ptr->PSC = ang;
  ang = app_ptr->PSH;
  degconv(ang_ptr, app_ptr->PSH_UNIT);
  app_ptr->PSH = ang;
  ang = app_ptr->PPA;
  degconv(ang_ptr, app_ptr->PPA_UNIT);
  app_ptr->PPA = ang;
  if (elem_ptr->POLARIZATION == 0) {
   if (app_ptr->OMIT_POL == 1) {
    app_ptr->PHEPOL = elem_ptr->PHEPOL;
    app_ptr->PHEPOL_UNIT = elem_ptr->PHEPOL_UNIT;
   };
   ang = app_ptr->PHEPOL;
   degconv(ang_ptr, app_ptr->PHEPOL_UNIT);
   app_ptr->PHEPOL = ang;
  };
  app_ptr->AMP_UNIT = 0;
  app_ptr->PSC_UNIT = 0;
  app_ptr->PSH_UNIT = 0;
  app_ptr->PPA_UNIT = 0;
  app_ptr->PHEPOL_UNIT = 0;
  app_ptr = app_ptr->NEXT;
 };
 return 0;
}
int
fixselem(struct Elem * elem_ptr)
{
 double radius, *radius_ptr = &radius;
 int radius_unit;
 double pdim, *pdim_ptr = &pdim;
 double qdim, *qdim_ptr = &qdim;
 int pqdim_unit;
 struct Port *port_ptr = ((void *)0);
 radius = elem_ptr->RADIUS;
 radius_unit = elem_ptr->RADIUS_UNIT;
 pdim = elem_ptr->PDIM;
 qdim = elem_ptr->QDIM;
 pqdim_unit = elem_ptr->PQDIM_UNIT;
 switch (elem_ptr->GEOMETRY) {
 case 0:
  mmconv(pdim_ptr, pqdim_unit);
  mmconv(qdim_ptr, pqdim_unit);
  radius = sqrt(pdim * pdim + qdim * qdim);
  break;
 case 1:
  mmconv(radius_ptr, radius_unit);
  pdim = 2 * radius;
  qdim = 2 * radius;
  break;
 default:
  interror("fixselem - 1");
 };
 radius_unit = 0;
 pqdim_unit = 0;
 if (elem_ptr->NPORTS == 0) {
  port_ptr = (struct Port *) malloc(sizeof(struct Port));
  if (port_ptr == ((void *)0)) {
   printf("%s", ErrorMessages[55]);
   interror("fixselem() -2- ");
  };
  port_ptr->PORTNUM = 1;
  port_ptr->AMP = 1;
  port_ptr->AMP_UNIT = 0;
  port_ptr->PSC = 0;
  port_ptr->PSC_UNIT = 0;
  port_ptr->PSH = 0;
  port_ptr->PSH_UNIT = 0;
  port_ptr->PPA = 0;
  port_ptr->PPA_UNIT = 0;
  port_ptr->PHEPOL = 90;
  port_ptr->PHEPOL_UNIT = 0;
  port_ptr->OMIT_POL = 1;
  port_ptr->NEXT = ((void *)0);
  elem_ptr->NPORTS = 1;
  elem_ptr->PORT_PTR = port_ptr;
 };
 fixport(elem_ptr);
 elem_ptr->RADIUS = radius;
 elem_ptr->RADIUS_UNIT = radius_unit;
 elem_ptr->PDIM = pdim;
 elem_ptr->QDIM = qdim;
 elem_ptr->PQDIM_UNIT = pqdim_unit;
 return 0;
}
int
fixsgrel(struct Group * group_ptr)
{
 struct Grid *grid;
 struct Elem *elem;
 double pstep, qstep, angle, rot_angle;
 double radius, pdim, qdim;
 double px, py, qx, qy;
 grid = group_ptr->GRID_PTR;
 elem = group_ptr->ELEM_PTR;
 fixselem(elem);
 fixsgrid(grid);
 grid->ROT_ANGLE = 0;
 switch (grid->TYPE) {
 case 0:
  if ((grid->PSTEP) == 0) {
   if ((group_ptr->GRPHAEXC_PTR)->TYPE == 3) {
    grid->PSTEP = elem->RADIUS;
    grid->QSTEP = elem->RADIUS;
   } else {
    grid->PSTEP = doubmax(elem->PDIM, elem->QDIM);
    grid->QSTEP = doubmax(elem->PDIM, elem->QDIM);
   }
  } else {
   if ((group_ptr->GRPHAEXC_PTR)->TYPE == 3) {
    if (grid->PSTEP < elem->RADIUS)
     printf("\n%s%s", MOSErrors[12], group_ptr->NAME);
   } else {
    if (grid->PSTEP < doubmax(elem->PDIM, elem->QDIM))
     printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
   }
  }
  grid->ANGLE = 90;
  break;
 case 1:
  if ((grid->PSTEP) == 0) {
   if ((group_ptr->GRPHAEXC_PTR)->TYPE == 3) {
    grid->PSTEP = elem->RADIUS;
    grid->QSTEP = elem->RADIUS;
   } else {
    grid->PSTEP = elem->PDIM;
    grid->QSTEP = elem->QDIM;
   }
  } else {
   if ((group_ptr->GRPHAEXC_PTR)->TYPE == 3) {
    if (grid->PSTEP < elem->RADIUS)
     printf("\n%s%s", MOSErrors[12], group_ptr->NAME);
   } else {
    if ((grid->PSTEP < elem->PDIM) || (grid->QSTEP < elem->QDIM))
     printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
   }
  }
  grid->ANGLE = 90;
  break;
 case 2:
  if (elem->GEOMETRY != 1) {
   printf("\n%s%s", MOSErrors[3], group_ptr->NAME);
   exit(1);
  };
  if ((grid->PSTEP) == 0) {
   grid->PSTEP = elem->PDIM;
   grid->QSTEP = elem->PDIM;
  } else if (grid->PSTEP < elem->PDIM) {
   printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
  };
  grid->ANGLE = 60;
  break;
 case 3:
  if ((grid->PX) != 0) {
   px = grid->PX;
   py = grid->PY;
   qx = grid->QX;
   qy = grid->QY;
   pstep = sqrt((px * px) + (py * py));
   qstep = sqrt((qx * qx) + (qy * qy));
   angle = dacos(((px * qx) + (py * qy)) / (pstep * qstep));
   rot_angle = dacos(px / pstep);
   grid->PSTEP = pstep;
   grid->QSTEP = qstep;
   grid->ANGLE = angle;
   grid->ROT_ANGLE = rot_angle;
  } else if (((grid->PSTEP) == 0) && ((grid->QSTEP) == 0) && ((grid->ANGLE) == 0)) {
   switch (elem->GEOMETRY) {
   case 1:
    radius = elem->PDIM / 2;
    angle = 60;
    pstep = 2 * radius;
    if ((angle > 45) && (angle <= 60))
     qstep = 2 * radius * 2 * dcos(angle);
    else if ((angle > 60) && (angle <= 90))
     qstep = 2 * radius;
    else
     interror("fixsgrel - 3");
    grid->PSTEP = pstep;
    grid->QSTEP = qstep;
    grid->ANGLE = angle;
    break;
   case 0:
    pdim = elem->PDIM;
    qdim = elem->QDIM;
    angle = datan((2 * qdim) / (pdim));
    pstep = pdim;
    qstep = (qdim) / (dsin(angle));
    grid->PSTEP = pstep;
    grid->QSTEP = qstep;
    grid->ANGLE = angle;
   };
  } else if (((grid->PSTEP) != 0) && ((grid->QSTEP) != 0) && ((grid->ANGLE) == 0)) {
   if (elem->GEOMETRY == 1) {
    pstep = grid->PSTEP;
    qstep = grid->QSTEP;
    radius = elem->PDIM / 2;
    if ((pstep < 2 * radius) || (qstep < 2 * radius)) {
     printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
     pstep = 2 * radius;
     qstep = 2 * radius;
    };
    angle = dacos(((qstep * qstep) + (pstep * pstep) - (4 * radius * radius)) / (2 * pstep * qstep));
    grid->ANGLE = angle;
   } else if (elem->GEOMETRY == 0) {
    pstep = grid->PSTEP;
    qstep = grid->QSTEP;
    pdim = elem->PDIM;
    qdim = elem->QDIM;
    if ((qstep < qdim) || (pstep < pdim)) {
     printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
     qstep = qdim;
    };
    angle = dasin(qdim / qstep);
    grid->ANGLE = angle;
   };
  }
  switch (elem->GEOMETRY) {
  case 1:
   pstep = grid->PSTEP;
   qstep = grid->QSTEP;
   radius = elem->PDIM / 2;
   if ((pstep < 2 * radius) || (qstep < 2 * radius)) {
    printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
   };
   if ((grid->ANGLE <= 45) || (grid->ANGLE > 90)) {
    printf("\n%s%f", MOSErrors[4], grid->ANGLE);
    exit(3);
   };
   break;
  case 0:
   pstep = grid->PSTEP;
   qstep = grid->QSTEP;
   pdim = elem->PDIM;
   qdim = elem->QDIM;
   if ((qstep < qdim) || (pstep < pdim)) {
    printf("\n%s%s", MOSErrors[2], group_ptr->NAME);
   };
   if ((grid->ANGLE <= (datan(elem->QDIM / elem->PDIM))) || (grid->ANGLE > 90)) {
    printf("\n%s%f", MOSErrors[4], grid->ANGLE);
    exit(3);
   };
   break;
  };
 };
 printf("\n** Generating GROUP: %s.", group_ptr->NAME);
 printf("\n** PSTEP,QSTEP set to:%f,%f", grid->PSTEP, grid->QSTEP);
 printf("\n** Grid ANGLE set to:%f ", grid->ANGLE);
 printf("\n** Group ROT_ANGLE set to: %f \n", grid->ROT_ANGLE);
 return 0;
}
int
fixsgrid(struct Grid * grid)
{
 double angle, *angle_ptr = &angle;
 int angle_unit;
 double pstep, *pstep_ptr = &pstep;
 double qstep, *qstep_ptr = &qstep;
 int pqstep_unit;
 double px, *px_ptr = &px;
 double py, *py_ptr = &py;
 double qx, *qx_ptr = &qx;
 double qy, *qy_ptr = &qy;
 int pqxy_unit;
 double rot_angle;
 angle = grid->ANGLE;
 angle_unit = grid->ANGLE_UNIT;
 pstep = grid->PSTEP;
 qstep = grid->QSTEP;
 pqstep_unit = grid->PQSTEP_UNIT;
 px = grid->PX;
 py = grid->PY;
 qx = grid->QX;
 qy = grid->QY;
 pqxy_unit = grid->PQXY_UNIT;
 rot_angle = grid->ROT_ANGLE;
 switch (grid->TYPE) {
 case 4:
  interror("fixsgrid - 1");
  break;
 case 0:
  if (pstep != 0) {
   mmconv(pstep_ptr, pqstep_unit);
   qstep = pstep;
  } else {
   qstep = 0;
  };
  angle = 90;
  break;
 case 1:
  if (pstep != 0) {
   mmconv(pstep_ptr, pqstep_unit);
   mmconv(qstep_ptr, pqstep_unit);
  } else {
   qstep = 0;
  };
  angle = 90;
  break;
 case 2:
  if (pstep != 0) {
   mmconv(pstep_ptr, pqstep_unit);
   qstep = pstep;
  } else {
   qstep = 0;
  };
  angle = 60;
  break;
 case 3:
  if (angle != 0) {
   degconv(angle_ptr, angle_unit);
   px = 0;
   py = 0;
   qx = 0;
   qy = 0;
  };
  if (pstep != 0) {
   mmconv(pstep_ptr, pqstep_unit);
   mmconv(qstep_ptr, pqstep_unit);
   px = 0;
   py = 0;
   qx = 0;
   qy = 0;
  };
  if (px != 0) {
   mmconv(px_ptr, pqxy_unit);
   mmconv(py_ptr, pqxy_unit);
   mmconv(qx_ptr, pqxy_unit);
   mmconv(qy_ptr, pqxy_unit);
   pstep = 0;
   qstep = 0;
   angle = 0;
  };
  break;
 };
 angle_unit = 0;
 pqstep_unit = 0;
 pqxy_unit = 0;
 rot_angle = 0;
 grid->ANGLE = angle;
 grid->ANGLE_UNIT = angle_unit;
 grid->PSTEP = pstep;
 grid->QSTEP = qstep;
 grid->PQSTEP_UNIT = pqstep_unit;
 grid->PX = px;
 grid->PY = py;
 grid->QX = qx;
 grid->QY = qy;
 grid->PQXY_UNIT = pqxy_unit;
 grid->ROT_ANGLE = rot_angle;
 return 0;
}
void
floatsup(void)
{
 double dummy;
 dummy = 1.0 + 0.0;
 printf("*******************************************************************************\n");
 printf("                         ARRAY PREPROCESSOR ver. %3.1f\n", dummy);
 printf("*******************************************************************************\n");
}
int
gainspec(struct charac * p1, struct charac ** pp2,
  double *gain_ptr,
  int *gain_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[32], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = gainval(*curr_ptr, curr_ptr, gain_ptr, gain_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 11, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
gainunit(struct charac * p1,
  struct charac ** pp2, int *gain_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 *curr_ptr = p1;
 *gain_unit_ptr = 2;
 if (GetKeyword(Keywords[64], curr_ptr) == 0)
  *gain_unit_ptr = 2;
 else if (GetKeyword(Keywords[15], curr_ptr) == 0)
  *gain_unit_ptr = 0;
 else
  return 33;
 *pp2 = *curr_ptr;
 return 0;
}
int
gainval(struct charac * p1, struct charac ** pp2,
 double *gain_ptr,
 int *gain_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetReal(gain_ptr, curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = gainunit(*curr_ptr, curr_ptr, gain_unit_ptr);
 if (error != 0)
  *gain_unit_ptr = 2;
 *pp2 = *curr_ptr;
 return 0;
}
int
gaussel(struct charac * p1, struct charac ** pp2,
 double *anglee_ptr,
 double *angleh_ptr,
 int *angle_unit_ptr,
 double *tapere_ptr,
 double *taperh_ptr,
 int *taper_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[35], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[59], curr_ptr));
 error = 0;
 error = (GetReal(anglee_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 19, " ");
  printf("\n%s", ErrorMessages[29]);
  return 17;
 };
 error = (GetKeyword(Keywords[60], curr_ptr));
 error = 0;
 error = (GetReal(angleh_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 19, " ");
  printf("\n%s", ErrorMessages[29]);
  return 17;
 };
 error = angunit(*curr_ptr, curr_ptr, angle_unit_ptr);
 if (error != 0)
  *angle_unit_ptr = 0;
 error = (GetKeyword(Keywords[61], curr_ptr));
 error = 0;
 error = (GetReal(tapere_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 27, " ");
  printf("\n%s", ErrorMessages[29]);
  return 17;
 };
 error = (GetKeyword(Keywords[62], curr_ptr));
 error = 0;
 error = (GetReal(taperh_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 27, " ");
  printf("\n%s", ErrorMessages[29]);
  return 17;
 };
 error = ampunit(curr_ptr, taper_unit_ptr);
 if (error != 0)
  *taper_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
geomspec(struct charac * p1, struct charac ** pp2,
  int *geometry_ptr,
  double *radius_ptr,
  int *radius_unit_ptr,
  double *pdim_ptr,
  double *qdim_ptr,
  int *pqdim_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[29], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[29]);
  return 1;
 };
 *geometry_ptr = 0;
 error = recspec(*curr_ptr, curr_ptr, pdim_ptr, qdim_ptr, pqdim_unit_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[25]);
  return 17;
 };
 *geometry_ptr = 1;
 error = circspec(*curr_ptr, curr_ptr, radius_ptr, radius_unit_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[28]);
  return 17;
 };
 return 17;
}
int
Get1Real(struct charac * p1,
  struct charac ** pp2, double *ureal_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = (GetReal(ureal_ptr, curr_ptr));
 if (error != 0) {
  return 11;
 };
 if (*ureal_ptr < 0) {
  return 12;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
GetInt(struct charac * p1,
       struct charac ** pp2, int *intero)
{
 struct charac *curr, **curr_ptr = &curr;
 int i = 0;
 char num[5 + 1];
 char ch;
 *curr_ptr = p1;
 ch = TapeGet(curr_ptr);
 if ((((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISdigit) == 0) && (ch != '+') && (ch != '-'))
  return 42;
 num[i] = ch;
 i = i + 1;
 ch = TapeGet(curr_ptr);
 while (((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISdigit) && ((*curr_ptr) != ((void *)0))) {
  if (i < 5) {
   num[i] = ch;
  };
  i = i + 1;
  ch = TapeGet(curr_ptr);
 };
 if (i >= 5) {
  num[5] = '\0';
  parserro(p1, 43, num);
  return 43;
 } else
  num[i] = '\0';
 *intero = atoi(num);
 *pp2 = *curr_ptr;
 return 0;
}
int
GetKeyword(char *kw, struct charac ** tp)
{
 struct charac *curr, **curr_ptr;
 char word[20 + 1], ch;
 int i = 0;
 curr_ptr = &curr;
 *curr_ptr = *tp;
 ch = TapeGet(curr_ptr);
 while (((((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISalnum)) || (ch == '_')) && (i < 20) && ((*curr_ptr) != ((void *)0))) {
  word[i] = ch;
  i = i + 1;
  ch = TapeGet(curr_ptr);
 };
 word[i] = '\0';
 if (strcmp(kw, word) == 0) {
  *tp = *curr_ptr;
  return 0;
 } else
  return 1;
}
int
GetNatur(struct charac * p1,
  struct charac ** pp2, int *natur_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 int val, *val_ptr = &val;
 *curr_ptr = p1;
 error = (GetInt(*curr_ptr, curr_ptr, val_ptr));
 if (error != 0) {
  return 44;
 };
 if (*val_ptr < 0) {
  return 12;
 };
 if (*val_ptr == 0) {
  return 45;
 };
 *natur_ptr = *val_ptr;
 *pp2 = *curr_ptr;
 return 0;
}
int
GetReal(double *reale, struct charac ** tp)
{
 struct charac *curr, **curr_ptr = &curr;
 int i = 0;
 char num[100 + 1];
 char ch;
 *curr_ptr = *tp;
 ch = TapeGet(curr_ptr);
 if ((((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISdigit) == 0) && (ch != '+') && (ch != '-') && (ch != '.'))
  return 13;
 num[i] = ch;
 i = i + 1;
 ch = TapeGet(curr_ptr);
 while (((((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISdigit) || (ch == '.') || (ch == 'e') || (ch == 'E') || (ch == '-')) && ((*curr_ptr) != ((void *)0)))) {
  if (i < 100)
   num[i] = ch;
  i = i + 1;
  ch = TapeGet(curr_ptr);
 };
 if (i >= 100)
  num[100] = '\0';
 else
  num[i] = '\0';
 *reale = atof(num);
 *tp = *curr_ptr;
 return 0;
}
int
GetUName(char word[30 + 1], struct charac ** tp)
{
 struct charac *curr, **curr_ptr;
 char ch;
 int i = 0;
 curr_ptr = &curr;
 *curr_ptr = *tp;
 ch = TapeGet(curr_ptr);
 while (((isletter(ch)) || (((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISdigit))) && ((*curr_ptr) != ((void *)0))) {
  if (i < 30)
   word[i] = ch;
  i = i + 1;
  ch = TapeGet(curr_ptr);
 };
 {
  if (i >= 30)
   word[30] = '\0';
  else
   word[i] = '\0';
 };
 if (i > 30)
  parserro(*tp, 7, word);
 if (strlen(word) == 0)
  return 2;
 if ((isletter(word[0])) == 0) {
  return 5;
 };
 if (InKWords(word) == 1) {
  return 6;
 };
 *tp = *curr_ptr;
 return 0;
}
int
GetUReal(struct charac * p1,
  struct charac ** pp2, double *ureal_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 double val, *val_ptr = &val;
 *curr_ptr = p1;
 error = (GetReal(val_ptr, curr_ptr));
 if (error != 0) {
  return 11;
 };
 if (*val_ptr < 0) {
  return 12;
 };
 *ureal_ptr = *val_ptr;
 *pp2 = *curr_ptr;
 return 0;
}
void
glvainit(void)
{
 floatsup();
 kwdsinit();
 emsginit();
 unaminit();
 moseinit();
}
void
gnodevis(int p,
  int q,
  double angle,
  double phase,
  struct Geomnode * gnode_list_start_ptr
)
{
 int error = 0;
 struct Geomnode *gnode_ptr;
 error = gnodfind(gnode_list_start_ptr, &gnode_ptr, p, q);
 if (error != 0) {
  interror("nodevis() - node not found -");
  exit(1);
 };
 (gnode_ptr->GEOMPORT_PTR)->PPA = phase;
 gnode_ptr->PHEA += angle;
 return;
}
int
gnodfind(struct Geomnode * gnode_list_start_ptr,
  struct Geomnode ** gnode_ptr,
  int p,
  int q
)
{
 *gnode_ptr = gnode_list_start_ptr;
 while ((!(((*gnode_ptr)->LOC_P == p) && ((*gnode_ptr)->LOC_Q == q))) && ((*gnode_ptr)->NEXT != ((void *)0)))
  (*gnode_ptr) = (*gnode_ptr)->NEXT;
 if (!(((*gnode_ptr)->LOC_P == p) && ((*gnode_ptr)->LOC_Q == q)))
  return 1;
 else
  return 0;
}
int
grampexc(struct charac * p1, struct charac ** pp2,
  struct GrAmpExc ** grampexc_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 double unif_val, *unif_val_ptr = &unif_val;
 double centre, *centre_ptr = &centre;
 double p1_et, *p1_et_ptr = &p1_et;
 double p2_et, *p2_et_ptr = &p2_et;
 double q1_et, *q1_et_ptr = &q1_et;
 double q2_et, *q2_et_ptr = &q2_et;
 int amp_unit, *amp_unit_ptr = &amp_unit;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[42], curr_ptr));
 if (error != 0) {
  *grampexc_ptr = ((void *)0);
  return 1;
 };
 error = unifamp(*curr_ptr, curr_ptr, unif_val_ptr, amp_unit_ptr);
 if (error == 0) {
  *grampexc_ptr = (struct GrAmpExc *) malloc(sizeof(struct GrAmpExc));
  if (*grampexc_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("grampexc()");
  };
  (*grampexc_ptr)->TYPE = 0;
  (*grampexc_ptr)->UNIF_VAL = unif_val;
  (*grampexc_ptr)->AMP_UNIT = amp_unit;
  (*grampexc_ptr)->PQEXP_PTR = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = secoramp(*curr_ptr, curr_ptr, centre_ptr, p1_et_ptr, p2_et_ptr, q1_et_ptr, q2_et_ptr, amp_unit_ptr);
 if (error == 17) {
  *grampexc_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[69]);
  return 17;
 };
 if (error == 0) {
  *grampexc_ptr = (struct GrAmpExc *) malloc(sizeof(struct GrAmpExc));
  if (*grampexc_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("grampexc()");
  };
  (*grampexc_ptr)->TYPE = 1;
  (*grampexc_ptr)->CENTRE = centre;
  (*grampexc_ptr)->P1_ET = p1_et;
  (*grampexc_ptr)->P2_ET = p2_et;
  (*grampexc_ptr)->Q1_ET = q1_et;
  (*grampexc_ptr)->Q2_ET = q2_et;
  (*grampexc_ptr)->AMP_UNIT = amp_unit;
  (*grampexc_ptr)->PQEXP_PTR = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 *grampexc_ptr = ((void *)0);
 return 17;
}
int
greldef(struct charac * p1, struct charac ** pp2,
 struct Grid ** grid_ptr, struct Elem ** elem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 *grid_ptr = ((void *)0);
 *elem_ptr = ((void *)0);
 error = 0;
 error = griddef1(*curr_ptr, curr_ptr, grid_ptr);
 if (error == 1) {
  return 1;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[16]);
  return 17;
 };
 error = elemdef(*curr_ptr, curr_ptr, elem_ptr);
 if (error == 1) {
  parserro(*curr_ptr, 67, " ");
  return 1;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[24]);
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
grexcdef(struct charac * p1, struct charac ** pp2,
  struct GrAmpExc ** grampexc_ptr, struct GrPhaExc ** grphaexc_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 *grampexc_ptr = ((void *)0);
 *grphaexc_ptr = ((void *)0);
 error = 0;
 error = (GetKeyword(Keywords[101], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = grampexc(*curr_ptr, curr_ptr, grampexc_ptr);
 if (error != 0) {
  printf("\n%s", ErrorMessages[79]);
  return 17;
 };
 error = grphaexc(*curr_ptr, curr_ptr, grphaexc_ptr);
 if (error != 0) {
  printf("\n%s", ErrorMessages[80]);
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
grgeodef(struct charac * p1, struct charac ** pp2,
  struct AddRem ** addrem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 struct AddRem *ultimo_ptr = ((void *)0);
 struct AddRem *a_ptr = ((void *)0), **app_ptr = &a_ptr;
 *curr_ptr = p1;
 error = 0;
 *addrem_ptr = ((void *)0);
 error = adddef(*curr_ptr, curr_ptr, addrem_ptr);
 if (error == 1) {
  parserro(*curr_ptr, 94, " ");
  return 17;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[62]);
  return 17;
 };
 *app_ptr = *addrem_ptr;
 ultimo_ptr = *addrem_ptr;
 while (1) {
  error = adremdef(*curr_ptr, curr_ptr, app_ptr);
  if (error == 1) {
   ultimo_ptr->NEXT = ((void *)0);
   *pp2 = *curr_ptr;
   return 0;
  };
  if (error == 17) {
   *addrem_ptr = ((void *)0);
   printf("\n%s", ErrorMessages[64]);
   return 17;
  };
  ultimo_ptr->NEXT = *app_ptr;
  ultimo_ptr = *app_ptr;
  ultimo_ptr->NEXT = ((void *)0);
 };
}
int
griddef1(struct charac * p1, struct charac ** pp2,
  struct Grid ** grid_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int grid_type;
 int orient, *orient_ptr = &orient;
 double pstep, *pstep_ptr = &pstep;
 double qstep, *qstep_ptr = &qstep;
 int pqstep_unit, *pqstep_unit_ptr = &pqstep_unit;
 double angle, *angle_ptr = &angle;
 int angle_unit, *angle_unit_ptr = &angle_unit;
 double px, *px_ptr = &px;
 double py, *py_ptr = &py;
 double qx, *qx_ptr = &qx;
 double qy, *qy_ptr = &qy;
 int pqxy_unit, *pqxy_unit_ptr = &pqxy_unit;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[14], curr_ptr));
 if (error != 0) {
  *grid_ptr = ((void *)0);
  return 1;
 };
 grid_type = 0;
 error = squgrdef(*curr_ptr, curr_ptr, pstep_ptr, pqstep_unit_ptr);
 if (error == 17) {
  *grid_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[16]);
  return 17;
 };
 if (error != 0) {
  grid_type = 1;
  error = recgrdef(*curr_ptr, curr_ptr, pstep_ptr, qstep_ptr, pqstep_unit_ptr);
  if (error == 17) {
   printf("\n%s", ErrorMessages[16]);
   *grid_ptr = ((void *)0);
   return 17;
  };
 };
 if (error != 0) {
  grid_type = 2;
  error = hexgrdef(*curr_ptr, curr_ptr, pstep_ptr, pqstep_unit_ptr);
  if (error == 17) {
   *grid_ptr = ((void *)0);
   printf("\n%s", ErrorMessages[16]);
   return 17;
  };
 };
 if (error != 0) {
  grid_type = 3;
  error = trigrdef(*curr_ptr, curr_ptr, angle_ptr, angle_unit_ptr, pstep_ptr, qstep_ptr, pqstep_unit_ptr, px_ptr, py_ptr, qx_ptr, qy_ptr, pqxy_unit_ptr);
  if (error == 17) {
   *grid_ptr = ((void *)0);
   printf("\n%s", ErrorMessages[16]);
   return 17;
  };
 };
 if (error != 0) {
  *grid_ptr = ((void *)0);
  parserro(*curr_ptr, 16, " ");
  return 17;
 };
 *grid_ptr = (struct Grid *) malloc(sizeof(struct Grid));
 if (*grid_ptr == ((void *)0)) {
  printf("%s", ErrorMessages[55]);
  interror("griddef1()");
 };
 (*grid_ptr)->TYPE = grid_type;
 (*grid_ptr)->ORIENT = orient;
 (*grid_ptr)->PSTEP = pstep;
 (*grid_ptr)->QSTEP = qstep;
 (*grid_ptr)->PQSTEP_UNIT = pqstep_unit;
 (*grid_ptr)->ANGLE = angle;
 (*grid_ptr)->ANGLE_UNIT = angle_unit;
 (*grid_ptr)->PX = px;
 (*grid_ptr)->PY = py;
 (*grid_ptr)->QX = qx;
 (*grid_ptr)->QY = qy;
 (*grid_ptr)->PQXY_UNIT = pqxy_unit;
 *pp2 = *curr_ptr;
 return 0;
}
int
groupdef(struct charac * p1, struct charac ** pp2,
  struct Group ** group_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 char groupname[30 + 1];
 struct Grid *grid = ((void *)0), **grid_ptr = &grid;
 struct Elem *elem = ((void *)0), **elem_ptr = &elem;
 struct AddRem *addrem = ((void *)0), **addrem_ptr = &addrem;
 struct GrAmpExc *grampexc = ((void *)0), **grampexc_ptr = &grampexc;
 struct GrPhaExc *grphaexc = ((void *)0), **grphaexc_ptr = &grphaexc;
 struct Err *err = ((void *)0), **err_ptr = &err;
 struct Fail *fail = ((void *)0), **fail_ptr = &fail;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[47], curr_ptr));
 if (error != 0) {
  *group_ptr = ((void *)0);
  return 1;
 };
 if (GetUName(groupname, curr_ptr) != 0) {
  parserro(*curr_ptr, 81, " ");
  return 17;
 };
 if (InUNames(groupname)) {
  parserro(*curr_ptr, 3, groupname);
  return 17;
 };
 InserUN(groupname);
 error = greldef(*curr_ptr, curr_ptr, grid_ptr, elem_ptr);
 if (error == 17) {
  return 17;
 };
 if (error == 0) {
  (*grid_ptr)->LEVEL = 1;
  (*elem_ptr)->LEVEL = 1;
  strcpy((*elem_ptr)->NAME, "ELEMENT");
 };
 error = grgeodef(*curr_ptr, curr_ptr, addrem_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 82, groupname);
  return 17;
 };
 error = grexcdef(*curr_ptr, curr_ptr, grampexc_ptr, grphaexc_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 82, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[50], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[50]);
  return 17;
 };
 *group_ptr = (struct Group *) malloc(sizeof(struct Group));
 if (*group_ptr == ((void *)0)) {
  parserro(*curr_ptr, 55, " ");
  interror("groupdef()");
 };
 strcpy((*group_ptr)->NAME, groupname);
 (*group_ptr)->NUM_OF_NODES = 0;
 (*group_ptr)->SHAPE = 0;
 (*group_ptr)->PSIZE = 0;
 (*group_ptr)->QSIZE = 0;
 (*group_ptr)->GRID_PTR = *grid_ptr;
 (*group_ptr)->ELEM_PTR = *elem_ptr;
 (*group_ptr)->GRAMPEXC_PTR = *grampexc_ptr;
 (*group_ptr)->GRPHAEXC_PTR = *grphaexc_ptr;
 (*group_ptr)->ADDREM_PTR = *addrem_ptr;
 (*group_ptr)->ERR_PTR = *err_ptr;
 (*group_ptr)->FAIL_PTR = *fail_ptr;
 (*group_ptr)->GEOMNODE_PTR = ((void *)0);
 (*group_ptr)->BUILT = 0;
 (*group_ptr)->SUPER_GROUP_PTR[0] = ((void *)0);
 *pp2 = *curr_ptr;
 return 0;
}
int
grphaexc(struct charac * p1, struct charac ** pp2,
  struct GrPhaExc ** grphaexc_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 double unif_val, *unif_val_ptr = &unif_val;
 double centre, *centre_ptr = &centre;
 double p1_ep, *p1_ep_ptr = &p1_ep;
 double p2_ep, *p2_ep_ptr = &p2_ep;
 double q1_ep, *q1_ep_ptr = &q1_ep;
 double q2_ep, *q2_ep_ptr = &q2_ep;
 int angle_unit, *angle_unit_ptr = &angle_unit;
 int direction, *direction_ptr = &direction;
 int omit_angle, *omit_angle_ptr = &omit_angle;
 double angle_start, *angle_start_ptr = &angle_start;
 double angle_step, *angle_step_ptr = &angle_step;
 int omit_phase, *omit_phase_ptr = &omit_phase;
 double phase_start, *phase_start_ptr = &phase_start;
 double phase_step, *phase_step_ptr = &phase_step;
 double u, *u_ptr = &u;
 double v, *v_ptr = &v;
 double theta, *theta_ptr = &theta;
 double phi, *phi_ptr = &phi;
 int phase_unit, *phase_unit_ptr = &phase_unit;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[43], curr_ptr));
 if (error != 0) {
  *grphaexc_ptr = ((void *)0);
  return 1;
 };
 error = unifpha(*curr_ptr, curr_ptr, unif_val_ptr, phase_unit_ptr);
 if (error == 0) {
  *grphaexc_ptr = (struct GrPhaExc *) malloc(sizeof(struct GrPhaExc));
  if (*grphaexc_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("grphaexc()");
  };
  (*grphaexc_ptr)->TYPE = 0;
  (*grphaexc_ptr)->UNIF_VAL = unif_val;
  (*grphaexc_ptr)->PHASE_UNIT = phase_unit;
  (*grphaexc_ptr)->PQEXP_PTR = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = secorpha(*curr_ptr, curr_ptr, centre_ptr, p1_ep_ptr, p2_ep_ptr, q1_ep_ptr, q2_ep_ptr, phase_unit_ptr);
 if (error == 17) {
  *grphaexc_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[76]);
  return 17;
 };
 if (error == 0) {
  *grphaexc_ptr = (struct GrPhaExc *) malloc(sizeof(struct GrPhaExc));
  if (*grphaexc_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("grphaexc()");
  };
  (*grphaexc_ptr)->TYPE = 1;
  (*grphaexc_ptr)->CENTRE = centre;
  (*grphaexc_ptr)->P1_EP = p1_ep;
  (*grphaexc_ptr)->P2_EP = p2_ep;
  (*grphaexc_ptr)->Q1_EP = q1_ep;
  (*grphaexc_ptr)->Q2_EP = q2_ep;
  (*grphaexc_ptr)->PHASE_UNIT = phase_unit;
  (*grphaexc_ptr)->PQEXP_PTR = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = serotpha(*curr_ptr, curr_ptr, direction_ptr, omit_angle_ptr, angle_start_ptr, angle_step_ptr, omit_phase_ptr, phase_start_ptr, phase_step_ptr, angle_unit_ptr, phase_unit_ptr);
 if (error == 17) {
  *grphaexc_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[77]);
  return 17;
 };
 if (error == 0) {
  *grphaexc_ptr = (struct GrPhaExc *) malloc(sizeof(struct GrPhaExc));
  if (*grphaexc_ptr == ((void *)0)) {
   printf("%s", ErrorMessages[55]);
   interror("grphaexc()");
  };
  (*grphaexc_ptr)->TYPE = 3;
  (*grphaexc_ptr)->DIRECTION = direction;
  (*grphaexc_ptr)->OMIT_ANGLE = omit_angle;
  (*grphaexc_ptr)->ANGLE_START = angle_start;
  (*grphaexc_ptr)->ANGLE_STEP = angle_step;
  (*grphaexc_ptr)->OMIT_PHASE = omit_phase;
  (*grphaexc_ptr)->PHASE_START = phase_start;
  (*grphaexc_ptr)->PHASE_STEP = phase_step;
  (*grphaexc_ptr)->ANGLE_UNIT = angle_unit;
  (*grphaexc_ptr)->PHASE_UNIT = phase_unit;
  (*grphaexc_ptr)->PQEXP_PTR = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = beampha(*curr_ptr, curr_ptr, u_ptr, v_ptr, theta_ptr, phi_ptr, angle_unit_ptr);
 if (error == 17) {
  *grphaexc_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[78]);
  return 17;
 };
 if (error == 0) {
  *grphaexc_ptr = (struct GrPhaExc *) malloc(sizeof(struct GrPhaExc));
  if (*grphaexc_ptr == ((void *)0)) {
   printf("%s", ErrorMessages[55]);
   interror("grphaexc()");
  };
  (*grphaexc_ptr)->TYPE = 4;
  (*grphaexc_ptr)->U = u;
  (*grphaexc_ptr)->V = v;
  (*grphaexc_ptr)->THETA = theta;
  (*grphaexc_ptr)->PHI = phi;
  (*grphaexc_ptr)->ANGLE_UNIT = angle_unit;
  (*grphaexc_ptr)->PQEXP_PTR = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 *grphaexc_ptr = ((void *)0);
 return 17;
}
int
grwrite(struct Group * group_ptr, char filename[30 + 1])
{
 int NEL, NPORTS, IDUM = 0;
 struct Geomnode *geomnode_ptr;
 struct Geomport *geomport_ptr;
 FILE *f;
 char datfilename[30 + 1];
 if (group_ptr == ((void *)0)) {
  interror(" grwrite() -1- ");
  exit(1);
 };
 geomnode_ptr = group_ptr->GEOMNODE_PTR;
 strcpy(datfilename, filename);
 strcat(datfilename, ".dat");
 printf("\n** Writing output file: %s", datfilename);
 printf("\n\nNEL \nNPORTS");
 printf("\nIDUM      REXA     REYA     REZA     THEA     PHEA     PSEA ");
 printf("\n          AMP      PSH      PSC      PHEPOL\n");
 NEL = (group_ptr->NUM_OF_NODES);
 printf("%4d", NEL);
 printf("\n");
 printf("%4d", NEL);
 printf("\n");
 NPORTS = (group_ptr->ELEM_PTR)->NPORTS;
 printf("%4d", NPORTS);
 printf("\n");
 printf("%4d", NPORTS);
 printf("\n");
 while (geomnode_ptr != ((void *)0)) {
  IDUM = IDUM + 1;
  printf("%4d ", IDUM);
  printf("\t%8.2f ", geomnode_ptr->XA);
  printf("%8.2f ", geomnode_ptr->YA);
  printf("%8.2f ", geomnode_ptr->ZA);
  printf("%8.2f ", geomnode_ptr->THEA);
  printf("%8.2f ", geomnode_ptr->PHEA);
  printf("%8.2f", geomnode_ptr->PSEA);
  printf("\n");
  printf("%4d ", IDUM);
  printf("\t%8.2f ", geomnode_ptr->XA);
  printf("%8.2f ", geomnode_ptr->YA);
  printf("%8.2f ", geomnode_ptr->ZA);
  printf("%8.2f ", geomnode_ptr->THEA);
  printf("%8.2f ", geomnode_ptr->PHEA);
  printf("%8.2f", geomnode_ptr->PSEA);
  printf("\n");
  geomport_ptr = geomnode_ptr->GEOMPORT_PTR;
  while (geomport_ptr != ((void *)0)) {
   printf("   \t%8.2f ", geomport_ptr->AMP);
   printf("%8.2f ", geomport_ptr->PSH + geomport_ptr->PPA);
   printf("%8.2f ", geomport_ptr->PSC);
   printf("%8.2f", geomport_ptr->PHEPOL);
   printf("\n");
   printf("   \t%8.2f ", geomport_ptr->AMP);
   printf("%8.2f ", geomport_ptr->PSH + geomport_ptr->PPA);
   printf("%8.2f ", geomport_ptr->PSC);
   printf("%8.2f", geomport_ptr->PHEPOL);
   printf("\n");
   geomport_ptr = geomport_ptr->NEXT;
  };
  geomnode_ptr = geomnode_ptr->NEXT;
 };
 printf("\n** End writing output file: %s \n", datfilename);
 return 0;
}
int
hexdef(struct charac * p1, struct charac ** pp2,
       struct Node ** node_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 int pcoord, *pcoord_ptr = &pcoord;
 int qcoord, *qcoord_ptr = &qcoord;
 *curr_ptr = p1;
 error = 0;
 *node_ptr = ((void *)0);
 error = (GetKeyword(Keywords[78], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = nodecoor(*curr_ptr, curr_ptr, pcoord_ptr, qcoord_ptr);
 if (error == 1) {
  parserro(*curr_ptr, 66, " ");
  return 17;
 };
 if (error == 17) {
  parserro(*curr_ptr, 66, " ");
  return 17;
 };
 *node_ptr = (struct Node *) malloc(sizeof(struct Node));
 if (*node_ptr == ((void *)0)) {
  parserro(*curr_ptr, 55, " ");
  interror("hexdef()");
 };
 (*node_ptr)->NEXT = ((void *)0);
 (*node_ptr)->PCOORD = pcoord;
 (*node_ptr)->QCOORD = qcoord;
 (*node_ptr)->THEA = 0;
 (*node_ptr)->PHEA = 0;
 (*node_ptr)->PSEA = 0;
 (*node_ptr)->ANGLE_UNIT = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
hexgrdef(struct charac * p1,
  struct charac ** pp2, double *pstep_ptr, int *pstep_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *pstep_ptr = 0;
 *pstep_unit_ptr = 0;
 error = (GetKeyword(Keywords[22], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = sinstep(*curr_ptr, curr_ptr, pstep_ptr, pstep_unit_ptr);
 if (error == 1) {
  *pstep_ptr = 0;
  *pstep_unit_ptr = 0;
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *pstep_ptr = 0;
  *pstep_unit_ptr = 0;
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
InKWords(char *WORD)
{
 int i;
 if (strlen(WORD) == 0) {
  printf("**INTERNAL ERROR - InKWords() - empty string passed.**");
  exit(1);
 };
 for (i = 0; i <= 125; i++) {
  if ((strcmp(WORD, Keywords[i])) == 0)
   return 1;
 };
 return 0;
}
int
InserUN(char *WORD)
{
 int i;
 if (strlen(WORD) == 0) {
  printf("**INTERNAL ERROR - InserUN() - empty string passed.**");
  exit(1);
 };
 for (i = 0; (i <= 20); i++) {
  if (strlen(UserNames[i]) == 0) {
   strcpy(UserNames[i], WORD);
  };
  return 0;
 };
 printf("** Internal error ** - InserUN()-: too many user names");
 exit(1);
 return 1;
}
void
interror(char *subname)
{
 printf("\n\n**ERROR INTERNAL** in function %s\n\n", subname);
 printf("** PROGRAM STOPPED **\n\n");
 exit(1);
}
int
intmax(int a, int b)
{
 if (a > b)
  return a;
 else
  return b;
}
int
intmin(int a, int b)
{
 if (a < b)
  return a;
 else
  return b;
}
int
InUNames(char *WORD)
{
 int i;
 if (strlen(WORD) == 0) {
  printf("**INTERNAL ERROR - InUNames() - empty string passed.**");
  exit(1);
 };
 for (i = 0; i <= 20; i++) {
  if ((strcmp(WORD, UserNames[i])) == 0)
   return 1;
 };
 return 0;
}
int
isletter(char ch)
{
 if ((((*__ctype_b_loc ())[(int) ((ch))] & (unsigned short int) _ISalpha)) || (ch == '_') || (ch == '-'))
  return 1;
 else
  return 0;
}
void
kwdsinit(void)
{
 char i;
 for (i = 0; (i <= 125); i++)
  Keywords[i][0] = '\0';
 strcpy(Keywords[0], "PLANE");
 strcpy(Keywords[1], "ARRAY");
 strcpy(Keywords[2], "IS");
 strcpy(Keywords[3], "SURFACE");
 strcpy(Keywords[4], "CYLINDER");
 strcpy(Keywords[5], "RADIUS");
 strcpy(Keywords[6], "mm");
 strcpy(Keywords[7], "cm");
 strcpy(Keywords[8], "dm");
 strcpy(Keywords[9], "m");
 strcpy(Keywords[10], "wl");
 strcpy(Keywords[11], "AXIS");
 strcpy(Keywords[12], "X");
 strcpy(Keywords[13], "Y");
 strcpy(Keywords[14], "GRID");
 strcpy(Keywords[15], "LINEAR");
 strcpy(Keywords[16], "STEP");
 strcpy(Keywords[17], "SQUARE");
 strcpy(Keywords[18], "RECTANGULAR");
 strcpy(Keywords[19], "PSTEP");
 strcpy(Keywords[20], "QSTEP");
 strcpy(Keywords[21], "TRIANGULAR");
 strcpy(Keywords[22], "HEXAGONAL");
 strcpy(Keywords[23], "ANGLE");
 strcpy(Keywords[24], "PX");
 strcpy(Keywords[25], "PY");
 strcpy(Keywords[26], "QX");
 strcpy(Keywords[27], "QY");
 strcpy(Keywords[28], "ELEMENT");
 strcpy(Keywords[29], "GEOMETRY");
 strcpy(Keywords[30], "MODEL");
 strcpy(Keywords[31], "POLARIZATION");
 strcpy(Keywords[32], "GAIN");
 strcpy(Keywords[33], "EXTERNAL");
 strcpy(Keywords[34], "COSINUS");
 strcpy(Keywords[35], "GAUSSIAN");
 strcpy(Keywords[36], "LINEAR");
 strcpy(Keywords[37], "ORIENTATION");
 strcpy(Keywords[38], "CIRCULAR");
 strcpy(Keywords[39], "PORTS");
 strcpy(Keywords[40], "PORT");
 strcpy(Keywords[41], "POL_ORIENT");
 strcpy(Keywords[42], "AMPLITUDE");
 strcpy(Keywords[43], "PHASE");
 strcpy(Keywords[44], "SHAPING");
 strcpy(Keywords[45], "SCANNING");
 strcpy(Keywords[46], "POL_ARRANGEMENT");
 strcpy(Keywords[47], "GROUP");
 strcpy(Keywords[48], "ERRORS");
 strcpy(Keywords[49], "FAILURES");
 strcpy(Keywords[50], "END");
 strcpy(Keywords[51], "deg");
 strcpy(Keywords[52], "rad");
 strcpy(Keywords[53], "PX");
 strcpy(Keywords[54], "PY");
 strcpy(Keywords[55], "QX");
 strcpy(Keywords[56], "QY");
 strcpy(Keywords[57], "PDIM");
 strcpy(Keywords[58], "QDIM");
 strcpy(Keywords[59], "E_ANG");
 strcpy(Keywords[60], "H_ANG");
 strcpy(Keywords[61], "E_TAP");
 strcpy(Keywords[62], "H_TAP");
 strcpy(Keywords[63], "POWER");
 strcpy(Keywords[64], "dB");
 strcpy(Keywords[65], "LH");
 strcpy(Keywords[66], "RH");
 strcpy(Keywords[67], "PHASE_SHAPING");
 strcpy(Keywords[68], "PHASE_SCANNING");
 strcpy(Keywords[69], "PHASE_POL_ARRANG");
 strcpy(Keywords[70], "THETA");
 strcpy(Keywords[71], "PHI");
 strcpy(Keywords[72], "PSI");
 strcpy(Keywords[73], "NODE");
 strcpy(Keywords[74], "P");
 strcpy(Keywords[75], "Q");
 strcpy(Keywords[76], "BLOCK");
 strcpy(Keywords[77], "POLYGON");
 strcpy(Keywords[78], "HEXAGON");
 strcpy(Keywords[79], "ADD");
 strcpy(Keywords[80], "REMOVE");
 strcpy(Keywords[81], "SECOND");
 strcpy(Keywords[82], "ORDER");
 strcpy(Keywords[83], "CENTRE");
 strcpy(Keywords[84], "P1_VAL");
 strcpy(Keywords[85], "P2_VAL");
 strcpy(Keywords[86], "Q1_VAL");
 strcpy(Keywords[87], "Q2_VAL");
 strcpy(Keywords[88], "UNIFORM");
 strcpy(Keywords[89], "P1_VAL");
 strcpy(Keywords[90], "P2_VAL");
 strcpy(Keywords[91], "Q1_VAL");
 strcpy(Keywords[92], "Q2_VAL");
 strcpy(Keywords[93], "CW");
 strcpy(Keywords[94], "CCW");
 strcpy(Keywords[95], "START");
 strcpy(Keywords[96], "POINTING");
 strcpy(Keywords[97], "U");
 strcpy(Keywords[98], "V");
 strcpy(Keywords[99], "ROTATION");
 strcpy(Keywords[100], "SEQUENTIAL");
 strcpy(Keywords[101], "GROUP_EXCITATION");
 strcpy(Keywords[102], "ADD_GROUP");
 strcpy(Keywords[103], "AT");
 strcpy(Keywords[104], "PLACE_GROUP");
 strcpy(Keywords[105], "DISPLACE");
 strcpy(Keywords[106], "MOVE");
 strcpy(Keywords[107], "TO");
 strcpy(Keywords[108], "");
 strcpy(Keywords[109], "");
 strcpy(Keywords[110], "");
 strcpy(Keywords[111], "");
 strcpy(Keywords[112], "");
 strcpy(Keywords[113], "");
 strcpy(Keywords[114], "");
 strcpy(Keywords[115], "");
 strcpy(Keywords[116], "");
 strcpy(Keywords[117], "");
 strcpy(Keywords[118], "");
 strcpy(Keywords[119], "");
 strcpy(Keywords[120], "");
 strcpy(Keywords[121], "");
 strcpy(Keywords[122], "");
 strcpy(Keywords[123], "");
 strcpy(Keywords[124], "");
 strcpy(Keywords[125], "");
 for (i = 0; (i <= 125); i++) {
  if (strlen(Keywords[i]) > 20) {
   printf("\n ******** ERROR: KEYWORD no.%d TOO LONG - CORRECT Keywords[] ASSIGNMENT\n", i);
   interror("kwdsinit()");
  };
 };
}
int
lenunit(struct charac ** tp, int *unit)
{
 struct charac *curr, **curr_ptr;
 curr_ptr = &curr;
 *curr_ptr = *tp;
 *unit = 0;
 if (GetKeyword(Keywords[6], curr_ptr) == 0)
  *unit = 0;
 else if (GetKeyword(Keywords[7], curr_ptr) == 0)
  *unit = 1;
 else if (GetKeyword(Keywords[8], curr_ptr) == 0)
  *unit = 2;
 else if (GetKeyword(Keywords[9], curr_ptr) == 0)
  *unit = 3;
 else
  return 14;
 *tp = *curr_ptr;
 return 0;
}
int
linconv(double *x_ptr, int unit)
{
 switch (unit) {
  case 0:
  break;
 case 1:
  *x_ptr = sqrt(*x_ptr);
  break;
 case 2:
  *x_ptr = pow(10, ((*x_ptr) / 20));
  break;
 default:
  interror("linconv() -1-");
 }
 return 0;
}
int
linpol(struct charac * p1, struct charac ** pp2,
       double *angle_ptr,
       int *angle_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[15], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = polor(*curr_ptr, curr_ptr, angle_ptr, angle_unit_ptr);
 if (error == 1) {
  *angle_ptr = 90;
  *angle_unit_ptr = 0;
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[31]);
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
mksblock(struct AddRem * addrem_ptr,
  struct Geomnode ** first_node_ptr,
  struct Geomnode ** last_node_ptr,
  double pstep,
  double qstep,
  double angle,
  int *nodes_num_ptr,
  int elem_shape,
  double elem_pdim,
  double elem_qdim
)
{
 struct Geomnode *app_ptr = ((void *)0), *primo_ptr = ((void *)0), *ultimo_ptr = ((void *)0);
 int p, q;
 int p1, q1, p2, q2;
 double x, y;
 int *pp1 = &p1, *pp2 = &p2, *qq1 = &q1, *qq2 = &q2;
 p1 = (addrem_ptr->NODE_PTR)->PCOORD;
 q1 = (addrem_ptr->NODE_PTR)->QCOORD;
 p2 = ((addrem_ptr->NODE_PTR)->NEXT)->PCOORD;
 q2 = ((addrem_ptr->NODE_PTR)->NEXT)->QCOORD;
 *nodes_num_ptr = 0;
 for (q = intmin(q1, q2); q <= intmax(q1, q2); q++) {
  for (p = intmin(p1, p2); p <= intmax(p1, p2); p++) {
   app_ptr = (struct Geomnode *) malloc(sizeof(struct Geomnode));
   if (app_ptr == ((void *)0)) {
    printf("%s", MOSErrors[0]);
    interror("mksblock()");
   };
   y = q * qstep * dsin(angle);
   x = p * pstep + q * qstep * dcos(angle);
   *nodes_num_ptr = *nodes_num_ptr + 1;
   app_ptr->LOC_P = p;
   app_ptr->LOC_Q = q;
   app_ptr->XA = x;
   app_ptr->YA = y;
   app_ptr->ZA = 0;
   app_ptr->SUBGROUP_PTR = ((void *)0);
   app_ptr->SHAPE = elem_shape;
   app_ptr->PSIZE = elem_pdim;
   app_ptr->QSIZE = elem_qdim;
   app_ptr->THEA = 0;
   app_ptr->PHEA = 0;
   app_ptr->PSEA = 0;
   if (primo_ptr == ((void *)0))
    primo_ptr = app_ptr;
   else
    ultimo_ptr->NEXT = app_ptr;
   ultimo_ptr = app_ptr;
   ultimo_ptr->NEXT = ((void *)0);
  };
 };
 *first_node_ptr = primo_ptr;
 *last_node_ptr = ultimo_ptr;
 return 0;
}
int
mkshex(struct AddRem * addrem_ptr,
       struct Geomnode ** first_node_ptr,
       struct Geomnode ** last_node_ptr,
       double pstep,
       double qstep,
       double angle,
       int *nodes_num_ptr,
       int elem_shape,
       double elem_pdim,
       double elem_qdim
)
{
 struct Geomnode *app_ptr = ((void *)0), *primo_ptr = ((void *)0), *ultimo_ptr = ((void *)0);
 int p, q, P[7 + 1], Q[7 + 1], i;
 double x, y;
 p = (addrem_ptr->NODE_PTR)->PCOORD;
 q = (addrem_ptr->NODE_PTR)->QCOORD;
 *nodes_num_ptr = 0;
 P[1] = p - 1;
 Q[1] = q + 1;
 P[2] = p;
 Q[2] = q + 1;
 P[3] = p + 1;
 Q[3] = q;
 P[4] = p + 1;
 Q[4] = q - 1;
 P[5] = p;
 Q[5] = q - 1;
 P[6] = p - 1;
 Q[6] = q;
 P[7] = p;
 Q[7] = q;
 for (i = 1; i <= 7; i++) {
  app_ptr = (struct Geomnode *) malloc(sizeof(struct Geomnode));
  if (app_ptr == ((void *)0)) {
   printf("%s", MOSErrors[0]);
   interror("mkshex()");
  };
  x = P[i] * pstep + Q[i] * qstep * dcos(angle);
  y = Q[i] * qstep * dsin(angle);
  *nodes_num_ptr = *nodes_num_ptr + 1;
  app_ptr->LOC_P = P[i];
  app_ptr->LOC_Q = Q[i];
  app_ptr->XA = x;
  app_ptr->YA = y;
  app_ptr->ZA = 0;
  app_ptr->SUBGROUP_PTR = ((void *)0);
  app_ptr->SHAPE = elem_shape;
  app_ptr->PSIZE = elem_pdim;
  app_ptr->QSIZE = elem_qdim;
  app_ptr->THEA = 0;
  app_ptr->PHEA = 0;
  app_ptr->PSEA = 0;
  if (primo_ptr == ((void *)0))
   primo_ptr = app_ptr;
  else
   ultimo_ptr->NEXT = app_ptr;
  ultimo_ptr = app_ptr;
  ultimo_ptr->NEXT = ((void *)0);
 };
 *first_node_ptr = primo_ptr;
 *last_node_ptr = ultimo_ptr;
 return 0;
}
int
mksnode(struct AddRem * addrem_ptr,
 struct Geomnode ** first_node_ptr,
 struct Geomnode ** last_node_ptr,
 double pstep,
 double qstep,
 double angle,
 int *nodes_num_ptr,
 int elem_shape,
 double elem_pdim,
 double elem_qdim
)
{
 struct Geomnode *app_ptr = ((void *)0);
 int p, q;
 double x, y;
 int *pp = &p, *qq = &q;
 p = (addrem_ptr->NODE_PTR)->PCOORD;
 q = (addrem_ptr->NODE_PTR)->QCOORD;
 *nodes_num_ptr = 0;
 app_ptr = (struct Geomnode *) malloc(sizeof(struct Geomnode));
 if (app_ptr == ((void *)0)) {
  printf("%s", MOSErrors[0]);
  interror("mksnode()");
 };
 x = p * pstep + q * qstep * dcos(angle);
 y = q * qstep * dsin(angle);
 *nodes_num_ptr = *nodes_num_ptr + 1;
 app_ptr->LOC_P = p;
 app_ptr->LOC_Q = q;
 app_ptr->XA = x;
 app_ptr->YA = y;
 app_ptr->ZA = 0;
 app_ptr->SUBGROUP_PTR = ((void *)0);
 app_ptr->NEXT = ((void *)0);
 app_ptr->SHAPE = elem_shape;
 app_ptr->PSIZE = elem_pdim;
 app_ptr->QSIZE = elem_qdim;
 fixnodor(addrem_ptr->NODE_PTR);
 app_ptr->THEA = (addrem_ptr->NODE_PTR)->THEA;
 app_ptr->PHEA = (addrem_ptr->NODE_PTR)->PHEA;
 app_ptr->PSEA = (addrem_ptr->NODE_PTR)->PSEA;
 *first_node_ptr = app_ptr;
 *last_node_ptr = app_ptr;
 return 0;
}
int
mmconv(double *x_ptr, int unit)
{
 switch (unit) {
  case 0:
  break;
 case 1:
  *x_ptr *= 10;
  break;
 case 2:
  *x_ptr *= 100;
  break;
 case 3:
  *x_ptr *= 1000;
  break;
 default:
  interror("mmconv -1- ");
 }
 return 0;
}
int
modspec(struct charac * p1, struct charac ** pp2,
 int *model_ptr,
 double *exp_ptr,
 double *anglee_ptr,
 double *angleh_ptr,
 int *angle_unit_ptr,
 double *tapere_ptr,
 double *taperh_ptr,
 int *taper_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[30], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[30]);
  return 1;
 };
 *model_ptr = 0;
 error = extmod(*curr_ptr, curr_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  return 17;
 };
 *model_ptr = 1;
 error = cosinus(*curr_ptr, curr_ptr, exp_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  return 17;
 };
 *model_ptr = 2;
 error = gaussel(*curr_ptr, curr_ptr, anglee_ptr, angleh_ptr, angle_unit_ptr, tapere_ptr, taperh_ptr, taper_unit_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[28]);
  return 17;
 };
 *model_ptr = 0;
 parserro(*curr_ptr, 35, " ");
 return 17;
}
void
moseinit(void)
{
 int i;
 for (i = 0; (i <= 20); i++)
  MOSErrors[i][0] = '\0';
 strcpy(MOSErrors[0], "** ERROR  B0: Out of memory during MOS.");
 strcpy(MOSErrors[1], "** ERROR  B1: External ELEMENT not suitable for GROUP: ");
 strcpy(MOSErrors[2], "** WARNING B2: GRID step(s) too small for specified element in GROUP: ");
 strcpy(MOSErrors[3], "** ERROR  B3: RECTANGULAR element not allowed on HEXAGONAL grid in GROUP: ");
 strcpy(MOSErrors[4], "** ERROR  B4: GRID angle out of non ambiguity range; angle=");
 strcpy(MOSErrors[5], "** ERROR  B5: SECOND ORDER law not allowed on irregular groups.");
 strcpy(MOSErrors[6], "** ERROR  B6: AMPLITUDE excitation error in GROUP: ");
 strcpy(MOSErrors[7], "** ERROR  B7: Only CIRCULAR elements allowed for ADD HEXAGON statement.");
 strcpy(MOSErrors[8], "** ERROR  B8: Error in group geometry; GROUP: ");
 strcpy(MOSErrors[9], "** ERROR  B9: PHASE excitation error in GROUP: ");
 strcpy(MOSErrors[10], "** ERROR B10: SEQUENTIAL ROTATION not allowed to multiport elements.");
 strcpy(MOSErrors[11], "** ERROR B11: SEQUENTIAL ROTATION not allowed on irregular shaped groups.");
 strcpy(MOSErrors[12], "** WARNING B12: GRID step(s) too small for sequential rotation in GROUP: ");
 strcpy(MOSErrors[13], "** ERROR B13: Cannot open output file:");
 strcpy(MOSErrors[14], "** ERROR B14: Simple element duplicate definition in GROUP: ");
 strcpy(MOSErrors[15], "** ERROR B15: ");
 strcpy(MOSErrors[16], "** ERROR B16: ");
 strcpy(MOSErrors[17], "** ERROR B17: ");
 strcpy(MOSErrors[18], "** ERROR B18: ");
 strcpy(MOSErrors[19], "** ERROR B19: ");
}
int
nodecoor(struct charac * p1, struct charac ** pp2,
  int *pcoord_ptr,
  int *qcoord_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[74], curr_ptr));
 error = 0;
 error = (GetInt(*curr_ptr, curr_ptr, pcoord_ptr));
 if (error != 0) {
  return 17;
 };
 error = (GetKeyword(Keywords[75], curr_ptr));
 error = 0;
 error = (GetInt(*curr_ptr, curr_ptr, qcoord_ptr));
 if (error != 0) {
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
nodedef(struct charac * p1, struct charac ** pp2,
 struct Node ** node_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 int pcoord, *pcoord_ptr = &pcoord;
 int qcoord, *qcoord_ptr = &qcoord;
 double thea, *thea_ptr = &thea;
 double phea, *phea_ptr = &phea;
 double psea, *psea_ptr = &psea;
 int angle_unit, *angle_unit_ptr = &angle_unit;
 int omit_orient;
 *curr_ptr = p1;
 error = 0;
 omit_orient = 0;
 *node_ptr = ((void *)0);
 error = (GetKeyword(Keywords[73], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = nodecoor(*curr_ptr, curr_ptr, pcoord_ptr, qcoord_ptr);
 if (error == 1) {
  parserro(*curr_ptr, 52, " ");
  return 17;
 };
 if (error == 17) {
  parserro(*curr_ptr, 53, " ");
  return 17;
 };
 if (error == 0) {
  error = nodorien(*curr_ptr, curr_ptr, thea_ptr, phea_ptr, psea_ptr, angle_unit_ptr);
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[54]);
  return 17;
 };
 if (error == 1) {
  omit_orient = 1;
 };
 *node_ptr = (struct Node *) malloc(sizeof(struct Node));
 if (*node_ptr == ((void *)0)) {
  parserro(*curr_ptr, 55, " ");
  interror("nodedef()");
 };
 (*node_ptr)->NEXT = ((void *)0);
 (*node_ptr)->PCOORD = pcoord;
 (*node_ptr)->QCOORD = qcoord;
 (*node_ptr)->THEA = thea;
 (*node_ptr)->PHEA = phea;
 (*node_ptr)->PSEA = psea;
 (*node_ptr)->ANGLE_UNIT = angle_unit;
 (*node_ptr)->OMIT_ORIENT = omit_orient;
 *pp2 = *curr_ptr;
 return 0;
}
int
nodorien(struct charac * p1, struct charac ** pp2,
  double *theta_ptr,
  double *phi_ptr,
  double *psi_ptr,
  int *angle_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[37], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[70], curr_ptr));
 error = 0;
 error = (GetReal(theta_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 19, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[71], curr_ptr));
 error = 0;
 error = (GetReal(phi_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 19, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[72], curr_ptr));
 error = 0;
 error = (GetReal(psi_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 19, " ");
  return 17;
 };
 error = angunit(*curr_ptr, curr_ptr, angle_unit_ptr);
 if (error != 0)
  *angle_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
void
nomefile(char fn[30 + 1])
{
 strcpy(fn, GLOBLE_FILENAME);
 return;
}
void
parserro(struct charac * err_ptr, int errcode, char *s)
{
 struct charac *p;
 int n = 0, i;
 static int errline_printed = 0;
 p = err_ptr;
 if (!errline_printed) {
  errline_printed = 1;
  printf("\nError occurred at line %d", err_ptr->LINE_NUM);
  while ((p->PREV != ((void *)0)) && ((p->PREV)->LINE_NUM == err_ptr->LINE_NUM)) {
   n++;
   p = p->PREV;
  };
  printf("\n%4d:\t", p->LINE_NUM);
  while ((p != ((void *)0)) && (p->LINE_NUM == err_ptr->LINE_NUM)) {
   printf("%c", p->info);
   p = p->NEXT;
  };
  printf("\n%    \t");
  for (i = 1; i <= n; i++) {
   printf(" ");
  };
  printf("^");
 };
 if (s == ((void *)0))
  printf("\n%s\n", ErrorMessages[errcode]);
 else
  printf("\n%s%s\n", ErrorMessages[errcode], s);
 return;
}
int
phaserot(struct charac * p1, struct charac ** pp2,
  double *phase_start_ptr,
  double *phase_step_ptr,
  int *phase_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[43], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[95], curr_ptr));
 error = 0;
 error = (GetReal(phase_start_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 74, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[16], curr_ptr));
 error = 0;
 error = angval(*curr_ptr, curr_ptr, phase_step_ptr, phase_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 74, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
polor(struct charac * p1, struct charac ** pp2,
      double *angle_ptr,
      int *angle_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[37], curr_ptr));
 if (error != 0) {
  *angle_ptr = 90;
  *angle_unit_ptr = 0;
  return 1;
 };
 *angle_ptr = 0;
 *angle_unit_ptr = 0;
 error = (GetKeyword(Keywords[12], curr_ptr));
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 *angle_ptr = 90;
 *angle_unit_ptr = 0;
 error = (GetKeyword(Keywords[13], curr_ptr));
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 error = angval(*curr_ptr, curr_ptr, angle_ptr, angle_unit_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  parserro(*curr_ptr, 30, " ");
  return 17;
 };
 return 17;
}
int
polorbis(struct charac * p1, struct charac ** pp2,
  double *phepol_ptr,
  int *phepol_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[41], curr_ptr));
 if (error != 0) {
  *phepol_ptr = 90;
  *phepol_unit_ptr = 0;
  return 1;
 };
 *phepol_ptr = 0;
 *phepol_unit_ptr = 0;
 error = (GetKeyword(Keywords[12], curr_ptr));
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 *phepol_ptr = 90;
 *phepol_unit_ptr = 0;
 error = (GetKeyword(Keywords[13], curr_ptr));
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 error = angval(*curr_ptr, curr_ptr, phepol_ptr, phepol_unit_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  parserro(*curr_ptr, 30, " ");
  return 17;
 };
 return 17;
}
int
polspec(struct charac * p1, struct charac ** pp2,
 int *polarization_ptr,
 double *phepol_ptr,
 int *phepol_unit_ptr,
 int *direction_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *polarization_ptr = 0;
 *phepol_ptr = 90;
 *phepol_unit_ptr = 0;
 *direction_ptr = 0;
 error = (GetKeyword(Keywords[31], curr_ptr));
 if (error != 0) {
  return 1;
 };
 *polarization_ptr = 0;
 error = linpol(*curr_ptr, curr_ptr, phepol_ptr, phepol_unit_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[31]);
  return 17;
 };
 *polarization_ptr = 1;
 error = circpol(*curr_ptr, curr_ptr, direction_ptr);
 if (error == 0) {
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[32]);
  return 17;
 };
 return 17;
}
int
polydef(struct charac * p1, struct charac ** pp2,
 struct Node ** node_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error, cont = 0;
 struct Node *primo_ptr = ((void *)0), *ultimo_ptr = ((void *)0), *app_ptr = ((void *)0);
 int pcoord, *pcoord_ptr = &pcoord;
 int qcoord, *qcoord_ptr = &qcoord;
 *curr_ptr = p1;
 error = 0;
 *node_ptr = ((void *)0);
 error = (GetKeyword(Keywords[77], curr_ptr));
 if (error != 0) {
  return 1;
 };
 while (1) {
  error = nodecoor(*curr_ptr, curr_ptr, pcoord_ptr, qcoord_ptr);
  if (error == 0) {
   cont = cont + 1;
   app_ptr = (struct Node *) malloc(sizeof(struct Node));
   if (app_ptr == ((void *)0)) {
    parserro(*curr_ptr, 55, " ");
    interror("polydef()");
   };
   app_ptr->PCOORD = pcoord;
   app_ptr->QCOORD = qcoord;
   app_ptr->THEA = 0;
   app_ptr->PHEA = 0;
   app_ptr->PSEA = 0;
   app_ptr->ANGLE_UNIT = 0;
   if (primo_ptr == ((void *)0)) {
    primo_ptr = app_ptr;
    ultimo_ptr = app_ptr;
    app_ptr->NEXT = ((void *)0);
   } else {
    ultimo_ptr->NEXT = app_ptr;
    ultimo_ptr = app_ptr;
    ultimo_ptr->NEXT = ((void *)0);
   };
  };
  if (error != 0) {
   break;
  };
 }
 if (cont < 3) {
  *node_ptr = ((void *)0);
  parserro(*curr_ptr, 65, " ");
  return 17;
 };
 *node_ptr = primo_ptr;
 *pp2 = *curr_ptr;
 return 0;
}
int
portamp(struct charac * p1, struct charac ** pp2,
 double *amp_ptr,
 int *amp_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[42], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = ampval(*curr_ptr, curr_ptr, amp_ptr, amp_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 27, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
portdef(struct charac * p1, struct charac ** pp2, struct Port * PORT_PTR, int *portnum_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 double amp, *amp_ptr = &amp;
 int amp_unit, *amp_unit_ptr = &amp_unit;
 double psc, *psc_ptr = &psc;
 int psc_unit, *psc_unit_ptr = &psc_unit;
 double psh, *psh_ptr = &psh;
 int psh_unit, *psh_unit_ptr = &psh_unit;
 double ppa, *ppa_ptr = &ppa;
 int ppa_unit, *ppa_unit_ptr = &ppa_unit;
 double phepol, *phepol_ptr = &phepol;
 int phepol_unit, *phepol_unit_ptr = &phepol_unit;
 int omit_pol, *omit_pol_ptr = &omit_pol;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[40], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[40]);
  return 1;
 };
 error = (GetNatur(*curr_ptr, curr_ptr, portnum_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  return 17;
 };
 *omit_pol_ptr = 0;
 error = polorbis(*curr_ptr, curr_ptr, phepol_ptr, phepol_unit_ptr);
 if (error == 1) {
  *omit_pol_ptr = 1;
  *phepol_ptr = 90;
  *phepol_unit_ptr = 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[38]);
  return 17;
 };
 error = portamp(*curr_ptr, curr_ptr, amp_ptr, amp_unit_ptr);
 if (error != 0) {
  printf("\n%s", ErrorMessages[39]);
  return 17;
 };
 error = pshdef1(*curr_ptr, curr_ptr, psh_ptr, psh_unit_ptr);
 if (error == 1) {
  *psh_ptr = 0;
  *psh_unit_ptr = 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[40]);
  return 17;
 };
 error = pscdef1(*curr_ptr, curr_ptr, psc_ptr, psc_unit_ptr);
 if (error == 1) {
  *psc_ptr = 0;
  *psc_unit_ptr = 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[40]);
  return 17;
 };
 error = ppadef1(*curr_ptr, curr_ptr, ppa_ptr, ppa_unit_ptr);
 if (error == 1) {
  *ppa_ptr = 0;
  *ppa_unit_ptr = 0;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[40]);
  return 17;
 };
 PORT_PTR->AMP = amp;
 PORT_PTR->AMP_UNIT = amp_unit;
 PORT_PTR->PSC = psc;
 PORT_PTR->PSC_UNIT = psc_unit;
 PORT_PTR->PSH = psh;
 PORT_PTR->PSH_UNIT = psh_unit;
 PORT_PTR->PPA = ppa;
 PORT_PTR->PPA_UNIT = ppa_unit;
 PORT_PTR->PHEPOL = phepol;
 PORT_PTR->PHEPOL_UNIT = phepol_unit;
 PORT_PTR->OMIT_POL = omit_pol;
 *pp2 = *curr_ptr;
 return 0;
}
int
portspec(struct charac * p1, struct charac ** pp2,
  int *nports_ptr,
  struct Port ** port_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error, n;
 int portnum, *portnum_ptr = &portnum;
 struct Port *primo_ptr = ((void *)0), *ultimo_ptr = ((void *)0), *app_ptr = ((void *)0);
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[39], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetNatur(*curr_ptr, curr_ptr, nports_ptr));
 if (error != 0) {
  *nports_ptr = 0;
  parserro(*curr_ptr, 93, " ");
  return 17;
 };
 for (n = 1; n <= *nports_ptr; n++) {
  app_ptr = (struct Port *) malloc(sizeof(struct Port));
  if (app_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("portspec()");
  };
  error = portdef(*curr_ptr, curr_ptr, app_ptr, portnum_ptr);
  if (error == 1) {
   parserro(*curr_ptr, 46, " ");
   return 17;
  };
  if (error == 17) {
   printf("\n%s%d", ErrorMessages[47], n);
   return 17;
  };
  app_ptr->PORTNUM = *portnum_ptr;
  if (primo_ptr == ((void *)0))
   primo_ptr = app_ptr;
  else
   ultimo_ptr->NEXT = app_ptr;
  ultimo_ptr = app_ptr;
  ultimo_ptr->NEXT = ((void *)0);
 };
 *port_ptr = primo_ptr;
 *pp2 = *curr_ptr;
 return 0;
}
int
ppadef1(struct charac * p1, struct charac ** pp2,
 double *ppa_ptr,
 int *ppa_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[69], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = angval(*curr_ptr, curr_ptr, ppa_ptr, ppa_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 37, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
pqlimits(struct Geomnode * gnode_ptr,
  struct Geomnode ** pmin_ptr,
  struct Geomnode ** pmax_ptr,
  struct Geomnode ** qmin_ptr,
  struct Geomnode ** qmax_ptr
)
{
 struct Geomnode *app_ptr;
 int pmin = 0x7fffffff, pmax = (-0x7fffffff - 1), qmin = 0x7fffffff, qmax = (-0x7fffffff - 1);
 *pmin_ptr = *pmax_ptr = *qmin_ptr = *qmax_ptr = app_ptr = gnode_ptr;
 while (app_ptr != ((void *)0)) {
  if ((app_ptr->LOC_P) < pmin) {
   pmin = app_ptr->LOC_P;
   *pmin_ptr = app_ptr;
  };
  if ((app_ptr->LOC_P) > pmax) {
   pmax = app_ptr->LOC_P;
   *pmax_ptr = app_ptr;
  };
  if ((app_ptr->LOC_Q) < qmin) {
   qmin = app_ptr->LOC_Q;
   *qmin_ptr = app_ptr;
  };
  if ((app_ptr->LOC_Q) > qmax) {
   qmax = app_ptr->LOC_Q;
   *qmax_ptr = app_ptr;
  };
  app_ptr = app_ptr->NEXT;
 };
 return 0;
}
void
prnfile(struct charac * firstel)
{
 struct charac *p;
 char ch = ' ';
 int line_num = 0;
 printf("\n");
 p = firstel;
 while ((p->NEXT) != ((void *)0)) {
  ch = p->info;
  if (p->LINE_NUM > line_num) {
   line_num = p->LINE_NUM;
   printf("\n%4d\t", line_num);
  }
  putchar(ch);
  p = p->NEXT;
 };
 printf("\n");
 return;
}
int
pscdef1(struct charac * p1, struct charac ** pp2,
 double *psc_ptr,
 int *psc_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[68], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = angval(*curr_ptr, curr_ptr, psc_ptr, psc_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 37, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
pshdef1(struct charac * p1, struct charac ** pp2,
 double *psh_ptr,
 int *psh_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[67], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = angval(*curr_ptr, curr_ptr, psh_ptr, psh_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 37, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
readfil3(char filename[30 + 1], struct charac ** firstel, struct charac ** lastel)
{
 FILE *f;
 char c;
 struct charac *p;
 int line_num = 1;
 char CR = '\n';
 char adlfilename[30 + 1];
 *firstel = ((void *)0);
 *lastel = ((void *)0);
 strcpy(adlfilename, filename);
 strcat(adlfilename, ".adl");
 if ((f = fopen(adlfilename, "r")) == ((void *)0)) {
  printf("%s %s", ErrorMessages[21], adlfilename);
  return 21;
 };
 c = (char) getc(f);
 if (c == (-1)) {
  printf("%s %s", ErrorMessages[23], adlfilename);
  return 23;
 };
 while (((*__ctype_b_loc ())[(int) ((c))] & (unsigned short int) _ISspace) || (c == ',')) {
  if (c == CR)
   line_num++;
  c = (char) getc(f);
 };
 p = (struct charac *) malloc(sizeof(struct charac));
 if (p == ((void *)0)) {
  printf("%s", ErrorMessages[22]);
  return 22;
 };
 p->info = c;
 p->LINE_NUM = line_num;
 p->PREV = ((void *)0);
 p->NEXT = ((void *)0);
 *firstel = p;
 *lastel = p;
 printf("\n");
 c = (char) getc(f);
 while (c != (-1)) {
  if (((*__ctype_b_loc ())[(int) ((c))] & (unsigned short int) _ISspace) || (c == ',')) {
   do {
    if (c == CR)
     line_num++;
    c = (char) getc(f);
   } while (((*__ctype_b_loc ())[(int) ((c))] & (unsigned short int) _ISspace) || (c == ','));
   p = (struct charac *) malloc(sizeof(struct charac));
   if (p == ((void *)0)) {
    printf("%s", ErrorMessages[22]);
    return 22;
   };
   p->info = ' ';
   p->LINE_NUM = line_num;
   p->PREV = *lastel;
   p->NEXT = ((void *)0);
   (*lastel)->NEXT = p;
   *lastel = p;
  } else {
   p = (struct charac *) malloc(sizeof(struct charac));
   if (p == ((void *)0)) {
    printf("%s", ErrorMessages[22]);
    return 22;
   };
   p->info = c;
   p->LINE_NUM = line_num;
   p->PREV = *lastel;
   p->NEXT = ((void *)0);
   (*lastel)->NEXT = p;
   *lastel = p;
   c = (char) getc(f);
  };
 };
 fclose(f);
 return 0;
}
int
recgrdef(struct charac * p1,
  struct charac ** pp2, double *pstep_ptr, double *qstep_ptr, int *pqstep_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *pstep_ptr = 0;
 *qstep_ptr = 0;
 *pqstep_unit_ptr = 0;
 error = (GetKeyword(Keywords[18], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = doubstep(*curr_ptr, curr_ptr, pstep_ptr, qstep_ptr, pqstep_unit_ptr);
 if (error == 1) {
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
recspec(struct charac * p1, struct charac ** pp2,
 double *pdim_ptr,
 double *qdim_ptr,
 int *pqdim_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[18], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[57], curr_ptr));
 error = 0;
 error = (Get1Real(*curr_ptr, curr_ptr, pdim_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[58], curr_ptr));
 error = 0;
 error = (Get1Real(*curr_ptr, curr_ptr, qdim_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  return 17;
 };
 error = lenunit(curr_ptr, pqdim_unit_ptr);
 if (error != 0)
  *pqdim_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
remdef(struct charac * p1, struct charac ** pp2,
       struct AddRem ** addrem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 struct Node *no_ptr = ((void *)0), **node_ptr = &no_ptr;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[80], curr_ptr));
 if (error != 0) {
  *addrem_ptr = ((void *)0);
  return 1;
 };
 error = nodedef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[58]);
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("remdef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 1;
  (*addrem_ptr)->BLOCK_TYPE = 0;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = blockdef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[59]);
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("remdef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 1;
  (*addrem_ptr)->BLOCK_TYPE = 1;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = polydef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[60]);
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("adddef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 1;
  (*addrem_ptr)->BLOCK_TYPE = 2;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 error = hexdef(*curr_ptr, curr_ptr, node_ptr);
 if (error == 17) {
  *addrem_ptr = ((void *)0);
  printf("\n%s", ErrorMessages[61]);
  return 17;
 };
 if (error == 0) {
  *addrem_ptr = (struct AddRem *) malloc(sizeof(struct AddRem));
  if (*addrem_ptr == ((void *)0)) {
   parserro(*curr_ptr, 55, " ");
   interror("adddef()");
  };
  (*addrem_ptr)->ADDREM_TYPE = 1;
  (*addrem_ptr)->BLOCK_TYPE = 3;
  (*addrem_ptr)->NODE_PTR = *node_ptr;
  (*addrem_ptr)->NEXT = ((void *)0);
  *pp2 = *curr_ptr;
  return 0;
 };
 *addrem_ptr = ((void *)0);
 parserro(*curr_ptr, 63, " ");
 return 17;
}
int
secoramp(struct charac * p1, struct charac ** pp2,
  double *centre_ptr,
  double *p1_et_ptr,
  double *p2_et_ptr,
  double *q1_et_ptr,
  double *q2_et_ptr,
  int *amp_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[81], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[82], curr_ptr));
 error = 0;
 error = (GetKeyword(Keywords[83], curr_ptr));
 error = 0;
 error = (GetReal(centre_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[84], curr_ptr));
 error = 0;
 error = (GetReal(p1_et_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[85], curr_ptr));
 error = 0;
 error = (GetReal(p2_et_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[86], curr_ptr));
 error = 0;
 error = (GetReal(q1_et_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[87], curr_ptr));
 error = 0;
 error = ampval(*curr_ptr, curr_ptr, q2_et_ptr, amp_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
double
secorder(double a,
  double b,
  double c,
  double d,
  double e,
  double x,
  double y
)
{
 double z;
 z = (a * x * x + b * y * y + c * x + d * y + e);
 return z;
}
int
secorpha(struct charac * p1, struct charac ** pp2,
  double *centre_ptr,
  double *p1_ep_ptr,
  double *p2_ep_ptr,
  double *q1_ep_ptr,
  double *q2_ep_ptr,
  int *phase_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[81], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[82], curr_ptr));
 error = 0;
 error = (GetKeyword(Keywords[83], curr_ptr));
 error = 0;
 error = (GetReal(centre_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[89], curr_ptr));
 error = 0;
 error = (GetReal(p1_ep_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[90], curr_ptr));
 error = 0;
 error = (GetReal(p2_ep_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[91], curr_ptr));
 error = 0;
 error = (GetReal(q1_ep_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[92], curr_ptr));
 error = 0;
 error = angval(*curr_ptr, curr_ptr, q2_ep_ptr, phase_unit_ptr);
 if (error != 0) {
  parserro(*curr_ptr, 68, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
void
seqrothg(double angle_start,
  double angle_step,
  double phase_start,
  double phase_step,
  struct Geomnode * g
)
{
 double cph, can;
 struct Geomnode *g_app_ptr;
 cph = phase_start;
 can = angle_start;
 g_app_ptr = g;
 while (g_app_ptr != ((void *)0)) {
  (g_app_ptr->GEOMPORT_PTR)->PPA = cph;
  g_app_ptr->PHEA = g_app_ptr->PHEA + can;
  cph += phase_step;
  can += angle_step;
  g_app_ptr = g_app_ptr->NEXT;
 };
 return;
}
void
seqrotrg(double angle_start,
  double angle_step,
  double phase_start,
  double phase_step,
  struct Geomnode * g
)
{
 struct Geomnode *pmin_ptr, *pmax_ptr, *qmin_ptr, *qmax_ptr;
 int pmin, pmax, qmin, qmax;
 int p, q, pcorr, qcorr, p1, p2, q1, q2, nodes_num, endvisit, cont;
 double cph, can;
 pqlimits(g, &pmin_ptr, &pmax_ptr, &qmin_ptr, &qmax_ptr);
 pmin = pmin_ptr->LOC_P;
 pmax = pmax_ptr->LOC_P;
 qmin = qmin_ptr->LOC_Q;
 qmax = qmax_ptr->LOC_Q;
 if ((pmin > pmax) || (qmin > qmax)) {
  interror("seqrotrg() -1- ");
  exit(1);
 };
 cph = phase_start;
 can = angle_start;
 nodes_num = (pmax - pmin + 1) * (qmax - qmin + 1);
 endvisit = 0;
 cont = 0;
 while (!endvisit) {
  if ((pmin == pmax) && (qmin == qmax)) {
   gnodevis(pmin, qmin, cph, can, g);
   cph += phase_step;
   can += angle_step;
   cont++;
   if (cont == nodes_num)
    endvisit = 1;
  } else {
   p1 = pmin;
   p2 = pmax - 1;
   q = qmax;
   if (p2 >= p1) {
    pcorr = p1;
    while ((pcorr <= p2) && (!endvisit)) {
     gnodevis(pcorr, q, cph, can, g);
     cph += phase_step;
     can += angle_step;
     (cont)++;
     if (cont == nodes_num)
      endvisit = 1;
     pcorr++;
    };
   };
   q1 = qmax;
   q2 = qmin + 1;
   p = pmax;
   if (q1 >= q2) {
    qcorr = q1;
    while ((qcorr >= q2) && (!endvisit)) {
     gnodevis(p, qcorr, cph, can, g);
     cph += phase_step;
     can += angle_step;
     (cont)++;
     if (cont == nodes_num)
      endvisit = 1;
     qcorr--;
    };
   };
   p1 = pmax;
   p2 = pmin + 1;
   q = qmin;
   if (p1 >= p2) {
    pcorr = p1;
    while ((pcorr >= p2) && (!endvisit)) {
     gnodevis(pcorr, q, cph, can, g);
     cph += phase_step;
     can += angle_step;
     (cont)++;
     if (cont == nodes_num)
      endvisit = 1;
     pcorr--;
    };
   };
   q1 = qmin;
   q2 = qmax - 1;
   p = pmin;
   if (q2 >= q1) {
    qcorr = q1;
    while ((qcorr <= q2) && (!endvisit)) {
     gnodevis(p, qcorr, cph, can, g);
     cph += phase_step;
     can += angle_step;
     (cont)++;
     if (cont == nodes_num)
      endvisit = 1;
     qcorr++;
    };
   };
  };
  pmin++;
  pmax--;
  qmin++;
  qmax--;
 };
 return;
}
int
serotdir(struct charac * p1, struct charac ** pp2,
  int *direction_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[93], curr_ptr));
 if (error == 0) {
  *direction_ptr = 0;
  *pp2 = *curr_ptr;
  return 0;
 };
 error = (GetKeyword(Keywords[94], curr_ptr));
 if (error == 0) {
  *direction_ptr = 1;
  *pp2 = *curr_ptr;
  return 0;
 };
 return 1;
}
int
serotpar(struct charac * p1, struct charac ** pp2,
  double *angle_start_ptr,
  double *angle_step_ptr,
  int *omit_phase_ptr,
  double *phase_start_ptr,
  double *phase_step_ptr,
  int *angle_unit_ptr,
  int *phase_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *omit_phase_ptr = 0;
 error = anglerot(*curr_ptr, curr_ptr, angle_start_ptr, angle_step_ptr, angle_unit_ptr);
 if (error == 17) {
  return 17;
 };
 if (error == 1) {
  *omit_phase_ptr = 1;
  return 1;
 };
 *omit_phase_ptr = 0;
 error = phaserot(*curr_ptr, curr_ptr, phase_start_ptr, phase_step_ptr, phase_unit_ptr);
 if (error == 17) {
  return 17;
 };
 if (error == 1) {
  *omit_phase_ptr = 1;
  *pp2 = *curr_ptr;
  return 0;
 };
 *omit_phase_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
serotpha(struct charac * p1, struct charac ** pp2,
  int *direction_ptr,
  int *omit_angle_ptr,
  double *angle_start_ptr,
  double *angle_step_ptr,
  int *omit_phase_ptr,
  double *phase_start_ptr,
  double *phase_step_ptr,
  int *angle_unit_ptr,
  int *phase_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *omit_angle_ptr = 0;
 *omit_phase_ptr = 0;
 error = (GetKeyword(Keywords[99], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetKeyword(Keywords[100], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[100]);
  return 17;
 };
 error = serotdir(*curr_ptr, curr_ptr, direction_ptr);
 if (error == 1) {
  *direction_ptr = 0;
 };
 error = serotpar(*curr_ptr, curr_ptr, angle_start_ptr, angle_step_ptr, omit_phase_ptr, phase_start_ptr, phase_step_ptr, angle_unit_ptr, phase_unit_ptr);
 if (error == 17) {
  return 17;
 };
 if (error == 1) {
  *omit_angle_ptr = 1;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
sgramp2n(struct GrAmpExc * grampexc_ptr,
  struct Geomnode * geomnode_ptr,
  struct Port * port_ptr,
  int group_shape
)
{
 struct Geomport *primo_ptr = ((void *)0), *app_ptr = ((void *)0), *ultimo_ptr = ((void *)0);
 struct Geomnode *geomnode_app_ptr = ((void *)0);
 struct Geomnode *pmin_tp = ((void *)0), **pmin_ptr = &pmin_tp;
 struct Geomnode *pmax_tp = ((void *)0), **pmax_ptr = &pmax_tp;
 struct Geomnode *qmin_tp = ((void *)0), **qmin_ptr = &qmin_tp;
 struct Geomnode *qmax_tp = ((void *)0), **qmax_ptr = &qmax_tp;
 struct Port *port_app_ptr = ((void *)0);
 double centre;
 double p1_et;
 double p2_et;
 double q1_et;
 double q2_et;
 double a, b, c, d, e, x1, y1;
 double A, B, C, D, E;
 double amp_val;
 double p1x, p1y, p2x, p2y, q1x, q1y, q2x, q2y, cex, cey;
 double Hx[7 + 1], Hy[7 + 1];
 int i;
 centre = grampexc_ptr->CENTRE;
 p1_et = grampexc_ptr->P1_ET;
 p2_et = grampexc_ptr->P2_ET;
 q1_et = grampexc_ptr->Q1_ET;
 q2_et = grampexc_ptr->Q2_ET;
 if (group_shape == 3) {
  pqlimits(geomnode_ptr, pmin_ptr, pmax_ptr, qmin_ptr, qmax_ptr);
  p1x = (*pmin_ptr)->XA;
  p2x = (*pmax_ptr)->XA;
  q1y = (*qmin_ptr)->YA;
  q2y = (*qmax_ptr)->YA;
  p1y = (q1y + q2y) / 2;
  p2y = p1y;
  q1x = (p1x + p2x) / 2;
  q2x = q1x;
  cex = q1x;
  cey = p1y;
 } else if (group_shape == 2) {
  geomnode_app_ptr = geomnode_ptr;
  for (i = 1; i <= 7; i++) {
   if (geomnode_app_ptr) {
    Hx[i] = geomnode_app_ptr->XA;
    Hy[i] = geomnode_app_ptr->YA;
    geomnode_app_ptr = geomnode_app_ptr->NEXT;
   } else {
    printf("NULL POINTER!\n");
    exit(1);
   }
  };
  p1x = Hx[5];
  p1y = Hy[5];
  p2x = Hx[2];
  p2y = Hy[2];
  q1x = (Hx[6] + Hx[7]) / 2;
  q1y = Hy[6];
  q2x = (Hx[4] + Hx[3]) / 2;
  q2y = Hy[4];
  cex = Hx[1];
  cey = Hy[1];
 } else {
  printf("\n%s", MOSErrors[5]);
  return 5;
 };
 x1 = p2x - cex;
 y1 = q2y - cey;
 e = centre;
 if (x1 == 0) {
  a = c = 0;
 } else {
  a = ((p1_et + p2_et - 2 * e) / (2 * x1 * x1));
  c = ((a * x1 * x1 + e - p1_et) / x1);
 };
 if (y1 == 0) {
  b = d = 0;
 } else {
  b = ((q1_et + q2_et - 2 * e) / (2 * y1 * y1));
  d = ((b * y1 * y1 + e - q1_et) / y1);
 };
 A = a;
 B = b;
 C = c - 2 * a * cex;
 D = d - 2 * b * cey;
 E = a * cex * cex + b * cey * cey - c * cex - d * cey + e;
 geomnode_app_ptr = geomnode_ptr;
 port_app_ptr = port_ptr;
 while (geomnode_app_ptr != ((void *)0)) {
  amp_val = secorder(A, B, C, D, E, geomnode_app_ptr->XA, geomnode_app_ptr->YA);
  primo_ptr = ultimo_ptr = app_ptr = ((void *)0);
  port_app_ptr = port_ptr;
  while (port_app_ptr != ((void *)0)) {
   app_ptr = (struct Geomport *) malloc(sizeof(struct Geomport));
   if (app_ptr == ((void *)0)) {
    printf("%s", ErrorMessages[55]);
    interror("sgramp2n()");
   };
   app_ptr->AMP = amp_val * port_app_ptr->AMP;
   if (primo_ptr == ((void *)0))
    primo_ptr = app_ptr;
   else
    ultimo_ptr->NEXT = app_ptr;
   ultimo_ptr = app_ptr;
   ultimo_ptr->NEXT = ((void *)0);
   port_app_ptr = port_app_ptr->NEXT;
  }
  geomnode_app_ptr->GEOMPORT_PTR = primo_ptr;
  geomnode_app_ptr = geomnode_app_ptr->NEXT;
 };
 return 0;
}
int
sgrampun(struct GrAmpExc * grampexc_ptr,
  struct Geomnode * geomnode_ptr,
  struct Port * port_ptr
)
{
 struct Geomport *primo_ptr = ((void *)0), *app_ptr = ((void *)0), *ultimo_ptr = ((void *)0);
 struct Geomnode *geomnode_app_ptr = ((void *)0);
 struct Port *port_app_ptr = ((void *)0);
 double unif_val;
 unif_val = grampexc_ptr->UNIF_VAL;
 geomnode_app_ptr = geomnode_ptr;
 port_app_ptr = port_ptr;
 while (geomnode_app_ptr != ((void *)0)) {
  primo_ptr = ultimo_ptr = app_ptr = ((void *)0);
  port_app_ptr = port_ptr;
  while (port_app_ptr != ((void *)0)) {
   app_ptr = (struct Geomport *) malloc(sizeof(struct Geomport));
   if (app_ptr == ((void *)0)) {
    printf("%s", ErrorMessages[55]);
    interror("sgrampun()");
   };
   app_ptr->AMP = unif_val * port_app_ptr->AMP;
   if (primo_ptr == ((void *)0))
    primo_ptr = app_ptr;
   else
    ultimo_ptr->NEXT = app_ptr;
   ultimo_ptr = app_ptr;
   ultimo_ptr->NEXT = ((void *)0);
   port_app_ptr = port_app_ptr->NEXT;
  }
  geomnode_app_ptr->GEOMPORT_PTR = primo_ptr;
  geomnode_app_ptr = geomnode_app_ptr->NEXT;
 };
 return 0;
}
int
sgrpha2n(struct GrPhaExc * grphaexc_ptr,
  struct Geomnode * geomnode_ptr,
  struct Port * port_ptr,
  int group_shape
)
{
 struct Geomport *geomport_app_ptr = ((void *)0);
 struct Geomnode *geomnode_app_ptr = ((void *)0);
 struct Port *port_app_ptr = ((void *)0);
 struct Geomnode *pmin_tp = ((void *)0), **pmin_ptr = &pmin_tp;
 struct Geomnode *pmax_tp = ((void *)0), **pmax_ptr = &pmax_tp;
 struct Geomnode *qmin_tp = ((void *)0), **qmin_ptr = &qmin_tp;
 struct Geomnode *qmax_tp = ((void *)0), **qmax_ptr = &qmax_tp;
 double centre;
 double p1_ep;
 double p2_ep;
 double q1_ep;
 double q2_ep;
 double a, b, c, d, e, x1, y1;
 double A, B, C, D, E;
 double phase_val;
 double p1x, p1y, p2x, p2y, q1x, q1y, q2x, q2y, cex, cey;
 double Hx[7 + 1], Hy[7 + 1];
 int i;
 centre = grphaexc_ptr->CENTRE;
 p1_ep = grphaexc_ptr->P1_EP;
 p2_ep = grphaexc_ptr->P2_EP;
 q1_ep = grphaexc_ptr->Q1_EP;
 q2_ep = grphaexc_ptr->Q2_EP;
 if (group_shape == 3) {
  pqlimits(geomnode_ptr, pmin_ptr, pmax_ptr, qmin_ptr, qmax_ptr);
  p1x = (*pmin_ptr)->XA;
  p2x = (*pmax_ptr)->XA;
  q1y = (*qmin_ptr)->YA;
  q2y = (*qmax_ptr)->YA;
  p1y = (q1y + q2y) / 2;
  p2y = p1y;
  q1x = (p1x + p2x) / 2;
  q2x = q1x;
  cex = q1x;
  cey = p1y;
 } else if (group_shape == 2) {
  geomnode_app_ptr = geomnode_ptr;
  for (i = 1; i <= 7; i++) {
   if (geomnode_app_ptr) {
    Hx[i] = geomnode_app_ptr->XA;
    Hy[i] = geomnode_app_ptr->YA;
    geomnode_app_ptr = geomnode_app_ptr->NEXT;
   } else {
    printf("NULL POINTER!\n");
    exit(1);
   }
  };
  p1x = Hx[5];
  p1y = Hy[5];
  p2x = Hx[2];
  p2y = Hy[2];
  q1x = (Hx[6] + Hx[7]) / 2;
  q1y = Hy[6];
  q2x = (Hx[4] + Hx[3]) / 2;
  q2y = Hy[4];
  cex = Hx[1];
  cey = Hy[1];
 } else {
  printf("\n%s", MOSErrors[5]);
  return 5;
 };
 x1 = p2x - cex;
 y1 = q2y - cey;
 e = centre;
 if (x1 == 0) {
  a = c = 0;
 } else {
  a = ((p1_ep + p2_ep - 2 * e) / (2 * x1 * x1));
  c = ((a * x1 * x1 + e - p1_ep) / x1);
 };
 if (y1 == 0) {
  b = d = 0;
 } else {
  b = ((q1_ep + q2_ep - 2 * e) / (2 * y1 * y1));
  d = ((b * y1 * y1 + e - q1_ep) / y1);
 };
 A = a;
 B = b;
 C = c - 2 * a * cex;
 D = d - 2 * b * cey;
 E = a * cex * cex + b * cey * cey - c * cex - d * cey + e;
 geomnode_app_ptr = geomnode_ptr;
 while (geomnode_app_ptr != ((void *)0)) {
  phase_val = secorder(A, B, C, D, E, geomnode_app_ptr->XA, geomnode_app_ptr->YA);
  geomport_app_ptr = geomnode_app_ptr->GEOMPORT_PTR;
  port_app_ptr = port_ptr;
  while (port_app_ptr != ((void *)0)) {
   geomport_app_ptr->PSH = phase_val + port_app_ptr->PSH;
   geomport_app_ptr->PSC = port_app_ptr->PSC;
   geomport_app_ptr->PPA = port_app_ptr->PPA;
   port_app_ptr = port_app_ptr->NEXT;
   geomport_app_ptr = geomport_app_ptr->NEXT;
  }
  geomnode_app_ptr = geomnode_app_ptr->NEXT;
 };
 return 0;
}
int
sgrphasr(struct Group * group_ptr)
{
 struct Geomnode *geomnode_app_ptr = ((void *)0);
 double angle_start, angle_step, phase_start, phase_step, sign;
 if ((group_ptr->ELEM_PTR)->NPORTS > 1) {
  printf("\n%s", MOSErrors[10]);
  return 10;
 };
 if (group_ptr->SHAPE == 5) {
  printf("\n%s", MOSErrors[11]);
  return 11;
 };
 if ((group_ptr->GRPHAEXC_PTR)->DIRECTION == 1)
  sign = +1;
 else
  sign = -1;
 if (((group_ptr->GRPHAEXC_PTR)->OMIT_ANGLE == 1) && ((group_ptr->GRPHAEXC_PTR)->OMIT_PHASE == 1)) {
  if (group_ptr->NUM_OF_NODES <= 2) {
   angle_start = phase_start = 0;
   angle_step = phase_step = sign * 90;
  } else {
   angle_start = phase_start = 0;
   angle_step = phase_step = sign * 360 / (group_ptr->NUM_OF_NODES);
  };
 } else if ((group_ptr->GRPHAEXC_PTR)->OMIT_PHASE == 1) {
  angle_start = (group_ptr->GRPHAEXC_PTR)->ANGLE_START;
  angle_step = (group_ptr->GRPHAEXC_PTR)->ANGLE_STEP;
  phase_start = angle_start;
  phase_step = angle_step;
 } else {
  angle_start = (group_ptr->GRPHAEXC_PTR)->ANGLE_START;
  angle_step = (group_ptr->GRPHAEXC_PTR)->ANGLE_STEP;
  phase_start = (group_ptr->GRPHAEXC_PTR)->PHASE_START;
  phase_step = (group_ptr->GRPHAEXC_PTR)->PHASE_STEP;
 };
 if (group_ptr->SHAPE == 3) {
  seqrotrg(angle_start, angle_step, phase_start, phase_step, group_ptr->GEOMNODE_PTR);
 } else if (group_ptr->SHAPE == 2) {
  seqrothg(angle_start, angle_step, phase_start, phase_step, group_ptr->GEOMNODE_PTR);
 }
 geomnode_app_ptr = group_ptr->GEOMNODE_PTR;
 while (geomnode_app_ptr != ((void *)0)) {
  (geomnode_app_ptr->GEOMPORT_PTR)->PSH = (group_ptr->ELEM_PTR)->PORT_PTR->PSH;
  (geomnode_app_ptr->GEOMPORT_PTR)->PSC = (group_ptr->ELEM_PTR)->PORT_PTR->PSC;
  (geomnode_app_ptr->GEOMPORT_PTR)->PPA += (group_ptr->ELEM_PTR)->PORT_PTR->PPA;
  geomnode_app_ptr = geomnode_app_ptr->NEXT;
 };
 return 0;
}
int
sgrphaun(struct GrPhaExc * grphaexc_ptr,
  struct Geomnode * geomnode_ptr,
  struct Port * port_ptr
)
{
 struct Geomport *geomport_app_ptr = ((void *)0);
 struct Geomnode *geomnode_app_ptr = ((void *)0);
 struct Port *port_app_ptr = ((void *)0);
 double unif_val;
 unif_val = grphaexc_ptr->UNIF_VAL;
 geomnode_app_ptr = geomnode_ptr;
 while (geomnode_app_ptr != ((void *)0)) {
  geomport_app_ptr = geomnode_app_ptr->GEOMPORT_PTR;
  port_app_ptr = port_ptr;
  while (port_app_ptr != ((void *)0)) {
   geomport_app_ptr->PSH = unif_val + port_app_ptr->PSH;
   geomport_app_ptr->PSC = port_app_ptr->PSC;
   geomport_app_ptr->PPA = port_app_ptr->PPA;
   port_app_ptr = port_app_ptr->NEXT;
   geomport_app_ptr = geomport_app_ptr->NEXT;
  }
  geomnode_app_ptr = geomnode_app_ptr->NEXT;
 };
 return 0;
}
int
sgrrot(struct Geomnode * start_ptr,
       double XC,
       double YC,
       double phi
)
{
 struct Geomnode *app_ptr;
 double XD, YD, XE, YE;
 app_ptr = start_ptr;
 if (app_ptr == ((void *)0)) {
  interror("sgrrot - 1 ");
 };
 while (app_ptr != ((void *)0)) {
  XD = app_ptr->XA;
  YD = app_ptr->YA;
  XE = ((XD - XC) * dcos(phi)) - ((YD - YC) * dsin(phi)) + XC;
  YE = ((XD - XC) * dsin(phi)) + ((YD - YC) * dcos(phi)) + YC;
  app_ptr->XA = XE;
  app_ptr->YA = YE;
  app_ptr->PHEA += phi;
  app_ptr = app_ptr->NEXT;
 };
 return 0;
}
int
simamp(struct Group * group_ptr)
{
 int error = 0;
 fixgramp(group_ptr->GRAMPEXC_PTR);
 switch ((group_ptr->GRAMPEXC_PTR)->TYPE) {
 case 0:
  error = sgrampun(group_ptr->GRAMPEXC_PTR, group_ptr->GEOMNODE_PTR, (group_ptr->ELEM_PTR)->PORT_PTR);
  break;
 case 1:
  error = sgramp2n(group_ptr->GRAMPEXC_PTR, group_ptr->GEOMNODE_PTR, (group_ptr->ELEM_PTR)->PORT_PTR, group_ptr->SHAPE);
  break;
 };
 if (error != 0) {
  printf("\n%s%s", MOSErrors[6], group_ptr->NAME);
  return 6;
 } else
  return 0;
}
int
simgroup(struct Group * group_ptr
)
{
 int error = 0;
 fixsgrel(group_ptr);
 error = addscan(group_ptr);
 if (error != 0) {
  printf("\n%s%s", MOSErrors[8], group_ptr->NAME);
  return 8;
 } else
  return 0;
}
int
simpha(struct Group * group_ptr)
{
 int error = 0;
 fixgrpha(group_ptr->GRPHAEXC_PTR);
 switch ((group_ptr->GRPHAEXC_PTR)->TYPE) {
 case 0:
  error = sgrphaun(group_ptr->GRPHAEXC_PTR, group_ptr->GEOMNODE_PTR, (group_ptr->ELEM_PTR)->PORT_PTR);
  break;
 case 1:
  error = sgrpha2n(group_ptr->GRPHAEXC_PTR, group_ptr->GEOMNODE_PTR, (group_ptr->ELEM_PTR)->PORT_PTR, group_ptr->SHAPE);
  break;
 case 3:
  error = sgrphasr(group_ptr);
  break;
 };
 if (error != 0) {
  printf("\n%s%s", MOSErrors[9], group_ptr->NAME);
  return 9;
 } else
  return 0;
}
int
simpol(struct Group * group_ptr)
{
 struct Geomport *geomport_app_ptr;
 struct Geomnode *geomnode_app_ptr;
 struct Port *port_app_ptr;
 geomnode_app_ptr = group_ptr->GEOMNODE_PTR;
 while (geomnode_app_ptr != ((void *)0)) {
  geomport_app_ptr = geomnode_app_ptr->GEOMPORT_PTR;
  port_app_ptr = (group_ptr->ELEM_PTR)->PORT_PTR;
  while (port_app_ptr != ((void *)0)) {
   geomport_app_ptr->PHEPOL = port_app_ptr->PHEPOL;
   port_app_ptr = port_app_ptr->NEXT;
   geomport_app_ptr = geomport_app_ptr->NEXT;
  }
  geomnode_app_ptr = geomnode_app_ptr->NEXT;
 };
 return 0;
}
int
sinelem(struct charac * p1, struct charac ** pp2,
 struct Elem ** elem_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 int geometry, *geometry_ptr = &geometry;
 double radius, *radius_ptr = &radius;
 int radius_unit, *radius_unit_ptr = &radius_unit;
 double pdim, *pdim_ptr = &pdim;
 double qdim, *qdim_ptr = &qdim;
 int pqdim_unit, *pqdim_unit_ptr = &pqdim_unit;
 int model, *model_ptr = &model;
 double exp, *exp_ptr = &exp;
 double anglee, *anglee_ptr = &anglee;
 double angleh, *angleh_ptr = &angleh;
 int angle_unit, *angle_unit_ptr = &angle_unit;
 double tapere, *tapere_ptr = &tapere;
 double taperh, *taperh_ptr = &taperh;
 int taper_unit, *taper_unit_ptr = &taper_unit;
 int polarization, *polarization_ptr = &polarization;
 double phepol, *phepol_ptr = &phepol;
 int phepol_unit, *phepol_unit_ptr = &phepol_unit;
 int direction, *direction_ptr = &direction;
 double gain, *gain_ptr = &gain;
 int gain_unit, *gain_unit_ptr = &gain_unit;
 int nports, *nports_ptr = &nports;
 struct Port *p_ptr, **port_ptr = &p_ptr;
 *curr_ptr = p1;
 error = 0;
 error = geomspec(*curr_ptr, curr_ptr, geometry_ptr, radius_ptr, radius_unit_ptr, pdim_ptr, qdim_ptr, pqdim_unit_ptr);
 if (error == 1) {
  return 1;
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[34]);
  return 17;
 };
 *model_ptr = 0;
 if (error == 0) {
  error = polspec(*curr_ptr, curr_ptr, polarization_ptr, phepol_ptr, phepol_unit_ptr, direction_ptr);
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[36]);
  return 17;
 };
 if (error == 1) {
  *polarization_ptr = 0;
  *phepol_ptr = 90;
  *phepol_unit_ptr = 0;
  *direction_ptr = 0;
  error = 0;
 };
 *gain_ptr = 0;
 *gain_unit_ptr = 0;
 if (error == 0) {
  error = portspec(*curr_ptr, curr_ptr, nports_ptr, port_ptr);
 };
 if (error == 17) {
  printf("\n%s", ErrorMessages[49]);
  return 17;
 };
 if (error == 1) {
  *nports_ptr = 0;
  *port_ptr = ((void *)0);
  error = 0;
 };
 (*elem_ptr)->TYPE = 0;
 strcpy((*elem_ptr)->NAME, "");
 (*elem_ptr)->GEOMETRY = geometry;
 (*elem_ptr)->RADIUS = radius;
 (*elem_ptr)->RADIUS_UNIT = radius_unit;
 (*elem_ptr)->PDIM = pdim;
 (*elem_ptr)->QDIM = qdim;
 (*elem_ptr)->PQDIM_UNIT = pqdim_unit;
 (*elem_ptr)->MODEL = model;
 (*elem_ptr)->EXP = exp;
 (*elem_ptr)->ANGLEE = anglee;
 (*elem_ptr)->ANGLEH = angleh;
 (*elem_ptr)->ANGLE_UNIT = angle_unit;
 (*elem_ptr)->TAPERE = tapere;
 (*elem_ptr)->TAPERH = taperh;
 (*elem_ptr)->TAPER_UNIT = taper_unit;
 (*elem_ptr)->POLARIZATION = polarization;
 (*elem_ptr)->PHEPOL = phepol;
 (*elem_ptr)->PHEPOL_UNIT = phepol_unit;
 (*elem_ptr)->DIRECTION = direction;
 (*elem_ptr)->GAIN = gain;
 (*elem_ptr)->GAIN_UNIT = gain_unit;
 (*elem_ptr)->NPORTS = nports;
 (*elem_ptr)->PORT_PTR = *port_ptr;
 *pp2 = *curr_ptr;
 return 0;
}
int
sinstep(struct charac * p1,
 struct charac ** pp2, double *step_ptr, int *step_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *step_ptr = 0;
 *step_unit_ptr = 0;
 error = (GetKeyword(Keywords[16], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetUReal(*curr_ptr, curr_ptr, step_ptr));
 if (error != 0) {
  *step_ptr = 0;
  return error;
 };
 error = lenunit(curr_ptr, step_unit_ptr);
 if (error != 0)
  *step_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
int
squgrdef(struct charac * p1,
  struct charac ** pp2, double *pstep_ptr, int *pstep_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *pstep_ptr = 0;
 *pstep_unit_ptr = 0;
 error = (GetKeyword(Keywords[17], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = sinstep(*curr_ptr, curr_ptr, pstep_ptr, pstep_unit_ptr);
 if (error == 1) {
  *pstep_ptr = 0;
  *pstep_unit_ptr = 0;
  *pp2 = *curr_ptr;
  return 0;
 };
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *pstep_ptr = 0;
  *pstep_unit_ptr = 0;
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
char
TapeGet(struct charac ** tp)
{
 char ch;
 if (*tp == ((void *)0))
  ch = '\0';
 else {
  ch = (*tp)->info;
  (*tp) = (*tp)->NEXT;
 };
 return ch;
}
int
trigrdef(struct charac * p1,
  struct charac ** pp2, double *angle_ptr, int *angle_unit_ptr, double *pstep_ptr, double *qstep_ptr, int *pqstep_unit_ptr,
  double *px_ptr, double *py_ptr, double *qx_ptr, double *qy_ptr, int *pqxy_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *angle_ptr = 0;
 *angle_unit_ptr = 0;
 *pstep_ptr = 0;
 *qstep_ptr = 0;
 *pqstep_unit_ptr = 0;
 *px_ptr = 0;
 *py_ptr = 0;
 *qx_ptr = 0;
 *qy_ptr = 0;
 *pqxy_unit_ptr = 0;
 error = (GetKeyword(Keywords[21], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = angstep(*curr_ptr, curr_ptr, angle_ptr, angle_unit_ptr, pstep_ptr, qstep_ptr, pqstep_unit_ptr);
 if (error == 17) {
  *angle_ptr = 0;
  *angle_unit_ptr = 0;
  *pstep_ptr = 0;
  *qstep_ptr = 0;
  *pqstep_unit_ptr = 0;
  parserro(*curr_ptr, 94, " ");
  return 17;
 };
 if (error != 0) {
  error = versdef(*curr_ptr, curr_ptr, px_ptr, py_ptr, qx_ptr, qy_ptr, pqxy_unit_ptr);
  if ((error != 1) && (error != 0)) {
   parserro(*curr_ptr, error, " ");
   *px_ptr = 0;
   *py_ptr = 0;
   *qx_ptr = 0;
   *qy_ptr = 0;
   *pqxy_unit_ptr = 0;
   return 17;
  };
  if (error == 1) {
   *angle_ptr = 0;
   *angle_unit_ptr = 0;
   *pstep_ptr = 0;
   *qstep_ptr = 0;
   *pqstep_unit_ptr = 0;
   *px_ptr = 0;
   *py_ptr = 0;
   *qx_ptr = 0;
   *qy_ptr = 0;
   *pqxy_unit_ptr = 0;
  };
 };
 *pp2 = *curr_ptr;
 return 0;
}
void
unaminit(void)
{
 char i;
 for (i = 0; (i <= 20); i++)
  strcpy(UserNames[i], "");
}
int
unifamp(struct charac * p1, struct charac ** pp2,
 double *unif_val_ptr,
 int *amp_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[88], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = ampval(*curr_ptr, curr_ptr, unif_val_ptr, amp_unit_ptr);
 if (error != 0) {
  *unif_val_ptr = 0;
  *amp_unit_ptr = 0;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
unifpha(struct charac * p1, struct charac ** pp2,
 double *unif_val_ptr,
 int *phase_unit_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[88], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = angval(*curr_ptr, curr_ptr, unif_val_ptr, phase_unit_ptr);
 if (error != 0) {
  *unif_val_ptr = 0;
  *phase_unit_ptr = 0;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
uvdir(struct charac * p1, struct charac ** pp2,
      double *u_ptr,
      double *v_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[97], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (uvval(*curr_ptr, curr_ptr, u_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 71, " ");
  return 17;
 };
 error = (GetKeyword(Keywords[98], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, 1, Keywords[98]);
  return 17;
 };
 error = (uvval(*curr_ptr, curr_ptr, v_ptr));
 if (error != 0) {
  printf("\n%s", ErrorMessages[71]);
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
uvval(struct charac * p1,
      struct charac ** pp2, double *val_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = (GetReal(val_ptr, curr_ptr));
 if (error != 0) {
  return 1;
 };
 if ((*val_ptr < -1) || (*val_ptr > 1)) {
  parserro(*curr_ptr, 72, " ");
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
int
versdef(struct charac * p1,
 struct charac ** pp2, double *px_ptr, double *py_ptr, double *qx_ptr, double *qy_ptr, int *pqxy_unit_ptr)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 *px_ptr = 0;
 *py_ptr = 0;
 *qx_ptr = 0;
 *qy_ptr = 0;
 *pqxy_unit_ptr = 0;
 error = (GetKeyword(Keywords[53], curr_ptr));
 if (error != 0) {
  return 1;
 };
 error = (GetReal(px_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *px_ptr = 0;
  *py_ptr = 0;
  *qx_ptr = 0;
  *qy_ptr = 0;
  *pqxy_unit_ptr = 0;
  return 17;
 };
 error = (GetKeyword(Keywords[54], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, Keywords[54]);
  return 17;
 };
 error = (GetReal(py_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *px_ptr = 0;
  *py_ptr = 0;
  *qx_ptr = 0;
  *qy_ptr = 0;
  *pqxy_unit_ptr = 0;
  return 17;
 };
 error = (GetKeyword(Keywords[55], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, Keywords[55]);
  return 17;
 };
 error = (GetReal(qx_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *px_ptr = 0;
  *py_ptr = 0;
  *qx_ptr = 0;
  *qy_ptr = 0;
  *pqxy_unit_ptr = 0;
  return 17;
 };
 error = (GetKeyword(Keywords[56], curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, Keywords[56]);
  return 17;
 };
 error = (GetReal(qy_ptr, curr_ptr));
 if (error != 0) {
  parserro(*curr_ptr, error, " ");
  *px_ptr = 0;
  *py_ptr = 0;
  *qx_ptr = 0;
  *qy_ptr = 0;
  *pqxy_unit_ptr = 0;
  return 17;
 };
 error = lenunit(curr_ptr, pqxy_unit_ptr);
 if (error != 0)
  *pqxy_unit_ptr = 0;
 *pp2 = *curr_ptr;
 return 0;
}
void
waitcont(void)
{
}
int
xycoord(struct charac * p1, struct charac ** pp2,
 double *xcoord_ptr,
 double *ycoord_ptr
)
{
 struct charac *curr, **curr_ptr = &curr;
 int error;
 *curr_ptr = p1;
 error = 0;
 error = (GetKeyword(Keywords[12], curr_ptr));
 error = 0;
 error = (GetReal(xcoord_ptr, curr_ptr));
 if (error != 0) {
  return 17;
 };
 error = (GetKeyword(Keywords[13], curr_ptr));
 error = 0;
 error = (GetReal(ycoord_ptr, curr_ptr));
 if (error != 0) {
  return 17;
 };
 *pp2 = *curr_ptr;
 return 0;
}
