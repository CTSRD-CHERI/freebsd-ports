# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	memcacheq
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Simple queue service over Memcache

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USE_CSTD=	gnu89
CFLAGS+=	-I"${BDB_INCLUDE_DIR}"
LDFLAGS+=	-l"${BDB_LIB_NAME}" -L"${LOCALBASE}/lib"

USE_RC_SUBR=	memcacheq
USE_BDB=	5
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} --with-bdb=${LOCALBASE} --enable-threads

PORTDOCS=	README

MCQDIR?=	/var/db/memcacheq
PLIST_SUB=	MCQDIR=${MCQDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
