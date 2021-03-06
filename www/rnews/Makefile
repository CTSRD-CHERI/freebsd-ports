# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	rnews
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server-side RSS aggregator written in PHP with MySQL

NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GD MYSQLSERVER DOCS
OPTIONS_DEFAULT=	GD
MYSQLSERVER_DESC=	Use MySQL-Server on localhost

.include <bsd.port.options.mk>

USE_PHP=	mysql mbstring pcre xml iconv
USE_MYSQL=	yes

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif

.if ${PORT_OPTIONS:MMYSQLSERVER}
RUN_DEPENDS+=	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql${MYSQL_VER}-server
.endif

RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	CHANGELOG INSTALL LICENSE README UPGRADE
.endif

CONFIGS=	inc/config.php inc/config_user.php

do-install:
	@${FIND} -s ${WRKSRC} -type  d | ${SED} -e 's,^${WRKSRC},${STAGEDIR}${WWWDIR},' \
		| ${XARGS} ${MKDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.php ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.css ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/*.js ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/.htaccess ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/tmp/.htaccess ${STAGEDIR}${WWWDIR}/tmp
	${INSTALL_DATA} ${WRKSRC}/favicon.ico ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/help.html ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} -v ${WRKSRC}/img/*.gif ${STAGEDIR}${WWWDIR}/img
	${INSTALL_DATA} -v ${WRKSRC}/img/*.png ${STAGEDIR}${WWWDIR}/img
	${INSTALL_DATA} -v ${WRKSRC}/img/*.jpg ${STAGEDIR}${WWWDIR}/img
	( ${FIND} ${WRKSRC}/inc -type f -not -name config_user.php -a -not -name config.php; ${ECHO} ${STAGEDIR}${WWWDIR}/inc ) \
		| ${XARGS} ${INSTALL_DATA} -v
	${INSTALL_DATA} -v ${WRKSRC}/magpierss/*.inc ${STAGEDIR}${WWWDIR}/magpierss
	${INSTALL_DATA} ${WRKSRC}/magpierss/extlib/Snoopy.class.inc ${STAGEDIR}${WWWDIR}/magpierss/extlib
	${INSTALL_DATA} -v ${WRKSRC}/opml/*.opml ${STAGEDIR}${WWWDIR}/opml
	@${CHOWN} ${WWWOWN} ${STAGEDIR}${WWWDIR}/magpierss/cache
	@${CHOWN} ${WWWOWN} ${STAGEDIR}${WWWDIR}/img/feeds
	@${CHOWN} ${WWWOWN} ${STAGEDIR}${WWWDIR}/tmp
.for FILE in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${WWWDIR}/${FILE}.sample
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC} \( -name "*.php" -o -name "*.inc" -o -name "*.js" -o -name "*.css" -o -name "*.jpg" \
		-o -name "*.gif" -o -name "*.png" -o -name ".htaccess" -o -name "help.html" -o -name "favicon.ico" -o -name "*.opml" \) \
		-and -not -name config_user.php -and -not -name config.php \
		| ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@exec if [ ! -f %D/%%WWWDIR%%/${FILE} ]; then \
		${INSTALL_DATA} %D/%%WWWDIR%%/${FILE}.sample %D/%%WWWDIR%%/${FILE}; \
		${CHOWN} ${WWWOWN} %D/%%WWWDIR%%/${FILE}; \
		${CHMOD} u+w %D/%%WWWDIR%%/${FILE}; fi' >> ${PLIST}
.endfor
.for FILE in ${CONFIGS}
	@${ECHO_CMD} '@unexec if cmp -s %D/%%WWWDIR%%/${FILE}.sample %D/%%WWWDIR%%/${FILE}; \
		then ${RM} -f %D/%%WWWDIR%%/${FILE}; fi' >> ${PLIST}
	@${ECHO_CMD} '%%WWWDIR%%/${FILE}.sample' >> ${PLIST}
.endfor
	@${ECHO_CMD} '@unexec if [ $$(ls %D/%%WWWDIR%%/img/feeds/|wc -w) -eq 0 ]; then ${RM} -rf %D/%%WWWDIR%%/img/feeds;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d -a -not -name feeds \
		| ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.mk>
