# Created by: Ronald Kuehn <rk@ronald.org>
# $FreeBSD$

PORTNAME=	lablgl
PORTVERSION=	20120306
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/lsl/dist/ \
		https://forge.ocamlcore.org/frs/download.php/816/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	bf@FreeBSD.org
COMMENT=	OpenGL interface for Objective Caml

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/lablGL
USES=		gmake
USE_XORG=	x11 xext xmu
USE_GL=		glut
USE_OCAML=	yes
USE_OCAML_WASH=	yes
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	THREADS
THREADS_DESC=	Threaded Tcl/Tk (must match lang/ocaml)

OPTIONS_DEFAULT=	THREADS

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

DOCSDIR=	${PREFIX}/share/doc/ocaml/lablgl
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/lablgl

CONFLICTS=	ocaml-notk-[0-9]* ocaml-nox11-[0-9]*

.include <bsd.port.options.mk>

USES+=		tk:84,85
.if ${PORT_OPTIONS:MTHREADS}
THR_CPP=	${PTHREAD_CFLAGS}
THR_LD=		${PTHREAD_LIBS}
.endif

post-extract:
	@${CP} ${WRKSRC}/Makefile.config.freebsd ${WRKSRC}/Makefile.config

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${LOCALBASE},g" \
		-e "s,/usr/local,${LOCALBASE},g" \
		-e "s,^\(BINDIR[ \t]*=\).*,\1${STAGEDIR}${PREFIX}/bin,g" \
		-e "s,^\(RANLIB[ \t]*=\).*,\1ranlib,g" \
		-e "s,^#\(LIBDIR[ \t]*=\).*,\1${PREFIX}/lib/ocaml,g" \
		-e "s,^#\(DLLDIR[ \t]*=\).*,\1${STAGEDIR}${PREFIX}/lib/ocaml/stublibs,g" \
		-e "s,^#\(INSTALLDIR[ \t]*=\).*,\1${STAGEDIR}${PREFIX}/lib/ocaml/lablGL,g" \
		-e "s!^#\(COPTS[ \t]*=\).*!\1-c ${CFLAGS} ${THR_CPP}!g" \
		-e "/^TKINCLUDES/s,=.*$$,= -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}," \
		-e "/^TKLIBS/s,=.*$$,= -L${LOCALBASE}/lib -ltk${TK_SHLIB_VER}\
		-ltcl${TCL_SHLIB_VER} ${THR_LD}," \
		${WRKSRC}/Makefile.config

	@${REINPLACE_CMD} -E \
		-e '/exec ocaml/s,\$$\(INSTALLDIR\),${PREFIX}/lib/ocaml/lablGL,' \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		${WRKSRC}/src/Makefile ${WRKSRC}/LablGlut/src/Makefile \
		${WRKSRC}/Togl/src/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/lablglut
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/togl
	@(cd ${WRKSRC}/LablGlut/examples && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/lablglut '! -name Makefile')
	@(cd ${WRKSRC}/Togl/examples && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/togl '! -name Makefile')
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
