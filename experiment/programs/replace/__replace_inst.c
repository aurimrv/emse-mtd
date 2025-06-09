
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
char *result; ponta_de_prova (9072, 1);
    result = fgets(s, maxsize, mystdin); 
    return (result != ((void *)0)); ponta_de_prova (9072, 2);
} 
int
addstr(c, outset, j, maxset) 
char c; 
char *outset; 
int *j; 
int maxset; 
{ 
bool result; ponta_de_prova (9218, 1);
    if (*j >= maxset) {
        ponta_de_prova (9218, 2);
        result = 0; }
    else 
        { 
            ponta_de_prova (9218, 3);
            outset[*j] = c; 
            *j = *j + 1; 
            result = 1; 
        } 
    ponta_de_prova (9218, 4);
    return result; ponta_de_prova (9218, 5);
} 
char
esc(s, i) 
char *s; 
int *i; 
{ 
char result; ponta_de_prova (9430, 1);
    if (s[*i] != '@') {
        ponta_de_prova (9430, 2);
        result = s[*i]; }
    else {
        if  ( ponta_de_prova (9430, 3), (s[*i + 1] == '\0') ){
            ponta_de_prova (9430, 4);
            result = '@'; }
        else 
            { 
                ponta_de_prova (9430, 5);
                *i = *i + 1; 
                if (s[*i] == 'n') {
                    ponta_de_prova (9430, 6);
                    result = 10; }
                else {
                    if  ( ponta_de_prova (9430, 7), (s[*i] == 't') ){
                        ponta_de_prova (9430, 8);
                        result = 9; }
                    else {
                        ponta_de_prova (9430, 9);
                        result = s[*i]; }}ponta_de_prova (9430, 11);
            } }
    ponta_de_prova (9430, 13);
    return result; ponta_de_prova (9430, 14);
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
char escjunk; ponta_de_prova (9754, 1);
    
    while  ( ponta_de_prova (9754, 2), ((src[*i] != delim) && (src[*i] != '\0')) )
        { 
            if  ( ponta_de_prova (9754, 3), (src[*i - 1] == '@') )
                { 
                    ponta_de_prova (9754, 4);
                    escjunk = esc(src, i); 
                    junk = addstr(escjunk, dest, j, maxset); 
                } 
            else {
                if  ( ponta_de_prova (9754, 5), (src[*i] != '-') ){
                    ponta_de_prova (9754, 6);
                    junk = addstr(src[*i], dest, j, maxset); }
                else {
                    if  ( ponta_de_prova (9754, 7), (*j <= 1 || src[*i + 1] == '\0') ){
                        ponta_de_prova (9754, 8);
                        junk = addstr('-', dest, j, maxset); }
                    else {
                        if  ( ponta_de_prova (9754, 9), ((isalnum(src[*i - 1])) && (isalnum(src[*i + 1]))
  && (src[*i - 1] <= src[*i + 1])) )
                            { 
                                for ( ponta_de_prova (9754, 10), k = src[*i-1]+1; ponta_de_prova (9754, 11), k<=src[*i+1]; ponta_de_prova (9754, 12), k++  )
                                    { 
                                        ponta_de_prova (9754, 13);
                                        junk = addstr(k, dest, j, maxset); 
                                    } 
                                ponta_de_prova (9754, 14);
                                *i = *i + 1; 
                            } 
                        else {
                            ponta_de_prova (9754, 15);
                            junk = addstr('-', dest, j, maxset); }}}}
            ponta_de_prova (9754, 19);
            (*i) = (*i) + 1; 
        } ponta_de_prova (9754, 20);
} 
bool
getccl(arg, i, pat, j) 
char *arg; 
int *i; 
char *pat; 
int *j; 
{ 
int jstart; 
bool junk; ponta_de_prova (10528, 1);
    *i = *i + 1; 
    if (arg[*i] == '^') 
        { 
            ponta_de_prova (10528, 2);
            junk = addstr('!', pat, j, 100); 
            *i = *i + 1; 
        } 
    else {
        ponta_de_prova (10528, 3);
        junk = addstr('[', pat, j, 100); }
    ponta_de_prova (10528, 4);
    jstart = *j; 
    junk = addstr(0, pat, j, 100); 
    dodash(']', arg, i, pat, j, 100); 
    pat[jstart] = *j - jstart - 1; 
    return (arg[*i] == ']'); ponta_de_prova (10528, 5);
} 
void
stclose(pat, j, lastj) 
char *pat; 
int *j; 
int lastj; 
{ 
int jt; 
int jp; 
bool junk; ponta_de_prova (10920, 1);
    for ( jp = *j - 1; ponta_de_prova (10920, 2), jp >= lastj ; ponta_de_prova (10920, 3), jp--  )
        { 
            ponta_de_prova (10920, 4);
            jt = jp + 1; 
            junk = addstr(pat[jp], pat, &jt, 100); 
        } 
    ponta_de_prova (10920, 5);
    *j = *j + 1; 
    pat[lastj] = '*'; 
} 
bool in_set_2(c) 
char c; 
{ ponta_de_prova (11168, 1);
    return (c == '%' || c == '$' || c == '*'); ponta_de_prova (11168, 2);
} 
bool in_pat_set(c) 
char c; 
{ ponta_de_prova (11242, 1);
    return ( c == 'c' || c == '%' || c == '$' || c == '?'
          || c == '[' || c == '!' || c == '*'); ponta_de_prova (11242, 2);
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
char escjunk; ponta_de_prova (11376, 1);
    j = 0; 
    i = start; 
    lastj = 0; 
    done = 0; 
    
    while  ( ponta_de_prova (11376, 2), ((!done) && (arg[i] != delim) && (arg[i] != '\0')) )
        { 
            ponta_de_prova (11376, 3);
            lj = j; 
            if ((arg[i] == '?')) {
                ponta_de_prova (11376, 4);
                junk = addstr('?', pat, &j, 100); }
            else {
                if  ( ponta_de_prova (11376, 5), ((arg[i] == '%') && (i == start)) ){
                    ponta_de_prova (11376, 6);
                    junk = addstr('%', pat, &j, 100); }
                else {
                    if  ( ponta_de_prova (11376, 7), ((arg[i] == '$') && (arg[i+1] == delim)) ){
                        ponta_de_prova (11376, 8);
                        junk = addstr('$', pat, &j, 100); }
                    else {
                        if  ( ponta_de_prova (11376, 9), ((arg[i] == '[')) )
                            { 
                                ponta_de_prova (11376, 10);
                                getres = getccl(arg, &i, pat, &j); 
                                done = (bool)(getres == 0); 
                            } 
                        else {
                            if  ( ponta_de_prova (11376, 11), ((arg[i] == '*') && (i > start)) )
                                { 
                                    ponta_de_prova (11376, 12);
                                    lj = lastj; 
                                    if (in_set_2(pat[lj])) {
                                        ponta_de_prova (11376, 13);
                                        done = 1; }
                                    else {
                                        ponta_de_prova (11376, 14);
                                        stclose(pat, &j, lastj); }ponta_de_prova (11376, 15);
                                } 
                            else 
                                { 
                                    ponta_de_prova (11376, 16);
                                    junk = addstr('c', pat, &j, 100); 
                                    escjunk = esc(arg, &i); 
                                    junk = addstr(escjunk, pat, &j, 100); 
                                } }}}}
            ponta_de_prova (11376, 21);
            lastj = lj; 
            if ((!done)) {
                ponta_de_prova (11376, 22);
                i = i + 1; }ponta_de_prova (11376, 23);
        } 
    ponta_de_prova (11376, 24);
    junk = addstr('\0', pat, &j, 100); 
    if ((done) || (arg[i] != delim)) {
        ponta_de_prova (11376, 25);
        result = 0; }
    else {
        if  ( ponta_de_prova (11376, 26), ((!junk)) ){
            ponta_de_prova (11376, 27);
            result = 0; }
        else {
            ponta_de_prova (11376, 28);
            result = i; }}
    ponta_de_prova (11376, 30);
    return result; ponta_de_prova (11376, 31);
} 
int
getpat(arg, pat) 
char* arg; 
char* pat; 
{ 
int makeres; ponta_de_prova (12508, 1);
    makeres = makepat(arg, 0, '\0', pat); 
    return (makeres > 0); ponta_de_prova (12508, 2);
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
character escjunk; ponta_de_prova (12640, 1);
    j = 0; 
    i = from; 
    
    while  ( ponta_de_prova (12640, 2), ((arg[i] != delim) && (arg[i] != '\0')) )
        { 
            if  ( ponta_de_prova (12640, 3), ((arg[i] == (unsigned)('&'))) ){
                ponta_de_prova (12640, 4);
                junk = addstr(-1, sub, &j, 100); }
            else 
                { 
                    ponta_de_prova (12640, 5);
                    escjunk = esc(arg, &i); 
                    junk = addstr(escjunk, sub, &j, 100); 
                } 
            ponta_de_prova (12640, 6);
            i = i + 1; 
        } 
    if  ( ponta_de_prova (12640, 7), (arg[i] != delim) ){
        ponta_de_prova (12640, 8);
        result = 0; }
    else 
        { 
            ponta_de_prova (12640, 9);
            junk = addstr('\0', &(*sub), &j, 100); 
            if ((!junk)) {
                ponta_de_prova (12640, 10);
                result = 0; }
            else {
                ponta_de_prova (12640, 11);
                result = i; }ponta_de_prova (12640, 12);
        } 
    ponta_de_prova (12640, 13);
    return result; ponta_de_prova (12640, 14);
} 
bool
getsub(arg, sub) 
char* arg; 
char* sub; 
{ 
int makeres; ponta_de_prova (13219, 1);
    makeres = makesub(arg, 0, '\0', sub); 
    return (makeres > 0); ponta_de_prova (13219, 2);
} 
void subline(); 
bool
locate(c, pat, offset) 
character c; 
char * pat; 
int offset; 
{ 
int i; 
bool flag; ponta_de_prova (13371, 1);
    flag = 0; 
    i = offset + pat[offset]; 
    
    while  ( ponta_de_prova (13371, 2), ((i > offset)) )
        { 
            if  ( ponta_de_prova (13371, 3), (c == pat[i]) )
                { 
                    ponta_de_prova (13371, 4);
                    flag = 1; 
                    i = offset; 
                } 
            else {
                ponta_de_prova (13371, 5);
                i = i - 1; }ponta_de_prova (13371, 6);
        } 
    ponta_de_prova (13371, 7);
    return flag; ponta_de_prova (13371, 8);
} 
bool
omatch(lin, i, pat, j) 
char* lin; 
int *i; 
char* pat; 
int j; 
{ 
char advance; 
bool result; ponta_de_prova (13643, 1);
    advance = -1; 
    if ((lin[*i] == '\0')) {
        ponta_de_prova (13643, 2);
        result = 0; }
    else 
        { 
            if  ( ponta_de_prova (13643, 3), (!in_pat_set(pat[j])) )
                { 
                    ponta_de_prova (13643, 4);
                    (void)fprintf(stdout, "in omatch: can't happen\n"); 
                    exit(-1); 
                } 
            else 
                { 
                    switch  ( ponta_de_prova (13643, 5), (pat[j]) )
                        { 
                            case 'c': ponta_de_prova (13643, 6);
                                if (lin[*i] == pat[j + 1]) {
                                    ponta_de_prova (13643, 7);
                                    advance = 1; }
                            ponta_de_prova (13643, 8);
                            break ; 
                            case '%': ponta_de_prova (13643, 9);
                                if (*i == 0) {
                                    ponta_de_prova (13643, 10);
                                    advance = 0; }
                            ponta_de_prova (13643, 11);
                            break ; 
                            case '?': ponta_de_prova (13643, 12);
                                if (lin[*i] != 10) {
                                    ponta_de_prova (13643, 13);
                                    advance = 1; }
                            ponta_de_prova (13643, 14);
                            break ; 
                            case '$': ponta_de_prova (13643, 15);
                                if (lin[*i] == 10) {
                                    ponta_de_prova (13643, 16);
                                    advance = 0; }
                            ponta_de_prova (13643, 17);
                            break ; 
                            case '[': ponta_de_prova (13643, 18);
                                if (locate(lin[*i], pat, j + 1)) {
                                    ponta_de_prova (13643, 19);
                                    advance = 1; }
                            ponta_de_prova (13643, 20);
                            break ; 
                            case '!': ponta_de_prova (13643, 21);
                                if ((lin[*i] != 10) && (!locate(lin[*i], pat, j+1))) {
                                    ponta_de_prova (13643, 22);
                                    advance = 1; }
                            ponta_de_prova (13643, 23);
                            break ; 
                            default: ponta_de_prova (13643, 24);
                                Caseerror(pat[j]); 
                        } 
                    ponta_de_prova (13643, 25);
                    ; 
                } ponta_de_prova (13643, 26);
        } 
    if  ( ponta_de_prova (13643, 27), ((advance >= 0)) )
        { 
            ponta_de_prova (13643, 28);
            *i = *i + advance; 
            result = 1; 
        } 
    else {
        ponta_de_prova (13643, 29);
        result = 0; }
    ponta_de_prova (13643, 30);
    return result; ponta_de_prova (13643, 31);
} 
patsize(pat, n) 
char* pat; 
int n; 
{ 
int size; ponta_de_prova (14587, 1);
    if (!in_pat_set(pat[n])) 
        { 
            ponta_de_prova (14587, 2);
            (void)fprintf(stdout, "in patsize: can't happen\n"); 
            exit(-1); 
        } 
    else {
        switch  ( ponta_de_prova (14587, 3), (pat[n]) )
            { 
                case 'c': ponta_de_prova (14587, 4);
                    size = 2; 
                break; 
                case '%': ponta_de_prova (14587, 5);
                    case '$': ponta_de_prova (14587, 6);
                        case '?': ponta_de_prova (14587, 6);
                            size = 1; 
                break; 
                case '[': ponta_de_prova (14587, 7);
                    case '!': ponta_de_prova (14587, 8);
                        size = pat[n + 1] + 2; 
                break ; 
                case '*': ponta_de_prova (14587, 9);
                    size = 1; 
                break ; 
                default: ponta_de_prova (14587, 10);
                    Caseerror(pat[n]); 
            } }
    ponta_de_prova (14587, 12);
    return size; ponta_de_prova (14587, 13);
} 
int
amatch(lin, offset, pat, j) 
char* lin; 
int offset; 
char* pat; 
int j; 
{ 
int i, k; 
bool result, done; ponta_de_prova (15013, 1);
    done = 0; 
    
    while  ( ponta_de_prova (15013, 2), ((!done) && (pat[j] != '\0')) ){
        if  ( ponta_de_prova (15013, 3), ((pat[j] == '*')) )
            { 
                ponta_de_prova (15013, 4);
                j = j + patsize(pat, j); 
                i = offset; 
                
                while  ( ponta_de_prova (15013, 5), ((!done) && (lin[i] != '\0')) )
                    { 
                        ponta_de_prova (15013, 6);
                        result = omatch(lin, &i, pat, j); 
                        if (!result) {
                            ponta_de_prova (15013, 7);
                            done = 1; }ponta_de_prova (15013, 8);
                    } 
                ponta_de_prova (15013, 9);
                done = 0; 
                
                while  ( ponta_de_prova (15013, 10), ((!done) && (i >= offset)) )
                    { 
                        ponta_de_prova (15013, 11);
                        k = amatch(lin, i, pat, j + patsize(pat, j)); 
                        if ((k >= 0)) {
                            ponta_de_prova (15013, 12);
                            done = 1; }
                        else {
                            ponta_de_prova (15013, 13);
                            i = i - 1; }ponta_de_prova (15013, 14);
                    } 
                ponta_de_prova (15013, 15);
                offset = k; 
                done = 1; 
            } 
        else 
            { 
                ponta_de_prova (15013, 16);
                result = omatch(lin, &offset, pat, j); 
                if ((!result)) 
                    { 
                        ponta_de_prova (15013, 17);
                        offset = -1; 
                        done = 1; 
                    } 
                else {
                    ponta_de_prova (15013, 18);
                    j = j + patsize(pat, j); }ponta_de_prova (15013, 19);
            } }
    ponta_de_prova (15013, 21);
    return offset; ponta_de_prova (15013, 22);
} 
void
putsub(lin, s1, s2, sub) 
char * lin; 
int s1, s2; 
char * sub; 
{ 
int i; 
int j; ponta_de_prova (15737, 1);
    i = 0; 
    
    while  ( ponta_de_prova (15737, 2), ((sub[i] != '\0')) )
        { 
            if  ( ponta_de_prova (15737, 3), ((sub[i] == -1)) ){
                for ( ponta_de_prova (15737, 4), j = s1; ponta_de_prova (15737, 5), j < s2; ponta_de_prova (15737, 6), j++  )
                    { 
                        ponta_de_prova (15737, 7);
                        fputc(lin[j],stdout); 
                    } }
            else 
                { 
                    ponta_de_prova (15737, 9);
                    fputc(sub[i],stdout); 
                } 
            ponta_de_prova (15737, 10);
            i = i + 1; 
        } ponta_de_prova (15737, 11);
} 
void
subline(lin, pat, sub) 
char *lin; 
char *pat; 
char *sub; 
{ 
int i, lastm, m; ponta_de_prova (16024, 1);
    lastm = -1; 
    i = 0; 
    
    while  ( ponta_de_prova (16024, 2), ((lin[i] != '\0')) )
        { 
            ponta_de_prova (16024, 3);
            m = amatch(lin, i, pat, 0); 
            if ((m >= 0) && (lastm != m)) 
                { 
                    ponta_de_prova (16024, 4);
                    putsub(lin, i, m, sub); 
                    lastm = m; 
                } 
            if  ( ponta_de_prova (16024, 5), ((m == -1) || (m == i)) )
                { 
                    ponta_de_prova (16024, 6);
                    fputc(lin[i],stdout); 
                    i = i + 1; 
                } 
            else {
                ponta_de_prova (16024, 7);
                i = m; }ponta_de_prova (16024, 8);
        } ponta_de_prova (16024, 9);
} 
void
change(pat, sub) 
char *pat, *sub; 
{ 
string line; 
bool result; ponta_de_prova (16372, 1);
    result = get_line(line, 100); 
    
    while  ( ponta_de_prova (16372, 2), ((result)) )
        { 
            ponta_de_prova (16372, 3);
            subline(line, pat, sub); 
            result = get_line(line, 100); 
        } ponta_de_prova (16372, 4);
} 
main(argc, argv) 
int argc; 
char *argv[]; 
{ ponta_de_prova (16564, 1);
    if ( strcmp("?", argv[1]) == 0 ) 
        { 
            ponta_de_prova (16564, 2);
            driver(atoi(argv[2]), argc, argv); 
        } 
    else 
        { 
            ponta_de_prova (16564, 3);
            driver(0, argc, argv); 
        } 
    ponta_de_prova (16564, 4);
    return 0; ponta_de_prova (16564, 5);
} 
void
Caseerror(n) 
int n; 
{ ponta_de_prova (16772, 1);
    (void)fprintf(stdout, "Missing case limb: line %d\n", n); 
    exit(4); 
} 

