#include <config.h>

/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 26 "src/p.y"


/*
 * DESCRIPTION
 *   Simple context-free grammar for parsing the control file. 
 *
 */

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif 

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif 

#ifdef HAVE_PWD_H
#include <pwd.h>
#endif 

#ifdef HAVE_GRP_H
#include <grp.h>
#endif 

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_ASM_PARAM_H
#include <asm/param.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

#ifndef HAVE_SOL_IP
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#endif

#ifdef HAVE_NETINET_IP_ICMP_H
#include <netinet/ip_icmp.h>
#endif

#ifdef HAVE_REGEX_H
#include <regex.h>
#endif

#include "net.h"
#include "monit.h"
#include "protocol.h"
#include "engine.h"
#include "alert.h"
#include "process.h"
#include "ssl.h"
#include "device.h"

// libmonit
#include "io/File.h"


/* ------------------------------------------------------------- Definitions */

  struct IHavePrecedence {
    int daemon;
    int logfile;
    int pidfile;
  }; 

  struct myrate {
    unsigned count;
    unsigned cycles;
  }; 

  /* yacc interface */
  void  yyerror(const char *,...);
  void  yyerror2(const char *,...);
  void  yywarning(const char *,...);
  void  yywarning2(const char *,...);

  /* lexer interface */
  int yylex(void);
  extern FILE *yyin;
  extern int lineno;
  extern int arglineno;
  extern char *yytext;
  extern char *argyytext;
  extern char *currentfile;
  extern char *argcurrentfile;
  extern int buffer_stack_ptr;

  /* Local variables */
  static int cfg_errflag = FALSE;
  static Service_T tail = NULL;
  static Service_T current = NULL;
  static Request_T urlrequest = NULL;
  static command_t command = NULL;
  static command_t command1 = NULL;
  static command_t command2 = NULL;
  static Service_T depend_list = NULL;
  static struct mygid gidset;
  static struct myuid uidset;
  static struct mystatus statusset;
  static struct myperm permset;
  static struct mysize sizeset;
  static struct myuptime uptimeset;
  static struct mymatch matchset;
  static struct myicmp icmpset;
  static struct mymail mailset;
  static struct myport portset;
  static struct mymailserver mailserverset;
  static struct myfilesystem filesystemset;
  static struct myresource resourceset;
  static struct mychecksum checksumset;
  static struct mytimestamp timestampset;
  static struct myactionrate actionrateset;
  static struct IHavePrecedence ihp = {FALSE, FALSE, FALSE};
  static struct myrate rate1 = {1, 1};
  static struct myrate rate2 = {1, 1};
  static char * htpasswd_file = NULL;
  static int    digesttype = DIGEST_CLEARTEXT;

#define BITMAP_MAX (sizeof(long long) * 8)


/* -------------------------------------------------------------- Prototypes */

  static void  preparse();
  static void  postparse();
  static void  addmail(char *, Mail_T, Mail_T *);
  static Service_T createservice(int, char *, char *, int (*)(Service_T));
  static void  addservice(Service_T);
  static void  adddependant(char *);
  static void  addservicegroup(char *);
  static void  addport(Port_T);
  static void  addresource(Resource_T);
  static void  addtimestamp(Timestamp_T, int);
  static void  addactionrate(ActionRate_T);
  static void  addsize(Size_T);
  static void  adduptime(Uptime_T);
  static void  addfilesystem(Filesystem_T);
  static void  addicmp(Icmp_T);
  static void  addgeneric(Port_T, char*, char*);
  static void  addcommand(int, unsigned);
  static void  addargument(char *);
  static void  addmmonit(URL_T, int, int, char *);
  static void  addmailserver(MailServer_T);
  static int   addcredentials(char *, char *, int, int);
#ifdef HAVE_LIBPAM
  static void  addpamauth(char *, int);
#endif
  static void  addhtpasswdentry(char *, char *, int);
  static uid_t get_uid(char *, uid_t);
  static gid_t get_gid(char *, gid_t);
  static void  addchecksum(Checksum_T);
  static void  addperm(Perm_T);
  static void  addmatch(Match_T, int, int);
  static void  addmatchpath(Match_T, int);
  static void  addstatus(Status_T);
  static void  adduid(Uid_T);
  static void  addgid(Gid_T);
  static void  addeuid(uid_t);
  static void  addegid(gid_t);
  static void  addeventaction(EventAction_T *, int, int);
  static void  seteventaction(EventAction_T *, int, int);
  static void  prepare_urlrequest(URL_T U);
  static void  seturlrequest(int, char *);
  static void  setlogfile(char *);
  static void  setpidfile(char *);
  static void  reset_mailset();
  static void  reset_mailserverset();
  static void  reset_portset();
  static void  reset_resourceset();
  static void  reset_timestampset();
  static void  reset_actionrateset();
  static void  reset_sizeset();
  static void  reset_uptimeset();
  static void  reset_checksumset();
  static void  reset_permset();
  static void  reset_uidset();
  static void  reset_statusset();
  static void  reset_gidset();
  static void  reset_filesystemset();
  static void  reset_icmpset();
  static void  reset_rateset();
  static void  check_name(char *);
  static int   check_perm(int);
  static void  check_hostname (char *);
  static void  check_exec(char *);
  static int   cleanup_hash_string(char *);
  static void  check_depend();
  static void  setsyslog(char *);
  static command_t copycommand(command_t);
  static int verifyMaxForward(int);  



/* Line 189 of yacc.c  */
#line 307 "src/y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     THEN = 260,
     OR = 261,
     FAILED = 262,
     SET = 263,
     LOGFILE = 264,
     FACILITY = 265,
     DAEMON = 266,
     SYSLOG = 267,
     MAILSERVER = 268,
     HTTPD = 269,
     ALLOW = 270,
     ADDRESS = 271,
     INIT = 272,
     READONLY = 273,
     CLEARTEXT = 274,
     MD5HASH = 275,
     SHA1HASH = 276,
     CRYPT = 277,
     DELAY = 278,
     PEMFILE = 279,
     ENABLE = 280,
     DISABLE = 281,
     HTTPDSSL = 282,
     CLIENTPEMFILE = 283,
     ALLOWSELFCERTIFICATION = 284,
     IDFILE = 285,
     STATEFILE = 286,
     SEND = 287,
     EXPECT = 288,
     EXPECTBUFFER = 289,
     CYCLE = 290,
     COUNT = 291,
     REMINDER = 292,
     PIDFILE = 293,
     START = 294,
     STOP = 295,
     PATHTOK = 296,
     HOST = 297,
     HOSTNAME = 298,
     PORT = 299,
     TYPE = 300,
     UDP = 301,
     TCP = 302,
     TCPSSL = 303,
     PROTOCOL = 304,
     CONNECTION = 305,
     ALERT = 306,
     NOALERT = 307,
     MAILFORMAT = 308,
     UNIXSOCKET = 309,
     SIGNATURE = 310,
     TIMEOUT = 311,
     RETRY = 312,
     RESTART = 313,
     CHECKSUM = 314,
     EVERY = 315,
     NOTEVERY = 316,
     DEFAULT = 317,
     HTTP = 318,
     APACHESTATUS = 319,
     FTP = 320,
     SMTP = 321,
     POP = 322,
     IMAP = 323,
     CLAMAV = 324,
     NNTP = 325,
     NTP3 = 326,
     MYSQL = 327,
     DNS = 328,
     SSH = 329,
     DWP = 330,
     LDAP2 = 331,
     LDAP3 = 332,
     RDATE = 333,
     RSYNC = 334,
     TNS = 335,
     PGSQL = 336,
     POSTFIXPOLICY = 337,
     SIP = 338,
     LMTP = 339,
     GPS = 340,
     RADIUS = 341,
     MEMCACHE = 342,
     STRING = 343,
     PATH = 344,
     MAILADDR = 345,
     MAILFROM = 346,
     MAILREPLYTO = 347,
     MAILSUBJECT = 348,
     MAILBODY = 349,
     SERVICENAME = 350,
     STRINGNAME = 351,
     NUMBER = 352,
     PERCENT = 353,
     LOGLIMIT = 354,
     CLOSELIMIT = 355,
     DNSLIMIT = 356,
     KEEPALIVELIMIT = 357,
     REPLYLIMIT = 358,
     REQUESTLIMIT = 359,
     STARTLIMIT = 360,
     WAITLIMIT = 361,
     GRACEFULLIMIT = 362,
     CLEANUPLIMIT = 363,
     REAL = 364,
     CHECKPROC = 365,
     CHECKFILESYS = 366,
     CHECKFILE = 367,
     CHECKDIR = 368,
     CHECKHOST = 369,
     CHECKSYSTEM = 370,
     CHECKFIFO = 371,
     CHECKPROGRAM = 372,
     CHILDREN = 373,
     SYSTEM = 374,
     STATUS = 375,
     RESOURCE = 376,
     MEMORY = 377,
     TOTALMEMORY = 378,
     LOADAVG1 = 379,
     LOADAVG5 = 380,
     LOADAVG15 = 381,
     SWAP = 382,
     MODE = 383,
     ACTIVE = 384,
     PASSIVE = 385,
     MANUAL = 386,
     CPU = 387,
     TOTALCPU = 388,
     CPUUSER = 389,
     CPUSYSTEM = 390,
     CPUWAIT = 391,
     GROUP = 392,
     REQUEST = 393,
     DEPENDS = 394,
     BASEDIR = 395,
     SLOT = 396,
     EVENTQUEUE = 397,
     SECRET = 398,
     HOSTHEADER = 399,
     UID = 400,
     GID = 401,
     MMONIT = 402,
     INSTANCE = 403,
     USERNAME = 404,
     PASSWORD = 405,
     TIMESTAMP = 406,
     CHANGED = 407,
     SECOND = 408,
     MINUTE = 409,
     HOUR = 410,
     DAY = 411,
     SSLAUTO = 412,
     SSLV2 = 413,
     SSLV3 = 414,
     TLSV1 = 415,
     CERTMD5 = 416,
     BYTE = 417,
     KILOBYTE = 418,
     MEGABYTE = 419,
     GIGABYTE = 420,
     INODE = 421,
     SPACE = 422,
     PERMISSION = 423,
     SIZE = 424,
     MATCH = 425,
     NOT = 426,
     IGNORE = 427,
     ACTION = 428,
     UPTIME = 429,
     EXEC = 430,
     UNMONITOR = 431,
     ICMP = 432,
     ICMPECHO = 433,
     NONEXIST = 434,
     EXIST = 435,
     INVALID = 436,
     DATA = 437,
     RECOVERED = 438,
     PASSED = 439,
     SUCCEEDED = 440,
     URL = 441,
     CONTENT = 442,
     PID = 443,
     PPID = 444,
     FSFLAG = 445,
     REGISTER = 446,
     CREDENTIALS = 447,
     URLOBJECT = 448,
     TARGET = 449,
     TIMESPEC = 450,
     MAXFORWARD = 451,
     FIPS = 452,
     NOTEQUAL = 453,
     EQUAL = 454,
     LESS = 455,
     GREATER = 456
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define THEN 260
#define OR 261
#define FAILED 262
#define SET 263
#define LOGFILE 264
#define FACILITY 265
#define DAEMON 266
#define SYSLOG 267
#define MAILSERVER 268
#define HTTPD 269
#define ALLOW 270
#define ADDRESS 271
#define INIT 272
#define READONLY 273
#define CLEARTEXT 274
#define MD5HASH 275
#define SHA1HASH 276
#define CRYPT 277
#define DELAY 278
#define PEMFILE 279
#define ENABLE 280
#define DISABLE 281
#define HTTPDSSL 282
#define CLIENTPEMFILE 283
#define ALLOWSELFCERTIFICATION 284
#define IDFILE 285
#define STATEFILE 286
#define SEND 287
#define EXPECT 288
#define EXPECTBUFFER 289
#define CYCLE 290
#define COUNT 291
#define REMINDER 292
#define PIDFILE 293
#define START 294
#define STOP 295
#define PATHTOK 296
#define HOST 297
#define HOSTNAME 298
#define PORT 299
#define TYPE 300
#define UDP 301
#define TCP 302
#define TCPSSL 303
#define PROTOCOL 304
#define CONNECTION 305
#define ALERT 306
#define NOALERT 307
#define MAILFORMAT 308
#define UNIXSOCKET 309
#define SIGNATURE 310
#define TIMEOUT 311
#define RETRY 312
#define RESTART 313
#define CHECKSUM 314
#define EVERY 315
#define NOTEVERY 316
#define DEFAULT 317
#define HTTP 318
#define APACHESTATUS 319
#define FTP 320
#define SMTP 321
#define POP 322
#define IMAP 323
#define CLAMAV 324
#define NNTP 325
#define NTP3 326
#define MYSQL 327
#define DNS 328
#define SSH 329
#define DWP 330
#define LDAP2 331
#define LDAP3 332
#define RDATE 333
#define RSYNC 334
#define TNS 335
#define PGSQL 336
#define POSTFIXPOLICY 337
#define SIP 338
#define LMTP 339
#define GPS 340
#define RADIUS 341
#define MEMCACHE 342
#define STRING 343
#define PATH 344
#define MAILADDR 345
#define MAILFROM 346
#define MAILREPLYTO 347
#define MAILSUBJECT 348
#define MAILBODY 349
#define SERVICENAME 350
#define STRINGNAME 351
#define NUMBER 352
#define PERCENT 353
#define LOGLIMIT 354
#define CLOSELIMIT 355
#define DNSLIMIT 356
#define KEEPALIVELIMIT 357
#define REPLYLIMIT 358
#define REQUESTLIMIT 359
#define STARTLIMIT 360
#define WAITLIMIT 361
#define GRACEFULLIMIT 362
#define CLEANUPLIMIT 363
#define REAL 364
#define CHECKPROC 365
#define CHECKFILESYS 366
#define CHECKFILE 367
#define CHECKDIR 368
#define CHECKHOST 369
#define CHECKSYSTEM 370
#define CHECKFIFO 371
#define CHECKPROGRAM 372
#define CHILDREN 373
#define SYSTEM 374
#define STATUS 375
#define RESOURCE 376
#define MEMORY 377
#define TOTALMEMORY 378
#define LOADAVG1 379
#define LOADAVG5 380
#define LOADAVG15 381
#define SWAP 382
#define MODE 383
#define ACTIVE 384
#define PASSIVE 385
#define MANUAL 386
#define CPU 387
#define TOTALCPU 388
#define CPUUSER 389
#define CPUSYSTEM 390
#define CPUWAIT 391
#define GROUP 392
#define REQUEST 393
#define DEPENDS 394
#define BASEDIR 395
#define SLOT 396
#define EVENTQUEUE 397
#define SECRET 398
#define HOSTHEADER 399
#define UID 400
#define GID 401
#define MMONIT 402
#define INSTANCE 403
#define USERNAME 404
#define PASSWORD 405
#define TIMESTAMP 406
#define CHANGED 407
#define SECOND 408
#define MINUTE 409
#define HOUR 410
#define DAY 411
#define SSLAUTO 412
#define SSLV2 413
#define SSLV3 414
#define TLSV1 415
#define CERTMD5 416
#define BYTE 417
#define KILOBYTE 418
#define MEGABYTE 419
#define GIGABYTE 420
#define INODE 421
#define SPACE 422
#define PERMISSION 423
#define SIZE 424
#define MATCH 425
#define NOT 426
#define IGNORE 427
#define ACTION 428
#define UPTIME 429
#define EXEC 430
#define UNMONITOR 431
#define ICMP 432
#define ICMPECHO 433
#define NONEXIST 434
#define EXIST 435
#define INVALID 436
#define DATA 437
#define RECOVERED 438
#define PASSED 439
#define SUCCEEDED 440
#define URL 441
#define CONTENT 442
#define PID 443
#define PPID 444
#define FSFLAG 445
#define REGISTER 446
#define CREDENTIALS 447
#define URLOBJECT 448
#define TARGET 449
#define TIMESPEC 450
#define MAXFORWARD 451
#define FIPS 452
#define NOTEQUAL 453
#define EQUAL 454
#define LESS 455
#define GREATER 456




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 259 "src/p.y"

  URL_T url;
  float real;
  int   number;
  char *string;



/* Line 214 of yacc.c  */
#line 754 "src/y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 766 "src/y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1001

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  206
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  164
/* YYNRULES -- Number of rules.  */
#define YYNRULES  509
/* YYNRULES -- Number of states.  */
#define YYNSTATES  893

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   456

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   204,     2,
       2,     2,     2,     2,   205,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   202,     2,   203,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    42,    45,    48,    51,    54,    57,    60,    63,    64,
      67,    69,    71,    73,    75,    77,    79,    81,    83,    85,
      87,    89,    91,    93,    95,    97,    99,   100,   103,   105,
     107,   109,   111,   113,   115,   117,   119,   121,   123,   125,
     127,   129,   131,   133,   135,   137,   138,   141,   143,   145,
     147,   149,   151,   153,   155,   157,   159,   161,   163,   165,
     167,   169,   171,   173,   174,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   205,
     207,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   235,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   257,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     288,   289,   292,   294,   296,   298,   300,   302,   304,   306,
     308,   310,   312,   317,   325,   334,   339,   340,   344,   349,
     352,   355,   359,   363,   369,   374,   381,   386,   390,   394,
     398,   402,   405,   409,   414,   415,   418,   424,   430,   436,
     438,   441,   447,   455,   456,   459,   461,   463,   465,   467,
     469,   472,   473,   476,   478,   480,   482,   484,   487,   490,
     493,   496,   500,   504,   507,   509,   511,   514,   517,   520,
     523,   526,   529,   532,   534,   540,   545,   548,   552,   556,
     560,   561,   566,   567,   573,   574,   580,   581,   587,   590,
     592,   595,   597,   598,   600,   605,   610,   615,   620,   625,
     630,   635,   640,   643,   648,   654,   658,   663,   667,   672,
     676,   681,   683,   686,   688,   691,   693,   695,   698,   701,
     704,   707,   708,   711,   714,   715,   718,   719,   722,   735,
     747,   759,   770,   771,   774,   777,   780,   781,   784,   789,
     792,   793,   796,   797,   799,   801,   803,   805,   806,   810,
     813,   816,   819,   822,   826,   829,   832,   835,   838,   841,
     846,   849,   852,   855,   858,   861,   864,   867,   870,   873,
     876,   879,   882,   886,   889,   891,   893,   896,   899,   902,
     903,   906,   909,   910,   913,   914,   918,   924,   925,   928,
     931,   933,   937,   942,   947,   952,   957,   962,   967,   972,
     977,   982,   987,   995,  1002,  1009,  1019,  1020,  1023,  1024,
    1028,  1029,  1033,  1034,  1038,  1039,  1042,  1050,  1058,  1059,
    1063,  1065,  1067,  1071,  1078,  1086,  1088,  1091,  1094,  1096,
    1099,  1101,  1103,  1105,  1107,  1109,  1111,  1113,  1115,  1117,
    1119,  1121,  1123,  1125,  1127,  1129,  1131,  1133,  1135,  1137,
    1139,  1141,  1143,  1144,  1149,  1151,  1154,  1156,  1158,  1160,
    1162,  1166,  1169,  1172,  1175,  1178,  1181,  1184,  1187,  1189,
    1192,  1194,  1203,  1210,  1212,  1215,  1217,  1219,  1221,  1223,
    1230,  1232,  1235,  1237,  1239,  1241,  1243,  1248,  1253,  1258,
    1260,  1262,  1264,  1269,  1274,  1279,  1284,  1289,  1294,  1298,
    1302,  1304,  1306,  1308,  1310,  1312,  1322,  1329,  1330,  1332,
    1334,  1336,  1338,  1340,  1341,  1343,  1345,  1347,  1349,  1351,
    1354,  1358,  1360,  1362,  1364,  1366,  1368,  1370,  1371,  1374,
    1378,  1379,  1382,  1386,  1387,  1394,  1401,  1408,  1417,  1428,
    1436,  1437,  1439,  1441,  1450,  1460,  1470,  1480,  1487,  1488,
    1490,  1492,  1494,  1496,  1505,  1513,  1521,  1526,  1531,  1532,
    1534,  1544,  1551,  1560,  1569,  1578,  1587,  1590,  1591,  1594
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     207,     0,    -1,    -1,   208,    -1,   209,    -1,   208,   209,
      -1,   226,    -1,   227,    -1,   232,    -1,   233,    -1,   237,
      -1,   241,    -1,   242,    -1,   243,    -1,   236,    -1,   234,
      -1,   235,    -1,   229,    -1,   230,    -1,   231,    -1,   268,
     210,    -1,   269,   212,    -1,   270,   214,    -1,   271,   216,
      -1,   272,   218,    -1,   273,   220,    -1,   274,   222,    -1,
     275,   224,    -1,    -1,   210,   211,    -1,   276,    -1,   277,
      -1,   278,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,   286,    -1,   287,    -1,   314,    -1,   317,    -1,   325,
      -1,   326,    -1,   327,    -1,   328,    -1,   332,    -1,    -1,
     212,   213,    -1,   276,    -1,   277,    -1,   278,    -1,   305,
      -1,   347,    -1,   314,    -1,   325,    -1,   317,    -1,   362,
      -1,   366,    -1,   367,    -1,   356,    -1,   365,    -1,   363,
      -1,   326,    -1,   327,    -1,   328,    -1,    -1,   214,   215,
      -1,   276,    -1,   277,    -1,   278,    -1,   305,    -1,   314,
      -1,   325,    -1,   317,    -1,   362,    -1,   366,    -1,   367,
      -1,   326,    -1,   327,    -1,   328,    -1,   358,    -1,   359,
      -1,   360,    -1,    -1,   216,   217,    -1,   276,    -1,   277,
      -1,   278,    -1,   305,    -1,   347,    -1,   314,    -1,   325,
      -1,   317,    -1,   362,    -1,   366,    -1,   367,    -1,   326,
      -1,   327,    -1,   328,    -1,   219,    -1,   218,   219,    -1,
     276,    -1,   277,    -1,   278,    -1,   305,    -1,   286,    -1,
     288,    -1,   314,    -1,   317,    -1,   325,    -1,   326,    -1,
     327,    -1,   328,    -1,    -1,   220,   221,    -1,   276,    -1,
     277,    -1,   278,    -1,   314,    -1,   317,    -1,   325,    -1,
     327,    -1,   328,    -1,   335,    -1,    -1,   222,   223,    -1,
     276,    -1,   277,    -1,   278,    -1,   305,    -1,   347,    -1,
     314,    -1,   325,    -1,   317,    -1,   362,    -1,   366,    -1,
     367,    -1,   326,    -1,   327,    -1,   328,    -1,    -1,   224,
     225,    -1,   276,    -1,   277,    -1,   278,    -1,   314,    -1,
     305,    -1,   317,    -1,   325,    -1,   327,    -1,   328,    -1,
     331,    -1,     8,   318,   322,   369,    -1,     8,   318,   202,
     320,   203,   322,   369,    -1,     8,   318,   171,   202,   320,
     203,   322,   369,    -1,     8,    11,    97,   228,    -1,    -1,
      39,    23,    97,    -1,     8,    34,    97,   361,    -1,     8,
      17,    -1,     8,   197,    -1,     8,     9,    89,    -1,     8,
       9,    12,    -1,     8,     9,    12,    10,    88,    -1,     8,
     142,   140,    89,    -1,     8,   142,   140,    89,   141,    97,
      -1,     8,   142,   141,    97,    -1,     8,    30,    89,    -1,
       8,    31,    89,    -1,     8,    38,    89,    -1,     8,   147,
     238,    -1,   239,   240,    -1,   238,   239,   240,    -1,   193,
     312,   294,   293,    -1,    -1,   191,   192,    -1,     8,    13,
     244,   312,   285,    -1,     8,    53,   202,   323,   203,    -1,
       8,    14,    44,    97,   246,    -1,   245,    -1,   244,   245,
      -1,    88,   283,   284,   294,   293,    -1,    88,    44,    97,
     283,   284,   294,   293,    -1,    -1,   246,   247,    -1,   248,
      -1,   253,    -1,   256,    -1,   260,    -1,   252,    -1,   251,
     249,    -1,    -1,   249,   250,    -1,   257,    -1,   258,    -1,
     259,    -1,    27,    -1,    27,    25,    -1,    25,    27,    -1,
      27,    26,    -1,    26,    27,    -1,   252,    24,    89,    -1,
     252,    28,    89,    -1,   252,    29,    -1,   254,    -1,   255,
      -1,    55,    25,    -1,    25,    55,    -1,    55,    26,    -1,
      26,    55,    -1,    16,    88,    -1,    24,    89,    -1,    28,
      89,    -1,    29,    -1,    15,    88,   204,    88,   267,    -1,
      15,   205,    88,   267,    -1,    15,    89,    -1,    15,    19,
      89,    -1,    15,    20,    89,    -1,    15,    22,    89,    -1,
      -1,    15,    89,   261,   265,    -1,    -1,    15,    19,    89,
     262,   265,    -1,    -1,    15,    20,    89,   263,   265,    -1,
      -1,    15,    22,    89,   264,   265,    -1,    15,    88,    -1,
     266,    -1,   265,   266,    -1,    88,    -1,    -1,    18,    -1,
     110,    95,    38,    89,    -1,   110,    95,    41,    89,    -1,
     110,    95,   170,    88,    -1,   110,    95,   170,    89,    -1,
     112,    95,    41,    89,    -1,   111,    95,    41,    89,    -1,
     113,    95,    41,    89,    -1,   114,    95,    16,    88,    -1,
     115,    95,    -1,   116,    95,    41,    89,    -1,   117,    95,
      41,    89,   311,    -1,    39,   279,   310,    -1,    39,   279,
     280,   310,    -1,    40,   279,   310,    -1,    40,   279,   280,
     310,    -1,    58,   279,   310,    -1,    58,   279,   280,   310,
      -1,   281,    -1,   279,   281,    -1,   282,    -1,   280,   282,
      -1,    88,    -1,    89,    -1,   145,    88,    -1,   146,    88,
      -1,   145,    97,    -1,   146,    97,    -1,    -1,   149,    90,
      -1,   149,    88,    -1,    -1,   150,    88,    -1,    -1,    43,
      88,    -1,     3,     7,   289,   290,   292,   295,   312,   313,
     353,     5,   351,   355,    -1,     3,     7,   186,   193,   315,
     312,   313,   353,     5,   351,   355,    -1,     3,     7,   291,
     292,   295,   312,   313,   353,     5,   351,   355,    -1,     3,
       7,   177,   368,   309,   312,   353,     5,   351,   355,    -1,
      -1,    42,    88,    -1,    44,    97,    -1,    54,    89,    -1,
      -1,    45,    47,    -1,    45,    48,   294,   293,    -1,    45,
      46,    -1,    -1,   161,    88,    -1,    -1,   158,    -1,   159,
      -1,   160,    -1,   157,    -1,    -1,    49,    64,   303,    -1,
      49,    62,    -1,    49,    73,    -1,    49,    75,    -1,    49,
      65,    -1,    49,    63,   300,    -1,    49,    68,    -1,    49,
      69,    -1,    49,    76,    -1,    49,    77,    -1,    49,    72,
      -1,    49,    83,   298,   299,    -1,    49,    70,    -1,    49,
      71,    -1,    49,    82,    -1,    49,    67,    -1,    49,    66,
      -1,    49,    74,    -1,    49,    78,    -1,    49,    79,    -1,
      49,    80,    -1,    49,    81,    -1,    49,    84,    -1,    49,
      85,    -1,    49,    86,   302,    -1,    49,    87,    -1,   296,
      -1,   297,    -1,   296,   297,    -1,    32,    88,    -1,    33,
      88,    -1,    -1,   194,    90,    -1,   194,    88,    -1,    -1,
     196,    97,    -1,    -1,   138,    89,   301,    -1,   138,    89,
      59,    88,   301,    -1,    -1,   144,    88,    -1,   143,    88,
      -1,   304,    -1,   303,     6,   304,    -1,    99,   348,    97,
      98,    -1,   100,   348,    97,    98,    -1,   101,   348,    97,
      98,    -1,   102,   348,    97,    98,    -1,   103,   348,    97,
      98,    -1,   104,   348,    97,    98,    -1,   105,   348,    97,
      98,    -1,   106,   348,    97,    98,    -1,   107,   348,    97,
      98,    -1,   108,   348,    97,    98,    -1,     3,   171,   180,
     353,     5,   351,   355,    -1,     3,   152,   188,   353,     5,
     351,    -1,     3,   152,   189,   353,     5,   351,    -1,     3,
     174,   348,    97,   349,   353,     5,   351,   355,    -1,    -1,
      36,    97,    -1,    -1,    56,    97,   153,    -1,    -1,    56,
      97,   153,    -1,    -1,    56,    97,   153,    -1,    -1,    57,
      97,    -1,     3,    97,    58,    97,    35,     5,   351,    -1,
       3,    97,    58,    97,    35,     5,    56,    -1,    -1,   187,
     316,    88,    -1,   199,    -1,   198,    -1,   318,   322,   369,
      -1,   318,   202,   320,   203,   322,   369,    -1,   318,   171,
     202,   320,   203,   322,   369,    -1,   319,    -1,    51,    90,
      -1,    52,    90,    -1,   321,    -1,   320,   321,    -1,   173,
      -1,    59,    -1,    50,    -1,   187,    -1,   182,    -1,   175,
      -1,   190,    -1,   146,    -1,   177,    -1,   148,    -1,   181,
      -1,   179,    -1,   168,    -1,   188,    -1,   189,    -1,   121,
      -1,   169,    -1,   120,    -1,    56,    -1,   151,    -1,   145,
      -1,   174,    -1,    -1,    53,   202,   323,   203,    -1,   324,
      -1,   323,   324,    -1,    91,    -1,    92,    -1,    93,    -1,
      94,    -1,    60,    97,    35,    -1,    60,   195,    -1,    61,
     195,    -1,   128,   129,    -1,   128,   130,    -1,   128,   131,
      -1,   137,    96,    -1,   139,   329,    -1,   330,    -1,   329,
     330,    -1,    95,    -1,     3,   120,   348,    97,   353,     5,
     351,   355,    -1,     3,   333,   353,     5,   351,   355,    -1,
     334,    -1,   333,   334,    -1,   338,    -1,   341,    -1,   343,
      -1,   344,    -1,     3,   336,   353,     5,   351,   355,    -1,
     337,    -1,   336,   337,    -1,   344,    -1,   341,    -1,   342,
      -1,   339,    -1,   132,   348,    97,    98,    -1,   133,   348,
      97,    98,    -1,   340,   348,    97,    98,    -1,   134,    -1,
     135,    -1,   136,    -1,   122,   348,   346,   361,    -1,   122,
     348,    97,    98,    -1,   123,   348,   346,   361,    -1,   123,
     348,    97,    98,    -1,   127,   348,   346,   361,    -1,   127,
     348,    97,    98,    -1,   118,   348,    97,    -1,   345,   348,
     346,    -1,   124,    -1,   125,    -1,   126,    -1,   109,    -1,
      97,    -1,     3,   151,   348,    97,   349,   353,     5,   351,
     355,    -1,     3,   152,   151,   353,     5,   351,    -1,    -1,
     201,    -1,   200,    -1,   199,    -1,   198,    -1,   152,    -1,
      -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,    51,
      -1,   175,   279,    -1,   175,   279,   280,    -1,    58,    -1,
      39,    -1,    40,    -1,   176,    -1,   350,    -1,   350,    -1,
      -1,    97,    35,    -1,    97,    97,    35,    -1,    -1,    97,
      35,    -1,    97,    97,    35,    -1,    -1,     4,     3,   183,
     354,     5,   352,    -1,     4,     3,   184,   354,     5,   352,
      -1,     4,     3,   185,   354,     5,   352,    -1,     3,     7,
     357,    59,   353,     5,   351,   355,    -1,     3,     7,   357,
      59,    33,    88,   353,     5,   351,   355,    -1,     3,   152,
     357,    59,   353,     5,   351,    -1,    -1,    20,    -1,    21,
      -1,     3,   166,   348,    97,   353,     5,   351,   355,    -1,
       3,   166,   348,    97,    98,   353,     5,   351,   355,    -1,
       3,   167,   348,   346,   361,   353,     5,   351,   355,    -1,
       3,   167,   348,    97,    98,   353,     5,   351,   355,    -1,
       3,   152,   190,   353,     5,   351,    -1,    -1,   162,    -1,
     163,    -1,   164,    -1,   165,    -1,     3,     7,   168,    97,
     353,     5,   351,   355,    -1,     3,   364,   170,    89,   353,
       5,   351,    -1,     3,   364,   170,    88,   353,     5,   351,
      -1,   172,   364,   170,    89,    -1,   172,   364,   170,    88,
      -1,    -1,   171,    -1,     3,   169,   348,    97,   361,   353,
       5,   351,   355,    -1,     3,   152,   169,   353,     5,   351,
      -1,     3,     7,   145,    88,   353,     5,   351,   355,    -1,
       3,     7,   145,    97,   353,     5,   351,   355,    -1,     3,
       7,   146,    88,   353,     5,   351,   355,    -1,     3,     7,
     146,    97,   353,     5,   351,   355,    -1,    45,   178,    -1,
      -1,    37,    97,    -1,    37,    97,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   305,   305,   306,   309,   310,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   337,   338,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   359,   360,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   382,   383,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   404,   405,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   424,
     425,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   442,   443,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   457,   458,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     477,   478,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   493,   497,   500,   506,   516,   517,   520,   525,
     530,   537,   545,   548,   553,   556,   560,   566,   571,   576,
     584,   587,   588,   591,   597,   598,   603,   610,   619,   625,
     626,   629,   648,   667,   668,   671,   672,   673,   674,   677,
     678,   689,   690,   693,   694,   695,   698,   699,   700,   703,
     704,   705,   706,   707,   710,   711,   714,   715,   718,   719,
     722,   725,   730,   738,   743,   746,   754,   758,   762,   766,
     770,   770,   777,   777,   784,   784,   791,   791,   798,   806,
     807,   810,   814,   815,   818,   821,   824,   831,   840,   845,
     850,   855,   861,   866,   871,   878,   881,   886,   889,   895,
     898,   903,   904,   907,   908,   911,   912,   915,   916,   917,
     918,   921,   922,   923,   926,   927,   930,   931,   934,   941,
     951,   960,   970,   976,   979,   982,   987,   990,   993,  1001,
    1006,  1007,  1010,  1011,  1012,  1013,  1014,  1017,  1020,  1023,
    1026,  1029,  1032,  1035,  1038,  1041,  1044,  1047,  1050,  1053,
    1056,  1059,  1063,  1066,  1069,  1072,  1075,  1078,  1081,  1084,
    1087,  1090,  1093,  1096,  1099,  1104,  1105,  1108,  1109,  1112,
    1113,  1116,  1121,  1122,  1127,  1128,  1132,  1139,  1140,  1145,
    1150,  1151,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1182,
    1186,  1190,  1196,  1202,  1207,  1212,  1219,  1222,  1227,  1230,
    1235,  1238,  1243,  1246,  1251,  1254,  1259,  1265,  1273,  1274,
    1280,  1281,  1284,  1288,  1291,  1295,  1300,  1303,  1306,  1307,
    1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1334,  1335,  1338,  1339,  1342,  1343,  1344,  1345,
    1348,  1352,  1356,  1362,  1365,  1368,  1374,  1378,  1381,  1382,
    1385,  1388,  1396,  1402,  1403,  1406,  1407,  1408,  1409,  1412,
    1418,  1419,  1422,  1423,  1424,  1425,  1428,  1433,  1440,  1447,
    1448,  1449,  1452,  1457,  1462,  1467,  1474,  1479,  1486,  1493,
    1500,  1501,  1502,  1505,  1506,  1509,  1515,  1522,  1523,  1524,
    1525,  1526,  1527,  1530,  1531,  1532,  1533,  1534,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1546,  1555,  1564,  1565,  1571,
    1581,  1582,  1588,  1598,  1601,  1604,  1607,  1612,  1616,  1623,
    1629,  1630,  1631,  1634,  1641,  1650,  1659,  1668,  1673,  1674,
    1675,  1676,  1677,  1680,  1687,  1694,  1700,  1707,  1715,  1718,
    1724,  1730,  1737,  1743,  1750,  1756,  1763,  1766,  1767,  1768
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "THEN", "OR", "FAILED",
  "SET", "LOGFILE", "FACILITY", "DAEMON", "SYSLOG", "MAILSERVER", "HTTPD",
  "ALLOW", "ADDRESS", "INIT", "READONLY", "CLEARTEXT", "MD5HASH",
  "SHA1HASH", "CRYPT", "DELAY", "PEMFILE", "ENABLE", "DISABLE", "HTTPDSSL",
  "CLIENTPEMFILE", "ALLOWSELFCERTIFICATION", "IDFILE", "STATEFILE", "SEND",
  "EXPECT", "EXPECTBUFFER", "CYCLE", "COUNT", "REMINDER", "PIDFILE",
  "START", "STOP", "PATHTOK", "HOST", "HOSTNAME", "PORT", "TYPE", "UDP",
  "TCP", "TCPSSL", "PROTOCOL", "CONNECTION", "ALERT", "NOALERT",
  "MAILFORMAT", "UNIXSOCKET", "SIGNATURE", "TIMEOUT", "RETRY", "RESTART",
  "CHECKSUM", "EVERY", "NOTEVERY", "DEFAULT", "HTTP", "APACHESTATUS",
  "FTP", "SMTP", "POP", "IMAP", "CLAMAV", "NNTP", "NTP3", "MYSQL", "DNS",
  "SSH", "DWP", "LDAP2", "LDAP3", "RDATE", "RSYNC", "TNS", "PGSQL",
  "POSTFIXPOLICY", "SIP", "LMTP", "GPS", "RADIUS", "MEMCACHE", "STRING",
  "PATH", "MAILADDR", "MAILFROM", "MAILREPLYTO", "MAILSUBJECT", "MAILBODY",
  "SERVICENAME", "STRINGNAME", "NUMBER", "PERCENT", "LOGLIMIT",
  "CLOSELIMIT", "DNSLIMIT", "KEEPALIVELIMIT", "REPLYLIMIT", "REQUESTLIMIT",
  "STARTLIMIT", "WAITLIMIT", "GRACEFULLIMIT", "CLEANUPLIMIT", "REAL",
  "CHECKPROC", "CHECKFILESYS", "CHECKFILE", "CHECKDIR", "CHECKHOST",
  "CHECKSYSTEM", "CHECKFIFO", "CHECKPROGRAM", "CHILDREN", "SYSTEM",
  "STATUS", "RESOURCE", "MEMORY", "TOTALMEMORY", "LOADAVG1", "LOADAVG5",
  "LOADAVG15", "SWAP", "MODE", "ACTIVE", "PASSIVE", "MANUAL", "CPU",
  "TOTALCPU", "CPUUSER", "CPUSYSTEM", "CPUWAIT", "GROUP", "REQUEST",
  "DEPENDS", "BASEDIR", "SLOT", "EVENTQUEUE", "SECRET", "HOSTHEADER",
  "UID", "GID", "MMONIT", "INSTANCE", "USERNAME", "PASSWORD", "TIMESTAMP",
  "CHANGED", "SECOND", "MINUTE", "HOUR", "DAY", "SSLAUTO", "SSLV2",
  "SSLV3", "TLSV1", "CERTMD5", "BYTE", "KILOBYTE", "MEGABYTE", "GIGABYTE",
  "INODE", "SPACE", "PERMISSION", "SIZE", "MATCH", "NOT", "IGNORE",
  "ACTION", "UPTIME", "EXEC", "UNMONITOR", "ICMP", "ICMPECHO", "NONEXIST",
  "EXIST", "INVALID", "DATA", "RECOVERED", "PASSED", "SUCCEEDED", "URL",
  "CONTENT", "PID", "PPID", "FSFLAG", "REGISTER", "CREDENTIALS",
  "URLOBJECT", "TARGET", "TIMESPEC", "MAXFORWARD", "FIPS", "NOTEQUAL",
  "EQUAL", "LESS", "GREATER", "'{'", "'}'", "':'", "'@'", "$accept",
  "cfgfile", "statement_list", "statement", "optproclist", "optproc",
  "optfilelist", "optfile", "optfilesyslist", "optfilesys", "optdirlist",
  "optdir", "opthostlist", "opthost", "optsystemlist", "optsystem",
  "optfifolist", "optfifo", "optstatuslist", "optstatus", "setalert",
  "setdaemon", "startdelay", "setexpectbuffer", "setinit", "setfips",
  "setlog", "seteventqueue", "setidfile", "setstatefile", "setpid",
  "setmmonits", "mmonitlist", "mmonit", "credentials", "setmailservers",
  "setmailformat", "sethttpd", "mailserverlist", "mailserver", "httpdlist",
  "httpdoption", "ssl", "optssllist", "optssl", "sslenable", "ssldisable",
  "signature", "sigenable", "sigdisable", "bindaddress", "pemfile",
  "clientpemfile", "allowselfcert", "allow", "$@1", "$@2", "$@3", "$@4",
  "allowuserlist", "allowuser", "readonly", "checkproc", "checkfile",
  "checkfilesys", "checkdir", "checkhost", "checksystem", "checkfifo",
  "checkprogram", "start", "stop", "restart", "argumentlist",
  "useroptionlist", "argument", "useroption", "username", "password",
  "hostname", "connection", "connectionunix", "icmp", "host", "port",
  "unixsocket", "type", "certmd5", "sslversion", "protocol",
  "sendexpectlist", "sendexpect", "target", "maxforward", "request",
  "hostheader", "secret", "apache_stat_list", "apache_stat", "exist",
  "pid", "ppid", "uptime", "icmpcount", "exectimeout", "programtimeout",
  "nettimeout", "retry", "actionrate", "urloption", "urloperator", "alert",
  "alertmail", "noalertmail", "eventoptionlist", "eventoption",
  "formatlist", "formatoptionlist", "formatoption", "every", "mode",
  "group", "depend", "dependlist", "dependant", "statusvalue",
  "resourceprocess", "resourceprocesslist", "resourceprocessopt",
  "resourcesystem", "resourcesystemlist", "resourcesystemopt",
  "resourcecpuproc", "resourcecpu", "resourcecpuid", "resourcemem",
  "resourceswap", "resourcechild", "resourceload", "resourceloadavg",
  "value", "timestamp", "operator", "time", "action", "action1", "action2",
  "rate1", "rate2", "recovery", "checksum", "hashtype", "inode", "space",
  "fsflag", "unit", "permission", "match", "matchflagnot", "size", "uid",
  "gid", "icmptype", "reminder", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   123,   125,    58,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   206,   207,   207,   208,   208,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   210,   210,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   212,   212,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   218,
     218,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   220,   220,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   222,   222,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   226,   226,   226,   227,   228,   228,   229,   230,
     231,   232,   232,   232,   233,   233,   233,   234,   235,   236,
     237,   238,   238,   239,   240,   240,   241,   242,   243,   244,
     244,   245,   245,   246,   246,   247,   247,   247,   247,   248,
     248,   249,   249,   250,   250,   250,   251,   251,   251,   252,
     252,   252,   252,   252,   253,   253,   254,   254,   255,   255,
     256,   257,   258,   259,   260,   260,   260,   260,   260,   260,
     261,   260,   262,   260,   263,   260,   264,   260,   260,   265,
     265,   266,   267,   267,   268,   268,   268,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   276,   277,   277,   278,
     278,   279,   279,   280,   280,   281,   281,   282,   282,   282,
     282,   283,   283,   283,   284,   284,   285,   285,   286,   286,
     287,   288,   289,   289,   290,   291,   292,   292,   292,   292,
     293,   293,   294,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   296,   297,   297,   298,
     298,   298,   299,   299,   300,   300,   300,   301,   301,   302,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   306,   307,   308,   309,   309,   310,   310,
     311,   311,   312,   312,   313,   313,   314,   314,   315,   315,
     316,   316,   317,   317,   317,   317,   318,   319,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   322,   322,   323,   323,   324,   324,   324,   324,
     325,   325,   325,   326,   326,   326,   327,   328,   329,   329,
     330,   331,   332,   333,   333,   334,   334,   334,   334,   335,
     336,   336,   337,   337,   337,   337,   338,   338,   339,   340,
     340,   340,   341,   341,   341,   341,   342,   342,   343,   344,
     345,   345,   345,   346,   346,   347,   347,   348,   348,   348,
     348,   348,   348,   349,   349,   349,   349,   349,   350,   350,
     350,   350,   350,   350,   350,   351,   352,   353,   353,   353,
     354,   354,   354,   355,   355,   355,   355,   356,   356,   356,
     357,   357,   357,   358,   358,   359,   359,   360,   361,   361,
     361,   361,   361,   362,   363,   363,   363,   363,   364,   364,
     365,   365,   366,   366,   367,   367,   368,   369,   369,   369
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     7,     8,     4,     0,     3,     4,     2,
       2,     3,     3,     5,     4,     6,     4,     3,     3,     3,
       3,     2,     3,     4,     0,     2,     5,     5,     5,     1,
       2,     5,     7,     0,     2,     1,     1,     1,     1,     1,
       2,     0,     2,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     5,     4,     2,     3,     3,     3,
       0,     4,     0,     5,     0,     5,     0,     5,     2,     1,
       2,     1,     0,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     2,     4,     5,     3,     4,     3,     4,     3,
       4,     1,     2,     1,     2,     1,     1,     2,     2,     2,
       2,     0,     2,     2,     0,     2,     0,     2,    12,    11,
      11,    10,     0,     2,     2,     2,     0,     2,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     0,     3,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     2,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     2,     1,     1,     2,     2,     2,     0,
       2,     2,     0,     2,     0,     3,     5,     0,     2,     2,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     7,     6,     6,     9,     0,     2,     0,     3,
       0,     3,     0,     3,     0,     2,     7,     7,     0,     3,
       1,     1,     3,     6,     7,     1,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     2,     1,     1,     1,     1,
       3,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       1,     8,     6,     1,     2,     1,     1,     1,     1,     6,
       1,     2,     1,     1,     1,     1,     4,     4,     4,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     3,     3,
       1,     1,     1,     1,     1,     9,     6,     0,     1,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     0,     2,     3,
       0,     2,     3,     0,     6,     6,     6,     8,    10,     7,
       0,     1,     1,     8,     9,     9,     9,     6,     0,     1,
       1,     1,     1,     8,     7,     7,     4,     4,     0,     1,
       9,     6,     8,     8,     8,     8,     2,     0,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     6,     7,    17,    18,    19,     8,     9,
      15,    16,    14,    10,    11,    12,    13,    28,    46,    65,
      83,     0,   113,   124,   140,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   392,
       0,     0,     0,     0,     0,   242,     0,     0,     1,     5,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    99,   101,   102,   103,   105,
     106,   104,   107,   108,   392,   365,   109,   110,   111,   112,
      25,    26,    27,   162,   161,   156,   261,   352,   179,     0,
     167,   168,   488,   169,   366,     0,     0,     0,   352,   170,
     174,     0,     0,     0,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    37,
      38,    33,    34,    35,    36,    39,    40,    41,    42,    43,
      44,    45,   498,   498,    47,    48,    49,    50,    51,    53,
      55,    54,    62,    63,    64,    52,    59,    56,    61,    60,
      57,    58,     0,    66,    67,    68,    69,    70,    71,    73,
      72,    77,    78,    79,    80,    81,    82,    74,    75,    76,
       0,    84,    85,    86,    87,    88,    90,    92,    91,    96,
      97,    98,    89,    93,    94,    95,   272,     0,     0,   255,
     256,   348,   251,   348,   367,   348,     0,   401,   402,   403,
     404,   405,   406,   410,   407,   408,   100,     0,     0,   507,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   125,   126,   127,   128,   129,   131,   133,   132,   137,
     138,   139,   130,   134,   135,   136,     0,   141,   142,   143,
     144,   146,   145,   147,   148,   149,   150,   151,     0,     0,
     155,     0,     0,   264,     0,   180,   266,   183,   489,   490,
     491,   492,   158,   396,   397,   398,   399,     0,   394,   164,
     166,   282,   174,     0,   171,     0,     0,   372,   388,   371,
     387,   385,   390,   377,   379,   389,   382,   386,   370,   391,
     375,   378,   381,   380,   374,   373,   383,   384,   376,     0,
     368,     0,   152,   234,   235,   236,   237,   239,   238,   240,
     241,   243,   350,   272,   447,   447,   447,   440,   441,   442,
     447,   447,     0,   447,   467,   413,   415,   416,   417,   418,
     447,   480,   447,   480,   447,   499,     0,   499,     0,     0,
       0,   447,   447,     0,     0,     0,     0,     0,     0,   467,
       0,     0,     0,   348,   252,   253,   245,   348,   247,   348,
     249,   400,   409,     0,     0,   362,   447,   429,   430,   431,
     467,   420,   425,   447,   423,   424,   422,   447,   163,     0,
     261,   263,   262,     0,   282,     0,     0,   176,   178,   177,
     395,     0,   286,   283,   284,   285,   280,   172,   175,     0,
       0,   392,   369,   508,     0,   244,     0,   276,   452,   451,
     450,   449,   448,     0,     0,     0,     0,     0,   467,   467,
       0,     0,   414,     0,     0,   481,   482,     0,     0,     0,
       0,     0,   467,   467,     0,     0,     0,     0,   467,     0,
       0,   273,     0,   346,   358,     0,   276,     0,     0,     0,
     257,   259,   258,   260,   254,   246,   248,   250,     0,   392,
       0,   421,     0,     0,     0,   157,   264,   265,   280,   353,
     267,     0,     0,     0,     0,   196,     0,   184,   185,   191,
     189,   186,   204,   205,   187,   188,   165,     0,   173,   393,
     392,   507,   509,     0,   275,     0,   287,   438,   444,   443,
     488,   444,   488,     0,     0,     0,     0,   453,   468,     0,
       0,   444,   439,   467,   467,   467,   467,   467,   467,   453,
       0,     0,   467,   488,   467,   467,   497,   496,     0,   467,
     444,   488,   506,     0,   352,     0,   352,   274,   287,     0,
       0,   349,   392,   507,   444,   488,     0,     0,   467,   282,
     181,     0,     0,     0,   228,   216,     0,   210,   198,   207,
     200,   209,   197,   199,   206,   208,   190,     0,     0,   203,
     281,   507,   153,   351,   279,   277,   282,     0,     0,     0,
     352,   314,   315,   433,   432,   435,   434,   426,   427,     0,
       0,   454,   455,   456,   457,   467,   469,   462,   463,   458,
     461,     0,   464,   465,   473,     0,     0,     0,     0,     0,
       0,     0,   467,     0,     0,     0,   467,     0,     0,     0,
     467,     0,   467,   467,   347,   467,   361,   360,     0,   354,
     352,     0,   473,   507,   363,   437,   436,   473,   428,     0,
     280,   217,   218,   219,     0,     0,   232,     0,     0,   213,
     192,   193,   194,   195,   201,   202,   154,   280,   317,   318,
     289,   324,     0,   292,   304,   303,   294,   295,   300,   301,
     298,   290,   305,   291,   296,   297,   306,   307,   308,   309,
     302,   319,   310,   311,     0,   313,   354,   316,   343,   344,
       0,   459,     0,   412,     0,     0,     0,     0,     0,   467,
       0,     0,   446,   501,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,   359,     0,   467,   354,   357,   356,
     342,   364,   419,     0,   182,     0,     0,     0,   232,   231,
     221,   229,   233,   215,   211,   212,   278,     0,   293,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   288,
     330,     0,   322,     0,   312,   467,     0,   460,     0,   473,
     473,   473,   473,   473,     0,   473,     0,   479,     0,   495,
     494,     0,   473,     0,     0,     0,   355,     0,   467,   473,
     223,   225,   227,   214,   230,   327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,   320,     0,
     299,   329,     0,   473,   470,   470,   470,   502,   503,   504,
     505,   493,     0,   477,   473,   473,   473,   483,   473,   473,
     473,     0,     0,   411,     0,     0,   325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   331,   323,     0,
     345,     0,     0,     0,     0,   473,   445,   500,   484,   486,
     485,   271,   473,     0,   327,   328,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   473,   471,     0,     0,
       0,     0,   478,   269,   473,   326,   270,   472,   466,   474,
     475,   476,   268
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    60,   125,    61,   144,    62,   163,
      63,   181,    74,    75,    90,   221,    91,   231,    92,   247,
      13,    14,   260,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   109,   110,   284,    24,    25,    26,    97,    98,
     398,   487,   488,   576,   660,   489,   490,   491,   492,   493,
     494,   661,   662,   663,   495,   655,   735,   736,   737,   740,
     741,   743,    27,    28,    29,    30,    31,    32,    33,    34,
      76,    77,    78,   201,   363,   202,   365,   263,   394,   397,
      79,   130,    80,   357,   456,   417,   506,   498,   406,   590,
     591,   592,   762,   810,   748,   836,   764,   759,   760,    81,
     132,   133,   134,   544,   366,   415,   266,   726,    82,   546,
     638,    83,    84,    85,   309,   310,   114,   277,   278,    86,
      87,    88,    89,   214,   215,   257,   141,   334,   335,   230,
     380,   381,   336,   382,   383,   337,   385,   338,   339,   340,
     510,   155,   423,   605,   613,   614,   889,   433,   852,   703,
     156,   440,   174,   175,   176,   272,   157,   158,   346,   159,
     160,   161,   453,   312
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -607
static const yytype_int16 yypact[] =
{
     358,    38,   -55,   -49,   -20,    27,    44,   123,   126,   144,
     241,   358,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,   299,  -607,  -607,  -607,    42,   146,   160,   209,  -607,
     170,   184,   178,   188,   192,    93,   204,   115,  -607,   -21,
      76,   277,   280,   323,   356,  -607,   350,   362,  -607,  -607,
     349,    58,   497,   569,     8,   296,   296,   222,   296,   -67,
     180,   377,   291,   313,   299,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,    11,  -607,  -607,  -607,  -607,  -607,
     265,   569,   316,   407,  -607,   380,    -6,    23,  -607,   331,
    -607,  -607,   334,  -607,  -607,   512,   341,   335,   394,   115,
     263,   278,   283,   606,   422,   412,   423,   308,   425,   427,
     433,   450,   451,   481,    41,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,    73,   318,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,     5,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
      80,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,    59,   486,   404,  -607,
    -607,   191,  -607,   191,  -607,   191,   551,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,   313,  -607,  -607,   386,   606,   422,
     544,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,   -58,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,   506,   584,
    -607,   513,   -61,   468,   529,  -607,   585,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,   -34,  -607,   494,
    -607,   455,   263,   445,  -607,   512,   606,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,   336,
    -607,   541,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,   586,    54,   213,   213,   213,  -607,  -607,  -607,
     213,   213,   165,   213,   637,  -607,  -607,  -607,  -607,  -607,
     213,    16,   213,    83,   213,   404,   473,  -607,   477,   237,
     459,   213,   213,   500,   566,   610,   464,   628,   576,   578,
     579,    57,    61,    10,  -607,  -607,  -607,    10,  -607,    10,
    -607,  -607,  -607,   606,   408,  -607,   213,  -607,  -607,  -607,
     613,  -607,  -607,   213,  -607,  -607,  -607,   213,  -607,   580,
     532,  -607,  -607,   594,   455,   534,   602,  -607,   516,  -607,
    -607,   595,  -607,  -607,  -607,  -607,   535,  -607,  -607,   287,
     471,   640,  -607,   660,   605,  -607,   614,   659,  -607,  -607,
    -607,  -607,  -607,   608,   -27,   -24,   612,   622,   578,   578,
     624,    18,  -607,   702,    39,  -607,  -607,    63,   131,   626,
     669,   632,   578,   578,   686,   653,   337,   346,   578,   656,
      43,  -607,   587,   720,   571,   667,   659,   731,   762,   615,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,   543,   640,
     129,  -607,   771,   680,   685,  -607,   468,  -607,   535,  -607,
    -607,     6,   690,   238,   245,   397,   440,  -607,  -607,  -607,
     370,  -607,  -607,  -607,  -607,  -607,  -607,   696,  -607,  -607,
     640,   422,  -607,   633,  -607,   504,   446,  -607,   719,  -607,
     334,   724,   334,   725,   726,   813,   820,   545,  -607,   791,
      95,  -607,  -607,   578,   578,   578,   578,   578,    50,   545,
     825,   829,   578,   334,   578,   578,  -607,  -607,   833,   396,
     744,   334,  -607,   775,   394,   321,   394,  -607,   446,   868,
      95,  -607,   640,   422,   776,   334,    95,   777,   578,   455,
    -607,   787,   788,   789,   675,   792,   793,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,   392,   794,   795,  -607,
    -607,   422,  -607,  -607,  -607,  -607,   455,   797,   798,   784,
     394,   502,  -607,  -607,  -607,  -607,  -607,  -607,  -607,    95,
      95,  -607,  -607,  -607,  -607,   578,  -607,  -607,  -607,  -607,
    -607,   296,  -607,  -607,   878,   882,   883,   884,   885,   886,
     804,   888,   578,    95,    95,   889,   578,   890,   891,    95,
     578,   892,   578,   578,  -607,   578,  -607,  -607,   810,   842,
     394,    86,   878,   422,  -607,  -607,  -607,   878,  -607,   895,
     535,   814,   815,   816,   817,   818,   893,   812,   819,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,   535,  -607,  -607,
    -607,   769,   461,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,   715,  -607,  -607,   767,  -607,   842,  -607,  -607,  -607,
     907,   161,   910,  -607,    95,    95,    95,    95,    95,   578,
      95,   909,  -607,  -607,    95,   911,    95,    95,  -607,   912,
      95,   913,   914,   915,  -607,   824,   578,   842,  -607,  -607,
    -607,  -607,  -607,    95,  -607,   818,   818,   818,   893,  -607,
     818,  -607,  -607,  -607,  -607,  -607,  -607,   826,  -607,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   916,
    -607,    -2,   727,   836,  -607,   578,    95,   401,   390,   878,
     878,   878,   878,   878,   920,   878,    95,  -607,    95,  -607,
    -607,    95,   878,    95,    95,    95,  -607,   921,   578,   878,
     818,   818,   818,  -607,  -607,   -14,   830,   831,   832,   834,
     835,   837,   838,   839,   840,   841,   461,  -607,  -607,   843,
    -607,  -607,   925,   878,   844,   844,   844,  -607,  -607,  -607,
    -607,  -607,    95,  -607,   878,   878,   878,  -607,   878,   878,
     878,    95,   928,  -607,   851,   854,  -607,   845,   846,   847,
     848,   849,   850,   852,   853,   855,   856,  -607,  -607,    95,
    -607,    36,   944,   947,   950,   878,  -607,  -607,  -607,  -607,
    -607,  -607,   878,    95,   821,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,   878,  -607,   922,    95,
      95,    95,  -607,  -607,   878,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -607,  -607,  -607,   945,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,   887,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,   857,   676,  -607,  -607,  -607,  -607,   862,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -157,
    -503,   224,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
     623,   681,   729,   -66,  -199,  -198,  -349,   570,   487,  -607,
     904,  -607,  -607,  -607,  -607,  -607,   511,  -467,  -384,   420,
    -607,   378,  -607,  -607,  -607,   106,  -607,  -607,   166,   400,
    -607,  -607,  -607,  -607,  -140,  -607,  -107,  -606,   737,  -607,
    -607,   741,   970,  -607,  -205,  -290,   -76,   688,  -200,   745,
     267,   749,   753,  -607,   760,  -607,  -607,  -607,   641,  -607,
    -607,   596,  -607,  -607,  -607,  -186,  -607,  -607,  -179,  -607,
     -19,   257,  -309,   448,  -248,  -500,  -280,  -336,  -192,  -515,
    -607,   635,  -607,  -607,  -607,  -209,   201,  -607,   858,  -607,
     271,   279,  -607,  -210
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -227
static const yytype_int16 yytable[] =
{
     203,   281,   205,   364,   367,   364,   369,   364,   219,   375,
     478,   560,   349,   374,   464,   196,   424,   425,   464,   412,
     464,   426,   427,   458,   430,   561,   562,   391,   563,   392,
     206,   434,   111,   441,   384,   445,   435,   436,   261,   197,
      50,   386,   449,   450,   472,   834,    51,    35,   323,    36,
     642,    37,    38,   518,    93,    39,   647,   273,   274,   275,
     276,   142,   387,   368,   111,   370,   360,   470,    40,    41,
     508,   877,    42,   511,   473,    52,    43,   400,   474,   264,
     341,   410,   509,   620,   412,   509,   807,   349,   808,    44,
     765,    45,   515,   516,   564,   565,   354,    65,    66,   698,
     699,   354,   197,   435,   436,   197,   530,   531,   416,    44,
      67,    96,   538,   198,   115,   519,    68,   116,    69,    70,
     412,   788,    53,   712,   713,   607,   608,   730,   207,   718,
     835,    94,   732,   878,   607,   608,   521,   609,   197,    54,
     540,   729,   728,   262,   610,   460,   609,   431,   509,   462,
     112,   523,   509,   610,   461,   361,   362,   350,   463,   324,
     524,   437,   438,   325,   326,   327,   328,   329,   468,   399,
     197,   351,   352,   330,   331,   650,   198,   197,   412,   198,
      46,   113,   217,   734,   439,    47,    71,   615,   616,   617,
     618,   619,   621,   332,   384,    72,   625,    73,   627,   628,
     746,   386,   667,   631,   769,   770,   771,   772,   773,   400,
     775,   566,   198,   218,   777,   333,   779,   780,    55,   525,
     782,    56,   649,   465,   342,   343,   554,   466,   526,   467,
     143,   342,   353,   789,   442,    48,   355,   794,   509,    57,
     356,    58,   344,    95,   345,   356,   117,   360,    96,   199,
     200,   198,   443,    99,   817,   818,   819,   820,   821,   100,
     823,   611,   612,   177,   193,   568,   813,   827,   220,   700,
     611,   612,   570,   101,   833,   102,   824,   103,   825,   199,
     200,   826,   104,   828,   829,   830,   711,   794,   794,   794,
     715,   582,   243,   569,   719,   105,   721,   722,   850,   723,
     571,   594,    64,   596,    65,    66,   361,   362,   108,   856,
     857,   858,   204,   859,   860,   861,    44,    67,   118,   246,
     192,   119,   855,    68,   626,    69,    70,   138,   152,   171,
     189,   862,   633,   178,   194,   501,   361,   362,    65,    66,
     882,   179,   195,   644,   106,   107,   646,   883,   242,   876,
      44,    67,   124,   428,   429,    65,    66,    68,   239,    69,
      70,   886,   244,   884,   120,   418,     1,    44,    67,   892,
     245,   666,   121,   774,    68,   208,    69,    70,   273,   274,
     275,   276,   437,   438,   199,   200,   287,   212,    65,    66,
     787,   122,   288,   553,   577,   289,   315,   316,   578,   579,
      44,    67,    72,   123,    73,   439,   512,    68,   213,    69,
      70,   419,   420,   421,   422,   522,   657,   258,   464,   259,
     658,   659,   572,   573,   581,   534,   535,    71,   267,   812,
     279,   541,   280,   731,   536,   537,    72,   635,    73,   639,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     264,   555,   832,    72,   283,    73,   290,   291,   287,   311,
     131,   148,   167,   185,   288,   574,   575,   289,     2,     3,
       4,     5,     6,     7,     8,     9,   643,    71,   587,   588,
     285,   292,   293,   696,   294,   286,    72,   295,    73,   347,
     499,   235,   251,   431,   630,   589,   268,   269,   270,   271,
     162,   313,   767,   364,   296,   297,   209,   210,   211,   298,
     299,   300,   314,   301,   317,   302,   318,   303,   304,   636,
     637,   287,   319,   305,   306,   307,   308,   288,   290,   291,
     289,   481,   482,   727,   587,   588,    65,    66,   320,   411,
     321,   483,   484,   485,   358,   701,   361,   362,    44,    67,
     584,   585,   586,   292,   293,    68,   294,    69,    70,   295,
     749,   750,   751,   752,   753,   754,   755,   756,   757,   758,
     322,   486,   180,   814,   815,   816,   296,   297,   790,   791,
     792,   298,   299,   300,   359,   301,   371,   302,   373,   303,
     304,   290,   291,   287,   388,   305,   306,   307,   308,   288,
     890,   891,   289,   273,   274,   275,   276,   389,    65,    66,
     390,   469,   402,   403,   404,   405,   292,   293,   393,   294,
      44,    67,   295,   853,   854,    71,   395,    68,   396,    69,
      70,   888,   888,   888,    72,   401,    73,   408,   413,   296,
     297,   197,   414,   446,   298,   299,   300,   447,   301,   448,
     302,   442,   303,   304,   451,   452,   287,   454,   305,   306,
     307,   308,   288,   290,   291,   289,   325,   326,   327,   328,
     329,   376,   455,   457,   500,   431,   459,   475,   377,   378,
     379,   262,   477,   126,   145,   164,   182,   479,   292,   293,
     480,   294,   496,   111,   295,   502,   497,    71,   601,   602,
     603,   604,   503,   504,   505,   507,    72,   520,    73,   513,
     431,   296,   297,   222,   232,   248,   298,   299,   300,   514,
     301,   517,   302,   527,   303,   304,   290,   291,   528,   529,
     305,   306,   307,   308,   431,   325,   326,   327,   328,   329,
     376,   127,   146,   165,   183,   532,   552,   377,   378,   379,
     533,   292,   293,   539,   294,   324,   543,   295,   545,   325,
     326,   327,   328,   329,   547,   542,   549,   550,   551,   330,
     331,   223,   233,   249,   296,   297,   556,   557,   567,   298,
     299,   300,   558,   301,   580,   302,   583,   303,   304,   128,
     147,   166,   184,   305,   306,   307,   308,   135,   149,   168,
     186,   136,   150,   169,   187,   137,   151,   170,   188,   139,
     153,   172,   190,   140,   154,   173,   191,   593,   599,   224,
     234,   250,   595,   597,   598,   600,   606,   225,   236,   252,
     623,   226,   237,   253,   624,   227,   238,   254,   629,   228,
     240,   255,   632,   229,   241,   256,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   634,   641,   645,   648,   651,   652,   653,   654,
    -220,   656,   702,   664,   665,   668,   669,   704,   705,   706,
     707,   708,   709,   710,   714,   716,   717,   720,   724,   725,
     733,   744,  -222,  -224,  -226,   738,   739,   747,   745,   761,
     763,   742,   766,   768,   776,   795,   778,   781,   783,   784,
     785,   786,   806,   809,   811,   822,   831,   837,   838,   839,
     849,   840,   841,   863,   842,   843,   844,   845,   846,   864,
     848,   851,   865,   866,   867,   868,   869,   870,   871,   879,
     872,   873,   880,   874,   875,   881,    59,   887,   407,   265,
     476,   216,   793,   559,   129,   835,   282,   548,   640,   697,
     885,    49,   847,   409,   372,   432,   471,   622,   444,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348
};

static const yytype_int16 yycheck[] =
{
      66,   108,    68,   201,   203,   203,   205,   205,    84,   219,
     394,   478,     7,   218,   363,     7,   325,   326,   367,   309,
     369,   330,   331,   359,   333,    19,    20,    88,    22,    90,
      97,   340,    53,   342,   220,   344,    20,    21,    44,    97,
      95,   220,   351,   352,   380,    59,    95,     9,     7,    11,
     550,    13,    14,    35,    12,    17,   556,    91,    92,    93,
      94,     3,   120,   203,    53,   205,    56,   376,    30,    31,
      97,    35,    34,    97,   383,    95,    38,   277,   387,    56,
       7,   286,   109,    33,   374,   109,    88,     7,    90,    51,
     696,    53,   428,   429,    88,    89,    42,    39,    40,   599,
     600,    42,    97,    20,    21,    97,   442,   443,    54,    51,
      52,    88,   448,   171,    38,    97,    58,    41,    60,    61,
     410,   727,    95,   623,   624,    39,    40,   642,   195,   629,
     144,    89,   647,    97,    39,    40,    97,    51,    97,    95,
      97,   641,    56,   149,    58,    88,    51,    97,   109,    88,
     171,    88,   109,    58,    97,   145,   146,   152,    97,   118,
      97,   145,   146,   122,   123,   124,   125,   126,   373,   203,
      97,   166,   167,   132,   133,   559,   171,    97,   468,   171,
     142,   202,   171,   650,   168,   147,   128,   523,   524,   525,
     526,   527,   528,   152,   380,   137,   532,   139,   534,   535,
     667,   380,   586,   539,   704,   705,   706,   707,   708,   409,
     710,   205,   171,   202,   714,   174,   716,   717,    95,    88,
     720,    95,   558,   363,   151,   152,    97,   367,    97,   369,
     172,   151,   152,   733,   151,   197,   177,   740,   109,    95,
     186,     0,   169,    97,   171,   186,   170,    56,    88,    88,
      89,   171,   169,    44,   769,   770,   771,   772,   773,    89,
     775,   175,   176,    62,    63,    27,   766,   782,     3,   605,
     175,   176,    27,    89,   789,    97,   776,    89,   778,    88,
      89,   781,    90,   783,   784,   785,   622,   790,   791,   792,
     626,   501,    91,    55,   630,   202,   632,   633,   813,   635,
      55,   510,     3,   512,    39,    40,   145,   146,   193,   824,
     825,   826,    90,   828,   829,   830,    51,    52,    41,     3,
      63,    41,   822,    58,   533,    60,    61,    60,    61,    62,
      63,   831,   541,    62,    63,   411,   145,   146,    39,    40,
     855,    62,    63,   553,   140,   141,   555,   862,    91,   849,
      51,    52,     3,   188,   189,    39,    40,    58,    91,    60,
      61,   876,    91,   863,    41,   152,     8,    51,    52,   884,
      91,   581,    16,   709,    58,   195,    60,    61,    91,    92,
      93,    94,   145,   146,    88,    89,    50,    96,    39,    40,
     726,    41,    56,   469,    24,    59,    88,    89,    28,    29,
      51,    52,   137,    41,   139,   168,   425,    58,    95,    60,
      61,   198,   199,   200,   201,   434,    24,    10,   767,    39,
      28,    29,    25,    26,   500,    88,    89,   128,    97,   765,
      89,   450,    97,   643,    88,    89,   137,   544,   139,   546,
     749,   750,   751,   752,   753,   754,   755,   756,   757,   758,
      56,   470,   788,   137,   191,   139,   120,   121,    50,    37,
      60,    61,    62,    63,    56,    25,    26,    59,   110,   111,
     112,   113,   114,   115,   116,   117,   552,   128,    32,    33,
     202,   145,   146,   590,   148,   202,   137,   151,   139,   171,
     203,    91,    92,    97,    98,    49,   162,   163,   164,   165,
       3,    89,   701,   701,   168,   169,   129,   130,   131,   173,
     174,   175,    89,   177,    89,   179,    89,   181,   182,   198,
     199,    50,    89,   187,   188,   189,   190,    56,   120,   121,
      59,    15,    16,   640,    32,    33,    39,    40,    88,   203,
      89,    25,    26,    27,    58,   611,   145,   146,    51,    52,
      46,    47,    48,   145,   146,    58,   148,    60,    61,   151,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      89,    55,     3,   183,   184,   185,   168,   169,   735,   736,
     737,   173,   174,   175,   180,   177,    35,   179,   202,   181,
     182,   120,   121,    50,    88,   187,   188,   189,   190,    56,
     880,   881,    59,    91,    92,    93,    94,    23,    39,    40,
      97,   203,   157,   158,   159,   160,   145,   146,   150,   148,
      51,    52,   151,   815,   816,   128,    97,    58,    43,    60,
      61,   879,   880,   881,   137,   141,   139,   192,    97,   168,
     169,    97,    56,   170,   173,   174,   175,   170,   177,   190,
     179,   151,   181,   182,    88,    45,    50,   193,   187,   188,
     189,   190,    56,   120,   121,    59,   122,   123,   124,   125,
     126,   127,    44,    97,   203,    97,    97,    97,   134,   135,
     136,   149,    88,    60,    61,    62,    63,   153,   145,   146,
      88,   148,    97,    53,   151,    35,   161,   128,   153,   154,
     155,   156,    97,    89,    45,    97,   137,     5,   139,    97,
      97,   168,   169,    90,    91,    92,   173,   174,   175,    97,
     177,    97,   179,    97,   181,   182,   120,   121,    59,    97,
     187,   188,   189,   190,    97,   122,   123,   124,   125,   126,
     127,    60,    61,    62,    63,    59,   203,   134,   135,   136,
      97,   145,   146,    97,   148,   118,    36,   151,   187,   122,
     123,   124,   125,   126,    97,   178,    35,     5,   153,   132,
     133,    90,    91,    92,   168,   169,     5,    97,    88,   173,
     174,   175,    97,   177,    88,   179,   153,   181,   182,    60,
      61,    62,    63,   187,   188,   189,   190,    60,    61,    62,
      63,    60,    61,    62,    63,    60,    61,    62,    63,    60,
      61,    62,    63,    60,    61,    62,    63,    98,     5,    90,
      91,    92,    98,    98,    98,     5,    35,    90,    91,    92,
       5,    90,    91,    92,     5,    90,    91,    92,     5,    90,
      91,    92,    98,    90,    91,    92,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    97,     5,    98,    98,    89,    89,    89,   204,
      88,    88,     4,    89,    89,    88,    88,     5,     5,     5,
       5,     5,    88,     5,     5,     5,     5,     5,    88,    57,
       5,    89,    88,    88,    88,    88,    88,   138,    89,   194,
     143,    18,     5,     3,     5,    89,     5,     5,     5,     5,
       5,    97,     6,   196,    88,     5,     5,    97,    97,    97,
       5,    97,    97,     5,    97,    97,    97,    97,    97,    88,
      97,    97,    88,    98,    98,    98,    98,    98,    98,     5,
      98,    98,     5,    98,    98,     5,    11,    35,   282,    97,
     390,    74,   738,   476,    60,   144,   109,   456,   548,   591,
     864,     1,   806,   285,   214,   334,   380,   529,   343,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,   110,   111,   112,   113,   114,   115,   116,   117,
     207,   208,   209,   226,   227,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   241,   242,   243,   268,   269,   270,
     271,   272,   273,   274,   275,     9,    11,    13,    14,    17,
      30,    31,    34,    38,    51,    53,   142,   147,   197,   318,
      95,    95,    95,    95,    95,    95,    95,    95,     0,   209,
     210,   212,   214,   216,     3,    39,    40,    52,    58,    60,
      61,   128,   137,   139,   218,   219,   276,   277,   278,   286,
     288,   305,   314,   317,   318,   319,   325,   326,   327,   328,
     220,   222,   224,    12,    89,    97,    88,   244,   245,    44,
      89,    89,    97,    89,    90,   202,   140,   141,   193,   238,
     239,    53,   171,   202,   322,    38,    41,   170,    41,    41,
      41,    16,    41,    41,     3,   211,   276,   277,   278,   286,
     287,   305,   306,   307,   308,   314,   317,   325,   326,   327,
     328,   332,     3,   172,   213,   276,   277,   278,   305,   314,
     317,   325,   326,   327,   328,   347,   356,   362,   363,   365,
     366,   367,     3,   215,   276,   277,   278,   305,   314,   317,
     325,   326,   327,   328,   358,   359,   360,   362,   366,   367,
       3,   217,   276,   277,   278,   305,   314,   317,   325,   326,
     327,   328,   347,   362,   366,   367,     7,    97,   171,    88,
      89,   279,   281,   279,    90,   279,    97,   195,   195,   129,
     130,   131,    96,    95,   329,   330,   219,   171,   202,   322,
       3,   221,   276,   277,   278,   314,   317,   325,   327,   328,
     335,   223,   276,   277,   278,   305,   314,   317,   325,   326,
     327,   328,   347,   362,   366,   367,     3,   225,   276,   277,
     278,   305,   314,   317,   325,   327,   328,   331,    10,    39,
     228,    44,   149,   283,    56,   245,   312,    97,   162,   163,
     164,   165,   361,    91,    92,    93,    94,   323,   324,    89,
      97,   312,   239,   191,   240,   202,   202,    50,    56,    59,
     120,   121,   145,   146,   148,   151,   168,   169,   173,   174,
     175,   177,   179,   181,   182,   187,   188,   189,   190,   320,
     321,    37,   369,    89,    89,    88,    89,    89,    89,    89,
      88,    89,    89,     7,   118,   122,   123,   124,   125,   126,
     132,   133,   152,   174,   333,   334,   338,   341,   343,   344,
     345,     7,   151,   152,   169,   171,   364,   171,   364,     7,
     152,   166,   167,   152,    42,   177,   186,   289,    58,   180,
      56,   145,   146,   280,   281,   282,   310,   280,   310,   280,
     310,    35,   330,   202,   320,   369,   127,   134,   135,   136,
     336,   337,   339,   340,   341,   342,   344,   120,    88,    23,
      97,    88,    90,   150,   284,    97,    43,   285,   246,   203,
     324,   141,   157,   158,   159,   160,   294,   240,   192,   323,
     320,   203,   321,    97,    56,   311,    54,   291,   152,   198,
     199,   200,   201,   348,   348,   348,   348,   348,   188,   189,
     348,    97,   334,   353,   348,    20,    21,   145,   146,   168,
     357,   348,   151,   169,   357,   348,   170,   170,   190,   348,
     348,    88,    45,   368,   193,    44,   290,    97,   353,    97,
      88,    97,    88,    97,   282,   310,   310,   310,   320,   203,
     348,   337,   353,   348,   348,    97,   283,    88,   294,   153,
      88,    15,    16,    25,    26,    27,    55,   247,   248,   251,
     252,   253,   254,   255,   256,   260,    97,   161,   293,   203,
     203,   322,    35,    97,    89,    45,   292,    97,    97,   109,
     346,    97,   346,    97,    97,   353,   353,    97,    35,    97,
       5,    97,   346,    88,    97,    88,    97,    97,    59,    97,
     353,   353,    59,    97,    88,    89,    88,    89,   353,    97,
      97,   346,   178,    36,   309,   187,   315,    97,   292,    35,
       5,   153,   203,   322,    97,   346,     5,    97,    97,   284,
     293,    19,    20,    22,    88,    89,   205,    88,    27,    55,
      27,    55,    25,    26,    25,    26,   249,    24,    28,    29,
      88,   322,   369,   153,    46,    47,    48,    32,    33,    49,
     295,   296,   297,    98,   361,    98,   361,    98,    98,     5,
       5,   153,   154,   155,   156,   349,    35,    39,    40,    51,
      58,   175,   176,   350,   351,   353,   353,   353,   353,   353,
      33,   353,   349,     5,     5,   353,   361,   353,   353,     5,
      98,   353,    98,   361,    97,   312,   198,   199,   316,   312,
     295,     5,   351,   322,   369,    98,   361,   351,    98,   353,
     294,    89,    89,    89,   204,   261,    88,    24,    28,    29,
     250,   257,   258,   259,    89,    89,   369,   294,    88,    88,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   312,   297,   351,   351,
     353,   279,     4,   355,     5,     5,     5,     5,     5,    88,
       5,   353,   351,   351,     5,   353,     5,     5,   351,   353,
       5,   353,   353,   353,    88,    57,   313,   312,    56,   351,
     355,   369,   355,     5,   293,   262,   263,   264,    88,    88,
     265,   266,    18,   267,    89,    89,   293,   138,   300,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   303,
     304,   194,   298,   143,   302,   313,     5,   280,     3,   351,
     351,   351,   351,   351,   353,   351,     5,   351,     5,   351,
     351,     5,   351,     5,     5,     5,    97,   353,   313,   351,
     265,   265,   265,   267,   266,    89,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,     6,    88,    90,   196,
     299,    88,   353,   351,   183,   184,   185,   355,   355,   355,
     355,   355,     5,   355,   351,   351,   351,   355,   351,   351,
     351,     5,   353,   355,    59,   144,   301,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,   304,    97,     5,
     355,    97,   354,   354,   354,   351,   355,   355,   355,   355,
     355,   355,   351,     5,    88,    88,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,   351,    35,    97,     5,
       5,     5,   355,   355,   351,   301,   355,    35,   350,   352,
     352,   352,   355
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 152:

/* Line 1455 of yacc.c  */
#line 493 "src/p.y"
    {
                   mailset.events = Event_All;
                    addmail((yyvsp[(2) - (4)].string), &mailset, &Run.maillist);
                  }
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 497 "src/p.y"
    {
                    addmail((yyvsp[(2) - (7)].string), &mailset, &Run.maillist);
                  }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 500 "src/p.y"
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[(2) - (8)].string), &mailset, &Run.maillist);
                  }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 506 "src/p.y"
    {
                    if (!Run.isdaemon || ihp.daemon) {
                      ihp.daemon     = TRUE;
                      Run.isdaemon   = TRUE;
                      Run.polltime   = (yyvsp[(3) - (4)].number);
                      Run.startdelay = (yyvsp[(4) - (4)].number);
                    }
                  }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 516 "src/p.y"
    { (yyval.number) = START_DELAY; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 517 "src/p.y"
    { (yyval.number) = (yyvsp[(3) - (3)].number); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 520 "src/p.y"
    {
                    Run.expectbuffer = (yyvsp[(3) - (4)].number) * (yyvsp[(4) - (4)].number);
                  }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 525 "src/p.y"
    {
                    Run.init = TRUE;
                  }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 530 "src/p.y"
    {
                  #ifdef OPENSSL_FIPS
                    Run.fipsEnabled = TRUE;
                  #endif
                  }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 537 "src/p.y"
    {
                   if (!Run.logfile || ihp.logfile) {
                     ihp.logfile = TRUE;
                     setlogfile((yyvsp[(3) - (3)].string));
                     Run.use_syslog = FALSE;
                     Run.dolog =TRUE;
                   }
                  }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 545 "src/p.y"
    {
                    setsyslog(NULL);
                  }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 548 "src/p.y"
    {
                    setsyslog((yyvsp[(5) - (5)].string)); FREE((yyvsp[(5) - (5)].string));
                  }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 553 "src/p.y"
    {
                    Run.eventlist_dir = (yyvsp[(4) - (4)].string);
                  }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 556 "src/p.y"
    {
                    Run.eventlist_dir = (yyvsp[(4) - (6)].string);
                    Run.eventlist_slots = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 560 "src/p.y"
    {
                    Run.eventlist_dir = Str_dup(MYEVENTLISTBASE);
                    Run.eventlist_slots = (yyvsp[(4) - (4)].number);
                  }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 566 "src/p.y"
    {
                    Run.idfile = (yyvsp[(3) - (3)].string);
                  }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 571 "src/p.y"
    {
                    Run.statefile = (yyvsp[(3) - (3)].string);
                  }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 576 "src/p.y"
    {
                   if (!Run.pidfile || ihp.pidfile) {
                     ihp.pidfile = TRUE;
                     setpidfile((yyvsp[(3) - (3)].string));
                   }
                 }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 591 "src/p.y"
    {
                    check_hostname(((yyvsp[(1) - (4)].url))->hostname);
                    addmmonit((yyvsp[(1) - (4)].url), (yyvsp[(2) - (4)].number), (yyvsp[(3) - (4)].number), (yyvsp[(4) - (4)].string)); 
                  }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 598 "src/p.y"
    {
                    Run.dommonitcredentials = FALSE;
                  }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 603 "src/p.y"
    {
                   if (((yyvsp[(4) - (5)].number)) > SMTP_TIMEOUT)
                     Run.mailserver_timeout = (yyvsp[(4) - (5)].number);
                   Run.mail_hostname = (yyvsp[(5) - (5)].string);
                  }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 610 "src/p.y"
    {
                   Run.MailFormat.from    = mailset.from    ?  mailset.from    : Str_dup(ALERT_FROM);
                   Run.MailFormat.replyto = mailset.replyto ?  mailset.replyto : NULL;
                   Run.MailFormat.subject = mailset.subject ?  mailset.subject : Str_dup(ALERT_SUBJECT);
                   Run.MailFormat.message = mailset.message ?  mailset.message : Str_dup(ALERT_MESSAGE);
                   reset_mailset();
                 }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 619 "src/p.y"
    {
                   Run.dohttpd = TRUE;
                   Run.httpdport = (yyvsp[(4) - (5)].number);
                 }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 629 "src/p.y"
    {
                    /* Restore the current text overriden by lookahead */
                    FREE(argyytext);
                    argyytext = Str_dup((yyvsp[(1) - (5)].string));

                    check_hostname((yyvsp[(1) - (5)].string));
                    mailserverset.host = (yyvsp[(1) - (5)].string);
                    mailserverset.username = (yyvsp[(2) - (5)].string);
                    mailserverset.password = (yyvsp[(3) - (5)].string);
                    mailserverset.ssl.version = (yyvsp[(4) - (5)].number);
                    if (mailserverset.ssl.version != SSL_VERSION_NONE) {
                      mailserverset.ssl.use_ssl = TRUE;
                      if (mailserverset.ssl.version == SSL_VERSION_SSLV2 ||
                         mailserverset.ssl.version == SSL_VERSION_SSLV3)
                         mailserverset.port = PORT_SMTPS;
                      mailserverset.ssl.certmd5 = (yyvsp[(5) - (5)].string);
                    }
                    addmailserver(&mailserverset);
                  }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 648 "src/p.y"
    {
                    /* Restore the current text overriden by lookahead */
                    FREE(argyytext);
                    argyytext = Str_dup((yyvsp[(1) - (7)].string));

                    check_hostname((yyvsp[(1) - (7)].string));
                    mailserverset.host = (yyvsp[(1) - (7)].string);
                    mailserverset.port = (yyvsp[(3) - (7)].number);
                    mailserverset.username = (yyvsp[(4) - (7)].string);
                    mailserverset.password = (yyvsp[(5) - (7)].string);
                    mailserverset.ssl.version = (yyvsp[(6) - (7)].number);
                    if (mailserverset.ssl.version != SSL_VERSION_NONE) {
                      mailserverset.ssl.use_ssl = TRUE;
                      mailserverset.ssl.certmd5 = (yyvsp[(7) - (7)].string);
                    }
                    addmailserver(&mailserverset);
                  }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 677 "src/p.y"
    { Run.httpdssl = FALSE; }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 678 "src/p.y"
    {
                    Run.httpdssl = TRUE;                   
                    if (! have_ssl())
                      yyerror("SSL is not supported");
                    else if (! Run.httpsslpem)
                      yyerror("SSL server PEM file is required (pemfile option)");
                    else if (! file_checkStat(Run.httpsslpem, "SSL server PEM file", S_IRWXU))
                      yyerror("SSL server PEM file permissions check failed");
                  }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 705 "src/p.y"
    { FREE((yyvsp[(3) - (3)].string)); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 706 "src/p.y"
    { FREE((yyvsp[(3) - (3)].string)); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 710 "src/p.y"
    { Run.httpdsig = TRUE; }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 711 "src/p.y"
    { Run.httpdsig = FALSE; }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 722 "src/p.y"
    { Run.bind_addr = (yyvsp[(2) - (2)].string); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 725 "src/p.y"
    {
                    Run.httpsslpem = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 730 "src/p.y"
    {
                    Run.httpsslclientpem = (yyvsp[(2) - (2)].string); 
                    Run.clientssl = TRUE;
                    if (!file_checkStat(Run.httpsslclientpem, "SSL client PEM file", S_IRWXU | S_IRGRP | S_IROTH))
                      yyerror2("SSL client PEM file has too loose permissions");
                  }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 738 "src/p.y"
    {   
                    Run.allowselfcert = TRUE;
                  }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 743 "src/p.y"
    {
                    addcredentials((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].string), DIGEST_CLEARTEXT, (yyvsp[(5) - (5)].number));
                  }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 746 "src/p.y"
    {
#ifdef HAVE_LIBPAM
                    addpamauth((yyvsp[(3) - (4)].string), (yyvsp[(4) - (4)].number));
#else
                    yyerror("PAM is not supported");
                    FREE((yyvsp[(3) - (4)].string));
#endif
                  }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 754 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(2) - (2)].string), NULL, DIGEST_CLEARTEXT);
                    FREE((yyvsp[(2) - (2)].string));
                  }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 758 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(3) - (3)].string), NULL, DIGEST_CLEARTEXT);
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 762 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(3) - (3)].string), NULL, DIGEST_MD5);
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 766 "src/p.y"
    {
                    addhtpasswdentry((yyvsp[(3) - (3)].string), NULL, DIGEST_CRYPT);
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 770 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(2) - (2)].string);
                    digesttype = CLEARTEXT;
                  }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 774 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 777 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(3) - (3)].string);
                    digesttype = DIGEST_CLEARTEXT;
                  }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 781 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 784 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(3) - (3)].string);
                    digesttype = DIGEST_MD5;
                  }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 788 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 791 "src/p.y"
    {
                    htpasswd_file = (yyvsp[(3) - (3)].string);
                    digesttype = DIGEST_CRYPT;
                  }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 795 "src/p.y"
    {
                    FREE(htpasswd_file);
                  }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 798 "src/p.y"
    {
                    if (! (add_net_allow((yyvsp[(2) - (2)].string)) || add_host_allow((yyvsp[(2) - (2)].string)))) {
                      yyerror2("erroneous network or host identifier %s", (yyvsp[(2) - (2)].string)); 
                    }
                    FREE((yyvsp[(2) - (2)].string));
                  }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 810 "src/p.y"
    { addhtpasswdentry(htpasswd_file, (yyvsp[(1) - (1)].string), digesttype);
                           FREE((yyvsp[(1) - (1)].string)); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 814 "src/p.y"
    { (yyval.number) = FALSE; }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 815 "src/p.y"
    { (yyval.number) = TRUE; }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 818 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                  }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 821 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                  }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 824 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                    matchset.ignore = FALSE;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[(4) - (4)].string));
                    addmatch(&matchset, ACTION_IGNORE, 0);
                  }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 831 "src/p.y"
    {
                    createservice(TYPE_PROCESS, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_process);
                    matchset.ignore = FALSE;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[(4) - (4)].string));
                    addmatch(&matchset, ACTION_IGNORE, 0);
                  }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 840 "src/p.y"
    {
                    createservice(TYPE_FILE, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_file);
                  }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 845 "src/p.y"
    {
                    createservice(TYPE_FILESYSTEM, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_filesystem);
                  }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 850 "src/p.y"
    {
                    createservice(TYPE_DIRECTORY, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_directory);
                  }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 855 "src/p.y"
    {
                    check_hostname((yyvsp[(4) - (4)].string)); 
                    createservice(TYPE_HOST, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_remote_host);
                  }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 861 "src/p.y"
    {
                    Run.system = createservice(TYPE_SYSTEM, (yyvsp[(2) - (2)].string), Str_dup(""), check_system); // The name given in the 'check system' statement overrides system hostname
                  }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 866 "src/p.y"
    {
                    createservice(TYPE_FIFO, (yyvsp[(2) - (4)].string), (yyvsp[(4) - (4)].string), check_fifo);
                  }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 871 "src/p.y"
    {
                        check_exec((yyvsp[(4) - (5)].string));
                        createservice(TYPE_PROGRAM, (yyvsp[(2) - (5)].string), (yyvsp[(4) - (5)].string), check_program);
                        current->program->timeout = (yyvsp[(5) - (5)].number);
                  }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 878 "src/p.y"
    {
                    addcommand(START, (yyvsp[(3) - (3)].number));
                  }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 881 "src/p.y"
    {
                    addcommand(START, (yyvsp[(4) - (4)].number));
                  }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 886 "src/p.y"
    {
                    addcommand(STOP, (yyvsp[(3) - (3)].number));
                  }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 889 "src/p.y"
    {
                    addcommand(STOP, (yyvsp[(4) - (4)].number));
                  }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 895 "src/p.y"
    {
                    addcommand(RESTART, (yyvsp[(3) - (3)].number));
                  }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 898 "src/p.y"
    {
                    addcommand(RESTART, (yyvsp[(4) - (4)].number));
                  }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 911 "src/p.y"
    { addargument((yyvsp[(1) - (1)].string)); }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 912 "src/p.y"
    { addargument((yyvsp[(1) - (1)].string)); }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 915 "src/p.y"
    { addeuid( get_uid((yyvsp[(2) - (2)].string), 0) ); FREE((yyvsp[(2) - (2)].string)); }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 916 "src/p.y"
    { addegid( get_gid((yyvsp[(2) - (2)].string), 0) ); FREE((yyvsp[(2) - (2)].string)); }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 917 "src/p.y"
    { addeuid( get_uid(NULL, (yyvsp[(2) - (2)].number)) ); }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 918 "src/p.y"
    { addegid( get_gid(NULL, (yyvsp[(2) - (2)].number)) ); }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 921 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 922 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 923 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 926 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 927 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 930 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 931 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 935 "src/p.y"
    {
                    portset.timeout = (yyvsp[(7) - (12)].number);
                    portset.retry = (yyvsp[(8) - (12)].number);
                    addeventaction(&(portset).action, (yyvsp[(11) - (12)].number), (yyvsp[(12) - (12)].number));
                    addport(&portset);
                  }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 942 "src/p.y"
    { 
                    prepare_urlrequest((yyvsp[(4) - (11)].url));
                    portset.timeout = (yyvsp[(6) - (11)].number);
                    portset.retry = (yyvsp[(7) - (11)].number);
                    addeventaction(&(portset).action, (yyvsp[(10) - (11)].number), (yyvsp[(11) - (11)].number));
                    addport(&portset);
                  }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 952 "src/p.y"
    {
                   portset.timeout = (yyvsp[(6) - (11)].number);
                   portset.retry = (yyvsp[(7) - (11)].number);
                   addeventaction(&(portset).action, (yyvsp[(10) - (11)].number), (yyvsp[(11) - (11)].number));
                   addport(&portset);
                  }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 961 "src/p.y"
    {
                   icmpset.type = (yyvsp[(4) - (10)].number);
                   icmpset.count = (yyvsp[(5) - (10)].number);
                   icmpset.timeout = (yyvsp[(6) - (10)].number);
                   addeventaction(&(icmpset).action, (yyvsp[(9) - (10)].number), (yyvsp[(10) - (10)].number));
                   addicmp(&icmpset);
                  }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 970 "src/p.y"
    {
                    if (current->type == TYPE_HOST)
                      portset.hostname = Str_dup(current->path);
                    else
                      portset.hostname = Str_dup(LOCALHOST);
                  }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 976 "src/p.y"
    { check_hostname((yyvsp[(2) - (2)].string)); portset.hostname = (yyvsp[(2) - (2)].string); }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 979 "src/p.y"
    { portset.port = (yyvsp[(2) - (2)].number); portset.family = AF_INET; }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 982 "src/p.y"
    {
                    portset.pathname = (yyvsp[(2) - (2)].string); portset.family = AF_UNIX;
                  }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 987 "src/p.y"
    {
                    portset.type = SOCK_STREAM;
                  }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 990 "src/p.y"
    {
                    portset.type = SOCK_STREAM;
                  }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 993 "src/p.y"
    {
                    portset.type = SOCK_STREAM;
                    portset.SSL.use_ssl = TRUE;
                    portset.SSL.version = (yyvsp[(3) - (4)].number);
                    if (portset.SSL.version == SSL_VERSION_NONE)
                      portset.SSL.version = SSL_VERSION_AUTO;
                    portset.SSL.certmd5 = (yyvsp[(4) - (4)].string);
                  }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1001 "src/p.y"
    {
                    portset.type = SOCK_DGRAM;
                  }
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1006 "src/p.y"
    { (yyval.string) = NULL; }
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1007 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1010 "src/p.y"
    { (yyval.number) = SSL_VERSION_NONE; }
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1011 "src/p.y"
    { (yyval.number) = SSL_VERSION_SSLV2; }
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1012 "src/p.y"
    { (yyval.number) = SSL_VERSION_SSLV3; }
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1013 "src/p.y"
    { (yyval.number) = SSL_VERSION_TLS; }
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1014 "src/p.y"
    { (yyval.number) = SSL_VERSION_AUTO; }
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1017 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DEFAULT);
                  }
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1020 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_APACHESTATUS);
                  }
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1023 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DEFAULT);
                  }
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1026 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DNS);
                  }
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1029 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_DWP);
                  }
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1032 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_FTP);
                  }
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1035 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_HTTP);
                  }
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1038 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_IMAP);
                  }
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1041 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_CLAMAV);
                  }
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1044 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_LDAP2);
                  }
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1047 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_LDAP3);
                  }
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1050 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_MYSQL);
                  }
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1053 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_SIP);
                  }
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1056 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_NNTP);
                  }
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1059 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_NTP3);
                    portset.type = SOCK_DGRAM;
                  }
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1063 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_POSTFIXPOLICY);
                  }
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1066 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_POP);
                  }
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1069 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_SMTP);
                  }
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1072 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_SSH);
                  }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1075 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_RDATE);
                  }
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1078 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_RSYNC);
                  }
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1081 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_TNS);
                  }
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1084 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_PGSQL);
                  }
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1087 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_LMTP);
                  }
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1090 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_GPS);
                  }
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1093 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_RADIUS);
                  }
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1096 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_MEMCACHE);
                  }
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1099 "src/p.y"
    {
                    portset.protocol = Protocol_get(Protocol_GENERIC);
                  }
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1108 "src/p.y"
    { addgeneric(&portset, (yyvsp[(2) - (2)].string), NULL); FREE((yyvsp[(2) - (2)].string));}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1109 "src/p.y"
    { addgeneric(&portset, NULL, (yyvsp[(2) - (2)].string)); FREE((yyvsp[(2) - (2)].string));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1113 "src/p.y"
    {
                    portset.request = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1116 "src/p.y"
    {
                    portset.request = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1122 "src/p.y"
    {
                     portset.maxforward = verifyMaxForward((yyvsp[(2) - (2)].number)); 
                   }
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1128 "src/p.y"
    { 
                    portset.request = Util_urlEncode((yyvsp[(2) - (3)].string)); 
                    FREE((yyvsp[(2) - (3)].string)); 
                  }
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1132 "src/p.y"
    {
                    portset.request = Util_urlEncode((yyvsp[(2) - (5)].string));
                    FREE((yyvsp[(2) - (5)].string));
                    portset.request_checksum = (yyvsp[(4) - (5)].string);
                  }
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1140 "src/p.y"
    {
                    portset.request_hostheader = (yyvsp[(2) - (2)].string);
                  }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1145 "src/p.y"
    { 
                    portset.request = (yyvsp[(2) - (2)].string); 
                  }
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1154 "src/p.y"
    { 
                    portset.ApacheStatus.loglimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.loglimit = (int)(yyvsp[(3) - (4)].number); 
                  }
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1158 "src/p.y"
    { 
                    portset.ApacheStatus.closelimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.closelimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1162 "src/p.y"
    { 
                    portset.ApacheStatus.dnslimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.dnslimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1166 "src/p.y"
    { 
                    portset.ApacheStatus.keepalivelimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.keepalivelimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1170 "src/p.y"
    { 
                    portset.ApacheStatus.replylimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.replylimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1174 "src/p.y"
    { 
                    portset.ApacheStatus.requestlimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.requestlimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1178 "src/p.y"
    { 
                    portset.ApacheStatus.startlimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.startlimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1182 "src/p.y"
    { 
                    portset.ApacheStatus.waitlimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.waitlimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1186 "src/p.y"
    { 
                    portset.ApacheStatus.gracefullimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.gracefullimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1190 "src/p.y"
    { 
                    portset.ApacheStatus.cleanuplimitOP = (yyvsp[(2) - (4)].number); 
                    portset.ApacheStatus.cleanuplimit = (int)((yyvsp[(3) - (4)].number)); 
                  }
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1196 "src/p.y"
    {
                    seteventaction(&(current)->action_NONEXIST, (yyvsp[(6) - (7)].number), (yyvsp[(7) - (7)].number));
                  }
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1202 "src/p.y"
    {
                    seteventaction(&(current)->action_PID, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                  }
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1207 "src/p.y"
    {
                    seteventaction(&(current)->action_PPID, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                  }
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1212 "src/p.y"
    {
                    uptimeset.operator = (yyvsp[(3) - (9)].number);
                    uptimeset.uptime = ((unsigned long long)(yyvsp[(4) - (9)].number) * (yyvsp[(5) - (9)].number));
                    addeventaction(&(uptimeset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    adduptime(&uptimeset);
                  }
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1219 "src/p.y"
    {
                   (yyval.number) = ICMP_ATTEMPT_COUNT;
                  }
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1222 "src/p.y"
    {    
                   (yyval.number) = (yyvsp[(2) - (2)].number);
                  }
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1227 "src/p.y"
    {
                   (yyval.number) = EXEC_TIMEOUT;
                  }
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1230 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (3)].number);
                  }
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1235 "src/p.y"
    {
                   (yyval.number) = PROGRAM_TIMEOUT; // Default program status check timeout is 5 min
                  }
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1238 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (3)].number);
                  }
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1243 "src/p.y"
    {
                   (yyval.number) = NET_TIMEOUT;
                  }
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1246 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (3)].number);
                  }
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1251 "src/p.y"
    {
                   (yyval.number) = 1;
                  }
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1254 "src/p.y"
    {
                   (yyval.number) = (yyvsp[(2) - (2)].number);
                  }
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1259 "src/p.y"
    {
                   actionrateset.count = (yyvsp[(2) - (7)].number);
                   actionrateset.cycle = (yyvsp[(4) - (7)].number);
                   addeventaction(&(actionrateset).action, (yyvsp[(7) - (7)].number), ACTION_IGNORE);
                   addactionrate(&actionrateset);
                 }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1265 "src/p.y"
    {
                   actionrateset.count = (yyvsp[(2) - (7)].number);
                   actionrateset.cycle = (yyvsp[(4) - (7)].number);
                   addeventaction(&(actionrateset).action, ACTION_UNMONITOR, ACTION_IGNORE);
                   addactionrate(&actionrateset);
                 }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1274 "src/p.y"
    {
                    seturlrequest((yyvsp[(2) - (3)].number), (yyvsp[(3) - (3)].string));
                    FREE((yyvsp[(3) - (3)].string));
                  }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1280 "src/p.y"
    { (yyval.number) = OPERATOR_EQUAL; }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1281 "src/p.y"
    { (yyval.number) = OPERATOR_NOTEQUAL; }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1284 "src/p.y"
    {
                   mailset.events = Event_All;
                   addmail((yyvsp[(1) - (3)].string), &mailset, &current->maillist);
                  }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1288 "src/p.y"
    {
                   addmail((yyvsp[(1) - (6)].string), &mailset, &current->maillist);
                  }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1291 "src/p.y"
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[(1) - (7)].string), &mailset, &current->maillist);
                  }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1295 "src/p.y"
    {
                   addmail((yyvsp[(1) - (1)].string), &mailset, &current->maillist);
                  }
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1300 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1303 "src/p.y"
    { (yyval.string) = (yyvsp[(2) - (2)].string); }
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1310 "src/p.y"
    { mailset.events |= Event_Action; }
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1311 "src/p.y"
    { mailset.events |= Event_Checksum; }
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1312 "src/p.y"
    { mailset.events |= Event_Connection; }
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1313 "src/p.y"
    { mailset.events |= Event_Content; }
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1314 "src/p.y"
    { mailset.events |= Event_Data; }
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1315 "src/p.y"
    { mailset.events |= Event_Exec; }
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1316 "src/p.y"
    { mailset.events |= Event_Fsflag; }
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1317 "src/p.y"
    { mailset.events |= Event_Gid; }
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1318 "src/p.y"
    { mailset.events |= Event_Icmp; }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1319 "src/p.y"
    { mailset.events |= Event_Instance; }
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1320 "src/p.y"
    { mailset.events |= Event_Invalid; }
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1321 "src/p.y"
    { mailset.events |= Event_Nonexist; }
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1322 "src/p.y"
    { mailset.events |= Event_Permission; }
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1323 "src/p.y"
    { mailset.events |= Event_Pid; }
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1324 "src/p.y"
    { mailset.events |= Event_PPid; }
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1325 "src/p.y"
    { mailset.events |= Event_Resource; }
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1326 "src/p.y"
    { mailset.events |= Event_Size; }
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1327 "src/p.y"
    { mailset.events |= Event_Status; }
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1328 "src/p.y"
    { mailset.events |= Event_Timeout; }
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1329 "src/p.y"
    { mailset.events |= Event_Timestamp; }
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1330 "src/p.y"
    { mailset.events |= Event_Uid; }
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1331 "src/p.y"
    { mailset.events |= Event_Uptime; }
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1342 "src/p.y"
    { mailset.from = (yyvsp[(1) - (1)].string); }
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1343 "src/p.y"
    { mailset.replyto = (yyvsp[(1) - (1)].string); }
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1344 "src/p.y"
    { mailset.subject = (yyvsp[(1) - (1)].string); }
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1345 "src/p.y"
    { mailset.message = (yyvsp[(1) - (1)].string); }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1348 "src/p.y"
    {
                   current->every.type = EVERY_SKIPCYCLES;
                   current->every.spec.cycle.number = (yyvsp[(2) - (3)].number);
                 }
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1352 "src/p.y"
    {
                   current->every.type = EVERY_CRON;
                   current->every.spec.cron = (yyvsp[(2) - (2)].string);
                 }
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1356 "src/p.y"
    {
                   current->every.type = EVERY_NOTINCRON;
                   current->every.spec.cron = (yyvsp[(2) - (2)].string);
                 }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1362 "src/p.y"
    {
                    current->mode = MODE_ACTIVE;
                  }
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1365 "src/p.y"
    {
                    current->mode = MODE_PASSIVE;
                  }
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1368 "src/p.y"
    {
                    current->mode = MODE_MANUAL;
                    current->monitor = MONITOR_NOT;
                  }
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1374 "src/p.y"
    { addservicegroup((yyvsp[(2) - (2)].string)); FREE((yyvsp[(2) - (2)].string));}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1385 "src/p.y"
    { adddependant((yyvsp[(1) - (1)].string)); }
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1388 "src/p.y"
    {
                        statusset.operator = (yyvsp[(3) - (8)].number);
                        statusset.return_value = (yyvsp[(4) - (8)].number);
                        addeventaction(&(statusset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                        addstatus(&statusset);
                   }
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1396 "src/p.y"
    {
                     addeventaction(&(resourceset).action, (yyvsp[(5) - (6)].number), (yyvsp[(6) - (6)].number));
                     addresource(&resourceset);
                   }
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1412 "src/p.y"
    {
                     addeventaction(&(resourceset).action, (yyvsp[(5) - (6)].number), (yyvsp[(6) - (6)].number));
                     addresource(&resourceset);
                   }
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1428 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_CPU_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10); 
                  }
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1433 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_TOTAL_CPU_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10); 
                  }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1440 "src/p.y"
    {
                    resourceset.resource_id = (yyvsp[(1) - (4)].number);
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10); 
                  }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1447 "src/p.y"
    { (yyval.number) = RESOURCE_ID_CPUUSER; }
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1448 "src/p.y"
    { (yyval.number) = RESOURCE_ID_CPUSYSTEM; }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1449 "src/p.y"
    { (yyval.number) = RESOURCE_ID_CPUWAIT; }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1452 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_MEM_KBYTE;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (4)].real) * ((yyvsp[(4) - (4)].number) / 1024.0)); 
                  }
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1457 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_MEM_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10); 
                  }
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1462 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_TOTAL_MEM_KBYTE;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (4)].real) * ((yyvsp[(4) - (4)].number) / 1024.0));
                  }
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1467 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_TOTAL_MEM_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1474 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_SWAP_KBYTE;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (4)].real) * ((yyvsp[(4) - (4)].number) / 1024.0));
                  }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1479 "src/p.y"
    {
                    resourceset.resource_id = RESOURCE_ID_SWAP_PERCENT;
                    resourceset.operator = (yyvsp[(2) - (4)].number);
                    resourceset.limit = ((yyvsp[(3) - (4)].number) * 10);
                  }
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1486 "src/p.y"
    { 
                    resourceset.resource_id = RESOURCE_ID_CHILDREN;
                    resourceset.operator = (yyvsp[(2) - (3)].number);
                    resourceset.limit = (int) (yyvsp[(3) - (3)].number); 
                  }
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1493 "src/p.y"
    { 
                    resourceset.resource_id = (yyvsp[(1) - (3)].number);
                    resourceset.operator = (yyvsp[(2) - (3)].number);
                    resourceset.limit = (int) ((yyvsp[(3) - (3)].real) * 10.0); 
                  }
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1500 "src/p.y"
    { (yyval.number) = RESOURCE_ID_LOAD1; }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1501 "src/p.y"
    { (yyval.number) = RESOURCE_ID_LOAD5; }
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1502 "src/p.y"
    { (yyval.number) = RESOURCE_ID_LOAD15; }
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1505 "src/p.y"
    { (yyval.real) = (yyvsp[(1) - (1)].real); }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1506 "src/p.y"
    { (yyval.real) = (float) (yyvsp[(1) - (1)].number); }
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1509 "src/p.y"
    {
                    timestampset.operator = (yyvsp[(3) - (9)].number);
                    timestampset.time = ((yyvsp[(4) - (9)].number) * (yyvsp[(5) - (9)].number));
                    addeventaction(&(timestampset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addtimestamp(&timestampset, FALSE);
                  }
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1515 "src/p.y"
    {
                    timestampset.test_changes = TRUE;
                    addeventaction(&(timestampset).action, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                    addtimestamp(&timestampset, TRUE);
                  }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1522 "src/p.y"
    { (yyval.number) = OPERATOR_EQUAL; }
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1523 "src/p.y"
    { (yyval.number) = OPERATOR_GREATER; }
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1524 "src/p.y"
    { (yyval.number) = OPERATOR_LESS; }
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1525 "src/p.y"
    { (yyval.number) = OPERATOR_EQUAL; }
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1526 "src/p.y"
    { (yyval.number) = OPERATOR_NOTEQUAL; }
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1527 "src/p.y"
    { (yyval.number) = OPERATOR_NOTEQUAL; }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 1530 "src/p.y"
    { (yyval.number) = TIME_SECOND; }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1531 "src/p.y"
    { (yyval.number) = TIME_SECOND; }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1532 "src/p.y"
    { (yyval.number) = TIME_MINUTE; }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1533 "src/p.y"
    { (yyval.number) = TIME_HOUR; }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1534 "src/p.y"
    { (yyval.number) = TIME_DAY; }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1537 "src/p.y"
    { (yyval.number) = ACTION_ALERT; }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1538 "src/p.y"
    { (yyval.number) = ACTION_EXEC; }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1539 "src/p.y"
    { (yyval.number) = ACTION_EXEC; }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1540 "src/p.y"
    { (yyval.number) = ACTION_RESTART; }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1541 "src/p.y"
    { (yyval.number) = ACTION_START; }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1542 "src/p.y"
    { (yyval.number) = ACTION_STOP; }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1543 "src/p.y"
    { (yyval.number) = ACTION_UNMONITOR; }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1546 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(1) - (1)].number);
                    if ((yyvsp[(1) - (1)].number) == ACTION_EXEC && command) {
                      command1 = command;
                      command = NULL;
                    }
                  }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1555 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(1) - (1)].number);
                    if ((yyvsp[(1) - (1)].number) == ACTION_EXEC && command) {
                      command2 = command;
                      command = NULL;
                    }
                  }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1565 "src/p.y"
    {
                    rate1.count  = (yyvsp[(1) - (2)].number);
                    rate1.cycles = (yyvsp[(1) - (2)].number);
                    if (rate1.cycles < 1 || rate1.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                  }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1571 "src/p.y"
    {
                    rate1.count  = (yyvsp[(1) - (3)].number);
                    rate1.cycles = (yyvsp[(2) - (3)].number);
                    if (rate1.cycles < 1 || rate1.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                    if (rate1.count < 1 || rate1.count > rate1.cycles)
                      yyerror2("the number of events must be bigger then 0 and less than poll cycles");
                  }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1582 "src/p.y"
    {
                    rate2.count  = (yyvsp[(1) - (2)].number);
                    rate2.cycles = (yyvsp[(1) - (2)].number);
                    if (rate2.cycles < 1 || rate2.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                  }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1588 "src/p.y"
    {
                    rate2.count  = (yyvsp[(1) - (3)].number);
                    rate2.cycles = (yyvsp[(2) - (3)].number);
                    if (rate2.cycles < 1 || rate2.cycles > BITMAP_MAX)
                      yyerror2("the number of cycles must be between 1 and %d", BITMAP_MAX);
                    if (rate2.count < 1 || rate2.count > rate2.cycles)
                      yyerror2("the number of events must be bigger then 0 and less than poll cycles");
                  }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1598 "src/p.y"
    {
                    (yyval.number) = ACTION_ALERT;
                  }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1601 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1604 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1607 "src/p.y"
    {
                    (yyval.number) = (yyvsp[(6) - (6)].number);
                  }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 1612 "src/p.y"
    {
                    addeventaction(&(checksumset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addchecksum(&checksumset);
                  }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 1617 "src/p.y"
    {
                    snprintf(checksumset.hash, sizeof(checksumset.hash), "%s", (yyvsp[(6) - (10)].string));
                    FREE((yyvsp[(6) - (10)].string));
                    addeventaction(&(checksumset).action, (yyvsp[(9) - (10)].number), (yyvsp[(10) - (10)].number));
                    addchecksum(&checksumset);
                  }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 1623 "src/p.y"
    {
                    checksumset.test_changes = TRUE;
                    addeventaction(&(checksumset).action, (yyvsp[(7) - (7)].number), ACTION_IGNORE);
                    addchecksum(&checksumset);
                  }
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 1629 "src/p.y"
    { checksumset.type = HASH_UNKNOWN; }
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 1630 "src/p.y"
    { checksumset.type = HASH_MD5; }
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 1631 "src/p.y"
    { checksumset.type = HASH_SHA1; }
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 1634 "src/p.y"
    {
                    filesystemset.resource = RESOURCE_ID_INODE;
                    filesystemset.operator = (yyvsp[(3) - (8)].number);
                    filesystemset.limit_absolute = (yyvsp[(4) - (8)].number);
                    addeventaction(&(filesystemset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 1641 "src/p.y"
    {
                    filesystemset.resource = RESOURCE_ID_INODE;
                    filesystemset.operator = (yyvsp[(3) - (9)].number);
                    filesystemset.limit_percent = (int)((yyvsp[(4) - (9)].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 1650 "src/p.y"
    {
                    if (!filesystem_usage(current->inf, current->path))
                      yyerror2("cannot read usage of filesystem %s", current->path);
                    filesystemset.resource = RESOURCE_ID_SPACE;
                    filesystemset.operator = (yyvsp[(3) - (9)].number);
                    filesystemset.limit_absolute = (int)((float)(yyvsp[(4) - (9)].real) / (float)current->inf->priv.filesystem.f_bsize * (float)(yyvsp[(5) - (9)].number));
                    addeventaction(&(filesystemset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 1659 "src/p.y"
    {
                    filesystemset.resource = RESOURCE_ID_SPACE;
                    filesystemset.operator = (yyvsp[(3) - (9)].number);
                    filesystemset.limit_percent = (int)((yyvsp[(4) - (9)].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addfilesystem(&filesystemset);
                  }
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 1668 "src/p.y"
    {
                    seteventaction(&(current)->action_FSFLAG, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                  }
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 1673 "src/p.y"
    { (yyval.number) = UNIT_BYTE; }
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 1674 "src/p.y"
    { (yyval.number) = UNIT_BYTE; }
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 1675 "src/p.y"
    { (yyval.number) = UNIT_KILOBYTE; }
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 1676 "src/p.y"
    { (yyval.number) = UNIT_MEGABYTE; }
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 1677 "src/p.y"
    { (yyval.number) = UNIT_GIGABYTE; }
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 1680 "src/p.y"
    {
                    permset.perm = check_perm((yyvsp[(4) - (8)].number));
                    addeventaction(&(permset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addperm(&permset);
                  }
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 1687 "src/p.y"
    {
                    matchset.ignore = FALSE;
                    matchset.match_path = (yyvsp[(4) - (7)].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, (yyvsp[(7) - (7)].number));
                    FREE((yyvsp[(4) - (7)].string)); 
                  }
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 1694 "src/p.y"
    {
                    matchset.ignore = FALSE;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[(4) - (7)].string);
                    addmatch(&matchset, (yyvsp[(7) - (7)].number), 0);
                  }
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 1700 "src/p.y"
    {
                    matchset.ignore = TRUE;
                    matchset.match_path = (yyvsp[(4) - (4)].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, ACTION_IGNORE);
                    FREE((yyvsp[(4) - (4)].string)); 
                  }
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 1707 "src/p.y"
    {
                    matchset.ignore = TRUE;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[(4) - (4)].string);
                    addmatch(&matchset, ACTION_IGNORE, 0);
                  }
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 1715 "src/p.y"
    {
                    matchset.not = FALSE;
                  }
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 1718 "src/p.y"
    {
                    matchset.not = TRUE;
                  }
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 1724 "src/p.y"
    {
                    sizeset.operator = (yyvsp[(3) - (9)].number);
                    sizeset.size = ((unsigned long long)(yyvsp[(4) - (9)].number) * (yyvsp[(5) - (9)].number));
                    addeventaction(&(sizeset).action, (yyvsp[(8) - (9)].number), (yyvsp[(9) - (9)].number));
                    addsize(&sizeset);
                  }
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 1730 "src/p.y"
    {
                    sizeset.test_changes = TRUE;
                    addeventaction(&(sizeset).action, (yyvsp[(6) - (6)].number), ACTION_IGNORE);
                    addsize(&sizeset);
                  }
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 1737 "src/p.y"
    {
                    uidset.uid = get_uid((yyvsp[(4) - (8)].string), 0);
                    addeventaction(&(uidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    adduid(&uidset);
                    FREE((yyvsp[(4) - (8)].string));
                  }
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 1743 "src/p.y"
    {
                    uidset.uid = get_uid(NULL, (yyvsp[(4) - (8)].number));
                    addeventaction(&(uidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    adduid(&uidset);
                  }
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 1750 "src/p.y"
    {
                    gidset.gid = get_gid((yyvsp[(4) - (8)].string), 0);
                    addeventaction(&(gidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addgid(&gidset);
                    FREE((yyvsp[(4) - (8)].string));
                  }
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 1756 "src/p.y"
    {
                    gidset.gid = get_gid(NULL, (yyvsp[(4) - (8)].number));
                    addeventaction(&(gidset).action, (yyvsp[(7) - (8)].number), (yyvsp[(8) - (8)].number));
                    addgid(&gidset);
                  }
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 1763 "src/p.y"
    { (yyval.number) = ICMP_ECHO; }
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 1766 "src/p.y"
    { mailset.reminder = 0; }
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 1767 "src/p.y"
    { mailset.reminder = (yyvsp[(2) - (2)].number); }
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 1768 "src/p.y"
    { mailset.reminder = (yyvsp[(2) - (3)].number); }
    break;



/* Line 1455 of yacc.c  */
#line 5587 "src/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1771 "src/p.y"



/* -------------------------------------------------------- Parser interface */


/**
 * Syntactic error routine
 *
 * This routine is automatically called by the lexer!
 */
void yyerror(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogError("%s:%i: Error: %s '%s'\n", currentfile, lineno, msg, yytext);
  cfg_errflag++;

  FREE(msg);

}

/**
 * Syntactical warning routine
 */
void yywarning(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogWarning("%s:%i: Warning: %s '%s'\n", currentfile, lineno, msg, yytext);

  FREE(msg);

}

/**
 * Argument error routine
 */
void yyerror2(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogError("%s:%i: Error: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);
  cfg_errflag++;

  FREE(msg);

}

/**
 * Argument warning routine
 */
void yywarning2(const char *s, ...) {
  va_list ap;
  char *msg = NULL;

  ASSERT(s);

  va_start(ap,s);
  msg = Str_vcat(s, ap);
  va_end(ap);

  LogWarning("%s:%i: Warning: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);

  FREE(msg);

}

/*
 * The Parser hook - start parsing the control file
 * Returns TRUE if parsing succeeded, otherwise FALSE
 */
int parse(char *controlfile) {

  ASSERT(controlfile);

  servicelist = tail = current = NULL;

  if ((yyin = fopen(controlfile,"r")) == (FILE *)NULL) {
    LogError("%s: Error: cannot open the control file '%s' -- %s\n", prog, controlfile, STRERROR);
    return FALSE;
  }

  currentfile = Str_dup(controlfile);

  /* 
   * Creation of the global service list is synchronized  
   */
  LOCK(Run.mutex)
    preparse();
    yyparse();
    fclose(yyin);
    postparse();
  END_LOCK;

  FREE(currentfile);

  if (argyytext != NULL)
    FREE(argyytext);

  /*
   * Secure check the monitrc file. The run control file must have the
   * same uid as the REAL uid of this process, it must have permissions
   * no greater than 700 and it must not be a symbolic link.
   */
  if (! file_checkStat(controlfile, "control file", S_IRUSR|S_IWUSR|S_IXUSR))
    return FALSE;

  return(cfg_errflag == 0);
}


/* ----------------------------------------------------------------- Private */


/**
 * Initialize objects used by the parser.
 */
static void preparse() {
  int i;

  /* Set instance incarnation ID */
  time(&Run.incarnation);
  /* Reset lexer */
  buffer_stack_ptr        = 0;
  lineno                  = 1;
  arglineno               = 1;
  argcurrentfile          = NULL;
  argyytext               = NULL;
  /* Reset parser */
  Run.stopped             = FALSE;
  Run.dolog               = FALSE;
  Run.dohttpd             = FALSE;
  Run.doaction            = FALSE;
  Run.httpdsig            = TRUE;
  Run.dommonitcredentials = TRUE;
  Run.mmonitcredentials   = NULL;
  Run.credentials         = NULL;
  Run.httpdssl            = FALSE;
  Run.httpsslpem          = NULL;
  Run.httpsslclientpem    = NULL;
  Run.clientssl           = FALSE;
  Run.allowselfcert       = FALSE; 
  Run.mailserver_timeout  = SMTP_TIMEOUT;
  Run.bind_addr           = NULL;
  Run.eventlist           = NULL;
  Run.eventlist_dir       = NULL;
  Run.eventlist_slots     = -1;
  Run.system              = NULL;
  Run.expectbuffer        = STRLEN;
  Run.mmonits             = NULL;
  Run.maillist            = NULL;
  Run.mailservers         = NULL;
  Run.MailFormat.from     = NULL;
  Run.MailFormat.replyto  = NULL;
  Run.MailFormat.subject  = NULL;
  Run.MailFormat.message  = NULL;
  depend_list             = NULL;
  Run.handler_init        = TRUE;
#ifdef OPENSSL_FIPS  
  Run.fipsEnabled         = FALSE;
#endif
  for (i = 0; i <= HANDLER_MAX; i++)
    Run.handler_queue[i] = 0;
  /* 
   * Initialize objects
   */
  reset_uidset();
  reset_statusset();
  reset_gidset();
  reset_sizeset();
  reset_mailset();
  reset_mailserverset();
  reset_portset();
  reset_permset();
  reset_icmpset();
  reset_rateset();
  reset_filesystemset();
  reset_resourceset();
  reset_checksumset();
  reset_timestampset();
  reset_actionrateset();
}


/*
 * Check that values are reasonable after parsing
 */
static void postparse() {
        if (cfg_errflag)
                return;

        /* If defined - add the last service to the service list */
        if (current)
                addservice(current);

        /* Check that we do not start monit in daemon mode without having a poll time */
        if (!Run.polltime && (Run.isdaemon || Run.init)) {
                LogError("%s: Error: Poll time not defined. Please define poll time in the\n control file or use the -d option when starting monit\n", prog);
                cfg_errflag++;
        }

        if (Run.logfile)
                Run.dolog = TRUE;

        for (Service_T s = servicelist; s; s = s->next) {
                if (s->type == TYPE_HOST) {
                        /* Verify that a remote service has a port or an icmp list */
                        if (!s->portlist && !s->icmplist) {
                                LogError("%s: Error: 'check host' statement is incomplete: Please specify a port number to test\n or an icmp test at the remote host: '%s'\n", prog, s->name);
                                cfg_errflag++;
                        }
                } else if (s->type == TYPE_PROGRAM) {
                        /* Create the Command object */
                        s->program->C = Command_new(s->path, NULL);
                        /* Verify that a program test has a status test */
                        if (! s->statuslist) {
                                LogError("%s: Error: 'check program %s' is incomplete: Please add an 'if status != n' test\n", prog, s->name);
                                cfg_errflag++;
                        }
                }
        }

        /* Add the default general system service if not specified explicitly: service name default to hostname */
        if (! Run.system) {
                char hostname[STRLEN];
                if (Util_getfqdnhostname(hostname, sizeof(hostname))) {
                        LogError("Cannot get system hostname -- please add 'check system <name>'\n");
                        cfg_errflag++;
                }
                if (Util_existService(hostname)) {
                        LogError("'check system' not defined in control file, failed to add automatic configuration (service name %s is used already) -- please add 'check system <name>' manually\n", hostname);
                        cfg_errflag++;
                } else {
                        Run.system = createservice(TYPE_SYSTEM, Str_dup(hostname), Str_dup(""), check_system);
                        addservice(Run.system);
                }
        }

        if (Run.mmonits) {
                if (Run.dohttpd) {
                        if (Run.dommonitcredentials) {
                                Auth_T c;
                                for (c = Run.credentials; c; c = c->next) {
                                        if (c->digesttype == DIGEST_CLEARTEXT && ! c->is_readonly) {
                                                Run.mmonitcredentials = c;
                                                break;
                                        }
                                }
                                if (! Run.mmonitcredentials)
                                LogWarning("%s: Warning: M/Monit registration with credentials enabled, but no suitable credentials found in monit configuration file -- please add 'allow user:password' option to 'set httpd' statement\n", prog);
                        }
                } else
                LogWarning("%s: Warning: M/Monit enabled but no httpd allowed -- please add 'set httpd' statement\n", prog);
        }

        /* Check the sanity of any dependency graph */
        check_depend();
}


/*
 * Create a new service object and add any current objects to the
 * service list.
 */
static Service_T createservice(int type, char *name, char *value, int (*check)(Service_T s)) {
  ASSERT(name);
  ASSERT(value);

  check_name(name);

  if (current)
        addservice(current);

  NEW(current);

  current->type = type;

  NEW(current->inf);
  Util_resetInfo(current);

  if (type == TYPE_PROGRAM) {
    NEW(current->program);
    current->program->timeout = PROGRAM_TIMEOUT;
  }

  /* Set default values */
  current->monitor = MONITOR_INIT;
  current->mode    = MODE_ACTIVE;
  current->name    = name;
  current->check   = check;
  current->path    = value;

  /* Initialize general event handlers */
  addeventaction(&(current)->action_DATA,     ACTION_ALERT,     ACTION_ALERT);
  addeventaction(&(current)->action_EXEC,     ACTION_ALERT,     ACTION_ALERT);
  addeventaction(&(current)->action_INVALID,  ACTION_RESTART,   ACTION_ALERT);
  addeventaction(&(current)->action_NONEXIST, ACTION_RESTART,   ACTION_ALERT);
  addeventaction(&(current)->action_PID,      ACTION_ALERT,     ACTION_IGNORE);
  addeventaction(&(current)->action_PPID,     ACTION_ALERT,     ACTION_IGNORE);
  addeventaction(&(current)->action_FSFLAG,   ACTION_ALERT,     ACTION_IGNORE);

  /* Initialize internal event handlers */
  addeventaction(&(current)->action_MONIT_START,  ACTION_START, ACTION_IGNORE);
  addeventaction(&(current)->action_MONIT_STOP,   ACTION_STOP,  ACTION_IGNORE);
  addeventaction(&(current)->action_MONIT_RELOAD, ACTION_START, ACTION_IGNORE);
  addeventaction(&(current)->action_ACTION,       ACTION_ALERT, ACTION_IGNORE);

  gettimeofday(&current->collected, NULL);

  return current;
}


/*
 * Add a service object to the servicelist
 */
static void addservice(Service_T s) {
  ASSERT(s);

  /* Add the service to the end of the service list */
  if (tail != NULL) {
    tail->next = s;
    tail->next_conf = s;
  } else {
    servicelist = s;
    servicelist_conf = s;
  }
  tail = s;
}


/* 
 * Add entry to service group list
 */
static void addservicegroup(char *name) {
  ServiceGroup_T g;
  ServiceGroupMember_T m;

  ASSERT(name);

  /* Check if service group with the same name is defined already */
  for (g = servicegrouplist; g; g = g->next)
    if (! strcasecmp(g->name, name))
      break;

  if (! g) {
    NEW(g);
    g->name = Str_dup(name);
    g->next = servicegrouplist;
    servicegrouplist = g;
  }

  NEW(m);
  m->name = Str_dup(current->name);
  m->next = g->members;
  g->members = m;
}


/* 
 * Add a dependant entry to the current service dependant list
 *
 */
static void adddependant(char *dependant) {
  Dependant_T d; 

  ASSERT(dependant);

  NEW(d);

  if (current->dependantlist != NULL)
    d->next = current->dependantlist;

  d->dependant = dependant;
  current->dependantlist = d;

}


/*
 * Add the given mailaddress with the appropriate alert notification
 * values and mail attributes to the given mailinglist.
 */
static void addmail(char *mailto, Mail_T f, Mail_T *l) {
  Mail_T m;

  ASSERT(mailto);

  NEW(m);
  m->to       = mailto;
  m->from     = f->from;
  m->subject  = f->subject;
  m->message  = f->message;
  m->events   = f->events;
  m->reminder = f->reminder;

  m->next = *l;
  *l = m;

  reset_mailset();
}


/*
 * Add the given portset to the current service's portlist
 */
static void addport(Port_T port) {
  Port_T p;

  ASSERT(port);

  NEW(p);
  p->port               = port->port;
  p->type               = port->type;
  p->socket             = port->socket;
  p->family             = port->family;
  p->action             = port->action;
  p->timeout            = port->timeout;
  p->retry              = port->retry;
  p->request            = port->request;
  p->generic            = port->generic;
  p->protocol           = port->protocol;
  p->pathname           = port->pathname;
  p->hostname           = port->hostname;
  p->url_request        = port->url_request;
  p->request_checksum   = port->request_checksum;
  p->request_hostheader = port->request_hostheader;
  memcpy(&p->ApacheStatus, &port->ApacheStatus, sizeof(struct apache_status));

  if (p->request_checksum) {
    cleanup_hash_string(p->request_checksum);
    if (strlen(p->request_checksum) == 32)
      p->request_hashtype = HASH_MD5;
    else if (strlen(p->request_checksum) == 40)
      p->request_hashtype = HASH_SHA1;
    else
      yyerror2("invalid checksum [%s]", p->request_checksum);
  } else
    p->request_hashtype = 0;

  if (port->SSL.use_ssl == TRUE) {
    if (!have_ssl()) {
      yyerror("ssl check cannot be activated. SSL is not supported");
    } else {
      if (port->SSL.certmd5 != NULL) {
	p->SSL.certmd5 = port->SSL.certmd5;
	cleanup_hash_string(p->SSL.certmd5);
      }
      p->SSL.use_ssl = TRUE;
      p->SSL.version = port->SSL.version;
    }
  }
  p->maxforward = port->maxforward;
  p->next = current->portlist;
  current->portlist = p;

  reset_portset();

}


/*
 * Add a new resource object to the current service resource list
 */
static void addresource(Resource_T rr) {
  Resource_T r;

  ASSERT(rr);

  NEW(r);
  if (! Run.doprocess)
    yyerror("Cannot activate service check. The process status engine was disabled. On certain systems you must run monit as root to utilize this feature)\n");
  r->resource_id = rr->resource_id;
  r->limit       = rr->limit;
  r->action      = rr->action;
  r->operator    = rr->operator;
  r->next        = current->resourcelist;

  current->resourcelist = r;
  reset_resourceset();
}


/*
 * Add a new file object to the current service timestamp list
 */
static void addtimestamp(Timestamp_T ts, int notime) {
  Timestamp_T t;

  ASSERT(ts);

  NEW(t);
  t->operator     = ts->operator;
  t->time         = ts->time;
  t->action       = ts->action;
  t->test_changes = ts->test_changes;

  if (t->test_changes || notime) {
    if (! file_exist(current->path)) {
      DEBUG("%s: Debug: the path '%s' used in the TIMESTAMP statement refer to a non-existing object\n", prog, current->path);
    } else if (!(t->timestamp = file_getTimestamp(current->path, S_IFDIR|S_IFREG))) {
      yyerror2("cannot get the timestamp for '%s'", current->path);
    }
  }

  t->next = current->timestamplist;
  current->timestamplist = t;

  reset_timestampset();
}


/*
 * Add a new object to the current service actionrate list
 */
static void addactionrate(ActionRate_T ar) {
  ActionRate_T a;

  ASSERT(ar);

  if (ar->count > ar->cycle)
    yyerror2("the number of restarts must be less than poll cycles");
  if (ar->count <= 0 || ar->cycle <= 0)
    yyerror2("zero or negative values not allowed in a action rate statement");

  NEW(a);
  a->count  = ar->count;
  a->cycle  = ar->cycle;
  a->action = ar->action;

  a->next = current->actionratelist;
  current->actionratelist = a;

  reset_actionrateset();
}



/*
 * Add a new Size object to the current service size list
 */
static void addsize(Size_T ss) {
  Size_T s;
  struct stat buf;

  ASSERT(ss);

  NEW(s);
  s->operator     = ss->operator;
  s->size         = ss->size;
  s->action       = ss->action;
  s->test_changes = ss->test_changes;
  /* Get the initial size for future comparision, if the file exists */
  if (s->test_changes) {
    s->test_changes_ok = !stat(current->path, &buf);
    if (s->test_changes_ok)
      s->size = (unsigned long long)buf.st_size;
  }

  s->next = current->sizelist;
  current->sizelist = s;

  reset_sizeset();
}


/*
 * Add a new Uptime object to the current service uptime list
 */
static void adduptime(Uptime_T uu) {
  Uptime_T u;

  ASSERT(uu);

  NEW(u);
  u->operator = uu->operator;
  u->uptime = uu->uptime;
  u->action = uu->action;

  u->next = current->uptimelist;
  current->uptimelist = u;

  reset_uptimeset();
}


/*
 * Set Checksum object in the current service
 */
static void addchecksum(Checksum_T cs) {

  int len;
  Checksum_T c;

  ASSERT(cs);

  cs->test_changes_ok = TRUE;

  if (! *cs->hash) {
    if (cs->type == HASH_UNKNOWN)
      cs->type = DEFAULT_HASH;
    if ( !(Util_getChecksum(current->path, cs->type, cs->hash, sizeof(cs->hash)))) {
      if (cs->test_changes == TRUE) {
        /* If the file doesn't exist and we're checking for checksum changes, set dummy value */
        cs->test_changes_ok = FALSE;
        snprintf(cs->hash, sizeof(cs->hash), "00000000000000000000000000000000");
      } else {
        yyerror2("cannot compute a checksum for file %s", current->path);
        reset_checksumset();
        return;
      }
    }
  }

  len = cleanup_hash_string(cs->hash);

  if (cs->type == HASH_UNKNOWN) {
    if (len == 32) {
      cs->type = HASH_MD5;
    } else if (len == 40) {
      cs->type = HASH_SHA1;
    } else {
      yyerror2("invalid checksum [%s] for file %s", cs->hash, current->path);
      reset_checksumset();
      return;
    }
  } else if (( cs->type == HASH_MD5 && len!=32 ) || ( cs->type == HASH_SHA1 && len != 40 )) {
    yyerror2("invalid checksum [%s] for file %s", cs->hash, current->path);
    reset_checksumset();
    return;
  }

  NEW(c);

  c->type            = cs->type;
  c->test_changes    = cs->test_changes;
  c->test_changes_ok = cs->test_changes_ok;
  c->action          = cs->action;
  snprintf(c->hash, sizeof(c->hash), "%s", cs->hash);

  current->checksum = c;

  reset_checksumset();

}


/*
 * Set Perm object in the current service
 */
static void addperm(Perm_T ps) {
  Perm_T p;

  ASSERT(ps);

  NEW(p);
  p->perm       = ps->perm;
  p->action     = ps->action;
  current->perm = p;
  reset_permset();

}


static void appendmatch(Match_T *list, Match_T item) {
  if (*list) {
    /* Find the end of the list (keep the same patterns order as in the config file) */
    Match_T last;
    for (last = *list; last->next; last = last->next)
      ;
    last->next = item;
  } else {
    *list = item;
  }
}


/*
 * Set Match object in the current service
 */
static void addmatch(Match_T ms, int actionnumber, int linenumber) {
  Match_T m;
  int     reg_return;

  ASSERT(ms);

  NEW(m);
#ifdef HAVE_REGEX_H
  NEW(m->regex_comp);
#endif

  m->match_string = ms->match_string;
  m->match_path   = ms->match_path ? Str_dup(ms->match_path) : NULL;
  m->action       = ms->action;
  m->not          = ms->not;
  m->ignore       = ms->ignore;
  m->next         = NULL;

  addeventaction(&(m->action), actionnumber, ACTION_IGNORE);

#ifdef HAVE_REGEX_H
  reg_return = regcomp(m->regex_comp, ms->match_string, REG_NOSUB|REG_EXTENDED);

  if (reg_return != 0) {
    char errbuf[STRLEN];
    regerror(reg_return, ms->regex_comp, errbuf, STRLEN);
    if (m->match_path != NULL) 
      yyerror2("regex parsing error:%s on line %i of", errbuf, linenumber);
    else
      yyerror2("regex parsing error:%s", errbuf);
  }
#endif
  appendmatch(m->ignore ? &current->matchignorelist : &current->matchlist, m);
}


static void addmatchpath(Match_T ms, int actionnumber) {

  FILE *handle;
  command_t savecommand = NULL;
  char buf[2048];
  int linenumber = 0;

  ASSERT(ms->match_path);

  handle = fopen(ms->match_path, "r");
  if (handle == NULL) {
    yyerror2("cannot read regex match file (%s)", ms->match_path);
    return;
  }

  while (!feof(handle)) {
    size_t len;

    linenumber++;

    if (! fgets(buf, 2048, handle))
      continue;

    len = strlen(buf);

    if (len == 0 || buf[0] == '\n')
      continue;

    if (buf[len-1] == '\n')
      buf[len-1] = 0;

    ms->match_string = Str_dup(buf);

    /* The addeventaction() called from addmatch() will reset the
     * command1 to NULL, but we need to duplicate the command for
     * each line, thus need to save it here */
    if (actionnumber == ACTION_EXEC) {
      if (command1 == NULL) {
        ASSERT(savecommand);
        command1 = savecommand;
      }
      savecommand = copycommand(command1);
    }

    addmatch(ms, actionnumber, linenumber);
  }

  if (actionnumber == ACTION_EXEC && savecommand)
    gccmd(&savecommand);

  fclose(handle);
}


/*
 * Set exit status test object in the current service
 */
static void addstatus(Status_T status) {
        Status_T s;
        ASSERT(status);
        NEW(s);
        s->return_value = status->return_value;
        s->operator = status->operator;
        s->action = status->action;
        s->next = current->statuslist;
        current->statuslist = s;

        reset_statusset();
}


/*
 * Set Uid object in the current service
 */
static void adduid(Uid_T us) {
  Uid_T u;

  ASSERT(us);

  NEW(u);
  u->uid       = us->uid;
  u->action    = us->action;
  current->uid = u;
  reset_uidset();
}


/*
 * Set Gid object in the current service
 */
static void addgid(Gid_T gs) {
  Gid_T g;

  ASSERT(gs);

  NEW(g);
  g->gid       = gs->gid;
  g->action    = gs->action;
  current->gid = g;
  reset_gidset();
}


/*
 * Add a new filesystem to the current service's filesystem list
 */
static void addfilesystem(Filesystem_T ds) {
  Filesystem_T dev;

  ASSERT(ds);

  NEW(dev);
  dev->resource           = ds->resource;
  dev->operator           = ds->operator;
  dev->limit_absolute     = ds->limit_absolute;
  dev->limit_percent      = ds->limit_percent;
  dev->action             = ds->action;

  dev->next               = current->filesystemlist;
  current->filesystemlist = dev;

  reset_filesystemset();

}


/*
 * Add a new icmp object to the current service's icmp list
 */
static void addicmp(Icmp_T is) {
  Icmp_T icmp;

  ASSERT(is);

  NEW(icmp);
  icmp->type         = is->type;      
  icmp->count        = is->count;
  icmp->timeout      = is->timeout;
  icmp->action       = is->action;
  icmp->is_available = FALSE;
  icmp->response     = -1;

  icmp->next         = current->icmplist;
  current->icmplist  = icmp;

  reset_icmpset();
}


/*
 * Set EventAction object
 */
static void addeventaction(EventAction_T *_ea, int failed, int succeeded) {
  EventAction_T ea;

  ASSERT(_ea);

  NEW(ea);
  NEW(ea->failed);
  NEW(ea->succeeded);

  ea->failed->id     = failed;
  ea->failed->count  = rate1.count;
  ea->failed->cycles = rate1.cycles;
  if (failed == ACTION_EXEC) {
    ASSERT(command1);
    ea->failed->exec = command1;
    command1 = NULL;
  }

  ea->succeeded->id     = succeeded;
  ea->succeeded->count  = rate2.count;
  ea->succeeded->cycles = rate2.cycles;
  if (succeeded == ACTION_EXEC) {
    ASSERT(command2);
    ea->succeeded->exec = command2;
    command2 = NULL;
  }
  *_ea = ea;
  reset_rateset();
}


/*
 * Redefine EventAction object (used for default action overloading)
 */
static void seteventaction(EventAction_T *_ea, int failed, int succeeded) {
  EventAction_T ea = *_ea;

  ASSERT(ea);
  ASSERT(ea->failed);
  ASSERT(ea->succeeded);

  ea->failed->id     = failed;
  ea->failed->count  = rate1.count;
  ea->failed->cycles = rate1.cycles;
  if (failed == ACTION_EXEC) {
    ASSERT(command1);
    ea->failed->exec = command1;
    command1 = NULL;
  }

  ea->succeeded->id     = succeeded;
  ea->succeeded->count  = rate2.count;
  ea->succeeded->cycles = rate2.cycles;
  if (succeeded == ACTION_EXEC) {
    ASSERT(command2);
    ea->succeeded->exec = command2;
    command2 = NULL;
  }
}


/*
 * Add a generic protocol handler to 
 */
static void addgeneric(Port_T port, char *send, char *expect) {
  Generic_T g = port->generic;

  if (g == NULL) {
    NEW(g);
    port->generic = g;
  } else {
    while (g->next != NULL)
      g = g->next;
    NEW(g->next);
    g = g->next;
  }

  if (send != NULL) {
    g->send = Str_dup(send);
    g->expect = NULL;
  } else if (expect != NULL) {
#ifdef HAVE_REGEX_H

    int   reg_return;
    NEW(g->expect);
    reg_return = regcomp(g->expect, expect, REG_NOSUB|REG_EXTENDED);
    if (reg_return != 0) {
      char errbuf[STRLEN];
      regerror(reg_return, g->expect, errbuf, STRLEN);
      yyerror2("regex parsing error:%s", errbuf);
    }
#else
    g->expect = Str_dup(expect);
#endif
    g->send = NULL;
  } 
}


/*
 * Add the current command object to the current service object's
 * start or stop program.
 */
static void addcommand(int what, unsigned timeout) {

  switch(what) {
          case START:   current->start = command; break;
          case STOP:    current->stop = command; break;
          case RESTART: current->restart = command; break;
  }

  command->timeout = timeout;

  command = NULL;

}


/*
 * Add a new argument to the argument list
 */
static void addargument(char *argument) {

  ASSERT(argument);

  if (! command) {

    NEW(command);
    check_exec(argument);

  }

  command->arg[command->length++] = argument;
  command->arg[command->length] = NULL;

  if (command->length >= ARGMAX)
    yyerror("exceeded maximum number of program arguments");

}


/*
 * Setup a url request for the current port object
 */
static void prepare_urlrequest(URL_T U) {

  ASSERT(U);

  portset.protocol = Protocol_get(Protocol_HTTP);

  if (urlrequest == NULL)
    NEW(urlrequest);
  urlrequest->url = U;
  portset.hostname = Str_dup(U->hostname);
  check_hostname(portset.hostname);
  portset.port = U->port;
  portset.url_request = urlrequest;
  portset.type = SOCK_STREAM;
  portset.request = Str_cat("%s%s%s", U->path, U->query ? "?" : "", U->query ? U->query : "");
  /* Only the HTTP protocol is supported for URLs.
     See also the lexer if this is to be changed in
     the future */
  portset.protocol = Protocol_get(Protocol_HTTP);
  if (IS(U->protocol, "https"))
    portset.SSL.use_ssl = TRUE;

}


/*
 * Set the url request for a port
 */
static void  seturlrequest(int operator, char *regex) {

  ASSERT(regex);

  if (! urlrequest)
    NEW(urlrequest);
  urlrequest->operator = operator;
#ifdef HAVE_REGEX_H
  {    
    int reg_return;
    NEW(urlrequest->regex);
    reg_return = regcomp(urlrequest->regex, regex, REG_NOSUB|REG_EXTENDED);
    if (reg_return != 0) {
      char errbuf[STRLEN];
      regerror(reg_return, urlrequest->regex, errbuf, STRLEN);
      yyerror2("regex parsing error: %s", errbuf);
    }
  }
#else
  urlrequest->regex = Str_dup(regex);
#endif

}


/*
 * Add a new data recipient server to the mmonit server list
 */
static void addmmonit(URL_T url, int timeout, int sslversion, char *certmd5) {
  Mmonit_T c;

  ASSERT(url);

  NEW(c);
  c->url = url;
  if (!strcmp(c->url->protocol, "https")) {
    if (!have_ssl()) {
      yyerror("ssl check cannot be activated. SSL is not supported");
    } else {
      c->ssl.use_ssl = TRUE;
      c->ssl.version = (sslversion == SSL_VERSION_NONE) ? SSL_VERSION_AUTO : sslversion;
      if (certmd5) {
	c->ssl.certmd5 = certmd5;
	cleanup_hash_string(c->ssl.certmd5);
      }
    }
  }
  c->timeout = timeout;
  c->next = NULL;

  if (Run.mmonits) {
    Mmonit_T C;
    for (C = Run.mmonits; C->next; C = C->next)
      /* Empty */ ;
    C->next = c;
  } else {
    Run.mmonits = c;
  }
}


/*
 * Add a new smtp server to the mail server list
 */
static void addmailserver(MailServer_T mailserver) {

  MailServer_T s;

  ASSERT(mailserver->host);

  NEW(s);
  s->host        = mailserver->host;
  s->port        = mailserver->port;
  s->username    = mailserver->username;
  s->password    = mailserver->password;
  s->ssl.use_ssl = mailserver->ssl.use_ssl;
  s->ssl.version = mailserver->ssl.version;
  s->ssl.certmd5 = mailserver->ssl.certmd5;

  s->next = NULL;

  if (Run.mailservers) {
    MailServer_T l;
    for (l = Run.mailservers; l->next; l = l->next) /* empty */;
    l->next = s;
  } else {
    Run.mailservers = s;
  }

  reset_mailserverset();
}


/*
 * Return uid if found on the system. If the parameter user is NULL
 * the uid parameter is used for looking up the user id on the system,
 * otherwise the user parameter is used.
 */
static uid_t get_uid(char *user, uid_t uid) {
  struct passwd *pwd;

  if (user) {
    pwd = getpwnam(user);

    if (pwd == NULL) {
      yyerror2("requested user not found on the system");
      return(0);
    }

  } else {

    if ( (pwd = getpwuid(uid)) == NULL ) {
      yyerror2("requested uid not found on the system");
      return(0);
    }
  }

  return(pwd->pw_uid);

}


/*
 * Return gid if found on the system. If the parameter group is NULL
 * the gid parameter is used for looking up the group id on the system,
 * otherwise the group parameter is used.
 */
static gid_t get_gid(char *group, gid_t gid) {
  struct group *grd;

  if (group) {
    grd = getgrnam(group);

    if (grd == NULL) {
      yyerror2("requested group not found on the system");
      return(0);
    }

  } else {

    if ( (grd = getgrgid(gid)) == NULL ) {
      yyerror2("requested gid not found on the system");
      return(0);
    }

  }

  return(grd->gr_gid);

}


/*
 * Add a new user id to the current command object.
 */
static void addeuid(uid_t uid) {
  if (!getuid()) {
    command->has_uid = TRUE;
    command->uid = uid;
  } else
    yyerror("uid statement requires root privileges");
}


/*
 * Add a new group id to the current command object.
 */
static void addegid(gid_t gid) {
  if (!getuid()) {
    command->has_gid = TRUE;
    command->gid = gid;
  } else
    yyerror("gid statement requires root privileges");
}


/*
 * Reset the logfile if changed
 */
static void setlogfile(char *logfile) {
  if (Run.logfile) {
    if (IS(Run.logfile, logfile)) {
      FREE(logfile);
      return;
    } else
      FREE(Run.logfile);
  }
  Run.logfile = logfile;
}


/*
 * Reset the pidfile if changed
 */
static void setpidfile(char *pidfile) {
  if (Run.pidfile) {
    if (IS(Run.pidfile, pidfile)) {
      FREE(pidfile);
      return;
    } else
      FREE(Run.pidfile);
  }
  Run.pidfile = pidfile;
}


/*
 * Read a apache htpasswd file and add credentials found for username
 */
static void addhtpasswdentry(char *filename, char *username, int dtype) {
  char *ht_username = NULL;
  char *ht_passwd = NULL;
  char buf[STRLEN];
  FILE *handle = NULL;
  int credentials_added = 0;

  ASSERT(filename);

  handle = fopen(filename, "r");

  if ( handle == NULL ) {
    if (username != NULL)
      yyerror2("cannot read htpasswd (%s)", filename);
    else
      yyerror2("cannot read htpasswd", filename);
    return;
  }

  while (!feof(handle)) {
    char *colonindex = NULL;
    int i;

    if (! fgets(buf, STRLEN, handle))
      continue;

    /* strip trailing non visible characters */
    for (i = (int)strlen(buf)-1; i >= 0; i--) {
      if ( buf[i] == ' '  || buf[i] == '\r' || buf[i] == '\n' || buf[i] == '\t' )
        buf[i] ='\0';
      else
        break;
    }

    if ( NULL == (colonindex = strchr(buf, ':')))
      continue;

    ht_passwd = Str_dup(colonindex+1);
    *colonindex = '\0';

    /* In case we have a file in /etc/passwd or /etc/shadow style we
     *  want to remove ":.*$" and Crypt and MD5 hashed dont have a colon
     */ 

    if ( (NULL != (colonindex = strchr(ht_passwd, ':'))) && ( dtype != DIGEST_CLEARTEXT) )
      *colonindex = '\0';

    ht_username = Str_dup(buf);

    if (username == NULL) {
      if (addcredentials(ht_username, ht_passwd, dtype, FALSE))
        credentials_added++;
    } else if (strcmp(username, ht_username) == 0)  {
      if (addcredentials(ht_username, ht_passwd, dtype, FALSE))
        credentials_added++;
    } else {
      FREE(ht_passwd);
      FREE(ht_username);
    }
  }

  if (credentials_added == 0) {
    if ( username == NULL )
      yywarning2("htpasswd file (%s) has no usable credentials", filename);
    else
      yywarning2("htpasswd file (%s) has no usable credentials for user %s", filename, username);
  }
  fclose(handle);
}


#ifdef HAVE_LIBPAM
static void addpamauth(char* groupname, int readonly) {
  Auth_T c = NULL;
  Auth_T prev = NULL;

  ASSERT(groupname);

  if (Run.credentials == NULL)
    NEW(Run.credentials);

  c = Run.credentials;
  do {
    if (c->groupname != NULL && IS(c->groupname, groupname)) {
      yywarning2("PAM group %s was added already, entry ignored", groupname);
      FREE(groupname);
      return;
    }
    prev = c;
    c = c->next;
  } while (c != NULL);

  NEW(prev->next);
  c = prev->next;

  c->next        = NULL;
  c->uname       = NULL;
  c->passwd      = NULL;
  c->groupname   = groupname;
  c->digesttype  = DIGEST_PAM;
  c->is_readonly = readonly;

  DEBUG("%s: Adding PAM group '%s'.\n", prog, groupname); 

  return;
}
#endif


/*
 * Add Basic Authentication credentials
 */
static int addcredentials(char *uname, char *passwd, int dtype, int readonly) {
  Auth_T c;

  ASSERT(uname);
  ASSERT(passwd);

  if (Run.credentials == NULL) {
    NEW(Run.credentials);
    c = Run.credentials;
  } else {

    if (Util_getUserCredentials(uname) != NULL) {
      yywarning2("credentials for user %s were already added, entry ignored", uname);
      FREE(uname);
      FREE(passwd);
      return FALSE;
    }

    c = Run.credentials;

    while ( c->next != NULL )
      c = c->next;

    NEW(c->next);
    c = c->next;

  }

  c->next        = NULL;
  c->uname       = uname;
  c->passwd      = passwd;
  c->groupname   = NULL;
  c->digesttype  = dtype;
  c->is_readonly = readonly;

  DEBUG("%s: Debug: Adding credentials for user '%s'.\n", prog, uname); 

  return TRUE;

}


/*
 * Set the syslog and the facilities to be used
 */
static void setsyslog(char *facility) {

  if (!Run.logfile || ihp.logfile) {
    ihp.logfile = TRUE;
    setlogfile(Str_dup("syslog"));
    Run.use_syslog = TRUE;
    Run.dolog = TRUE;
  }

  if (facility) {
    if (IS(facility,"log_local0"))
      Run.facility = LOG_LOCAL0;
    else if (IS(facility, "log_local1"))
      Run.facility = LOG_LOCAL1;
    else if (IS(facility, "log_local2"))
      Run.facility = LOG_LOCAL2;
    else if (IS(facility, "log_local3"))
      Run.facility = LOG_LOCAL3;
    else if (IS(facility, "log_local4"))
      Run.facility = LOG_LOCAL4;
    else if (IS(facility, "log_local5"))
      Run.facility = LOG_LOCAL5;
    else if (IS(facility, "log_local6"))
      Run.facility = LOG_LOCAL6;
    else if (IS(facility, "log_local7"))
      Run.facility = LOG_LOCAL7;
    else if (IS(facility, "log_daemon"))
      Run.facility = LOG_DAEMON;
    else
      yyerror2("invalid syslog facility");
  } else {
    Run.facility = LOG_USER;
  }

}


/*
 * Reset the current mailset for reuse
 */
static void reset_mailset() {
  memset(&mailset, 0, sizeof(struct mymail));
}


/*
 * Reset the mailserver set to default values
 */
static void reset_mailserverset() {
  memset(&mailserverset, 0, sizeof(struct mymailserver));
  mailserverset.port = PORT_SMTP;
  mailserverset.ssl.use_ssl = FALSE;
  mailserverset.ssl.version = SSL_VERSION_AUTO;
}


/*
 * Reset the Port set to default values
 */
static void reset_portset() {
  memset(&portset, 0, sizeof(struct myport));
  portset.socket = -1;
  portset.type = SOCK_STREAM;
  portset.family = AF_INET;
  portset.SSL.version = SSL_VERSION_AUTO;
  portset.timeout = NET_TIMEOUT;
  portset.retry = 1;
  portset.maxforward = 70;
  urlrequest = NULL;
}


/*
 * Reset the Proc set to default values
 */
static void reset_resourceset() {
  resourceset.resource_id = 0;
  resourceset.limit = 0;
  resourceset.action = NULL;
  resourceset.operator = OPERATOR_EQUAL;
}


/*
 * Reset the Timestamp set to default values
 */
static void reset_timestampset() {
  timestampset.operator = OPERATOR_EQUAL;
  timestampset.time = 0;
  timestampset.test_changes = FALSE;
  timestampset.action = NULL;
}


/*
 * Reset the ActionRate set to default values
 */
static void reset_actionrateset() {
  actionrateset.count = 0;
  actionrateset.cycle = 0;
  actionrateset.action = NULL;
}


/*
 * Reset the Size set to default values
 */
static void reset_sizeset() {
  sizeset.operator = OPERATOR_EQUAL;
  sizeset.size = 0;
  sizeset.test_changes = FALSE;
  sizeset.action = NULL;
}


/*
 * Reset the Uptime set to default values
 */
static void reset_uptimeset() {
  uptimeset.operator = OPERATOR_EQUAL;
  uptimeset.uptime = 0;
  uptimeset.action = NULL;
}


/*
 * Reset the Checksum set to default values
 */
static void reset_checksumset() {
  checksumset.type         = HASH_UNKNOWN;
  checksumset.test_changes = FALSE;
  checksumset.action       = NULL;
  *checksumset.hash        = 0;
}


/*
 * Reset the Perm set to default values
 */
static void reset_permset() {
  permset.perm = 0;
  permset.action = NULL;
}


/*
 * Reset the Status set to default values
 */
static void reset_statusset() {
        statusset.return_value = 0;
        statusset.operator = OPERATOR_EQUAL;
        statusset.action = NULL;
}


/*
 * Reset the Uid set to default values
 */
static void reset_uidset() {
  uidset.uid = 0;
  uidset.action = NULL;
}


/*
 * Reset the Gid set to default values
 */
static void reset_gidset() {
  gidset.gid = 0;
  gidset.action = NULL;
}


/*
 * Reset the Filesystem set to default values
 */
static void reset_filesystemset() {
  filesystemset.resource = 0;
  filesystemset.operator = OPERATOR_EQUAL;
  filesystemset.limit_absolute = -1;
  filesystemset.limit_percent = -1;
  filesystemset.action = NULL;
}


/*
 * Reset the ICMP set to default values
 */
static void reset_icmpset() {
  icmpset.type = ICMP_ECHO;
  icmpset.count = ICMP_ATTEMPT_COUNT;
  icmpset.timeout = NET_TIMEOUT;
  icmpset.action = NULL;
}


/*
 * Reset the Rate set to default values
 */
static void reset_rateset() {
  rate1.count  = 1;
  rate1.cycles = 1;

  rate2.count  = 1;
  rate2.cycles = 1;
}


/* ---------------------------------------------------------------- Checkers */


/*
 * Check for unique service name
 */
static void check_name(char *name) {
  ASSERT(name);

  if (Util_existService(name) || (current && IS(name, current->name)))
    yyerror2("service name conflict, %s already defined", name);
  if (name && *name == '/')		
          yyerror2("service name '%s' must not start with '/' -- ", name);	
}


/*
 * Permission statement semantic check
 */
static int check_perm(int perm) {
  int result;
  char *status;
  char buf[STRLEN];

  snprintf(buf, STRLEN, "%d", perm);

  result = (int)strtol(buf, &status, 8);

  if ( *status != '\0' || result < 0 || result > 07777 )
    yyerror2("permission statements must have an octal value between 0 and 7777");

  return result;
}


/*
 * Check hostname 
 */
static void check_hostname(char *hostname) {

  ASSERT(hostname);

  if (!check_host(hostname))
    yywarning2("hostname did not resolve");
}

/*
 * Check the dependency graph for errors
 * by doing a topological sort, thereby finding any cycles.
 * Assures that graph is a Directed Acyclic Graph (DAG).
 */
static void check_depend() {
  Service_T s;
  Service_T depends_on = NULL;
  Service_T* dlt = &depend_list; /* the current tail of it                                 */
  int done;                      /* no unvisited nodes left?                               */
  int found_some;                /* last iteration found anything new ?                    */
  depend_list = NULL;            /* depend_list will be the topological sorted servicelist */

  do { 
    done = TRUE;
    found_some = FALSE; 
    for (s = servicelist; s; s = s->next) {
        Dependant_T d;
      if (s->visited)
	  continue;
      done = FALSE; // still unvisited nodes
      depends_on = NULL;
      for (d = s->dependantlist; d; d = d->next) {
        Service_T dp = Util_getService(d->dependant);
        if (!dp) {
          LogError("%s: Error: Depend service '%s' is not defined in the control file\n", prog, d->dependant);
          exit(1);
        }
        if (!dp->visited) {
          depends_on = dp;
        }
      }

      if (!depends_on) {
        s->visited = TRUE;
        found_some = TRUE;
        *dlt = s;
        dlt = &s->next_depend;
      }
    }
  } while (found_some && !done);
	
  if (!done) {
        ASSERT(depends_on);
	LogError("%s: Error: Found a depend loop in the control file involving the service '%s'\n", prog, depends_on->name);
	exit(1);
   } 

  ASSERT(depend_list);
  servicelist = depend_list;

  for (s = depend_list; s; s = s->next_depend)
    s->next = s->next_depend;

  reset_depend();
}


/*
 * Check if the executable exist
 */
static void check_exec(char *exec) {
        if (! File_exist(exec))
                yywarning2("Program does not exist:");
        else if (! File_isExecutable(exec))
                yywarning2("Program is not executable:");
}


/* Return a valid max forward value for SIP header */
static int verifyMaxForward(int mf) { 
  int max = 70;

  if (mf >= 0 && mf <= 255)
    max = mf;
  else
    yywarning2("SIP max forward is outside the range [0..255]. Setting max forward to 70");

  return max;
}


/* -------------------------------------------------------------------- Misc */


/*
 * Cleans up an md5 string, tolower and remove byte separators
 */
static int cleanup_hash_string(char *hashstring) {
  int i = 0, j = 0;

  ASSERT(hashstring);

  while (hashstring[i] != '\0') {
    if (isxdigit((int) hashstring[i])) {
      hashstring[j] = tolower((int)hashstring[i]);
      j++;
    } 
    i++;
  }
  hashstring[j] = '\0';
  return j;
}


/* Return deep copy of the command */
static command_t copycommand(command_t source) {
  int i;
  command_t copy = NULL;

  NEW(copy);
  copy->length = source->length;
  copy->has_uid = source->has_uid;
  copy->uid = source->uid;
  copy->has_gid = source->has_gid;
  copy->gid = source->gid;
  copy->timeout = source->timeout;
  for (i = 0; i < copy->length; i++)
     copy->arg[i] = Str_dup(source->arg[i]);
  copy->arg[copy->length] = NULL;

  return copy;
}


