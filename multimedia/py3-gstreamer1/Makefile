# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	1.2.1
CATEGORIES=	multimedia python
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	1
DISTNAME=	gst-python-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Python bindings for gstreamer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake pathfix pkgconfig tar:bzip2
USE_PYTHON=	3
USE_GNOME=	py3gobject3
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${GST_VERSION}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE} ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

PLIST_SUB+=	PVERSION=${PYTHON_VER:S/.//}

post-install:
	${SETENV} PYTHON=${PYTHON_CMD} ${SH} ${WRKSRC}/py-compile \
		--destdir ${STAGEDIR} \
		--basedir ${PYTHON_SITELIBDIR} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/pygst.py

.include <bsd.port.mk>
