# $FreeBSD$

PORTNAME=	lysdr
PORTVERSION=	0.0.6
CATEGORIES=	comms hamradio
MASTER_SITES=	GH

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Lysdr SDR program for Unix

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libjack.so:${PORTSDIR}/audio/jack

WRKSRC=		${WRKDIR}/gordonjcp-lysdr-46d31fe
USE_GITHUB=	yes
GH_ACCOUNT=	gordonjcp
GH_COMMIT=	46d31fe
GH_TAGNAME=	stable-0

USES=		pkgconfig
USE_GNOME=	gtk20
PLIST_FILES=	bin/lysdr

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/cexp.c ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/lysdr ${STAGEDIR}${PREFIX}/bin/lysdr

.include <bsd.port.mk>
