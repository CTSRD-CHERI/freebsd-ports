# Created by: Max Khon
# $FreeBSD$

PORTNAME=	bsopack
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/0.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binkley-style outbound netmail packer

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf

USES=		makeinfo
MAN1=		bsopack.1
MANCOMPRESSED=	yes
INFO=		bsopack

NO_STAGE=	yes
.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
