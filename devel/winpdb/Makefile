# Created by: ijliao
# $FreeBSD$

PORTNAME=	winpdb
PORTVERSION=	1.4.8
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	winpdb

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Advanced Python debugger

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

USES=		python
PYTHON_FEATURES=autoplist distutils
USE_WX=		3.0+
WX_COMPS=	python

.include <bsd.port.mk>
