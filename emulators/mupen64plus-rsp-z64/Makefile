# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-rsp-z64
DISTFILES=	${PORTNAME}${PKGNAMESUFFIX}-src-${PORTVERSION}.0${EXTRACT_SUFX}:plugin

COMMENT=	Low-level RSP processor plugin for the Mupen64Plus

LIB_DEPENDS=	libmupen64plus.so.2:${PORTSDIR}/emulators/mupen64plus-core

USE_GL=		#
USE_SDL=	#

MASTERDIR=	${.CURDIR}/../mupen64plus-core

OPTIONS_DEFINE=	#

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/${PORTNAME}
LDFLAGS+=	-L${LOCALBASE}/lib

EXTRACT_AFTER_ARGS=	#
BUILD_WRKSRC=		${WRKSRC}/${PORTNAME}${PKGNAMESUFFIX}/projects/unix
WRKSRC=			${WRKDIR}

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
