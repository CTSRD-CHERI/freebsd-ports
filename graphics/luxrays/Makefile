# Created by: Natacha Porté <natbsd@instinctive.eu>
# $FreeBSD$

PORTNAME=	luxrays
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://src.luxrender.net/luxrays/archive/
DISTNAME=	${HG_NODEID}
DIST_SUBDIR=	luxrender

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Accelerate the ray intersection process by using GPUs

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libfreeimage.a:${PORTSDIR}/graphics/freeimage
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

DEPRECATED=	No longer needed as luxrender bundles its own verion now
EXPIRATION_DATE=2014-08-15

HG_NODEID=	475fbf15f0ca

USES=		bison cmake tar:bzip2
USE_GL=		glew glut
WRKSRC=		${WRKDIR}/luxrays-${HG_NODEID}

CMAKE_ARGS=	-DLUXRAYS_DISABLE_OPENCL:BOOL=ON

NO_STAGE=	yes
do-install:
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${PREFIX}/include)
	${INSTALL_DATA} ${WRKSRC}/lib/libluxrays.a ${PREFIX}/lib

.include <bsd.port.mk>
