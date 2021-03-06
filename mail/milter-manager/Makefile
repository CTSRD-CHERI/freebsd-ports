# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	milter-manager
PORTVERSION=	2.0.4
CATEGORIES=	mail ruby
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:S/-/%20/}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Super milter that can invoke several milters selectively

LICENSE=	AGPLv3 GFDL GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	rubygem-glib2>0:${PORTSDIR}/devel/rubygem-glib2
LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev
RUN_DEPENDS=	rubygem-glib2>0:${PORTSDIR}/devel/rubygem-glib2

USE_RC_SUBR=	milter-manager
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		--with-libev \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USES=		gmake pkgconfig libtool
USE_GNOME=	glib20 intltool
USE_LDCONFIG=	yes
USE_RUBY=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

MANLANG=       "" ja
PORTDOCS=	*
PORTEXAMPLES=	*

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${DOCSDIR}
.else
CONFIGURE_ARGS+=--with-html-dir=${WRKDIR}/doc
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=	${WRKDIR}/examples
.endif

post-patch:
	${FIND} ${WRKSRC} -type f -name Makefile.in -exec \
	${REINPLACE_CMD} -e "s#\$$(datadir)/@PACKAGE@#${DATADIR}#" \
			 -e "s#\$$(datarootdir)/\$$(PACKAGE)#${DATADIR}#" {} +
	${REINPLACE_CMD} -e "s#\\\\\$$(pkgdatadir)/sample#${EXAMPLESDIR}#" ${WRKSRC}/configure

.include <bsd.port.mk>
