# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thunderbird
DISTVERSION=	31.0
CATEGORIES=	mail news net-im ipv6
DISTNAME=	${PORTNAME}-${DISTVERSION}
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/linux-i686/en-US

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Mozilla Thunderbird is standalone mail and news that stands above

USES=		tar:bzip2

WANT_GTK218=	yes

USE_LINUX_APPS=	dbusglib dbuslibs alsalib alsa-plugins-oss

.include "${.CURDIR}/../../www/linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
