# Created by: Max Khon
# $FreeBSD$

PORTNAME=	nltools
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nodelist tools

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf

NO_STAGE=	yes
.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
