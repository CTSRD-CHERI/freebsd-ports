# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	eieio
PORTVERSION=	0.17
PORTREVISION=	6
CATEGORIES=	devel elisp
MASTER_SITES=	SF/cedet/${PORTNAME}/${PORTVERSION} \
		http://dryice.name/computer/FreeBSD/distfiles/

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
#DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER= ports@FreeBSD.org
COMMENT=	Enhanced Integration of Emacs Interpreted Objects

USE_EMACS=	yes

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/speedbar/speedbar.el:${PORTSDIR}/editors/speedbar${PORTNAMESUFFIX}

USES=		gmake
CONFLICTS=	cedet*
INFO=		eieio

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/eieio

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "New version of eieio is now in devel/cedet."
	@${ECHO_MSG} "Hit C-c now if you want the new version."
	@${ECHO_MSG} ""

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/eieio.info ${PREFIX}/info

.include <bsd.port.mk>
