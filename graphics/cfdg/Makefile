# Created by: Anatoly Borodin <anatoly.borodin@gmail.com>
# $FreeBSD$

PORTNAME=	cfdg
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	http://www.contextfreeart.org/download/ \
		http://glyphic.s3.amazonaws.com/cfa/download/
DISTNAME=	ContextFreeSource${PORTVERSION}

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Context Free Design Grammar compiler

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

WRKSRC=		${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

USES=		gmake tar:tgz
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/cfdg

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfdg ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/input/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
