# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	O2-tools
PORTVERSION=	2.00
CATEGORIES=	graphics
MASTER_SITES=	http://www.imglab.org/p/O2/archives/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Huge image processing tools and libraries

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/echo.*RANLIB/,+1d' ${WRKSRC}/libsrc/*/Makefile.in

.include <bsd.port.mk>
