# $FreeBSD$

PORTNAME=	gnome-clipboard-daemon
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
DISTNAME=	${PORTNAME:S,^gnome-,,}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that keeps the content of your X clipboard in memory

LICENSE=	GPLv2

USES=		pkgconfig tar:bzip2
USE_GNOME=	gtk20

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^CFLAGS=|CFLAGS?=| ; \
		 s|-o clipboard-daemon |-o ${PORTNAME} |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
