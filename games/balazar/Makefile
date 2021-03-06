# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	balazar
PORTVERSION=	0.3.4
PORTREVISION=	4
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/balazar/
DISTNAME=	Balazar-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D adventure and roleplaying game

LIB_DEPENDS=	libcal3d.so:${PORTSDIR}/graphics/cal3d \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	soya_editor:${PORTSDIR}/graphics/py-soya3d \
		${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		${PYTHON_SITELIBDIR}/tofu/client.py:${PORTSDIR}/net/py-tofu \
		${PYTHON_SITELIBDIR}/cerealizer/__init__.py:${PORTSDIR}/security/py-cerealizer

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		glew
USE_SDL=	sdl mixer
USES=		gettext twisted tar:bzip2

PYDISTUTILS_PKGNAME=	Balazar
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/setup.cfg

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
