# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	translate
PORTVERSION=	1.11
CATEGORIES=	misc
MASTER_SITES=	http://www.freebsdcluster.org/~mich/software/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Translates string using Babelfish

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

# same binary file bin/translate
CONFLICTS_INSTALL=	google-translate-cli-*

USES=		perl5 shebangfix
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/translate man/man1/translate.1.gz
SHEBANG_FILES=	translate

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
