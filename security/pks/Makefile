# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=		pks
PORTVERSION=		0.9.6.20040312
CATEGORIES=		security www
MASTER_SITES=		http://pks.sourceforge.net/:sf ${MASTER_SITE_LOCAL}:local
MASTER_SITE_SUBDIR=	.:sf mandree:local
DISTFILES=		pks-current.tgz:sf,local

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	PGP Public Key Server

LICENSE=        BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GCC=	any
USE_BDB=	yes
WANT_BDB_VER=	41 # pks dumps core with 42 and doesn't build with 43+

OPTIONS_DEFINE= DOCS
PORTDOCS=       pks_help.* README EMAIL
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/pks --localstatedir=/var/pks \
		--docdir=${PREFIX}/share/doc/pks --sysconfdir=${EXAMPLESDIR} \
		--libdir=${LOCALBASE}/lib --with-libwrap
MAKE_ENV+=	SUBDIRS=
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	DBLIB="-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}" DBINC=-I${BDB_INCLUDE_DIR} DBHDR=db.h


SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_RC_SUBR=	pksd

.include <bsd.port.options.mk>

post-extract:
	@${CP} -a ${FILESDIR}/EMAIL ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgpsplit
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pksdctl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pksclient
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/pksd
	${INSTALL_DATA}  ${WRKSRC}/pksd.conf ${STAGEDIR}${PREFIX}/etc/pksd.conf.sample
	#${CHOWN} pksd:pksd /var/pks

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
