# $FreeBSD$

PORTNAME=	nmsg
PORTVERSION=	0.8.0
PORTREVISION=	1
# DISTNAME=	${PORTNAME}-${PORTVERSION}
CATEGORIES=	net
MASTER_SITES=	https://dl.farsightsecurity.com/dist/nmsg/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Network message encapsulation system

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

LIB_DEPENDS+=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libxs.so:${PORTSDIR}/devel/libxs \
		libwdns.so:${PORTSDIR}/dns/wdns

DOCBOOK_XML=	${LOCALBASE}/share/xml/docbook/4.2
DOCBOOK_XSL_NS=	${LOCALBASE}/share/doc/docbook-xsl-ns/html/docbook.css.source.html
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${DOCBOOK_XML}:${PORTSDIR}/textproc/docbook-xml \
		${DOCBOOK_XSL_NS}:${PORTSDIR}/textproc/docbook-xsl-ns

ALL_TARGET=	all
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
ALL_TARGET+=	html-local
.endif

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig
CONFIGURE_ARGS+=	--with-pkgconfigdir='$${exec_prefix}/libdata/pkgconfig'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnmsg.so.6.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nmsg/nmsg_msg8_base.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/doxygen/html/* ${STAGEDIR}${DOCSDIR}/html
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
