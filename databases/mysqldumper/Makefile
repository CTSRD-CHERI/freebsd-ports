# Created by: Marek Holienka <marekholienka@gmail.com>
# $FreeBSD$

PORTNAME=	mysqldumper
PORTVERSION=	1.24.4
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/MySQLDumper/
DISTNAME=	MySQLDumper${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for backing up MySQL databases

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBI>=1.48:${PORTSDIR}/databases/p5-DBI

OPTIONS_DEFINE=	APACHE LIGHTTPD
OPTIONS_DEFAULT=APACHE

PORTSCOUT=	limit:^[0-9\.]*$$

NO_BUILD=	yes
USE_MYSQL=	yes
USE_PHP=	ftp mysql session zlib
USES=		perl5 zip

PLIST_SUB=	WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
WRKSRC=		${WRKDIR}/msd${PORTVERSION}

APACHE_USE=		APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
