# Created by: HSIN-HSIUNG CHANG <sexbear@tmu.edu.tw>
# $FreeBSD$

PORTNAME=	phppdflib
PORTVERSION=	2.8
CATEGORIES=	print
MASTER_SITES=	http://www.potentialtech.com/
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use API for creating PDF files dynamically

USE_PHP=	yes
WANT_PHP_MOD=	yes

IGNORE_WITH_PHP=5

WRKSRC=		${WRKDIR}/phppdflib
USES=	tar:bzip2
NO_BUILD=	yes

MYADMDIR?=	www/data/phppdflib

PLIST_SUB+=	MYADMDIR=${MYADMDIR}

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${MYADMDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${MYADMDIR}

.include <bsd.port.mk>
