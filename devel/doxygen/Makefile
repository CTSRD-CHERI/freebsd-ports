# Created by: Joep Grooten <joep@di.nl>
# $FreeBSD$

PORTNAME=	doxygen
PORTVERSION=	1.8.7
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Documentation system for C, C++, and other languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake \
		flex>0:${PORTSDIR}/textproc/flex \
		python:${PORTSDIR}/lang/python \
		dvips:${PORTSDIR}/print/tex-dvipsk \
		${LOCALBASE}/share/fonts/cm-super/README:${PORTSDIR}/print/cm-super

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		bison iconv perl5 gmake
USE_PYTHON=	2
ALL_TARGET=	all
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS=	--prefix ${PREFIX} --perl ${PERL} --make ${MAKE_CMD} \
		--install "${INSTALL}" --flex ${LOCALBASE}/bin/flex
REINPLACE_ARGS=	-i ''

EXTRACT_AFTER_ARGS=	--exclude '*/libmd5'	\
			--exclude '*/libpng'	\
			--exclude '*/tmake'

PLIST=		${WRKDIR}/plist
TMPDOCDEST=	${WRKDIR}/tmpdocdest

PLIST_FILES=	bin/doxygen

OPTIONS_DEFINE=	HTMLDOCS QT4 PDFDOCS
QT4_DESC=	Install Doxywizard GUI
HTMLDOCS_DESC=	Install documentation in HTML format
PDFDOCS_DESC=	Install documentation in PDF format

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTMLDOCS}
ALL_TARGET+=	docs
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz

.if ${PORT_OPTIONS:MPDFDOCS}
ALL_TARGET+=	pdf
USE_TEX=	latex:build
USE_GHOSTSCRIPT_BUILD=	yes
MAKE_ARGS+=	HAVE_PDFDOCS=yes
.endif # PDFDOCS
.endif # HTMLDOCS

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	corelib gui xml qmake_build moc_build rcc_build

# Need this in env for build
QTDIR?=		${QT_PREFIX}
CONFIGURE_ENV=	QTDIR="${QTDIR}"
CONFIGURE_ARGS+=--with-doxywizard
.endif # QT4

.if ${MACHINE_ARCH:tl} == alpha
CONFIGURE_ARGS+=	--enable-langs no
.endif

.if ${PORT_OPTIONS:MQT4}
PLIST_FILES+=	bin/doxywizard
.endif # QT4

pre-configure:
	@cd ${WRKSRC};for pro in src/*.pro.in addon/doxywizard/doxywizard.pro.in;do \
		${ECHO} "unix:LIBS += ${ICONV_LIB}" >> $$pro; done
	@${CHMOD} +x ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|TMAKE *=.*|TMAKE=${LOCALBASE}/bin/tmake|' \
		-e 's|TMAKEPATH *=.*|TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++|' \
			${WRKSRC}/Makefile ${WRKSRC}/*/Makefile \
			${WRKSRC}/addon/doxywizard/Makefile

post-build:
	cd ${BUILD_WRKSRC}/examples; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} all

pre-install:
	${RM} -rf ${TMPDOCDEST} ${PLIST}
	${TOUCH} ${PLIST}
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${TMPDOCDEST}/doxygen
	${RM} -f ${WRKSRC}/examples/diagrams/html/*.md5 \
		 ${WRKSRC}/examples/diagrams/html/*.map
	${TAR} -C ${WRKSRC} --exclude '*/_*' -cf - html \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' --exclude '*.dot' \
		-cf - examples \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
.if ${PORT_OPTIONS:MPDFDOCS}
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/archoverview.eps \
			${TMPDOCDEST}/doxygen
.endif # PDFDOCS
	@cd ${TMPDOCDEST} \
	&& ${FIND} -s * -type f -o -type l \
		| ${SED} -e 's|^|share/doc/|' >> ${PLIST} \
	&& ${FIND} -d * -type d \
		| ${SED} -e 's|^|@dirrm share/doc/|' >> ${PLIST}
.endif # HTMLDOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MQT4}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${STAGEDIR}${PREFIX}/bin/
.endif # QT4
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/doxygen
	${TAR} -C ${TMPDOCDEST} -cf - doxygen \
		| ${TAR} -C ${STAGEDIR}${PREFIX}/share/doc --unlink -xf -
.endif # HTMLDOCS

.include <bsd.port.mk>
