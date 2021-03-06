# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	cal3d
PORTVERSION=	20060720
PORTREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	acm/${PORTNAME}
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Skeletal based 3D character animation library written in C++ (devel)

CONFLICTS=	cal3d-[0-9]*

USES=		pkgconfig libtool tar:bzip2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake autoheader libtoolize
AUTOMAKE_ARGS=	--add-missing

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^\(pkgconfigdir\ =\).*|\1 $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|<istream>|<iostream>|' \
		${WRKSRC}/src/cal3d/buffersource.h \
		${WRKSRC}/src/cal3d/loader.h \
		${WRKSRC}/src/cal3d/streamsource.h
	@${REINPLACE_CMD} -e '/^all_libraries/d' ${WRKSRC}/src/cal3d/Makefile.am

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${LIBTOOLIZE} --automake --force

# XXX: handle slight differences between 6.x and 5.x/4.x
post-install:
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/libcal3d.a

.include <bsd.port.mk>
