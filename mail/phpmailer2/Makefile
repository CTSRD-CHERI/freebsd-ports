# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	phpmailer2
PORTVERSION=	2.0.4
CATEGORIES=	mail
MASTER_SITES=	SF/phpmailer/phpmailer%20for%20php4/PHPMailer%20v${PORTVERSION}%20for%20PHP4
DISTNAME=	PHPMailer_v${DISTVERSION}

MAINTAINER= ports@FreeBSD.org
COMMENT=	Full Featured Email Transfer Class for PHP4

CONFLICTS=	phpmailer-5*

USES=		dos2unix
NO_BUILD=	yes
USE_PHP=	pcre

SUB_FILES=	pkg-message

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR}
.for f in class.phpmailer.php class.pop3.php class.smtp.php
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/language
	@${INSTALL_DATA} ${WRKSRC}/language/* ${DATADIR}/language
	@${MKDIR} ${DATADIR}/test
	@${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	@${CP} -R ${WRKSRC}/phpdocs/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
