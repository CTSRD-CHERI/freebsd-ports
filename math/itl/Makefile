# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	itl
PORTVERSION=	4.0.0.1
CATEGORIES=	math devel
MASTER_SITES=	http://www.osl.iu.edu/download/research/itl/
DISTNAME=	${PORTNAME}-4.0.0-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Iterative Template Library (based on MTL)

BUILD_DEPENDS=	${LOCALBASE}/include/mtl/mtl.h:${PORTSDIR}/math/mtl \
		${LOCALBASE}/include/blitz/blitz.h:${PORTSDIR}/math/blitz++
RUN_DEPENDS=	${LOCALBASE}/include/mtl/mtl.h:${PORTSDIR}/math/mtl \
		${LOCALBASE}/lib/libblitz.a:${PORTSDIR}/math/blitz++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mtl=${LOCALBASE}/include \
		--with-blitz=${LOCALBASE}/include
NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(WITH_MPI) || exists(${LOCALBASE}/bin/hcp)
BUILD_DEPENDS+=	${LOCALBASE}/bin/hcp:${PORTSDIR}/net/lam
RUN_DEPENDS+=	${LOCALBASE}/bin/hcp:${PORTSDIR}/net/lam
CONFIGURE_ARGS+=--with-mpi=lam
.endif

.include <bsd.port.post.mk>
