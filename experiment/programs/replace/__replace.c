extern void exit();

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
extern int fclose (FILE *__stream);
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
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc)
  ;
extern void setbuf (FILE * __stream, char * __buf) ;
extern int setvbuf (FILE * __stream, char * __buf,
      int __modes, size_t __n) ;
extern void setbuffer (FILE * __stream, char * __buf,
         size_t __size) ;
extern void setlinebuf (FILE *__stream) ;
extern int fprintf (FILE * __stream,
      const char * __format, ...);
extern int printf (const char * __format, ...);
extern int sprintf (char * __s,
      const char * __format, ...) ;
extern int vfprintf (FILE * __s, const char * __format,
       __gnuc_va_list __arg);
extern int vprintf (const char * __format, __gnuc_va_list __arg);
extern int vsprintf (char * __s, const char * __format,
       __gnuc_va_list __arg) ;
extern int snprintf (char * __s, size_t __maxlen,
       const char * __format, ...)
     ;
extern int vsnprintf (char * __s, size_t __maxlen,
        const char * __format, __gnuc_va_list __arg)
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
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
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
extern int fputs (const char * __s, FILE * __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void * __ptr, size_t __size,
       size_t __n, FILE * __stream) ;
extern size_t fwrite (const void * __ptr, size_t __size,
        size_t __n, FILE * __s);
extern size_t fread_unlocked (void * __ptr, size_t __size,
         size_t __n, FILE * __stream) ;
extern size_t fwrite_unlocked (const void * __ptr, size_t __size,
          size_t __n, FILE * __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE * __stream, fpos_t * __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern void clearerr (FILE *__stream) ;
extern int feof (FILE *__stream) ;
extern int ferror (FILE *__stream) ;
extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;
extern void perror (const char *__s);
extern int fileno (FILE *__stream) ;
extern int fileno_unlocked (FILE *__stream) ;
extern int pclose (FILE *__stream);
extern FILE *popen (const char *__command, const char *__modes)
  ;
extern char *ctermid (char *__s)
  ;
extern void flockfile (FILE *__stream) ;
extern int ftrylockfile (FILE *__stream) ;
extern void funlockfile (FILE *__stream) ;
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);

typedef char bool;
typedef char character;
typedef char string[100];
FILE* mystdin;
void Caseerror();
bool
get_line(s, maxsize)
char *s;
int maxsize;
{
    char *result;
    result = fgets(s, maxsize, mystdin);
    return (result != ((void *)0));
}
int
addstr(c, outset, j, maxset)
char c;
char *outset;
int *j;
int maxset;
{
    bool result;
    if (*j >= maxset)
 result = 0;
    else {
 outset[*j] = c;
 *j = *j + 1;
 result = 1;
    }
    return result;
}
char
esc(s, i)
char *s;
int *i;
{
    char result;
    if (s[*i] != '@')
 result = s[*i];
    else
 if (s[*i + 1] == '\0')
     result = '@';
 else
 {
     *i = *i + 1;
     if (s[*i] == 'n')
  result = 10;
     else
  if (s[*i] == 't')
      result = 9;
  else
      result = s[*i];
 }
    return result;
}
void change();
 void
dodash(delim, src, i, dest, j, maxset)
char delim;
char *src;
int *i;
char *dest;
int *j;
int maxset;
{
    int k;
    bool junk;
    char escjunk;
    while ((src[*i] != delim) && (src[*i] != '\0'))
    {
 if (src[*i - 1] == '@') {
     escjunk = esc(src, i);
     junk = addstr(escjunk, dest, j, maxset);
 } else
     if (src[*i] != '-')
  junk = addstr(src[*i], dest, j, maxset);
     else if (*j <= 1 || src[*i + 1] == '\0')
  junk = addstr('-', dest, j, maxset);
     else if ((isalnum(src[*i - 1])) && (isalnum(src[*i + 1]))
  && (src[*i - 1] <= src[*i + 1]))
  {
      for (k = src[*i-1]+1; k<=src[*i+1]; k++)
      {
   junk = addstr(k, dest, j, maxset);
      }
      *i = *i + 1;
  }
     else
  junk = addstr('-', dest, j, maxset);
 (*i) = (*i) + 1;
    }
}
bool
getccl(arg, i, pat, j)
char *arg;
int *i;
char *pat;
int *j;
{
    int jstart;
    bool junk;
    *i = *i + 1;
    if (arg[*i] == '^') {
 junk = addstr('!', pat, j, 100);
 *i = *i + 1;
    } else
 junk = addstr('[', pat, j, 100);
    jstart = *j;
    junk = addstr(0, pat, j, 100);
    dodash(']', arg, i, pat, j, 100);
    pat[jstart] = *j - jstart - 1;
    return (arg[*i] == ']');
}
 void
stclose(pat, j, lastj)
char *pat;
int *j;
int lastj;
{
    int jt;
    int jp;
    bool junk;
    for (jp = *j - 1; jp >= lastj ; jp--)
    {
 jt = jp + 1;
 junk = addstr(pat[jp], pat, &jt, 100);
    }
    *j = *j + 1;
    pat[lastj] = '*';
}
bool in_set_2(c)
char c;
{
  return (c == '%' || c == '$' || c == '*');
}
bool in_pat_set(c)
char c;
{
  return ( c == 'c' || c == '%' || c == '$' || c == '?'
          || c == '[' || c == '!' || c == '*');
}
int
makepat(arg, start, delim, pat)
char *arg;
int start;
char delim;
char *pat;
{
    int result;
    int i, j, lastj, lj;
    bool done, junk;
    bool getres;
    char escjunk;
    j = 0;
    i = start;
    lastj = 0;
    done = 0;
    while ((!done) && (arg[i] != delim) && (arg[i] != '\0')) {
 lj = j;
 if ((arg[i] == '?'))
     junk = addstr('?', pat, &j, 100);
 else if ((arg[i] == '%') && (i == start))
     junk = addstr('%', pat, &j, 100);
 else if ((arg[i] == '$') && (arg[i+1] == delim))
     junk = addstr('$', pat, &j, 100);
 else if ((arg[i] == '['))
 {
     getres = getccl(arg, &i, pat, &j);
     done = (bool)(getres == 0);
 }
 else if ((arg[i] == '*') && (i > start))
 {
     lj = lastj;
     if (in_set_2(pat[lj]))
  done = 1;
     else
  stclose(pat, &j, lastj);
 }
 else
 {
     junk = addstr('c', pat, &j, 100);
     escjunk = esc(arg, &i);
     junk = addstr(escjunk, pat, &j, 100);
 }
 lastj = lj;
 if ((!done))
     i = i + 1;
    }
    junk = addstr('\0', pat, &j, 100);
    if ((done) || (arg[i] != delim))
 result = 0;
    else
 if ((!junk))
     result = 0;
 else
     result = i;
    return result;
}
int
getpat(arg, pat)
char* arg;
char* pat;
{
    int makeres;
    makeres = makepat(arg, 0, '\0', pat);
    return (makeres > 0);
}
int
makesub(arg, from, delim, sub)
 char* arg;
 int from;
 character delim;
 char* sub;
{
    int result;
    int i, j;
    bool junk;
    character escjunk;
    j = 0;
    i = from;
    while ((arg[i] != delim) && (arg[i] != '\0')) {
 if ((arg[i] == (unsigned)('&')))
     junk = addstr(-1, sub, &j, 100);
 else {
     escjunk = esc(arg, &i);
     junk = addstr(escjunk, sub, &j, 100);
 }
 i = i + 1;
    }
    if (arg[i] != delim)
 result = 0;
    else {
 junk = addstr('\0', &(*sub), &j, 100);
 if ((!junk))
     result = 0;
 else
     result = i;
    }
    return result;
}
bool
getsub(arg, sub)
 char* arg;
 char* sub;
{
    int makeres;
    makeres = makesub(arg, 0, '\0', sub);
    return (makeres > 0);
}
void subline();
 bool
locate(c, pat, offset)
 character c;
 char * pat;
 int offset;
{
    int i;
    bool flag;
    flag = 0;
    i = offset + pat[offset];
    while ((i > offset))
    {
 if (c == pat[i]) {
     flag = 1;
     i = offset;
 } else
     i = i - 1;
    }
    return flag;
}
bool
omatch(lin, i, pat, j)
 char* lin;
 int *i;
 char* pat;
 int j;
{
    char advance;
    bool result;
    advance = -1;
    if ((lin[*i] == '\0'))
 result = 0;
    else
    {
 if (!in_pat_set(pat[j]))
 {
     (void)fprintf(stdout, "in omatch: can't happen\n");
     exit(-1);
 } else
 {
      switch (pat[j])
      {
      case 'c':
   if (lin[*i] == pat[j + 1])
       advance = 1;
   break ;
      case '%':
   if (*i == 0)
       advance = 0;
   break ;
      case '?':
   if (lin[*i] != 10)
       advance = 1;
   break ;
      case '$':
   if (lin[*i] == 10)
       advance = 0;
   break ;
      case '[':
   if (locate(lin[*i], pat, j + 1))
       advance = 1;
   break ;
      case '!':
   if ((lin[*i] != 10) && (!locate(lin[*i], pat, j+1)))
       advance = 1;
   break ;
      default:
   Caseerror(pat[j]);
      };
  }
    }
    if ((advance >= 0))
    {
 *i = *i + advance;
 result = 1;
    } else
 result = 0;
    return result;
}
patsize(pat, n)
 char* pat;
 int n;
{
    int size;
    if (!in_pat_set(pat[n])) {
 (void)fprintf(stdout, "in patsize: can't happen\n");
 exit(-1);
    } else
 switch (pat[n])
 {
 case 'c': size = 2; break;
 case '%': case '$': case '?':
     size = 1;
     break;
 case '[': case '!':
     size = pat[n + 1] + 2;
     break ;
 case '*':
     size = 1;
     break ;
 default:
     Caseerror(pat[n]);
 }
    return size;
}
int
amatch(lin, offset, pat, j)
 char* lin;
 int offset;
 char* pat;
 int j;
{
    int i, k;
    bool result, done;
    done = 0;
    while ((!done) && (pat[j] != '\0'))
 if ((pat[j] == '*')) {
     j = j + patsize(pat, j);
     i = offset;
     while ((!done) && (lin[i] != '\0')) {
  result = omatch(lin, &i, pat, j);
  if (!result)
      done = 1;
     }
     done = 0;
     while ((!done) && (i >= offset)) {
  k = amatch(lin, i, pat, j + patsize(pat, j));
  if ((k >= 0))
      done = 1;
  else
      i = i - 1;
     }
     offset = k;
     done = 1;
 } else {
     result = omatch(lin, &offset, pat, j);
     if ((!result)) {
  offset = -1;
  done = 1;
     } else
  j = j + patsize(pat, j);
 }
     return offset;
}
void
putsub(lin, s1, s2, sub)
  char * lin;
  int s1, s2;
  char * sub;
{
    int i;
    int j;
    i = 0;
    while ((sub[i] != '\0')) {
 if ((sub[i] == -1))
     for (j = s1; j < s2; j++)
     {
  fputc(lin[j],stdout);
     }
 else
 {
     fputc(sub[i],stdout);
 }
 i = i + 1;
    }
}
void
subline(lin, pat, sub)
 char *lin;
 char *pat;
 char *sub;
{
 int i, lastm, m;
 lastm = -1;
 i = 0;
 while ((lin[i] != '\0'))
 {
     m = amatch(lin, i, pat, 0);
     if ((m >= 0) && (lastm != m)) {
  putsub(lin, i, m, sub);
  lastm = m;
     }
     if ((m == -1) || (m == i)) {
  fputc(lin[i],stdout);
  i = i + 1;
     } else
  i = m;
 }
}
 void
change(pat, sub)
char *pat, *sub;
{
    string line;
    bool result;
    result = get_line(line, 100);
    while ((result)) {
 subline(line, pat, sub);
 result = get_line(line, 100);
    }
}
main(argc, argv)
int argc;
char *argv[];
{
    if ( strcmp("?", argv[1]) == 0 )
    {
        driver(atoi(argv[2]), argc, argv);
    }
    else
    {
        driver(0, argc, argv);
    }
    return 0;
}
void
Caseerror(n)
 int n;
{
 (void)fprintf(stdout, "Missing case limb: line %d\n", n);
 exit(4);
}
