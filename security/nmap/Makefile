# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	nmap
DISTVERSION=	6.46
CATEGORIES=	security ipv6
MASTER_SITES=	http://nmap.org/dist/ \
		LOCAL/ohauer

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Port scanning utility for large networks

# nmap-6.46 => r32840
# http://nmap.org/book/man-legal.html
# Install the nmap modified license because of
# http://insecure.org/news/download-com-fiasco.html
LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DOCS IPV6 SSL
OPTIONS_DEFAULT=IPV6 SSL

SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_CONFIGURE_OFF=	--without-openssl
SSL_CFLAGS=		-I${OPENSSLINC}

IPV6_CONFIGURE_OFF=	--with-libpcap=${LOCALBASE}/IPv6

.include <bsd.port.options.mk>

# PR: ports/159376  Workaround if OS is build with WITHOUT_INET6
.if ! ${PORT_OPTIONS:MIPV6}
LIB_DEPENDS+=		libpcap.so:${PORTSDIR}/net/libpcap
.endif

PORTDOCS=	CHANGELOG HACKING
STRIP_FILES=	nmap nping

.if ${PORT_OPTIONS:MSSL}
STRIP_FILES+=	ncat
.endif

CONFIGURE_ARGS+=--without-localdirs \
		--without-zenmap \
		--without-ndiff \
		--with-libpcre=${LOCALBASE} \
		--with-liblua=included \
		--without-nmap-update

# fix for gcc from ports
.if ${CC} != "cc" && ${CC} !="clang"
GCCLIBDIR_CMDS=	${CC} -print-file-name=libstdc++.so | ${SED} -e 's/libstdc++.so//'
CONFIGURE_ARGS+=LDFLAGS="-L$$(${GCCLIBDIR_CMDS})"
NDCC=	true
.endif

# XXX limit results if we do a grep in the sources!
post-extract:
	@${RM} -rf ${WRKSRC}/mswin32

post-configure:
	@${REINPLACE_CMD} -e "s|^DESTDIR *=|& ${DESTDIR}|" ${WRKSRC}/Makefile

pre-install:
	${FIND} ${WRKSRC} -type f \( -name \*.orig -o -name \*.bak \) -delete

post-install:
	${STRIP_CMD} ${STRIP_FILES:S|^|${STAGEDIR}${PREFIX}/bin/|}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

# gcc from ports is in use
.if defined(NDCC)
	@${ECHO_MSG} do not forget to adjust libnmap.conf
.endif

.include <bsd.port.mk>
