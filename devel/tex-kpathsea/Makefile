# $FreeBSD$

PORTNAME=	kpathsea
PORTVERSION=	6.1.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20120701-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Path searching library for TeX

USES=		gmake tar:xz libtool
USE_LDCONFIG=	yes
USE_TEX=	texlive
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES}
EXTRACT_FILES=	${DISTNAME}/build-aux \
		${DISTNAME}/texk/kpathsea
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea
GNU_CONFIGURE=	yes

INFO=		kpathsea

.include <bsd.port.mk>
