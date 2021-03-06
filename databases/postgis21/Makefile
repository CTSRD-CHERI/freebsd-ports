# $FreeBSD$

PORTNAME=	postgis
PORTVERSION=	2.1.0
PORTREVISION=	6
CATEGORIES=	databases geography
MASTER_SITES=	http://download.osgeo.org/postgis/source/

MAINTAINER=	trevor@bitba.se
COMMENT=	Geographic objects support for PostgreSQL databases

LICENSE=	GPLv2

LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj \
		libgeos.so:${PORTSDIR}/graphics/geos \
		libjson.so:${PORTSDIR}/devel/json-c
RUN_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER_NODOT}-server

CONFLICTS=	postgis-1.* postgis-2.0.*
LATEST_LINK=	postgis21

USE_GNOME=	libxml2
USES=		gmake iconv:wchar_t perl5 pgsql pkgconfig libtool:keepla
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	build

OPTIONS_DEFINE=		LOADERGUI RASTER TOPOLOGY SFCGAL
OPTIONS_DEFAULT=	TOPOLOGY

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

LOADERGUI_DESC=	Enable shp2pgsql-gui
RASTER_DESC=	Raster support
TOPOLOGY_DESC=	Topology support
SFCGAL_DESC=	Enable sfcgal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLOADERGUI}
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gui
PLIST_SUB+=		LOADERGUI=""
.else
CONFIGURE_ARGS+=	--without-gui
PLIST_SUB+=		LOADERGUI="@comment "
.endif

.if ${PORT_OPTIONS:MRASTER}
.if ${OSVERSION} < 900033
BROKEN=			Raster suppport is broken on FreeBSD < 9.x
.endif
LIB_DEPENDS+=		libgdal.so:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-raster --with-gdalconfig=${LOCALBASE}/bin/gdal-config
PLIST_SUB+=		RASTER=""
.else
CONFIGURE_ARGS+=	--without-raster
PLIST_SUB+=		RASTER="@comment "
.endif

.if ${PORT_OPTIONS:MTOPOLOGY}
CONFIGURE_ARGS+=	--with-topology
PLIST_SUB+=		TOPOLOGY=""
.else
CONFIGURE_ARGS+=	--without-topology
PLIST_SUB+=		TOPOLOGY="@comment "
.endif

.if ${PORT_OPTIONS:MSFCGAL}
LIB_DEPENDS+=	libSFCGAL.so:${PORTSDIR}/databases/sfcgal
CONFIGURE_ARGS+=	--with-sfcgal=${LOCALBASE}/bin/sfcgal-config
PLIST_SUB+=	SFCGAL=""
.else
CONFIGURE_ARGS+=	--without-sfcgal
PLIST_SUB+=	SFCGAL="@comment "
.endif

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${GREP} -lR 'bin/bash' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e "s|/bin/bash|/bin/sh|"

pre-configure:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install: .SILENT
	${MKDIR} ${STAGEDIR}/${DATADIR}/tiger_2011
	(cd ${WRKSRC}/extras/tiger_geocoder/tiger_2011/ && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/tiger_2011/ "! ( -name *\.orig -o -name *\.bak )" )
	${MKDIR} ${STAGEDIR}/${DATADIR}/utils
	(cd ${WRKSRC}/utils/ && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/utils/ "! ( -name *\.orig -o -name *\.bak )" )

.include <bsd.port.mk>
