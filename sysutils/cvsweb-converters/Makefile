# Created by: Martin Kammerhofer <mkamm@gmx.net>
# $FreeBSD$

PORTNAME=	cvsweb-converters
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mitglied.multimania.de/mkamm/distfiles/ \
		http://www.student.tugraz.at/kammerhofer/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create hyperlinks to cvsweb from cvs[up] output or FreeBSD commitlogs

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 tar:bzip2
NO_BUILD=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/commitlog2cvsweb bin/cvsrdiff2cvsweb \
		bin/cvsuplog2cvsweb etc/cvsweb-converters.conf.sample
PKGMESSAGE=	${WRKDIR}/pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
	@${SED} -e 's|$${PREFIX}|${PREFIX}|g' -- \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
