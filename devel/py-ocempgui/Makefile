# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	ocempgui
PORTVERSION=	0.2.9
PORTREVISION=	7
CATEGORIES=	devel python
MASTER_SITES=	SF/ocemp/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	OcempGUI-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	GUI toolkit in python

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${LOCALBASE}/include/${PYTHON_VERSION}/pygame/pygame.h:${PORTSDIR}/devel/py-game

USES=		python:2
USE_GNOME=	atk

PYTHON_FEATURES=	autoplist distutils

.include <bsd.port.mk>
