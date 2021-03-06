# Created by: ijliao
# $FreeBSD$
#   $MCom: ports/audio/solfege/Makefile,v 1.7 2007/09/09 23:47:50 mezz Exp $

PORTNAME=	solfege
PORTVERSION=	3.22.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}
PKGNAMESUFFIX=	-nosound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free eartraining software

LICENSE=	GPLv3

BUILD_DEPENDS=	docbook-xsl>0:${PORTSDIR}/textproc/docbook-xsl \
		txt2man:${PORTSDIR}/textproc/txt2man

USES=		display gettext gmake makeinfo pathfix pkgconfig
USE_GNOME=	pygtk2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_XML2PO=""
CONFIGURE_ARGS=	--disable-oss-sound \
		--enable-docbook-stylesheet=${STYLESHEET}
MAKE_ARGS=	nopycompile=YES skipmanual=yes

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	GNOME

GNOME_USE=	GNOME=pygnomeextras

STYLESHEET=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl

post-patch:
	@${REINPLACE_CMD} -e \
		's|cp --parents|${PAX} -rw|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|type=sequencer-device|type=fake-synth| ; \
		 s|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/default.config
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} -e \
		's|.*\(#!\).*|\1${PYTHON_CMD}|'

post-install:
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${DATADIR_REL})

.include <bsd.port.mk>
