# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	replaceit
PORTVERSION=	1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://pldaniels.com/replaceit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light replacement to the combination of sed/awk/grep/head/tail

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	CC="${CC}" PRF="${CFLAGS}"

PORTDOCS=	CHANGELOG README
PLIST_FILES=	bin/replaceit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replaceit ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
