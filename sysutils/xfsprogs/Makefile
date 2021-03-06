# Created by: Craig Rodrigues <rodrigc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfsprogs
PORTVERSION=	2.9.8
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://oss.sgi.com/projects/xfs/cmd_tars/ \
		ftp://oss.sgi.com/projects/xfs/previous/cmd_tars/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	-1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities and library to manipulate an XFS filesystem

LICENSE=	LGPL21 GPLv2
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/doc/COPYING

USES=		gettext gmake libtool readline
USE_AUTOTOOLS=	autoconf libtoolize
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=		INSTALL="${INSTALL} ${_BINOWNGRP}" \
			LIBTOOL=${LIBTOOL} OPTIMIZER=" "
MAKE_ENV+=		INSTALL="${INSTALL} ${_BINOWNGRP}"
CONFIGURE_ARGS+=	--disable-shared --enable-readline
ALL_TARGET=

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/utmp/d' \
		${WRKSRC}/quota/report.c ${WRKSRC}/quota/util.c
	@${FIND} ${WRKDIR} -name "*.m4" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/local|'${LOCALBASE}'|g'
	@${RM} -f ${WRKSRC}/configure

post-configure:
	@${FIND} ${WRKSRC}/include -name "builddefs" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LIBRT =|LIBRT = -lrt|g'
	@${REINPLACE_CMD} 's|$$(PKG_DOC_DIR)|$$(DESTDIR)&|g' ${WRKSRC}/Makefile
.for dir in db doc fsck growfs io logprint mdrestore mkfs quota repair rtcp
	@${REINPLACE_CMD} -E 's,PKG_(BIN|DOC|INC|SBIN)_DIR,DESTDIR)$$(&,g' \
		${WRKSRC}/${dir}/Makefile
.endfor
.for i in 3 5 8
	@${REINPLACE_CMD} 's|$$(PKG_MAN_DIR)|$$(DESTDIR)&|g' \
		${WRKSRC}/man/man${i}/Makefile
.endfor
	@${REINPLACE_CMD} 's|$$(PKG_LOCALE_DIR)|$$(DESTDIR)&|' \
		${WRKSRC}/include/buildmacros

.include <bsd.port.mk>
