# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	visionworkbench
PORTVERSION=	2.2.0
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://ti.arc.nasa.gov/m/project/nasa-vision-workbench/
DISTNAME=	VisionWorkbench-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose image processing and computer vision library

BROKEN=		Fails to configure

LICENSE=	NOSA
LICENSE_GROUPS=	OSI
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=		fortran pkgconfig
USE_QT4=	moc_build qmake_build
USE_LDCONFIG=	yes
USE_PYTHON=	yes

LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS+=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
LIB_DEPENDS+=	libgdal.so:${PORTSDIR}/graphics/gdal
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
LIB_DEPENDS+=	libcairomm-1.0.so:${PORTSDIR}/graphics/cairomm

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-DBOOST_FILESYSTEM_VERSION=2,,g" ${WRKSRC}/configure

pre-configure:
	echo "HAVE_PKG_FLAPACK=yes" >> ${WRKSRC}/config.options
	echo "PKG_FLAPACK_LDFLAGS=${LDFLAGS}" >> ${WRKSRC}/config.options
	echo "HAVE_PKG_PYTHON=yes" >> ${WRKSRC}/config.options
	echo "PYTHON_LDFLAGS=-L${PYTHON_LIBDIR} -lboost_python -l${PYTHON_VERSION} ${PTHREAD_LIBS}" >> ${WRKSRC}/config.options
	echo "PYTHON_CPPFLAGS=-I${PYTHON_INCLUDEDIR}" >> ${WRKSRC}/config.options
	echo "HAVE_PKG_QT=yes" >> ${WRKSRC}/config.options
	echo "PKG_QT_LDFLAGS=-L${QT_LIBDIR}" >> ${WRKSRC}/config.options
	echo "PKG_QT_CPPFLAGS=-I${QT_INCDIR}" >> ${WRKSRC}/config.options
	echo "HAVE_PKG_BOOST=yes" >> ${WRKSRC}/config.options
	echo "PKG_BOOST_THREAD_MORE_LIBS=${PTHREAD_LIBS}" >> ${WRKSRC}/config.options
	echo "PKG_PATHS=${LOCALBASE}" >> ${WRKSRC}/config.options

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
