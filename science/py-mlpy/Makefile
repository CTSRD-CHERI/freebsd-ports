# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mlpy
PORTVERSION=	3.5.0
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	High performance Python package for predictive modeling

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		cython>0:${PORTSDIR}/lang/cython
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${PYTHON_SITELIBDIR}/numpy/core
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
