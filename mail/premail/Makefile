# Created by: ache
# $FreeBSD$

PORTNAME=	premail
PORTVERSION=	0.46
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	ftp://ftp.jpunix.com/pub/remailer-tools/ \
		ftp://ftp.kiarchive.ru/pub/unix/crypto/

MAINTAINER= ports@FreeBSD.org
COMMENT=	E-mail privacy package, support anon remailers, PGP, nyms

BUILD_DEPENDS+=	pgp:${PORTSDIR}/security/pgp

WRKSRC=		${WRKDIR}/premail
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	premail

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} premail ${PREFIX}/bin
	${MKDIR} -m 555 ${PREFIX}/share/doc/premail
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   preferences doc-0.46.html doc-0.46.txt ${PREFIX}/share/doc/premail
	@${ECHO_MSG}
	@${ECHO_MSG} "Check ${PREFIX}/share/doc/premail for further instructions"
	@${ECHO_MSG}

.include <bsd.port.mk>
