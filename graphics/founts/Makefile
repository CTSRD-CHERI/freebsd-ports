# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	founts
PORTVERSION=	13
CATEGORIES=	graphics games
MASTER_SITES=	http://www.linuxmotors.com/founts/downloads/
DISTFILES=	${PORTNAME}-${DISTVERSION}.tgz

MAINTAINER=	koalative@gmail.com
COMMENT=	Demo/program inspired by Erics cascade

LICENSE=	GPLv2

USE_SDL=	sdl

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Founts" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Game;" false

post-patch:
#	@${REINPLACE_CMD} -e 's|#define ELAST 1.7||' \
#		${WRKSRC}/${PORTNAME}.c
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' \
		${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-lm `${SDL_CONFIG} --cflags --libs` founts.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
