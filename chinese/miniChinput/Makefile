# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	miniChinput
PORTVERSION=	0.1.9
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/0-1-9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny version of Chinput

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
USES=		iconv gmake
USE_XORG=	x11 xt
USE_LDCONFIG=	yes
ALL_TARGET=	all data
INSTALL_TARGET=	install data-install
MAKE_JOBS_UNSAFE=	yes

BROKEN=		Hard code make, gcc, g++ and more everywhere
MAN1=		chinput.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Build fails on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,make,${MAKE_CMD},g' ${WRKSRC}/src/Makefile.in
	@echo "install:" >> ${WRKSRC}/src/IMdkit/Makefile
	@${REINPLACE_CMD} 's,^CFLAGS =,CFLAGS +=,' ${WRKSRC}/ImmModules/cce/Makefile.in \
		${WRKSRC}/ImmModules/turbo/Makefile.in \
		${WRKSRC}/src/server/Makefile.in \
		${WRKSRC}/src/client/Makefile.in
	@${REINPLACE_CMD} -e 's#$$(prefix)$$(imdir)/{gb,gbk,big5}#$$(prefix)$$(imdir)/gb $$(prefix)$$(imdir)/gbk $$(prefix)$$(imdir)/big5#g' ${WRKSRC}/ImmModules/turbo/Makefile.in
	@${REINPLACE_CMD} -e 's,-@PACKAGE_VERSION@,,g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's,/share/man,/man,g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/src/IMdkit/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
