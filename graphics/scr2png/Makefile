# Created by: nik
# $FreeBSD$

PORTNAME=	scr2png
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nik

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Converts the output of "vidcontrol -p" to PNG

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

NO_WRKSUBDIR=	yes
USES=		uidfix
MAKE_ARGS=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX}

PLIST_FILES=	bin/scr2png man/man1/scr2png.1.gz

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<gd/gd\.h>|<gd.h>|' ${WRKSRC}/scr2png.c

.include <bsd.port.mk>
