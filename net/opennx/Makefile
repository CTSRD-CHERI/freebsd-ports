# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	opennx
PORTVERSION=	0.16.0.729
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CI-source

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open source drop in replacement for NoMachine's NX client

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient \
		libcups.so:${PORTSDIR}/print/cups-base

WRKSRC=		${WRKDIR}/${PORTNAME}-0.16

GNU_CONFIGURE=	yes
USES=		gmake
USE_XORG=	xmu
USE_WX=		2.8+
WX_UNICODE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
CPPFLAGS+=	-I${LOCALBASE}/include

INSTALLS_ICONS=	yes

NO_PACKAGE=	must generate a fresh private key at install time
LEGAL_PACKAGE=	yes

SSH_KEYGEN?=	ssh-keygen

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

# do not use default private key included with tarball
post-patch:
	@${RM} ${WRKSRC}/share/keys/server.id_dsa.key
	@${SSH_KEYGEN} -N '' -b 2048 -q -f ${WRKSRC}/share/keys/server.id_dsa.key
	@${REINPLACE_CMD} 's|/usr/NX/bin/||' \
		${WRKSRC}/extres/xdg/innovidata-opennx.desktop \
		${WRKSRC}/extres/xdg/innovidata-opennx-admin.desktop \
		${WRKSRC}/extres/xdg/innovidata-opennx-wizard.desktop
	@${RM} ${WRKSRC}/extres/xdg/*.bak

post-install:
	@${CHMOD} 440 ${STAGEDIR}${PREFIX}/share/keys/server.id_dsa.key

.include <bsd.port.mk>
