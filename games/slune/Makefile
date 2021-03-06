# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	slune
PORTVERSION=	1.0.15
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/slune/
DISTNAME=	Slune-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D game. includes racing, car-crashing, and lots of action

RUN_DEPENDS=	soya_editor:${PORTSDIR}/graphics/py-soya3d \
		${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		${PYTHON_SITELIBDIR}/py2play/level.py:${PORTSDIR}/net-p2p/py-py2play
LIB_DEPENDS=	libcal3d.so:${PORTSDIR}/graphics/cal3d

DOS2UNIX_GLOB=	*.po *.mo
USES=		dos2unix gettext tar:bzip2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		glew
USE_SDL=	sdl mixer

PYDISTUTILS_PKGNAME=	Slune
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share

DESKTOP_ENTRIES=	"Slune" \
			"3D racing game" \
			"${DATADIR}/images/slune.48.png" \
			"slune" \
			"Game;ArcadeGame;" \
			false

NO_STAGE=	yes
post-extract:
.for FILE in slune.po.orig slune.po.rej
	@${RM} ${WRKSRC}/locale/es/LC_MESSAGES/${FILE}
.endfor

.for FILE in slune.po-0 slune.sl.mo slune.sl.po slune2.mo slune2.po
	@${RM} ${WRKSRC}/locale/sl/LC_MESSAGES/${FILE}
.endfor

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.cfg

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
