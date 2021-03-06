# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	raine
PORTVERSION=	0.43.3
PORTREVISION=	9
CATEGORIES=	emulators games
MASTER_SITES=	http://www.rainemu.com/html/archive/
DISTNAME=	${PORTNAME}s-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arcade Emulator for M68000, M68020, and Z80 based hardware

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	liballeg.so:${PORTSDIR}/devel/allegro \
		libpng15.so:${PORTSDIR}/graphics/png \
		libvga.so:${PORTSDIR}/graphics/svgalib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake tar:bzip2
USE_SDL=	sdl
USE_GNOME=	gnomehier
MAKEFILE=	makefile

ONLY_FOR_ARCHS=	i386

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s, [$$]_mcpu,,g" ${WRKSRC}/detect-cpu
	@${REINPLACE_CMD} -e "s,sdl-config,${SDL_CONFIG},g" -e "s,/usr/share/,/share/,g" \
		${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s,/usr/share/games/raine,${DATADIR},g" \
		${WRKSRC}/source/raine.c
	@${REINPLACE_CMD} -e "s,^#ifdef GFX_SVGA,#ifdef GFX_SVGALIB,g" \
		${WRKSRC}/source/gui/rgui.c \
		${WRKSRC}/source/alleg/display.c \
		${WRKSRC}/source/config.c

.include <bsd.port.post.mk>
