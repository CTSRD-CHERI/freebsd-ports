# Created by: Alex Miller <asm@asm.kiev.ua>
# $FreeBSD$

PORTNAME=	frickin
DISTVERSION=	2.0BETA2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frickin PPTP Proxy

MAKE_JOBS_UNSAFE=	yes
USE_RC_SUBR=	frickin
SUB_FILES=	pkg-message
PORTDOCS=	INSTALL LICENSE
PLIST_FILES=	sbin/frickin2 etc/frickin.conf.sample

NO_STAGE=	yes
post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g;' \
	${WRKSRC}/src/Makefile.FreeBSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}2 ${PREFIX}/sbin/${PORTNAME}2
	${INSTALL_DATA} ${WRKSRC}/frickin.conf.default ${PREFIX}/etc/frickin.conf.sample

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}

.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
