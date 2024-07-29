struct gzip_data {
  int level;
};

struct hostname_data {
  char *F;
};

struct killall_data {
  char *s;

  int signum;
  pid_t cur_pid;
  char **names;
  short *err;
  struct int_list { struct int_list *next; int val; } *pids;
};

struct md5sum_data {
  int sawline;
};

struct mknod_data {
  char *Z, *m;
};

struct mktemp_data {
  char *p, *tmpdir;
};

struct mount_data {
  struct arg_list *o;
  char *t, *O;

  unsigned long flags;
  char *opts;
  int okuser;
};

struct passwd_data {
  char *a;
};

struct pidof_data {
  char *o;
};

struct seq_data {
  char *s, *f;

  int precision, buflen;
};

struct su_data {
  char *s, *c;
};

struct umount_data {
  struct arg_list *t;

  char *types;
};

struct ftpget_data {
  char *u, *p, *P;

  int fd;
};

struct host_data {
  char *t;

  char **nsname;
  unsigned nslen;
};

struct microcom_data {
  long s;

  int fd, stok;
  struct termios old_stdin, old_fd;
};

struct netcat_data {
  char *f, *s;
  long q, p, W, w;
};

struct sntp_data {
  long r, t;
  char *p, *m, *M;
};

struct wget_data {
  char *p, *O;
  long max_redirect;

  int sock, https;
  char *url;
#if CFG_WGET_LIBTLS
  struct tls *tls;
#elif CFG_TOYBOX_LIBCRYPTO
  struct ssl_ctx_st *ctx;
  struct ssl_st *ssl;
#endif
};

struct base64_data {
  long w;

  unsigned total;
  unsigned n;  // number of bits used in encoding. 5 for base32, 6 for base64
  unsigned align;  // number of bits to align to
};

struct blkid_data {
  struct arg_list *s;
  char *o;
};

struct chrt_data {
  long p;
};

struct count_data {
  unsigned long long size, start;
  unsigned tick, *slice;
};

struct dos2unix_data {
  char *tempfile;
};

struct fallocate_data {
  long o, l;
};

struct fmt_data {
  long width;

  int level, pos;
};

struct free_data {
  unsigned bits;
  unsigned long long units;
  char *buf;
};

struct getopt_data {
  struct arg_list *l;
  char *o, *n;
};

struct hexedit_data {
  char *data, *search, keybuf[16], input[80];
  long long len, base, pos;
  int numlen, undo, undolen, mode;
  unsigned rows, cols;
};

struct ionice_data {
  long p, n, c;
};

struct makedevs_data {
  char *d;
};

struct mkpasswd_data {
  long P;
  char *m, *S;
};

struct pwgen_data {
  char *r;
};

struct realpath_data {
  char *R, *relative_base;
};

struct setfattr_data {
  char *x, *v, *n;
};

struct setsid_data {
  long c;
};

struct sha3sum_data {
  long a;
  unsigned long long rc[24];
};

struct shred_data {
  long o, n, s;
};

struct shuf_data {
  long n;

  char **lines;
  long count;
};

struct stat_data {
  char *c;

  union {
    struct stat st;
    struct statfs sf;
  } stat;
  char *file, *pattern;
  int patlen;
};

struct tac_data {
  struct double_list *dl;
};

struct timeout_data {
  char *s, *k;

  struct pollfd pfd;
  sigjmp_buf sj;
  int fds[2], pid, rc;
};

struct truncate_data {
  char *s;

  long long size;
  int type;
};

struct watch_data {
  int n;

  pid_t pid, oldpid;
};

struct xxd_data {
  long s, g, o, l, c;
};

struct bc_data {
  // This actually needs to be a BcVm*, but the toybox build
  // system complains if I make it so. Instead, we'll just cast.
  char *vm;

  size_t nchars;
  char *file, sig, max_ibase;
  uint16_t line_len;
};

struct diff_data {
  long U;
  struct arg_list *L;
  char *F, *S, *new_line_format, *old_line_format, *unchanged_line_format;

  int dir_num, size, is_binary, differ, change, len[2], *offset[2];
  struct stat st[2];
  struct {
    char **list;
    int nr_elm;
  } dir[2];
  struct {
    FILE *fp;
    int len;
  } file[2];
};

struct expr_data {
  char **tok, *delete;
};

struct fsck_data {
  int fd_num;
  char *t_list;

  struct double_list *devices;
  char *arr_flag;
  char **arr_type;
  int negate;
  int sum_status;
  int nr_run;
  int sig_num;
  long max_nr_run;
};

struct hexdump_data {
    long s, n;

    long long len, pos, ppos;
    const char *fmt;
    unsigned int fn, bc;  // file number and byte count
    char linebuf[16];  // line buffer - serves double duty for sqeezing repeat
                       // lines and for accumulating full lines accross file
                       // boundaries if necessesary.
};

struct man_data {
  char *M, *k;

  char any, cell, ex, *f, k_done, *line, *m, **sct, **scts, **sufs;
  regex_t reg;
};

struct more_data {
  struct termios inf;
  int cin_fd;
};

struct stty_data {
  char *F;

  int fd, col;
  unsigned output_cols;
};

struct telnet_data {
  int sock;
  char buf[2048]; // Half sizeof(toybuf) allows a buffer full of IACs.
  struct termios old_term;
  struct termios raw_term;
  uint8_t mode;
  int echo, sga;
  int state, request;
};

struct vi_data {
  char *s;

  char *filename;
  int vi_mode, tabstop, list;
  int cur_col, cur_row, scr_row;
  int drawn_row, drawn_col;
  int count0, count1, vi_mov_flag;
  unsigned screen_height, screen_width;
  char vi_reg, *last_search;
  struct str_line {
    int alloc;
    int len;
    char *data;
  } *il;
  size_t screen, cursor; //offsets
  //yank buffer
  struct yank_buf {
    char reg;
    int alloc;
    char* data;
  } yank;

  size_t filesize;
// mem_block contains RO data that is either original file as mmap
// or heap allocated inserted data
  struct block_list {
    struct block_list *next, *prev;
    struct mem_block {
      size_t size;
      size_t len;
      enum alloc_flag {
        MMAP,  //can be munmap() before exit()
        HEAP,  //can be free() before exit()
        STACK, //global or stack perhaps toybuf
      } alloc;
      const char *data;
    } *node;
  } *text;

// slices do not contain actual allocated data but slices of data in mem_block
// when file is first opened it has only one slice.
// after inserting data into middle new mem_block is allocated for insert data
// and 3 slices are created, where first and last slice are pointing to original
// mem_block with offsets, and middle slice is pointing to newly allocated block
// When deleting, data is not freed but mem_blocks are sliced more such way that
// deleted data left between 2 slices
  struct slice_list {
    struct slice_list *next, *prev;
    struct slice {
      size_t len;
      const char *data;
    } *node;
  } *slices;
};

struct basename_data {
  char *s;
};

struct cal_data {
  struct tm *now;
};

struct chgrp_data {
  uid_t owner;
  gid_t group;
  char *owner_name, *group_name;
  int symfollow;
};

struct chmod_data {
  char *mode;
};

struct cmp_data {
  long n;

  int fd;
  char *name;
};

struct cp_data {
  union {
    // install's options
    struct {
      char *g, *o, *m, *t;
    } i;
    // cp's options
    struct {
      char *t, *preserve;
    } c;
  };

  char *destname;
  struct stat top;
  int (*callback)(struct dirtree *try);
  uid_t uid;
  gid_t gid;
  int pflags;
};

struct cpio_data {
  char *F, *H, *R;
};

struct cut_data {
  char *d, *O;
  struct arg_list *select[5]; // we treat them the same, so loop through

  unsigned line;
  int pairs;
  regex_t reg;
};

struct date_data {
  char *s, *r, *I, *D, *d;

  unsigned nano;
};

struct dd_data {
  // Display fields
  int show_xfer, show_records;
  unsigned long long bytes, in_full, in_part, out_full, out_part, start;
};

struct df_data {
  struct arg_list *t;

  int units, width[6];
};

struct du_data {
  long d;

  unsigned long depth, total;
  dev_t st_dev;
  void *inodes;
};

struct env_data {
  struct arg_list *u;
  char *e;
};

struct expand_data {
  struct arg_list *t;

  unsigned tabcount, *tab;
};

struct file_data {
  int max_name_len;
  off_t len;
};

struct find_data {
  char **filter;
  struct double_list *argdata;
  int topdir, xdev, depth;
  time_t now;
  long max_bytes;
  char *start;
};

struct grep_data {
  long m, A, B, C;
  struct arg_list *f, *e, *M, *S, *exclude_dir;
  char *color;

  char *purple, *cyan, *red, *green, *grey;
  struct double_list *reg;
  int found, tried, delim;
  struct arg_list **fixed;
};

struct head_data {
  long c, n;

  int file_no;
};

struct iconv_data {
  char *f, *t;

  void *ic;
};

struct id_data {
  int is_groups;
};

struct kill_data {
  char *s;
  struct arg_list *o;
};

struct ln_data {
  char *t;
};

struct logger_data {
  char *p, *t;

  int priority;
};

struct ls_data {
  long w, l, block_size;
  char *color, *sort;

  struct dirtree *files, *singledir;
  unsigned screen_width;
  int nl_title;
  char *escmore;
};

struct mkdir_data {
  char *m, *Z;
};

struct mkfifo_data {
  char *m;
  char *Z;

  mode_t mode;
};

struct nice_data {
  long n;
};

struct nl_data {
  char *s, *n, *b;
  long w, l, v;

  // Count of consecutive blank lines for -l has to persist between files
  long lcount, slen;
};

struct od_data {
  struct arg_list *t;
  char *A;
  long N, w, j;

  int address_idx;
  unsigned types, leftover, star;
  char *buf; // Points to buffers[0] or buffers[1].
  char *bufs[2]; // Used to detect duplicate lines.
  off_t pos;
};

struct paste_data {
  char *d;

  int files;
};

struct patch_data {
  char *i, *d;
  long v, p, g, F;

  void *current_hunk;
  long oldline, oldlen, newline, newlen, linenum, outnum;
  int context, state, filein, fileout, filepatch, hunknum;
  char *tempname;
};

struct ps_data {
  union {
    struct {
      struct arg_list *G, *g, *U, *u, *t, *s, *p, *O, *o, *P, *k;
    } ps;
    struct {
      long n, m, d, s;
      struct arg_list *u, *p, *o, *k, *O;
    } top;
    struct {
      char *L;
      struct arg_list *G, *g, *P, *s, *t, *U, *u;
      char *d;

      void *regexes, *snapshot;
      int signal;
      pid_t self, match;
    } pgrep;
  };

  struct ps_ptr_len {
    void *ptr;
    long len;
  } gg, GG, pp, PP, ss, tt, uu, UU;
  struct dirtree *threadparent;
  unsigned width, height, scroll;
  dev_t tty;
  void *fields, *kfields;
  long long ticks, bits, time;
  int kcount, forcek, sortpos, pidlen;
  int (*match_process)(long long *slot);
  void (*show_process)(void *tb);
};

struct renice_data {
  long n;
};

struct sed_data {
  char *i;
  struct arg_list *f, *e;

  // processed pattern list
  struct double_list *pattern;

  char *nextline, *remember, *tarxform;
  void *restart, *lastregex;
  long nextlen, rememberlen, count;
  int fdout, noeol;
  unsigned xx, tarxlen, xflags;
  char delim, xftype;
};

struct sort_data {
  char *t;
  struct arg_list *k;
  char *o, *T, S;

  void *key_list;
  unsigned linecount;
  char **lines, *name;
};

struct split_data {
  long n, l, b, a;

  char *outfile;
};

struct strings_data {
  long n;
  char *t;
};

struct tail_data {
  long n, c;
  char *s;

  int file_no, last_fd, ss;
  struct xnotify *not;
  struct {
    char *path;
    int fd;
    struct dev_ino di;
  } *F;
};

struct tar_data {
  char *f, *C, *I;
  struct arg_list *T, *X, *xform;
  long strip;
  char *to_command, *owner, *group, *mtime, *mode, *sort;
  struct arg_list *exclude;

  struct double_list *incl, *excl, *seen;
  struct string_list *dirs;
  char *cwd, **xfsed;
  int fd, ouid, ggid, hlc, warn, sparselen, pid, xfpipe[2];
  struct dev_ino archive_di;
  long long *sparse;
  time_t mtt;

  // hardlinks seen so far (hlc many)
  struct {
    char *arg;
    struct dev_ino di;
  } *hlx;

  // Parsed information about a tar header.
  struct tar_header {
    char *name, *link_target, *uname, *gname;
    long long size, ssize;
    uid_t uid;
    gid_t gid;
    mode_t mode;
    time_t mtime;
    dev_t device;
  } hdr;
};

struct tee_data {
  void *outputs;
  int out;
};

struct touch_data {
  char *t, *r, *d;
};

struct ulimit_data {
  long P;
};

struct uniq_data {
  long w, s, f;

  long repeats;
};

struct uudecode_data {
  char *o;
};

struct wc_data {
  unsigned long totals[5];
};

struct xargs_data {
  long s, n, P;
  char *E;

  long entries, bytes, np;
  char delim;
  FILE *tty;
};
extern union global_union {
	struct gzip_data gzip;
	struct hostname_data hostname;
	struct killall_data killall;
	struct md5sum_data md5sum;
	struct mknod_data mknod;
	struct mktemp_data mktemp;
	struct mount_data mount;
	struct passwd_data passwd;
	struct pidof_data pidof;
	struct seq_data seq;
	struct su_data su;
	struct umount_data umount;
	struct ftpget_data ftpget;
	struct host_data host;
	struct microcom_data microcom;
	struct netcat_data netcat;
	struct sntp_data sntp;
	struct wget_data wget;
	struct base64_data base64;
	struct blkid_data blkid;
	struct chrt_data chrt;
	struct count_data count;
	struct dos2unix_data dos2unix;
	struct fallocate_data fallocate;
	struct fmt_data fmt;
	struct free_data free;
	struct getopt_data getopt;
	struct hexedit_data hexedit;
	struct ionice_data ionice;
	struct makedevs_data makedevs;
	struct mkpasswd_data mkpasswd;
	struct pwgen_data pwgen;
	struct realpath_data realpath;
	struct setfattr_data setfattr;
	struct setsid_data setsid;
	struct sha3sum_data sha3sum;
	struct shred_data shred;
	struct shuf_data shuf;
	struct stat_data stat;
	struct tac_data tac;
	struct timeout_data timeout;
	struct truncate_data truncate;
	struct watch_data watch;
	struct xxd_data xxd;
	struct bc_data bc;
	struct diff_data diff;
	struct expr_data expr;
	struct fsck_data fsck;
	struct hexdump_data hexdump;
	struct man_data man;
	struct more_data more;
	struct stty_data stty;
	struct telnet_data telnet;
	struct vi_data vi;
	struct basename_data basename;
	struct cal_data cal;
	struct chgrp_data chgrp;
	struct chmod_data chmod;
	struct cmp_data cmp;
	struct cp_data cp;
	struct cpio_data cpio;
	struct cut_data cut;
	struct date_data date;
	struct dd_data dd;
	struct df_data df;
	struct du_data du;
	struct env_data env;
	struct expand_data expand;
	struct file_data file;
	struct find_data find;
	struct grep_data grep;
	struct head_data head;
	struct iconv_data iconv;
	struct id_data id;
	struct kill_data kill;
	struct ln_data ln;
	struct logger_data logger;
	struct ls_data ls;
	struct mkdir_data mkdir;
	struct mkfifo_data mkfifo;
	struct nice_data nice;
	struct nl_data nl;
	struct od_data od;
	struct paste_data paste;
	struct patch_data patch;
	struct ps_data ps;
	struct renice_data renice;
	struct sed_data sed;
	struct sort_data sort;
	struct split_data split;
	struct strings_data strings;
	struct tail_data tail;
	struct tar_data tar;
	struct tee_data tee;
	struct touch_data touch;
	struct ulimit_data ulimit;
	struct uniq_data uniq;
	struct uudecode_data uudecode;
	struct wc_data wc;
	struct xargs_data xargs;
} this;
