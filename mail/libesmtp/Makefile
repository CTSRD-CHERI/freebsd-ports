# Created by: tobez@tobez.org
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	1.0.6
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://ftp.osuosl.org/pub/blfs/svn/l/ \
		GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for posting electronic mail

LICENSE=	LGPL21

OPTIONS_DEFINE=	OPENSSL DEBUG DOCS EXAMPLES
OPTIONS_DEFAULT=	OPENSSL

USES=		gmake tar:bzip2
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
# require-all-recipients (implied by enable-all) is required for Balsa
CONFIGURE_ARGS=	--enable-all --disable-isoc
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
PLIST_SUB+=		NEED_OPENSSL=""
.else
CONFIGURE_ARGS+=	--without-openssl
PLIST_SUB+=		NEED_OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS Notes README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
