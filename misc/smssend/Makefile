# Created by: Miklos Niedermayer <mico@bsd.hu>
# $FreeBSD$

PORTNAME=	smssend
PORTVERSION=	3.5
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	LOCAL/laszlof \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to send a SMS to any GSM

LIB_DEPENDS=	libskyutils.so:${PORTSDIR}/misc/skyutils

USES=		libtool shebangfix
SHEBANG_FILES=	bestsms.sh email2smssend
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/smssend

.include <bsd.port.mk>
