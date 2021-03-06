# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	phpGedView
PORTVERSION=	4.2.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:tl}/1%20PhpGedView/PhpGedView%20v${PORTVERSION}
DISTNAME=	${PORTNAME:S/p/P/}-basic-${PORTVERSION}

MAINTAINER=	fbsd@opal.com
COMMENT=	Online genealogy viewer

DEPRECATED=	Superceded by www/webtrees
EXPIRATION_DATE=2014-08-15

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USES=		zip:infozip
USE_PHP=	calendar dom gd pcre session xml
NO_BUILD=	yes

SUB_FILES=	pkg-message pkg-deinstall
DISTATE=	config.php config_download.php config_gedcom.php

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
DB_DESC=	Data storage

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
USE_PHP +=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
USE_PHP +=	pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP +=	pdo_sqlite
.endif

post-extract:
.for f in ${DISTATE}
	@${MV} ${WRKSRC}/${f} ${WRKSRC}/${f}-dist
.endfor

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}/index ${STAGEDIR}${WWWDIR}/media
	@${CHMOD} -R u+w ${STAGEDIR}${WWWDIR}/index ${STAGEDIR}${WWWDIR}/media
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/index ${WWWDIR}/media' >>${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R u+w ${WWWDIR}/index ${WWWDIR}/media' >>${TMPPLIST}

.include <bsd.port.mk>
