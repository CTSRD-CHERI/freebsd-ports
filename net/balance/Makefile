# Created by: Joseph Scott <joseph@randomnetworks.com>
# $FreeBSD$

PORTNAME=	balance
PORTVERSION=	3.54
CATEGORIES=	net
MASTER_SITES=	http://www.inlab.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple but powerful generic TCP proxy with round robin features

ALL_TARGET=	balance
USE_RC_SUBR=	balance

MAN1=		balance.1

NO_STAGE=	yes
pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|' \
	-e 's|^CC|CC?|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/balance ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/balance.1 ${MAN1PREFIX}/man/man1
	@${MKDIR} /var/run/balance

.include <bsd.port.mk>
