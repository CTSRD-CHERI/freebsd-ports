# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	nagiostat
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagiostat parses performance-data from Nagios and generates graphs

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool \
		nagios:${PORTSDIR}/net-mgmt/nagios

USES=		perl5 tar:tgz
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NAGIOSDIR?=	/var/spool/nagios
DOC_FILES=	README GPL.txt

NAGIOSWWWDIR?=	www/nagios
PLIST_SUB+=	NAGIOSWWWDIR=${NAGIOSWWWDIR}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%NAGIOSTATCONFDIR%%|${PREFIX}/etc/|' \
		-e 's|%%NAGIOSTATDIR%%|${PREFIX}/libexec/${PORTNAME}/|' \
		-e 's|%%NAGIOSTATRRD%%|${NAGIOSDIR}/${PORTNAME}rrd/|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/nagiostat ${WRKSRC}/nagiostat.conf ${WRKSRC}/README
do-install:
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	@${MKDIR} ${NAGIOSDIR}/${PORTNAME}rrd
	@${INSTALL_SCRIPT} ${WRKSRC}/nagiostat ${PREFIX}/libexec/${PORTNAME}/
	@${LN} -fs ${PREFIX}/libexec/${PORTNAME}/nagiostat ${PREFIX}/${NAGIOSWWWDIR}/cgi-bin/nagiostat.cgi
	@${INSTALL_DATA} ${WRKSRC}/nagiostat.conf ${PREFIX}/etc/nagiostat.conf-sample
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}/html-templates/
	@${INSTALL_DATA} ${WRKSRC}/html-templates/default.html ${PREFIX}/libexec/${PORTNAME}/html-templates/
	@${INSTALL_DATA} ${WRKSRC}/html-templates/graphindex.html ${PREFIX}/libexec/${PORTNAME}/html-templates/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
