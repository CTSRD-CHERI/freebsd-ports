# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	dreampie
PORTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python shell which is designed to be reliable and fun

LICENSE=	GPLv3

USE_GNOME=	pygtk2 pygtksourceview
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

pre-patch:
	@${REINPLACE_CMD} -e "s|share/man/man1|man/man1|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
