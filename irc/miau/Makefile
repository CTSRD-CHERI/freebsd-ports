# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=		miau
PORTVERSION=		0.6.6
CATEGORIES=		irc ipv6
MASTER_SITES=		SF

MAINTAINER=		dhn@FreeBSD.org
COMMENT=	Fully featured easy to use IRC-bouncer

USES=			iconv tar:bzip2
GNU_CONFIGURE=		yes

INFO=			miau

CONFIGURE_ARGS=		--enable-dccbounce \
			--enable-automode \
			--enable-releasenick \
			--enable-ctcp-replies \
			--enable-mkpasswd \
			--enable-uptime \
			--enable-chanlog \
			--enable-privlog \
			--enable-onconnect \
			--enable-empty-awaymsg \
			--enable-dumpstatus \
			--disable-dependency-tracking
CPPFLAGS+=		-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS IPV6
IPV6_CONFIGURE_ON=	--enable-ipv6

post-patch:
	@${REINPLACE_CMD} -e 's,\$$datadir/doc/miau/examples,${EXAMPLESDIR},g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
