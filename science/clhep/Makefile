# Created by: will
# $FreeBSD$

PORTNAME=	clhep
PORTVERSION=	2.2.0.1
CATEGORIES=	science
MASTER_SITES=	http://wwwasd.web.cern.ch/wwwasd/lhc++/clhep/DISTRIBUTION/tarFiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-oriented toolkit for particle physics applications by CERN

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

WRKSRC=		${WRKDIR}/${PORTVERSION}/${PORTNAME:tu}

USES=		cmake:outsource perl5 tar:tgz
USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/DESTINATION/s|lib$${LIB_SUFFIX}|libdata|' \
		${WRKSRC}/cmake/Modules/ClhepToolchain.cmake

.include <bsd.port.mk>
