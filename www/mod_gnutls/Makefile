# Created by: Fumiyuki Shimizu <fumifumi@abacustech.jp>
# $FreeBSD$

PORTNAME=	mod_gnutls
PORTVERSION=	0.5.10
PORTREVISION=	3
CATEGORIES=	www security
MASTER_SITES=	http://modgnutls.sourceforge.net/downloads/ \
		http://www.outoforder.cc/downloads/mod_gnutls/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mod_gnutls uses the GnuTLS library to provide SSL, and TLS encryption for Apache HTTPD

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

USE_AUTOTOOLS=	libtool
USES=		pkgconfig tar:bzip2
USE_APACHE=	22
GNU_CONFIGURE=	yes

DOCS=		LICENSE NEWS README README.ENV

NO_STAGE=	yes
.include <bsd.port.pre.mk>

DBDIR=	${PREFIX}/var/db/${PORTNAME}

SUB_FILES=	pkg-message
PLIST_SUB+=	DBDIR=${DBDIR}

CONFIGURE_ARGS=	--with-apxs=${APXS}

# mod_gnutls does not conflict with mod_ssl.
#pre-install:
#	@if test -e '${LOCALBASE}/${APACHEMODDIR}/mod_ssl.so'; then for opt in -a -A -A; do '${APXS}' -e "$${opt}" -n ssl '${LOCALBASE}/${APACHEMODDIR}/mod_ssl.so' >/dev/null 2>&1; done; else true; fi

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} '${DOCSDIR}'
	@cd '${WRKSRC}' && ${INSTALL_DATA} ${DOCS} '${DOCSDIR}'
.endif
	@if test -d '${DBDIR}'; then true; else ${MKDIR} '${DBDIR}'; fi
	@${CHOWN} '${WWWOWN}:${WWWGRP}' '${DBDIR}'
	@${CHMOD} 'u=rwx,g=rx,o=' '${DBDIR}'
	@${CAT} '${PKGMESSAGE}'

.include <bsd.port.post.mk>
