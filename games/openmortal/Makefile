# Created by: krion@FreeBSD.org
# $FreeBSD$

PORTNAME=	openmortal
PORTVERSION=	0.7
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Parody of the once popular coin-up fighting game, Mortal Kombat

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		tar:bzip2 dos2unix perl5
GNU_CONFIGURE=	yes
USE_SDL=	mixer image sdl net
DOS2UNIX_FILES=	src/gfx.cpp

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.include <bsd.port.mk>
