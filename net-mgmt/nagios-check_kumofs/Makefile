# $FreeBSD$

PORTNAME=	check_kumofs
PORTVERSION=	0.20100118
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
PKGNAMEPREFIX=	nagios-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin for kumofs manager/server

RUN_DEPENDS=	\
	nagios-plugins>0:${PORTSDIR}/net-mgmt/nagios-plugins \
	kumoctl:${PORTSDIR}/databases/kumofs

PLIST_FILES=	libexec/nagios/check_kumomgr libexec/nagios/check_kumosvr

NO_STAGE=	yes
do-build:
	${MKDIR} ${WRKSRC}
.for f in check_kumomgr check_kumosvr
	${SED} -e 's|/usr/local|${PREFIX}|' ${FILESDIR}/${f}.in > ${WRKSRC}/${f}
.endfor

do-install:
.for f in check_kumomgr check_kumosvr
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/libexec/nagios/${f}
.endfor

.include <bsd.port.mk>
