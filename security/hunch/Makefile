# Created by: Dan Pelleg <daniel+hunch@pelleg.org>
# $FreeBSD$

PORTNAME=	hunch
PORTVERSION=	1.1.8
CATEGORIES=	security
MASTER_SITES=	http://s89813419.onlinehome.us/ \
		http://www.cs.cmu.edu/~dpelleg/download/

MAINTAINER= ports@FreeBSD.org
COMMENT=	Scan httpd log files for vulnerability probes, mail admins

DEPRECATED=	Likely unused interactive port
EXPIRATION_DATE=2014-08-20

RUN_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net

USES=		perl5

IS_INTERACTIVE=	yes
NO_BUILD=	true

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} "Installing files"
	@${INSTALL_DATA} ${WRKSRC}/etc/hunch-special ${PREFIX}/etc
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/complain-httpd ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/contact ${PREFIX}/bin

post-install:
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
