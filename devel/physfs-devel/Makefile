# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	physfs
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://offload1.icculus.org/${PORTNAME}/downloads/
PKGNAMESUFFIX=	-devel

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Library to provide abstract access to various archives

USES=		cmake
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

patch-autotools-libtool:
	@${DO_NADA}

post-patch:
	@${REINPLACE_CMD} -e \
		's|CHECK_INCLUDE_FILE(sys/ucred.h HAVE_UCRED_H|& "-include sys/param.h"|g; \
		 s|CHECK_INCLUDE_FILE(readline/readline.h HAVE_READLINE_H|& "-include stdio.h"|g; \
		 s|CHECK_INCLUDE_FILE(readline/history.h HAVE_HISTORY_H|& "-include stdio.h"|g; \
		 s|CHECK_LIBRARY_EXISTS("readline" "history.*|SET(HAVE_LIBHISTORY TRUE)|g; \
		 s|" " \(readline curses\)|\1|' ${WRKSRC}/CMakeLists.txt

	@${REINPLACE_CMD} -e 's|\(define SIZEOF_INT\) 4|\1 (LONG_BIT/8)|g' \
		${WRKSRC}/platform/unix.c

.include <bsd.port.mk>
