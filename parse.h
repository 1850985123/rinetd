/* A recursive-descent parser generated by peg 0.1.18 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 25
#line 1 "parse.peg"

#define YY_CTX_LOCAL 1
#define YY_CTX_MEMBERS \
    FILE *fp; \
    int isAuthAllow; \
    unsigned int port, bindPort, connectPort; \
    char *bindAddress, *connectAddress;
#define YY_INPUT(yyctx, buf, result, max_size) \
{ \
    int yyc = fgetc(yyctx->fp); \
    result = (EOF == yyc) ? 0 : (*(buf) = yyc, 1); \
}
#define PARSE_ERROR exit(1);

#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy_eof(yycontext *yy); /* 25 */
YY_RULE(int) yy_digit(yycontext *yy); /* 24 */
YY_RULE(int) yy_name(yycontext *yy); /* 23 */
YY_RULE(int) yy_filename(yycontext *yy); /* 22 */
YY_RULE(int) yy_pattern(yycontext *yy); /* 21 */
YY_RULE(int) yy_auth_key(yycontext *yy); /* 20 */
YY_RULE(int) yy_service(yycontext *yy); /* 19 */
YY_RULE(int) yy_number(yycontext *yy); /* 18 */
YY_RULE(int) yy_port(yycontext *yy); /* 17 */
YY_RULE(int) yy_ipv4(yycontext *yy); /* 16 */
YY_RULE(int) yy_connect_port(yycontext *yy); /* 15 */
YY_RULE(int) yy_connect_address(yycontext *yy); /* 14 */
YY_RULE(int) yy_bind_port(yycontext *yy); /* 13 */
YY_RULE(int) yy_bind_address(yycontext *yy); /* 12 */
YY_RULE(int) yy_eol(yycontext *yy); /* 11 */
YY_RULE(int) yy_comment(yycontext *yy); /* 10 */
YY_RULE(int) yy_logcommon(yycontext *yy); /* 9 */
YY_RULE(int) yy_pidlogfile(yycontext *yy); /* 8 */
YY_RULE(int) yy_logfile(yycontext *yy); /* 7 */
YY_RULE(int) yy_auth(yycontext *yy); /* 6 */
YY_RULE(int) yy_rule(yycontext *yy); /* 5 */
YY_RULE(int) yy__(yycontext *yy); /* 4 */
YY_RULE(int) yy_invalid_syntax(yycontext *yy); /* 3 */
YY_RULE(int) yy_line(yycontext *yy); /* 2 */
YY_RULE(int) yy_file(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_invalid_syntax(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_invalid_syntax\n"));
  {
#line 161
   PARSE_ERROR; /* FIXME */ ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_logcommon(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_logcommon\n"));
  {
#line 157
  
	logFormatCommon = 1;
;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_pidlogfile(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_pidlogfile\n"));
  {
#line 150
  
	pidLogFileName = strdup(yytext);
	if (!pidLogFileName) {
		PARSE_ERROR;
	}
;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_logfile(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_logfile\n"));
  {
#line 143
  
	logFileName = strdup(yytext);
	if (!logFileName) {
		PARSE_ERROR;
	}
;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_auth_key(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_auth_key\n"));
  {
#line 141
   yy->isAuthAllow = (yytext[0] == 'a'); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_auth(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_auth\n"));
  {
#line 119
  
	allRules = (Rule *)
		realloc(allRules, sizeof(Rule) * (allRulesCount + 1));
	if (!allRules) {
		PARSE_ERROR;
	}
	allRules[allRulesCount].pattern = strdup(yytext);
	if (!allRules[allRulesCount].pattern) {
		PARSE_ERROR;
	}
	allRules[allRulesCount].type = yy->isAuthAllow ? allowRule : denyRule;
	if (seTotal > 0) {
		if (seInfo[seTotal - 1].rulesStart == 0) {
			seInfo[seTotal - 1].rulesStart = allRulesCount;
		}
		++seInfo[seTotal - 1].rulesCount;
	} else {
		++globalRulesCount;
	}
	++allRulesCount;
;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_port(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_port\n"));
  {
#line 110
  
	struct servent *bindService = getservbyname(yytext, "tcp");
	yy->port = bindService ? ntohs(bindService->s_port) : atoi(yytext);
	if (yy->port == 0 || yy->port >= 65536) {
		syslog(LOG_ERR, "bind port missing or out of range\n");
		PARSE_ERROR;
	}
;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_connect_port(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_connect_port\n"));
  {
#line 108
   yy->connectPort = yy->port; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_bind_port(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_bind_port\n"));
  {
#line 107
   yy->bindPort = yy->port; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_connect_address(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_connect_address\n"));
  {
#line 106
   yy->connectAddress = strdup(yytext); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_bind_address(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_bind_address\n"));
  {
#line 105
   yy->bindAddress = strdup(yytext); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_rule(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_rule\n"));
  {
#line 21
  
	/* Turn all of this stuff into reasonable addresses */
	struct in_addr iaddr;
	if (getAddress(yy->bindAddress, &iaddr) < 0) {
		fprintf(stderr, "rinetd: host %s could not be resolved.\n",
			yy->bindAddress);
		PARSE_ERROR;
	}
	/* Make a server socket */
	SOCKET fd = socket(PF_INET, SOCK_STREAM, 0);
	if (fd == INVALID_SOCKET) {
		syslog(LOG_ERR, "couldn't create "
			"server socket! (%m)\n");
		PARSE_ERROR;
	}
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	memcpy(&saddr.sin_addr, &iaddr, sizeof(iaddr));
	saddr.sin_port = htons(yy->bindPort);
	int tmp = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
		(const char *) &tmp, sizeof(tmp));
	if (bind(fd, (struct sockaddr *)
		&saddr, sizeof(saddr)) == SOCKET_ERROR)
	{
		/* Warn -- don't exit. */
		syslog(LOG_ERR, "couldn't bind to "
			"address %s port %d (%m)\n",
			yy->bindAddress, yy->bindPort);
		closesocket(fd);
		PARSE_ERROR;
	}
	if (listen(fd, RINETD_LISTEN_BACKLOG) == SOCKET_ERROR) {
		/* Warn -- don't exit. */
		syslog(LOG_ERR, "couldn't listen to "
			"address %s port %d (%m)\n",
			yy->bindAddress, yy->bindPort);
		closesocket(fd);
		PARSE_ERROR;
	}
#if _WIN32
	u_long ioctltmp;
#else
	int ioctltmp;
#endif
	ioctlsocket(fd, FIONBIO, &ioctltmp);
	if (getAddress(yy->connectAddress, &iaddr) < 0) {
		/* Warn -- don't exit. */
		syslog(LOG_ERR, "host %s could not be resolved.\n",
			yy->bindAddress);
		closesocket(fd);
		PARSE_ERROR;
	}
	/* Allocate server info */
	seInfo = (ServerInfo *)
		realloc(seInfo, sizeof(ServerInfo) * (seTotal + 1));
	if (!seInfo) {
		PARSE_ERROR;
	}
	ServerInfo *srv = &seInfo[seTotal];
	memset(srv, 0, sizeof(*srv));
	srv->fd = fd;
	srv->localAddr = iaddr;
	srv->localPort = htons(yy->connectPort);
	srv->fromHost = yy->bindAddress;
	if (!srv->fromHost) {
		PARSE_ERROR;
	}
	srv->fromPort = yy->bindPort;
	srv->toHost = yy->connectAddress;
	if (!srv->toHost) {
		PARSE_ERROR;
	}
	srv->toPort = yy->connectPort;
#ifndef _WIN32
	if (fd > maxfd) {
		maxfd = fd;
	}
#endif
	++seTotal;

	yy->bindAddress = yy->connectAddress = NULL;
;
  }
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy_eof(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "eof"));  if (!yymatchChar(yy, '\0')) goto l1;
  yyprintf((stderr, "  ok   %s @ %s\n", "eof", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "eof", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_digit(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "digit"));  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l2;
  yyprintf((stderr, "  ok   %s @ %s\n", "digit", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "digit", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_name(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "name"));  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\000\000\376\377\377\007\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l3;
  l4:;	
  {  int yypos5= yy->__pos, yythunkpos5= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\376\377\377\207\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l5;  goto l4;
  l5:;	  yy->__pos= yypos5; yy->__thunkpos= yythunkpos5;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "name", yy->__buf+yy->__pos));
  return 1;
  l3:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "name", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_filename(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "filename"));
  {  int yypos7= yy->__pos, yythunkpos7= yy->__thunkpos;  if (!yymatchChar(yy, '"')) goto l8;  if (!yymatchClass(yy, (unsigned char *)"\377\377\377\377\373\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377")) goto l8;
  l9:;	
  {  int yypos10= yy->__pos, yythunkpos10= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\377\377\377\377\373\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377")) goto l10;  goto l9;
  l10:;	  yy->__pos= yypos10; yy->__thunkpos= yythunkpos10;
  }  if (!yymatchChar(yy, '"')) goto l8;  goto l7;
  l8:;	  yy->__pos= yypos7; yy->__thunkpos= yythunkpos7;  if (!yymatchClass(yy, (unsigned char *)"\377\331\377\377\376\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377")) goto l6;
  l11:;	
  {  int yypos12= yy->__pos, yythunkpos12= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\377\331\377\377\376\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377")) goto l12;  goto l11;
  l12:;	  yy->__pos= yypos12; yy->__thunkpos= yythunkpos12;
  }
  }
  l7:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "filename", yy->__buf+yy->__pos));
  return 1;
  l6:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "filename", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_pattern(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "pattern"));  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l13;
  l14:;	
  {  int yypos15= yy->__pos, yythunkpos15= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l15;  goto l14;
  l15:;	  yy->__pos= yypos15; yy->__thunkpos= yythunkpos15;
  }
  {  int yypos16= yy->__pos, yythunkpos16= yy->__thunkpos;  if (!yymatchChar(yy, '.')) goto l16;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l16;
  l18:;	
  {  int yypos19= yy->__pos, yythunkpos19= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l19;  goto l18;
  l19:;	  yy->__pos= yypos19; yy->__thunkpos= yythunkpos19;
  }
  {  int yypos20= yy->__pos, yythunkpos20= yy->__thunkpos;  if (!yymatchChar(yy, '.')) goto l20;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l20;
  l22:;	
  {  int yypos23= yy->__pos, yythunkpos23= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l23;  goto l22;
  l23:;	  yy->__pos= yypos23; yy->__thunkpos= yythunkpos23;
  }
  {  int yypos24= yy->__pos, yythunkpos24= yy->__thunkpos;  if (!yymatchChar(yy, '.')) goto l24;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l24;
  l26:;	
  {  int yypos27= yy->__pos, yythunkpos27= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\004\377\203\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l27;  goto l26;
  l27:;	  yy->__pos= yypos27; yy->__thunkpos= yythunkpos27;
  }  goto l25;
  l24:;	  yy->__pos= yypos24; yy->__thunkpos= yythunkpos24;
  }
  l25:;	  goto l21;
  l20:;	  yy->__pos= yypos20; yy->__thunkpos= yythunkpos20;
  }
  l21:;	  goto l17;
  l16:;	  yy->__pos= yypos16; yy->__thunkpos= yythunkpos16;
  }
  l17:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "pattern", yy->__buf+yy->__pos));
  return 1;
  l13:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "pattern", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_auth_key(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "auth_key"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l28;
#undef yytext
#undef yyleng
  }
  {  int yypos29= yy->__pos, yythunkpos29= yy->__thunkpos;  if (!yymatchString(yy, "allow")) goto l30;  goto l29;
  l30:;	  yy->__pos= yypos29; yy->__thunkpos= yythunkpos29;  if (!yymatchString(yy, "deny")) goto l28;
  }
  l29:;	  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l28;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_auth_key, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "auth_key", yy->__buf+yy->__pos));
  return 1;
  l28:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "auth_key", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_service(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "service"));  if (!yy_name(yy)) goto l31;
  yyprintf((stderr, "  ok   %s @ %s\n", "service", yy->__buf+yy->__pos));
  return 1;
  l31:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "service", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_number(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "number"));  if (!yy_digit(yy)) goto l32;
  l33:;	
  {  int yypos34= yy->__pos, yythunkpos34= yy->__thunkpos;  if (!yy_digit(yy)) goto l34;  goto l33;
  l34:;	  yy->__pos= yypos34; yy->__thunkpos= yythunkpos34;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "number", yy->__buf+yy->__pos));
  return 1;
  l32:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "number", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_port(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "port"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l35;
#undef yytext
#undef yyleng
  }
  {  int yypos36= yy->__pos, yythunkpos36= yy->__thunkpos;  if (!yy_number(yy)) goto l37;  goto l36;
  l37:;	  yy->__pos= yypos36; yy->__thunkpos= yythunkpos36;  if (!yy_service(yy)) goto l35;
  }
  l36:;	  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l35;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_port, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "port", yy->__buf+yy->__pos));
  return 1;
  l35:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "port", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ipv4(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ipv4"));
  {  int yypos39= yy->__pos, yythunkpos39= yy->__thunkpos;  if (!yy_number(yy)) goto l40;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\100\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l40;  if (!yy_number(yy)) goto l40;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\100\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l40;  if (!yy_number(yy)) goto l40;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\100\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l40;  if (!yy_number(yy)) goto l40;  goto l39;
  l40:;	  yy->__pos= yypos39; yy->__thunkpos= yythunkpos39;  if (!yymatchChar(yy, '0')) goto l38;
  }
  l39:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "ipv4", yy->__buf+yy->__pos));
  return 1;
  l38:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ipv4", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_connect_port(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "connect_port"));  if (!yy_port(yy)) goto l41;  yyDo(yy, yy_1_connect_port, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "connect_port", yy->__buf+yy->__pos));
  return 1;
  l41:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "connect_port", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_connect_address(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "connect_address"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l42;
#undef yytext
#undef yyleng
  }  if (!yy_ipv4(yy)) goto l42;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l42;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_connect_address, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "connect_address", yy->__buf+yy->__pos));
  return 1;
  l42:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "connect_address", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_bind_port(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "bind_port"));  if (!yy_port(yy)) goto l43;  yyDo(yy, yy_1_bind_port, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "bind_port", yy->__buf+yy->__pos));
  return 1;
  l43:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "bind_port", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_bind_address(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "bind_address"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l44;
#undef yytext
#undef yyleng
  }  if (!yy_ipv4(yy)) goto l44;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l44;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_bind_address, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "bind_address", yy->__buf+yy->__pos));
  return 1;
  l44:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "bind_address", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_eol(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "eol"));
  {  int yypos46= yy->__pos, yythunkpos46= yy->__thunkpos;
  {  int yypos48= yy->__pos, yythunkpos48= yy->__thunkpos;  if (!yymatchChar(yy, '\r')) goto l48;  goto l49;
  l48:;	  yy->__pos= yypos48; yy->__thunkpos= yythunkpos48;
  }
  l49:;	  if (!yymatchChar(yy, '\n')) goto l47;  goto l46;
  l47:;	  yy->__pos= yypos46; yy->__thunkpos= yythunkpos46;  if (!yy_eof(yy)) goto l45;
  }
  l46:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "eol", yy->__buf+yy->__pos));
  return 1;
  l45:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "eol", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "comment"));  if (!yymatchChar(yy, '#')) goto l50;
  l51:;	
  {  int yypos52= yy->__pos, yythunkpos52= yy->__thunkpos;
  {  int yypos53= yy->__pos, yythunkpos53= yy->__thunkpos;  if (!yy_eol(yy)) goto l53;  goto l52;
  l53:;	  yy->__pos= yypos53; yy->__thunkpos= yythunkpos53;
  }  if (!yymatchDot(yy)) goto l52;  goto l51;
  l52:;	  yy->__pos= yypos52; yy->__thunkpos= yythunkpos52;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "comment", yy->__buf+yy->__pos));
  return 1;
  l50:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_logcommon(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "logcommon"));  if (!yymatchString(yy, "logcommon")) goto l54;  yyDo(yy, yy_1_logcommon, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "logcommon", yy->__buf+yy->__pos));
  return 1;
  l54:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "logcommon", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_pidlogfile(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "pidlogfile"));  if (!yymatchString(yy, "pidlogfile")) goto l55;  if (!yy__(yy)) goto l55;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l55;
#undef yytext
#undef yyleng
  }  if (!yy_filename(yy)) goto l55;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l55;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_pidlogfile, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "pidlogfile", yy->__buf+yy->__pos));
  return 1;
  l55:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "pidlogfile", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_logfile(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "logfile"));  if (!yymatchString(yy, "logfile")) goto l56;  if (!yy__(yy)) goto l56;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l56;
#undef yytext
#undef yyleng
  }  if (!yy_filename(yy)) goto l56;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l56;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_logfile, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "logfile", yy->__buf+yy->__pos));
  return 1;
  l56:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "logfile", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_auth(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "auth"));  if (!yy_auth_key(yy)) goto l57;  if (!yy__(yy)) goto l57;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l57;
#undef yytext
#undef yyleng
  }  if (!yy_pattern(yy)) goto l57;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l57;
#undef yytext
#undef yyleng
  }  yyDo(yy, yy_1_auth, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "auth", yy->__buf+yy->__pos));
  return 1;
  l57:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "auth", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_rule(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "rule"));  if (!yy_bind_address(yy)) goto l58;  if (!yy__(yy)) goto l58;  if (!yy_bind_port(yy)) goto l58;  if (!yy__(yy)) goto l58;  if (!yy_connect_address(yy)) goto l58;  if (!yy__(yy)) goto l58;  if (!yy_connect_port(yy)) goto l58;  yyDo(yy, yy_1_rule, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "rule", yy->__buf+yy->__pos));
  return 1;
  l58:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "rule", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy__(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "_"));  if (!yymatchClass(yy, (unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l59;
  l60:;	
  {  int yypos61= yy->__pos, yythunkpos61= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l61;  goto l60;
  l61:;	  yy->__pos= yypos61; yy->__thunkpos= yythunkpos61;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_", yy->__buf+yy->__pos));
  return 1;
  l59:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "_", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_invalid_syntax(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "invalid_syntax"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l62;
#undef yytext
#undef yyleng
  }
  l63:;	
  {  int yypos64= yy->__pos, yythunkpos64= yy->__thunkpos;
  {  int yypos65= yy->__pos, yythunkpos65= yy->__thunkpos;  if (!yy_eol(yy)) goto l65;  goto l64;
  l65:;	  yy->__pos= yypos65; yy->__thunkpos= yythunkpos65;
  }  if (!yymatchDot(yy)) goto l64;  goto l63;
  l64:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;
  }  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l62;
#undef yytext
#undef yyleng
  }  if (!yy_eol(yy)) goto l62;  yyDo(yy, yy_1_invalid_syntax, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "invalid_syntax", yy->__buf+yy->__pos));
  return 1;
  l62:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "invalid_syntax", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_line(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "line"));
  {  int yypos67= yy->__pos, yythunkpos67= yy->__thunkpos;  if (!yy__(yy)) goto l67;  goto l68;
  l67:;	  yy->__pos= yypos67; yy->__thunkpos= yythunkpos67;
  }
  l68:;	
  {  int yypos69= yy->__pos, yythunkpos69= yy->__thunkpos;
  {  int yypos71= yy->__pos, yythunkpos71= yy->__thunkpos;  if (!yy_rule(yy)) goto l72;  goto l71;
  l72:;	  yy->__pos= yypos71; yy->__thunkpos= yythunkpos71;  if (!yy_auth(yy)) goto l73;  goto l71;
  l73:;	  yy->__pos= yypos71; yy->__thunkpos= yythunkpos71;  if (!yy_logfile(yy)) goto l74;  goto l71;
  l74:;	  yy->__pos= yypos71; yy->__thunkpos= yythunkpos71;  if (!yy_pidlogfile(yy)) goto l75;  goto l71;
  l75:;	  yy->__pos= yypos71; yy->__thunkpos= yythunkpos71;  if (!yy_logcommon(yy)) goto l69;
  }
  l71:;	  goto l70;
  l69:;	  yy->__pos= yypos69; yy->__thunkpos= yythunkpos69;
  }
  l70:;	
  {  int yypos76= yy->__pos, yythunkpos76= yy->__thunkpos;  if (!yy__(yy)) goto l76;  goto l77;
  l76:;	  yy->__pos= yypos76; yy->__thunkpos= yythunkpos76;
  }
  l77:;	
  {  int yypos78= yy->__pos, yythunkpos78= yy->__thunkpos;  if (!yy_comment(yy)) goto l78;  goto l79;
  l78:;	  yy->__pos= yypos78; yy->__thunkpos= yythunkpos78;
  }
  l79:;	  if (!yy_eol(yy)) goto l66;
  yyprintf((stderr, "  ok   %s @ %s\n", "line", yy->__buf+yy->__pos));
  return 1;
  l66:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "line", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_file(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "file"));
  l81:;	
  {  int yypos82= yy->__pos, yythunkpos82= yy->__thunkpos;
  {  int yypos83= yy->__pos, yythunkpos83= yy->__thunkpos;  if (!yy_line(yy)) goto l84;  goto l83;
  l84:;	  yy->__pos= yypos83; yy->__thunkpos= yythunkpos83;  if (!yy_invalid_syntax(yy)) goto l82;
  }
  l83:;	  goto l81;
  l82:;	  yy->__pos= yypos82; yy->__thunkpos= yythunkpos82;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "file", yy->__buf+yy->__pos));
  return 1;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_file);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif